/* 
*   hbird.c
*   
*/

/*

float hyst;

if( 60 < freq < 100)
    hyst = 2.5

if(100 < freq < 200)
    hyst = 3.5

if(200 < freq < 300)
    hyst = 4.5

if(300 < freq < 400)
    hyst 5.5



*/






#include "hbird.h"

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

enum MusicScale UpdateScaleLCD(uint16 currADC)
{
    // Sets the LCD to the right position
    CharLCD_Position(0,14);
    CharLCD_PrintString("      ");  //clear 6 chars
    CharLCD_Position(0,14);
    //maps ADC val to one of the scales
 
    enum MusicScale scale = map(currADC, 0, 240, 0, 6);
    // Prints the string to the LCD
    switch(scale){
        case MAJOR:
            CharLCD_PrintString("Major");
            break;        
        case NATURAL_MINOR:
            CharLCD_PrintString("NatMin");
            break;        
        case MAJOR_PENT:
            CharLCD_PrintString("PntMaj");
            break;        
        case MINOR_PENT:
            CharLCD_PrintString("PntMin");
            break;        
        case WHOLE_TONE:
            CharLCD_PrintString("Whole");
            break;        
        case BLUES:
            CharLCD_PrintString("Blues");
            break;
        case CHROMATIC:
            CharLCD_PrintString("Chroma");
            break;
    }
    // Returns the current scale to main
    return scale;
}

void UpdateTuner(double freqTable[MIDI_LEN], uint8 midiNumber, float freq) 
{
    float up, lb, okayUp, okayLb, upperThresh, lowerThresh;   //define upper and lower bounds for the note above/below of the "NoteSnapped" midiNumber
    up = (freqTable[midiNumber+1] - freqTable[midiNumber])/2;
    lb = (freqTable[midiNumber]-freqTable[midiNumber-1])/2;
    
    // setting threshold for which the user is on key
    okayUp = freqTable[midiNumber] + (.1*up);
    okayLb = freqTable[midiNumber] - (0.1*lb);
    
    upperThresh = up - okayUp;
    lowerThresh = okayLb - lb;
    
    // Here i define variables that split the interval between the snapped midi note & upper/lower note into three sections.
    float up1, up2, lb1, lb2;
    //Clears the whole second row
    CharLCD_PosPrintString(1,0,"                    ");
    // Prints neighboring notes on either side and current note in the center    
    char noteStr[3] = "   ";
    CharLCD_PosPrintString(1,2,midi_note_truename(midiNumber-1, noteStr));
    CharLCD_PosPrintString(1,14,midi_note_truename(midiNumber+1, noteStr));
    CharLCD_PosPrintString(1,8,midi_note_truename(midiNumber, noteStr));
    
    // USER ON KEY
    if (freq > okayLb && freq < okayLb) {
        CharLCD_PosPrintString(1,7,">");
        CharLCD_PosPrintString(1,11,"<");
    }
            
    
    // USER IS SHARP
    if(freq >= freqTable[midiNumber]) {
        up1 = freqTable[midiNumber] + upperThresh/3; 
        up2 = freqTable[midiNumber] + 2*up1;
        
        
        if(freq < up1) {
            CharLCD_PosPrintString(1,5,"   ");
            CharLCD_PosPrintString(1,11,">  ");
        } 
        else if(freq < up2 && freq >= up1) {
            CharLCD_PosPrintString(1,5,"   ");
            CharLCD_PosPrintString(1,11," > ");
        }
        else {
            CharLCD_PosPrintString(1,5,"   ");
            CharLCD_PosPrintString(1,11,"  >");
        }
    }
    // USER IS FLAT
    else if(freq < freqTable[midiNumber]) {
        lb1 = freqTable[midiNumber] - (lowerThresh/3);
        lb2 = freqTable[midiNumber] - (2*lb1);
        if(freq > lb1) {
            CharLCD_PosPrintString(1,5,"  <");
            CharLCD_PosPrintString(1,11,"   ");
        }
        else if(freq > lb2 && freq <= lb1) {
            CharLCD_PosPrintString(1,5," < ");
            CharLCD_PosPrintString(1,11,"   ");
        }
        else {
            CharLCD_PosPrintString(1,5,"<  ");
            CharLCD_PosPrintString(1,11,"   ");
        }
    }
}
enum MusicKey UpdateKeyLCD(uint16 currADC)
{   
    // maps ADC value to one of the keys
    enum MusicKey key = map(currADC, 0, 255, 0, 11);
    
    // Prints the string to the LCD, borrowing funciton from midi.c
    char noteStr[4] = "   ";
    CharLCD_PosPrintString(0,11,"  ")
    CharLCD_PosPrintString(0,11,midi_note_basename(key));
    
    // Return the updated key to main
    return key;
}

void initDisplay(void){
    
    CharLCD_ClearDisplay();
    
    UpdateKeyLCD(ADC_UI_GetResult16(KEY));   //update key
    UpdateScaleLCD(ADC_UI_GetResult16(SCALE));   //update scale
     
    CharLCD_PosPrintString(2,11,"          ");
    CharLCD_PosPrintString(2,11,"Hist:");  
    uint16 tempHyst = map(ADC_UI_GetResult16(HYST),0,255,0,101);
    if(tempHyst > 100) { tempHyst = 100; }
    CharLCD_PrintNumber(tempHyst);
    CharLCD_PrintString("%");

    CharLCD_PosPrintString(2,0,"          ");
    CharLCD_PosPrintString(2,0,"Velo:"); 
    uint16 tempVelo = map(ADC_UI_GetResult16(HYST),0,255,0,101);
    if(tempVelo > 100) { tempVelo = 100; }
    CharLCD_PrintNumber(tempVelo); 
}

void PushArray(char array[], char *value){   
    array[0] = value[0];
    array[1] = value[1];
    array[2] = value[2];
    array[3] = ' ';
}

int PrintNoteHistory(char array[]){

    static int status = 4;
    char tempBuf[22] = {};

    if(status > 0){
        //shift parent array
        int i;
        for(i = 25; i > 0; i--){
            
            array[i] = array[i - 1];
            
        }
        if(status == 4){
            array[0] = ' ';
        }
        status--;
        
        //create string to print after shifting by 1
        memcpy(tempBuf, &array[4], 20);
        CharLCD_PosPrintString(3,0,tempBuf);
        
    }else{
        status = 4;
    }
    
    return status; 
}

#if 0
//Random Crap from main.c
/* Identity Reply message */
const uint8 CYCODE MIDI_IDENTITY_REPLY[] = {
    0xF0u,      /* SysEx */
    0x7Eu,      /* Non-Realtime */
    0x7Fu,      /* ID of target device (7F - "All Call") */
    0x06u,      /* Sub-ID#1 - General Information */
    0x02u,      /* Sub-ID#2 - Identity Reply */
    0x7Du,      /* Manufacturer's ID: 7D - Educational Use */
    0xB4u, 0x04u,               /* Family code */
    0x32u, 0xD2u,               /* Model number */
    0x01u, 0x00u, 0x00u, 0x00u, /* Version number */
    /*0xF7         End of SysEx automatically appended */
};
#endif
/* [] END OF FILE */
