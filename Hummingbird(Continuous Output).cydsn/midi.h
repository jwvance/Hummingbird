#ifndef __MIDI_H__
#define __MIDI_H__

#define MIDI_LEN 128

    // Enumerated types for the note snapping function
enum MusicKey {KEY_OF_C, KEY_OF_Db, KEY_OF_D, KEY_OF_Eb, KEY_OF_E, KEY_OF_F,
               KEY_OF_Gb, KEY_OF_G, KEY_OF_Ab, KEY_OF_A, KEY_OF_Bb, KEY_OF_B};    

enum MusicScale {MAJOR, NATURAL_MINOR, MAJOR_PENT, MINOR_PENT, WHOLE_TONE, BLUES, CHROMATIC};    
    
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
 * Detects if the frequency has changed enough to change MIDI note.
 * Returns 1 if a new MIDI note should be calculated, 0 if not.
 */
int midi_note_changed(double freq, int last_midi, double notes[MIDI_LEN], int hystVal);

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

int NoteSnap(double freqTable[MIDI_LEN], float freq, enum MusicKey key, enum MusicScale scale);

#endif
