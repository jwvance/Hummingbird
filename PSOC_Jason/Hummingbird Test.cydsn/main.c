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
#include <FS.h>
#include <math.h>

int16 ADCoutput;

#define DATA_LENGTH 1024
uint16 dataFrame1[DATA_LENGTH] = {};
uint16 dataFrame2[DATA_LENGTH] = {};
uint16 frameIndex = 0;
uint8 currFrame = 0;

// DMA Configuration for DMA 
#define DMA_BYTES_PER_BURST 1
#define DMA_REQUEST_PER_BURST 1
#define DMA_SRC_BASE (CYDEV_PERIPH_BASE)
#define DMA_DST_BASE (CYDEV_SRAM_BASE)

char8 LCDstr[16];
int16 bufferFull = 0;

CY_ISR_PROTO(GetSample);  //declare the interrupt

//convert a decimal to binary for printing binary strings
const char *byte_to_binary(int x){
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

void DMA_Config(){    
    // Variable declarations for DMA
    uint8 DMA_1_Chan;
    uint8 DMA_1_TD[1] = {0};
    
    uint8 DMA_2_Chan;
    uint8 DMA_2_TD[1] = {0};

    // Iniitialize DMA channel 
    DMA_1_Chan = DMA_1_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST,
                                     HI16(DMA_SRC_BASE), HI16(DMA_DST_BASE));

    DMA_2_Chan = DMA_2_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST,
                                     HI16(DMA_SRC_BASE), HI16(DMA_DST_BASE));
    
    // Allocate TD 
    DMA_1_TD[0] = CyDmaTdAllocate();
    DMA_2_TD[0] = CyDmaTdAllocate();
    
    // TD configuration setting 
    CyDmaTdSetConfiguration(DMA_1_TD[0], DATA_LENGTH*2, DMA_1_TD[0], DMA_1__TD_TERMOUT_EN | TD_INC_DST_ADR);
    CyDmaTdSetConfiguration(DMA_2_TD[0], DATA_LENGTH*2, DMA_2_TD[0], DMA_1__TD_TERMOUT_EN | TD_INC_DST_ADR);
    
    // Set Source and Destination address 
    CyDmaTdSetAddress(DMA_1_TD[0], LO16((uint32)ADC_SAR_1_SAR_WRK0_PTR),
                      LO16((uint32)dataFrame1));  //VDAC8_1_Data_PTR
    CyDmaTdSetAddress(DMA_2_TD[0], LO16((uint32)ADC_SAR_1_SAR_WRK0_PTR),
                      LO16((uint32)dataFrame2));  //VDAC8_1_Data_PTR

    // TD initialization 
    CyDmaChSetInitialTd(DMA_1_Chan, DMA_1_TD[0]);
    CyDmaChSetInitialTd(DMA_2_Chan, DMA_2_TD[0]);

    // Enable the DMA channel 
    CyDmaChEnable(DMA_1_Chan, 1u);
    CyDmaChEnable(DMA_2_Chan, 1u);
}

int main()
{    
    CyGlobalIntEnable; // Enable global interrupts 
    isr_1_StartEx(GetSample);  // Start the ADC sampling interrupt
    FS_Init(); // Start the file system 
    LCD_Start(); // Start the LCD
    Timer_1_Start(); // Start the data sample timer
    ADC_SAR_1_Start();  // Start the ADC conversion
    //ADC_SAR_1_StartConvert();
    DMA_Config();  //config the DMA
    
    
    FS_Remove("samples.txt");    //remove existing file
    FS_FILE * pFile;    //create file pointer for new file
    pFile = FS_FOpen("samples.txt", "w");   //create new file with writing capabilities
    
    //Turn on DMA for both frames
    Control_Reg_1_Write(1);
    Control_Reg_2_Write(1);
    
    for(;;)
    {   
        /*
        LCD_Position(0u, 0u);
        LCD_PrintString("ADC Output: ");
        LCD_Position(1u, 0u);
        LCD_PrintString("DAC Input: ");
        // Print the ADC output value on LCD 
        LCD_Position(0u, strlen("ADC Output: "));
        LCD_PrintInt16(dataFrame1[1]);//ADC_SAR_1_GetResult16());

        // Print the DAC Data register value 
        LCD_Position(1u, strlen("DAC Input: "));
        LCD_PrintInt16(dataFrame2[1]); //VDAC8_1_Data
        */
        
        
        if(dataFrame1[DATA_LENGTH-1] != 0){
            Control_Reg_1_Write(0);
            Control_Reg_2_Write(0);
            
            char data [16];
            uint i;
            // Fills the file with the data from the buffer
            for(i = 0; i < DATA_LENGTH; i++){
                sprintf(data, "%d\n", dataFrame1[i]);
                FS_Write(pFile, data, SizeOfString(data));
            }
            //bufferFull = 0;    // Stops it from continuing to print to file
        
            FS_FClose(pFile);
        
            sprintf(LCDstr, "Write Complete");
            LCD_Position(0u, 0u);
            LCD_PrintString(LCDstr);
            exit(0);
        }
        
        
        // Skips the file writing until the buffer is full
        //if(bufferFull)
        {                        
            //initialize fft arrays
            /*double fftInput[SAMPLE_LEN];
            int loop;
            for(loop=0; loop<SAMPLE_LEN; loop++){
                fftInput[loop]=dataFrame1[loop];   
            }
            
            //Populates Note-MIDI array (index=midi note, value=frequency
            double noteTable[MIDI_LEN];
            //populate_midi_array(noteTable);
            
            //Initilize the Frequency Variable that will be computed by pitch.c functions
            double pitchHz;
            
            // RUNS FFT HERE, using pitch_fft function from pitch.h
            //pitchHz = pitch_fft(fftInput, sampImg);
            // Finds MIDI note using midi.h function and creates MIDI array
            //double midiNote = midi_note_from_freq(noteTable,pitchHz);
    	 
            LCD_ClearDisplay();
            LCD_Position(0,0);
            LCD_PrintNumber(pitchHz);
            
            CyDelay(1000);
            
            // Reset the fftInput the sample
            int i;
            for(i=0; i<SAMPLE_LEN; i++)
            {
                //fftInput[i]=sampReal[i];  
                sampImg[i] = 0;
            }
            //isr_1_StartEx(GetSample);
            bufferFull = 0;
            */
            
            
            
        }        
    }
}


CY_ISR(GetSample){
    /*
    // Clear pending Interrupt 
    isr_1_ClearPending();
    
    if(ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT) && !bufferFull) {
        ADCoutput = ADC_SAR_1_GetResult16();
        // Pushes the sample onto the frame (AKA buffer) if we have room
        if(frameIndex < DATA_LENGTH){
            dataFrame1[frameIndex] = (double)ADCoutput;    
            frameIndex++;
            
        }else{          // Tells the main our buffer is full, resets frame index
//            if(currFrame){
//                currFrame = 0;
//            }else{
//                currFrame = 1;
//            }
            bufferFull = 1;
            frameIndex = 0;
            //isr_1_Stop();
        }
    }  
    */
}
