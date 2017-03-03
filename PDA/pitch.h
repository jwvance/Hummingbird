#ifndef __PITCH_H__
#define __PITCH_H__
    
#include "fft.h"

#define SAMPLE_LEN 1024
#define SAMPLE_RATE 16000

/*
 * Sets up the FFT tables to SAMPLE_LEN size.
 */
void pitch_init();

/*
 * Calculate the fundamental pitch using FFT.
 * Returns 0.0 on error.
 */
double pitch_fft(double real[SAMPLE_LEN], double imag[SAMPLE_LEN]);

double pitch_yaapt(double samples[SAMPLE_LEN]);

#endif
