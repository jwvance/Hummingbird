#include <math.h>
#include "midi.h"

/*******************************************************************************
* Function Name: GenerateMidiArray
********************************************************************************
* Summary:
*  Aquires command, note, and velocity bytes and tosses them into an array (supplied by user)
*
* Parameters:
*  midiArray[4], cmd, note, vel
*
* Return:
*  None, modifies midiArray[]
*
*******************************************************************************/
void GenerateMidiArray(uint8 midiArray[4], uint8 cmd, uint8 note, uint8 vel)
{
    midiArray[0]=cmd;
    midiArray[1]=note;
    midiArray[2]=vel;
}

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
	return (int)(round((69 + (12 * log(freq / 440) / log(2.0)))));
}

int midi_note_changed(double freq, int last_midi, double notes[MIDI_LEN], float hystVal)
{
    if (last_midi < 1) {
        last_midi = 1;
    } else if (last_midi > 126) {
        last_midi = 126;
    }
    
    float upper = notes[last_midi] + hystVal*(notes[last_midi + 1] - notes[last_midi]);
    float lower = notes[last_midi] - hystVal*(notes[last_midi] - notes[last_midi - 1]);
    
    return (freq > upper) || (freq < lower);
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
		return "D#";
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
		return "A#";
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
// REVISIONS:
//  Trying to implement this design: freq<freqtable[key+startOctave+scale[i]]
int scaleMajor[29]=    { 0, 2, 4, 5, 7, 9,11,        // first octave
                        12,14,16,17,19,21,23,        // second octave
                        24,26,28,29,31,33,35,        // third octave
                        36,38,40,41,43,45,47,        // forth octave
                        48};
int scaleNatMinor[29]=
                     { 0, 2, 3, 5, 7, 8,10,         // first octave
                      12,14,15,17,19,20,22,        // second octave
                      24,26,27,29,31,32,34,        // third octave
                      36,38,39,41,43,44,46,        // forth octave
                      48};
#if 1
int NoteSnap(double freqTable[MIDI_LEN], float freq, enum MusicKey key, enum MusicScale scale)
{  
    if(key<0 || key>=127){
        return -1;
    }
    
    
    int i = key;    // Scrolls through our scale to find the proper note
    int note, prevNote;       // Our output, and temporary variable for storing the current MIDI note
    float lb,up; // lower and upper bounds for computing the rounded freq


    // error out for freq < keying point
    if(freq<freqTable[i]) {
            return -1;
    } 

    if (scale == CHROMATIC) {
        return (float)midi_note_from_freq(freq);
    }
    
    // Major scale
    if(scale==MAJOR){
        while(i<50)     //cycles through all the notes in the major scale
        {
            note = key + 24 + scaleMajor[i];        // The current MIDI note is the key+octave scaler+place we are in the scale
            if(freq<freqTable[note]){               // When freq<note, we've found a note with a frequency higher than our input, now we are in the ballpark
                prevNote = key + 24 + scaleMajor[i-1]; //Find the previous note, then compare which our input was closer to
                if(freqTable[note]-freq > freq-freqTable[prevNote]){
                    return prevNote;                // If our input is closer to the previous note, return the previous
                }
                else{
                    return note;                    // If our input is closer to the current note, return the current note.
                }      
            }
            i++;
            
        }
    }


    // Increment Minor scale
    else if(scale==NATURAL_MINOR) {        
        {
            while(i<50)     //cycles through all the notes in the major scale
            {
                note = key + 24 + scaleNatMinor[i];        // The current MIDI note is the key+octave scaler+place we are in the scale
                if(freq<freqTable[note]){               // When freq<note, we've found a note with a frequency higher than our input, now we are in the ballpark
                    prevNote = key + 24 + scaleNatMinor[i-1]; //Find the previous note, then compare which our input was closer to
                    if(freqTable[note]-freq > freq-freqTable[prevNote]){
                        return prevNote;                // If our input is closer to the previous note, return the previous
                    }
                    else{
                        return note;                    // If our input is closer to the current note, return the current note.
                    }      
                }
                i++;
                
            }
        }
    }
          // End of minor


    // increment major pentatonic scale
    else if(scale==MAJOR_PENT) {
            while(freq > freqTable[i] && i<127) {        //C
                    i=i+2;        // D 
                    if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-2];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-2];
                               } 
                               return freqTable[i];
                       }
                       i=i+2;        // E
                       if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-2];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-2];
                               } 
                               return freqTable[i];
                       }
                       i=i+3;        //G
                       if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-3];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-3];
                               } 
                               return freqTable[i];
                       }
                       i=i+2;        //A
                       if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-2];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-2];
                               } 
                               return freqTable[i];
                       }
                       i=i+3;        // C
                       if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-3];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-3];
                               } 
                               return freqTable[i];
                       }
            }
    }        // end of major p


    // Minor Pentatonic scale
    else if(scale==MINOR_PENT) { 
            while(freq > freqTable[i] && i<127) {        // C
                    i=i+3;        //Eb
                    if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-3];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-3];
                               } 
                               return freqTable[i];
                       }
                       i=i+2;        //F
                       if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-2];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-2];
                               } 
                               return freqTable[i];
                       }
                       i=i+2;        //G
                       if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-2];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-2];
                               } 
                               return freqTable[i];
                       }
                       i=i+3;        //Bb
                       if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-3];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-3];
                               } 
                               return freqTable[i];
                       }
                       i=i+2;        // back at C
                       if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-2];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-2];
                               } 
                               return freqTable[i];
                       }
            }
    }        // end of minor pentatonic scale


    // Whole tone scale
    else if(scale==WHOLE_TONE) {
            while(freq > freqTable[i] && i<127) {
                    i=i+2;
                    if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-2];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-2];
                               } 
                               return freqTable[i];
                       }
            }
    }


    // Blues scale
    else if(scale==BLUES) {
            while(freq > freqTable[i] && i<127) {        //C
                    i=i+3;        //Eb
                    if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-3];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-3];
                               } 
                               return freqTable[i];
                       }
                       i=i+2;        //F
                       if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-2];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-2];
                               } 
                               return freqTable[i];
                       }
                       i++;        //Gb
                       if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-1];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-1];
                               } 
                               return freqTable[i];
                       }
                       i++;        //G
                       if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-1];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-1];
                               } 
                               return freqTable[i];
                       }
                       i=i+3;        //Bb
                       if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-3];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-3];
                               } 
                               return freqTable[i];
                       }
                       i=i+2;        // back at C again
                       if(freq<freqTable[i]) {
                        lb= freq - freqTable[i-2];
                        up= freqTable[i] - freq;
                               if(lb<up){
                                       return freqTable[i-2];
                               } 
                               return freqTable[i];
                       }
            }
    }        // end of blues scale
    
    return -1;




}        // end of FrequencyMap
#endif