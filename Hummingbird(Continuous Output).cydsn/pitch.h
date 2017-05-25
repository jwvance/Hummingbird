#ifndef __PITCH_H__
#define __PITCH_H__
    
#include "fft.h"
#include "device.h"
#define FRAME_LEN 256  //256
#define SAMPLE_RATE 8000 //8000

#define R_THRES 0.9    
#define LAG_MIN 6
#define LAG_MAX 200
    
/*
 * Sets up the FFT tables to FRAME_LEN size.
 */
void pitch_init();

/*
 * Calculate the fundamental pitch using FFT.
 * Returns 0.0 on error.
 */
//double pitch_fft(double real[FRAME_LEN], double imag[FRAME_LEN]);

//double pitch_yaapt(double samples[FRAME_LEN]);

double pitch_zero_cross(int16 samples[FRAME_LEN]);

float auto_correlate(int16 samples[FRAME_LEN]);

float pitch_amdf(int16 samples[FRAME_LEN]);

float pitch_auto_fft(int16 samples[FRAME_LEN]);

#endif
