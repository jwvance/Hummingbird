#ifndef __MIDI_H__
#define __MIDI_H__

#define MIDI_LEN 128

/*
 * Populates the notes array with the frequencies
 * corresponding to MIDI values. The index of each array
 * element will be the note.
 */
void populate_midi_array(double notes[MIDI_LEN]);

/*
 * Takes the populated notes array, and a test frequency.
 * Returns the corresponding MIDI note, using basic approximation.
 */
int midi_note_from_freq(double freq);

/*
 * Given a MIDI note, returns a string of the
 * base name note (C, D, Bb...). Does not include octave.
 *
 * Returns an empty string if the note cannot be determined.
 */
char *midi_note_basename(int note);

/*
 * Given a MIDI note, returns the octave that note is in.
 */
int midi_note_octave(int note);

/*
 * Given a MIDI note, returns the MIDI note with the same
 * note value, in the specified octave.
 */
int midi_note_shift_octave(int note, int new_octave);

#endif
