/* 
*   hbird.c
*   
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
 
    enum MusicScale scale = map(currADC, 0, 255, 0, 5);
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

enum MusicKey UpdateKeyLCD(uint16 currADC)
{   
    // maps ADC value to one of the keys
    enum MusicKey key = map(currADC, 0, 255, 0, 11);
    
    // Prints the string to the LCD, borrowing funciton from midi.c
    CharLCD_PosPrintString(0,11,"  ")
    CharLCD_PosPrintString(0,11,midi_note_basename(key));
    
    // Return the updated key to main
    return key;
}

void initDisplay(void){
    
    CharLCD_ClearDisplay();
    
    UpdateKeyLCD(UI_ADC_GetResult16(KEY));   //update key
    UpdateScaleLCD(UI_ADC_GetResult16(SCALE));   //update scale
     
    CharLCD_PosPrintString(2,11,"          ");
    CharLCD_PosPrintString(2,11,"Hist:");
        
    float tempHyst = (float)map(UI_ADC_GetResult16(HYST),0,255,50,100);
    
    tempHyst /= 100;
    
    CharLCD_PrintNumber(tempHyst);
    CharLCD_PrintString("%");
    

    CharLCD_PosPrintString(2,0,"          ");
    CharLCD_PosPrintString(2,0,"Vel:"); 
    CharLCD_PrintNumber(map(UI_ADC_GetResult16(VELO),0,255,0,100));   
}

/* [] END OF FILE */
