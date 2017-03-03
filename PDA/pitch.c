#include "pitch.h"

static double cos_table[SAMPLE_LEN];
static double sin_table[SAMPLE_LEN];

void pitch_init()
{
	fft_init(cos_table, sin_table, SAMPLE_LEN);
}

double pitch_fft(double real[SAMPLE_LEN], double imag[SAMPLE_LEN])
{
	int r = transform(real, imag, cos_table, sin_table, SAMPLE_LEN);
	if (!r) {
		return 0;
	}

	double max = 0.0;
	int max_i = 0;

	int i;
	for (i = 0; i < SAMPLE_LEN; i++) {
		if (real[i] > max) {
			max = real[i];
			max_i = i;
		}
	}

	return (double)max_i * (SAMPLE_RATE / (double)SAMPLE_LEN);
}

double pitch_yaapt(double samples[SAMPLE_LEN])
{
	return 0.0;
}
