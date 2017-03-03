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
bool fft_init(double cos_table[], double sin_table[], size_t n);

/*
 * FFT function. Call this one.
 */
bool transform(double real[], double imag[], double cos_table[],
			   double sin_table[], doublesize_t n);

bool inverse_transform(double real[], double imag[], double cos_table[],
					   double sin_table[], size_t n);

/* 
 * Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
 * The vector's length must be a power of 2. Uses the Cooley-Tukey decimation-in-time radix-2 algorithm.
 * Returns true if successful, false otherwise (n is not a power of 2, or out of memory).
 */
bool transform_radix2(double real[], double imag[], double cos_table[],
					  double sin_table[], size_t n);

bool transform_bluestein(double real[], double imag[], double cos_table[],
						 double sin_table[], size_t n);

bool convolve_real(const double x[], const double y[], double out[], size_t n);

bool convolve_complex(const double xreal[], const double ximag[], const double yreal[], const double yimag[], double outreal[], double outimag[], size_t n);



