/* 
 * Free FFT and convolution (C)
 * 
 * Copyright (c) 2016 Project Nayuki
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

#pragma once

#include <stdlib.h>
#include <stdbool.h>

/*
 * Initialize the sine and cosine tables.
 */
bool fft_init(float cos_table[], float sin_table[], size_t n);

/*
 * FFT function. Call this one.
 */
bool transform(float real[], float imag[], float cos_table[],
			   float sin_table[], size_t n);

bool inverse_transform(float real[], float imag[], float cos_table[],
					   float sin_table[], size_t n);

/* 
 * Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
 * The vector's length must be a power of 2. Uses the Cooley-Tukey decimation-in-time radix-2 algorithm.
 * Returns true if successful, false otherwise (n is not a power of 2, or out of memory).
 */
bool transform_radix2(float real[], float imag[], float cos_table[],
					  float sin_table[], size_t n);

bool transform_bluestein(float real[], float imag[], float cos_table[],
						 float sin_table[], size_t n);

bool convolve_real(const float x[], const float y[], float out[], float cos_table[], float sin_table[], size_t n);

bool convolve_complex(const float xreal[], const float ximag[], const float yreal[], const float yimag[], float outreal[], float outimag[], float cos_table[], float sin_table[], size_t n);



