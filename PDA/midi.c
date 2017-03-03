#include <math.h>
#include "midi.h"

void populate_midi_array(double notes[MIDI_LEN])
{
	// Frequency of A, used as a basis for generation
	int freq_a = 440;

	// Shifted up 1 (- 9 changed to - 8) for unknown reasons
	int i;
	for (i = 0; i < 128; i++) {
		notes[i] = (freq_a / 32) * pow(2.0, (i - 8) / 12.0); 
	}
}

int midi_note_from_freq(double freq)
{
	if (freq =< notes[0]) return 0;
	if (freq >= notes[127]) return 127;

	return 69 + (12 * log(freq / 440) / log(2.0));
}

char *midi_note_basename(int note)
{
	if (note % 12 == 0) {
		return "C";
	} else if ((note - 1) % 12 == 0) {
		return "C#";
	} else if ((note - 2) % 12 == 0) {
		return "D";
	} else if ((note - 3) % 12 == 0) {
		return "Eb";
	} else if ((note - 4) % 12 == 0) {
		return "E";
	} else if ((note - 5) % 12 == 0) {
		return "F";
	} else if ((note - 6) % 12 == 0) {
		return "F#";
	} else if ((note - 7) % 12 == 0) {
		return "G";
	} else if ((note - 8) % 12 == 0) {
		return "G#";
	} else if ((note - 9) % 12 == 0) {
		return "A";
	} else if ((note - 10) % 12 == 0) {
		return "Bb";
	} else if ((note - 11) % 12 == 0) {
		return "B";
	}

	return "";
}

int midi_note_octave(int note)
{
	return note / 12;
}

int midi_note_shift_octave(int note, int new_octave)
{
	int oct = midi_note_octave(note);
	if (oct == new_octave) return note;
	return note - (12 * (oct - new_octave));
}
