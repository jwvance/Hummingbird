/*** hbird.h ***
*   Contains functions relevant to the hummingbird main file, including functions for the user interface
*
*/

#include <device.h>
#include <stdlib.h>
#include <stdio.h>
#include <midi.h>
#include <pitch.h>

//defines for UI ADC mux
#define KEY     0
#define SCALE   1
#define HYST    2   
#define VELO    3

/* Function: Map
*   Takes a value, an input and output range. Returns the input value "mapped" from the input range to the output range
*   Useful for the user interface controls (potentiometer->scale/key)
*/
long map(long x, long in_min, long in_max, long out_min, long out_max);

/* Function: UpdateScaleLCD
*   Return: The current scale from the ADC,
*           Prints the current scale as a string to the LCD display
*   Input:  none, reads ADC value in the function
*   WARNING: Assumes LCD display and UI_ADC as been initilized properly
*/
enum MusicScale UpdateScaleLCD(uint16 currADC);

/* Function: UpdateKeyLCD
*   Return: The current key from the ADC,
*           Prints the current key as a string to the LCD display
*   Input:  none, reads ADC value in the function
*   WARNING: Assumes LCD display and UI_ADC has been initilized properly
*/
enum MusicKey UpdateKeyLCD(uint16 currADC);

void initDisplay(void);

void PushArray(int array[], int value, int size);

void PrintNoteHistory(int array[]);

/* [] END OF FILE */


