/* 
*   hbird.c
*   
*/
#include "hbird.h"


long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

enum MusicScale UpdateScaleLCD()
{
    // Sets the LCD to the right position
    CharLCD_Position(0,6);
    
    // Grabs the ADC value from the scale pot, maps it to one of the scales
    UI_ADC_IsEndConversion(UI_ADC_WAIT_FOR_RESULT);
    enum MusicScale scale = map(UI_ADC_GetResult16(0u), 0, 255, 0, 5);
    // Prints the string to the LCD
    switch(scale){
        case MAJOR:
            CharLCD_PrintString("Maj");
            break;        
        case NATURAL_MINOR:
            CharLCD_PrintString("NatMin");
            break;        
        case MAJOR_PENT:
            CharLCD_PrintString("MajPnt");
            break;        
        case MINOR_PENT:
            CharLCD_PrintString("MinPnt");
            break;        
        case WHOLE_TONE:
            CharLCD_PrintString("Whole");
            break;        
        case BLUES:
            CharLCD_PrintString("Blues");
            break;
    }
    // Returns the scale enum to main
    return scale;
}

enum MusicKey UpdateKeyLCD()
{
    // Sets the LCD to the right position
    CharLCD_Position(1,6);
    
    // Grabs the ADC value from the key pot, maps it to one of the keys
    UI_ADC_IsEndConversion(UI_ADC_WAIT_FOR_RESULT);
    enum MusicKey key = map(UI_ADC_GetResult16(1u), 0, 255, 0, 11);
    // Prints the string to the LCD, borrowing funciton from midi.c
    CharLCD_PrintString(midi_note_basename(key));
    
    // Returns the key enum to main
    return key;
}

/* [] END OF FILE */
