/* 
 * Free FFT and convolution (C)
 * 
 * Copyright (c) 2014 Project Nayuki
 * https://www.nayuki.io/page/free-small-fft-in-multiple-languages
 * 
 * (MIT License)
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * - The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 * - The Software is provided "as is", without warranty of any kind, express or
 *   implied, including but not limited to the warranties of merchantability,
 *   fitness for a particular purpose and noninfringement. In no event shall the
 *   authors or copyright holders be liable for any claim, damages or other
 *   liability, whether in an action of contract, tort or otherwise, arising from,
 *   out of or in connection with the Software or the use or other dealings in the
 *   Software.
 */

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "fft.h"

// Private function prototypes
static size_t reverse_bits(size_t x, unsigned int n);
static void *memdup(const void *src, size_t n);

#define FFT_SIZE_MAX ((size_t)-1)

bool fft_init(float cos_table[], float sin_table[], size_t n) {
	// Trigonometric tables
	if (FFT_SIZE_MAX / sizeof(float) < n / 2)
		return false;
	int i;
	for (i = 0; i < n / 2; i++) {
		cos_table[i] = cos(2 * M_PI * i / n);
		sin_table[i] = sin(2 * M_PI * i / n);
	}

	return true;
}


bool transform(float real[], float imag[], float cos_table[],
			   float sin_table[], size_t n) {
	if (n == 0)
		return true;
	else if ((n & (n - 1)) == 0)  // Is power of 2
		return transform_radix2(real, imag, cos_table, sin_table, n);
	else  // More complicated algorithm for arbitrary sizes
		return transform_bluestein(real, imag, cos_table, sin_table, n);
}


bool inverse_transform(float real[], float imag[], float cos_table[],
					   float sin_table[], size_t n) {
	return transform(imag, real, cos_table, sin_table, n);
}


bool transform_radix2(float real[], float imag[], float cos_table[],
					  float sin_table[], size_t n) {
	// Variables
	bool status = false;
	unsigned int levels;
	size_t size;
	size_t i;
	
	// Compute levels = floor(log2(n))
	{
		size_t temp = n;
		levels = 0;
		while (temp > 1) {
			levels++;
			temp >>= 1;
		}
		if (1u << levels != n)
			return false;  // n is not a power of 2
	}
	
	// Bit-reversed addressing permutation
	for (i = 0; i < n; i++) {
		size_t j = reverse_bits(i, levels);
		if (j > i) {
			float temp = real[i];
			real[i] = real[j];
			real[j] = temp;
			temp = imag[i];
			imag[i] = imag[j];
			imag[j] = temp;
		}
	}
	
	// Cooley-Tukey decimation-in-time radix-2 FFT
	for (size = 2; size <= n; size *= 2) {
		size_t halfsize = size / 2;
		size_t tablestep = n / size;
		for (i = 0; i < n; i += size) {
			size_t j;
			size_t k;
			for (j = i, k = 0; j < i + halfsize; j++, k += tablestep) {
				float tpre =  real[j+halfsize] * cos_table[k] + imag[j+halfsize] * sin_table[k];
				float tpim = -real[j+halfsize] * sin_table[k] + imag[j+halfsize] * cos_table[k];
				real[j + halfsize] = real[j] - tpre;
				imag[j + halfsize] = imag[j] - tpim;
				real[j] += tpre;
				imag[j] += tpim;
			}
		}
		if (size == n)  // Prevent overflow in 'size *= 2'
			break;
	}
	status = true;
	
	return status;
}

bool transform_bluestein(float real[], float imag[], float cos_table[],
						 float sin_table[], size_t n) {
	// Variables
	bool status = false;
	float *areal, *aimag;
	float *breal, *bimag;
	float *creal, *cimag;
	size_t m;
	size_t size_n, size_m;
	size_t i;
	
	// Find a power-of-2 convolution length m such that m >= n * 2 + 1
	{
		size_t target;
		if (n > (FFT_SIZE_MAX - 1) / 2)
			return false;
		target = n * 2 + 1;
		for (m = 1; m < target; m *= 2) {
			if (FFT_SIZE_MAX / 2 < m)
				return false;
		}
	}
	
	// Allocate memory
	if (FFT_SIZE_MAX / sizeof(float) < n || FFT_SIZE_MAX / sizeof(float) < m)
		return false;
	size_n = n * sizeof(float);
	size_m = m * sizeof(float);
	areal = calloc(m, sizeof(float));
	aimag = calloc(m, sizeof(float));
	breal = calloc(m, sizeof(float));
	bimag = calloc(m, sizeof(float));
	creal = malloc(size_m);
	cimag = malloc(size_m);
	if (cos_table == NULL || sin_table == NULL
			|| areal == NULL || aimag == NULL
			|| breal == NULL || bimag == NULL
			|| creal == NULL || cimag == NULL)
		goto cleanup;
	
	// Temporary vectors and preprocessing
	for (i = 0; i < n; i++) {
		areal[i] =  real[i] * cos_table[i] + imag[i] * sin_table[i];
		aimag[i] = -real[i] * sin_table[i] + imag[i] * cos_table[i];
	}
	breal[0] = cos_table[0];
	bimag[0] = sin_table[0];
	for (i = 1; i < n; i++) {
		breal[i] = breal[m - i] = cos_table[i];
		bimag[i] = bimag[m - i] = sin_table[i];
	}
	
	// Convolution
	if (!convolve_complex(areal, aimag, breal, bimag, creal, cimag, cos_table, sin_table, m))
		goto cleanup;
	
	// Postprocessing
	for (i = 0; i < n; i++) {
		real[i] =  creal[i] * cos_table[i] + cimag[i] * sin_table[i];
		imag[i] = -creal[i] * sin_table[i] + cimag[i] * cos_table[i];
	}
	status = true;
	
	// Deallocation
cleanup:
	free(cimag);
	free(creal);
	free(bimag);
	free(breal);
	free(aimag);
	free(areal);
	free(sin_table);
	free(cos_table);
	return status;
}

bool convolve_real(const float x[], const float y[], float out[], float cos_table[], float sin_table[], size_t n) {
	float *ximag, *yimag, *zimag;
	bool status = false;
	ximag = calloc(n, sizeof(float));
	yimag = calloc(n, sizeof(float));
	zimag = calloc(n, sizeof(float));
	if (ximag == NULL || yimag == NULL || zimag == NULL)
		goto cleanup;
	
	status = convolve_complex(x, ximag, y, yimag, out, zimag, cos_table, sin_table, n);
cleanup:
	free(zimag);
	free(yimag);
	free(ximag);
	return status;
}


bool convolve_complex(const float xreal[], const float ximag[], const float yreal[], const float yimag[], float outreal[], float outimag[], float cos_table[], float sin_table[], size_t n) {
	bool status = false;
	size_t size;
	size_t i;
	float *xr, *xi, *yr, *yi;
	if (FFT_SIZE_MAX / sizeof(float) < n)
		return false;
	size = n * sizeof(float);
	xr = memdup(xreal, size);
	xi = memdup(ximag, size);
	yr = memdup(yreal, size);
	yi = memdup(yimag, size);
	if (xr == NULL || xi == NULL || yr == NULL || yi == NULL)
		goto cleanup;
	
	if (!transform(xr, xi, cos_table, sin_table, n))
		goto cleanup;
	if (!transform(yr, yi, cos_table, sin_table, n))
		goto cleanup;
	for (i = 0; i < n; i++) {
		float temp = xr[i] * yr[i] - xi[i] * yi[i];
		xi[i] = xi[i] * yr[i] + xr[i] * yi[i];
		xr[i] = temp;
	}
	if (!inverse_transform(xr, xi, cos_table, sin_table, n))
		goto cleanup;
	for (i = 0; i < n; i++) {  // Scaling (because this FFT implementation omits it)
		outreal[i] = xr[i] / n;
		outimag[i] = xi[i] / n;
	}
	status = true;
	
cleanup:
	free(yi);
	free(yr);
	free(xi);
	free(xr);
	return status;
}

static size_t reverse_bits(size_t x, unsigned int n) {
	size_t result = 0;
	unsigned int i;
	for (i = 0; i < n; i++, x >>= 1)
		result = (result << 1) | (x & 1);
	return result;
}

static void *memdup(const void *src, size_t n) {
	void *dest = malloc(n);
	if (dest != NULL)
		memcpy(dest, src, n);
	return dest;
}
