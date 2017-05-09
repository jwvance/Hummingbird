#include "pitch.h"
#include <project.h>

static float cos_table[FRAME_LEN];
static float sin_table[FRAME_LEN];

void pitch_init()
{
    fft_init(cos_table, sin_table, FRAME_LEN);
}

double pitch_zero_cross(int16 samples[FRAME_LEN])
{
        int zc = 0;
        int i;
        for (i = 0; i < FRAME_LEN - 1; i++) {
                if (samples[i] * samples[i + 1] < 0) {
                        zc++;
                }
        }

        return ((double)zc / 2) / ((double)FRAME_LEN / SAMPLE_RATE);
}

float auto_correlate(int16 samples[FRAME_LEN]){
    float r;
    float best_r = 0;
    int16 best_lag = -1;
    
  
    int16 lag;
    for(lag = LAG_MIN; lag < LAG_MAX + 1; lag++){
        int32 ac = 0;
        
        int16 i;
        for(i = 0; i < FRAME_LEN - lag; i++){
            ac = ac + samples[i] * samples[i + lag];              
        }
        
        //double r;
        r = (float)ac / (float)FRAME_LEN;
        
        if(r > best_r){
            best_r = r;
            best_lag = lag;
        }  
    }     
    return (float)SAMPLE_RATE / best_lag;    
}

float pitch_auto_fft(int16 samples[FRAME_LEN])
{
    float f[FRAME_LEN];
    float imag[FRAME_LEN] = {};
    
    int i;
    for (i = 0; i < FRAME_LEN; i++) {
        f[i] = (float)samples[i] / 100;
    }
    
    transform(f, imag, cos_table, sin_table, FRAME_LEN);
    
    for (i = 0; i < FRAME_LEN; i++) {
        // Multiply by conjugate
        f[i] = f[i] * f[i] + imag[i] * imag[i];
        imag[i] = 0;
    }
    
    inverse_transform(f, imag, cos_table, sin_table, FRAME_LEN);
    
    int best_lag = 0;
    float max = 0;
    int lag;
    for (lag = LAG_MIN; lag < LAG_MAX; lag++) {
        if (f[lag] > max) {
            max = f[lag];
            best_lag = lag;
        }
    }
    
    return (float)SAMPLE_RATE / best_lag;
}

float pitch_amdf(int16 samples[FRAME_LEN])
{
    float r;
    float best_r = 1000;
    int best_lag = -1;
    
    uint16 lag;
    for (lag = LAG_MIN; lag < LAG_MAX + 1; lag++) {
        int amdf = 0;
        
        int i;
        for (i = 0; i < FRAME_LEN - lag; i++) {
            amdf += abs(samples[i] - samples[i + lag]);
        }
        
        r = (float)amdf / (float)FRAME_LEN;
        
        if (r < best_r) {
            best_r = r;
            best_lag = lag;
        }
    }
    
    return (float)SAMPLE_RATE / (float)best_lag;
}


//static double cos_table[FRAME_LEN];
//static double sin_table[FRAME_LEN];

//void pitch_init()
//{
//	fft_init(cos_table, sin_table, FRAME_LEN);
//}

//double pitch_fft(double real[FRAME_LEN], double imag[FRAME_LEN])
//{
//	int r = transform(real, imag, cos_table, sin_table, FRAME_LEN);
//	if (!r) {
//		return 0;
//	}
//
//	double max = 0.0;
//	int max_i = 0;
//
//	int i;
//	// for (i = 0; i < FRAME_LEN; i++) {
//	for (i = 3; i < FRAME_LEN-974; i++) {
//        
//		if (real[i] > max) {
//			max = real[i];
//			max_i = i;
//		}
//	}
//
//	return (double)max_i * (SAMPLE_RATE / (double)FRAME_LEN);
//}

//double pitch_yaapt(double samples[FRAME_LEN])
//{
//	return 0.0;
//}
