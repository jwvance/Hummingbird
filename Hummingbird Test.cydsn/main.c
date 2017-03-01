/* ========================================
 *
 * Copyright HUMMINGBIRD, 2017
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF HUMMINGBIRD.
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h>
#include <string.h>     
#include <stdlib.h>
#include <WAV.h>
#include <FS.h>

int16 ADCoutput;

#define DATA_LENGTH 1024u
short dataFrame1[DATA_LENGTH] = {};
short dataFrame2[DATA_LENGTH] = {};
uint16 frameIndex = 0;
uint8 currFrame = 0;

char8 LCDstr[10];
int16 bufferFull = 0;
uint8 frameCompleteFlag=0;

FS_FILE * pFile;
FILE *wav_sample;
const char *file = "wav_sample";


CY_ISR_PROTO(GetSample);  //declare the interrupt

const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}


int SizeOfString(char data[]){
    int i = 0;
    int size = 0;
    while(i < 8){
       
        if(data[i] == '\n'){
            size++;
            return size;
        }else{
            size++;
        } 
        i++;
    }
    return size;
}

int main()
{    
    // Enable global interrupts 
    CyGlobalIntEnable;
    
    // Start the file system
    FS_Init();
    
    // Start the LCD
    LCD_Start();
    
    // Start the data sample timer
    Timer_1_Start();
    
    // Start the ADC conversion
    ADC_SAR_1_Start();
    ADC_SAR_1_StartConvert();
    
    // Start the interrupt
    isr_1_StartEx(GetSample);
    
    // Display the value of ADC output on LCD 
    //LCD_Position(0u, 0u);
    //LCD_PrintString("ADC_Output:");
    
    //create .wav file, write all bytes to file
    //wav_sample = wavfile_open(file);
    //wavfile_write(wav_sample, dataFrame, DATA_LENGTH);
    //wavfile_close(wav_sample);  
    
    pFile = FS_FOpen("wamples.txt", "w");
    
    for(;;)
    {
        
        
        // Skips the file writing until the buffer is full
        if(bufferFull){
            char data [16];
            uint i;
            // Fills the file with the data from the buffer
            for(i = 0; i < DATA_LENGTH; i++){
                sprintf(data, "%d\n", dataFrame1[i]);
                FS_Write(pFile, data, SizeOfString(data));
            }
            bufferFull = 0;    // Stops it from continuing to print to file
        
             FS_FClose(pFile);
        
            sprintf(LCDstr, "Write Complete");
            LCD_Position(0u, 0u);
            LCD_PrintString(LCDstr);
        
        }
        
       
        
       
    }
}

CY_ISR(GetSample){
    /* Clear pending Interrupt */
    isr_1_ClearPending();
    
    if(ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT)) {
        ADCoutput = ADC_SAR_1_GetResult16();
        // Pushes the sample onto the frame (AKA buffer) if we have room
        if(frameIndex < DATA_LENGTH){
            dataFrame1[frameIndex] = ADCoutput;    
            frameIndex++;
            
        }else{          // Tells the main our buffer is full, resets frame index
//            if(currFrame){
//                currFrame = 0;
//            }else{
//                currFrame = 1;
//            }
            bufferFull = 1;
            frameIndex = 0;

            
        }
    }  
}