/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*  This is source code for the datasheet example of the USBFS component.
*   
* Related Document:
*  Universal Serial Bus Specification Revision 2.0 
*  Universal Serial Bus Device Class Definition for MIDI Devices Release 1.0
*  MIDI 1.0 Detailed Specification Document Version 4.2
*
********************************************************************************
* Copyright 2012-2013, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

// Comment

#include <device.h>
// Hummingbird Includes
#include <fft.h>
#include <midi.h>
#include <pitch.h>
#include <hbird.h>

/**** Defines ****/
#define BUTT1	(0x01u)
#define BUTT2	(0x02u)

#define THRESHHOLD 110

// Variables for Button I/O
uint8 csButtStates = 0u;
uint8 csButtStates_old = 0u;
uint8 csButtChange = 0u;
uint8 inqFlags_old = 0u;
char8 LCDstr[10];

// Variables for audio aquisition ISR
int16 dataFrames[2][FRAME_LEN];

int16 ADCoutput;
uint16 frameIndex = 0;
uint8 currFrame = 0;
uint8 sampleFrame = 0;              // Frame for main to process on.

int max_value = 0;

// Flags
bool frameReady[2] = {};          // Flag frame as valid for processing.
bool frameLocked[2] = {};          // Sample is being processed and should not be overwritten
bool sustain = false;                   // flag for holding a note until the user is done singing
bool frameProcessed=false;          // Flag to prevent us from processing the same frame twice while we fill the next frame

// Variables for MIDI/PDA
uint8 midiMsg[4];  
int lastNote = -1;                  // Last sent MIDI note. -1 means no MIDI signal was active.
int i=0;
float pitchHz;
double noteTable[MIDI_LEN]; //(index=midi note, value=frequency)
uint8 frame1InUse=0;
uint8 frame2InUse=0;
enum MusicScale curScale=MAJOR;
enum MusicKey   curKey=KEY_OF_C;

int test_max;


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

/* Need for Identity Reply message */
extern volatile uint8 USB_MIDI1_InqFlags;
extern volatile uint8 USB_MIDI2_InqFlags;

volatile uint8 usbActivityCounter = 0u;




/*******************************************************************************
* Function Name: SleepIsr
*******************************************************************************/
CY_ISR(SleepIsr)
{
    /* Chech USB activity */
    if( USB_CheckActivity() != 0u ){
        usbActivityCounter = 0u;
    }else{
        usbActivityCounter++;
    }
    /* Clear Pending Interrupt */
    SleepTimer_GetStatus();
}

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

int main()
{
    /**** Initilizations ****/
        
    // Enable global interrupts 
    CyGlobalIntEnable;
    CY_ISR_PROTO(GetSample);  //declare the audio sampling interrupt
    //CY_ISR_PROTO(UI_isr_Interrupt);     //declare the user interface interrupt
    
    I2C_CharLCD_Start();
    CharLCD_Start();
    
    // Start the interrupt
    isr_1_StartEx(GetSample);
    //UI_isr_StartEx(UI_isr_Interrupt);
        
    // Start the data sample timer
    Timer_1_Start();
    
    // Start the ADC conversion
    ADC_SAR_1_Start();
    ADC_SAR_1_StartConvert();
    UI_ADC_Start();
    UI_ADC_StartConvert();
     
    UART_Start();
    
    pitch_init();
    
    //Populates Note-MIDI array 
    populate_midi_array(noteTable);    

    /* Start USBFS device 0 with VDDD operation */
    USB_Start(0u, USB_DWR_VDDD_OPERATION); 
    
    /**** End of initilizations ****/
    
    /****************************************************** M A I N  L O O P ***************************************************************/
    while(1u)
    {
        #if 0
        if(USB_IsConfigurationChanged() != 0u) /* Host could send double SET_INTERFACE request */
        {
            if(USB_GetConfiguration() != 0u)   /* Init IN endpoints when device configured */
            {
                MIDI_PWR_Write(0u); /* Power ON CY8CKIT-044 board */ //WE DON'T HAVE THIS BOARD?? -MAG
                /* Start ISR to determine the sleep condition */
                Sleep_isr_StartEx(SleepIsr);
                /* Start SleepTimer's operation */
                SleepTimer_Start();
            	/* Enable the output endpoint */
                USB_MIDI_EP_Init();
            }
            else
            {
                SleepTimer_Stop();
            }    
        }        
        #endif
        
        if (1)
        //if(USB_GetConfiguration() != 0u)    /* Service USB MIDI when device configured */
        {
            #if 0
            /* Call this API from UART RX ISR for Auto DMA mode */
            #if(USB_EP_MM != USB__EP_DMAAUTO) 
                USB_MIDI_IN_Service();
            #endif
            /* In Manual EP Memory Management mode OUT_EP_Service() 
            *  may have to be called from main foreground or from OUT EP ISR
            */
            #if(USB_EP_MM != USB__EP_DMAAUTO) 
                USB_MIDI_OUT_EP_Service();
            #endif

            /* Sending an Identity Reply Universal Sysex message back to the computer */
            if((USB_MIDI1_InqFlags & USB_INQ_IDENTITY_REQ_FLAG) != 0u)
            {
                USB_PutUsbMidiIn(sizeof(MIDI_IDENTITY_REPLY), (uint8 *)MIDI_IDENTITY_REPLY, USB_MIDI_CABLE_00);
                USB_MIDI1_InqFlags &= ~USB_INQ_IDENTITY_REQ_FLAG;
            }
            #if (USB_MIDI_EXT_MODE >= USB_TWO_EXT_INTRF)
                if((USB_MIDI2_InqFlags & USB_INQ_IDENTITY_REQ_FLAG) != 0u)
                {
                    USB_PutUsbMidiIn(sizeof(MIDI_IDENTITY_REPLY), (uint8 *)MIDI_IDENTITY_REPLY, USB_MIDI_CABLE_01);
                    USB_MIDI2_InqFlags &= ~USB_INQ_IDENTITY_REQ_FLAG;
                }
            #endif /* End USB_MIDI_EXT_MODE >= USB_TWO_EXT_INTRF */
            #endif
            
            /*********************** M I D I  O U T P U T ****************************/
            // This is the frame we are operating on. It is always the opposite of the current frame, which is being written
            sampleFrame = currFrame ^ 0b01; 
            if (frameReady[sampleFrame]&&!frameProcessed) {
                // Lock the current frame and unset the current flag.
                frameLocked[sampleFrame] = true;
                frameProcessed = true;
                
                // Runs Pitch Detection Algorithm        
                //pitchHz = pitch_fft(dataFrames[sampleFrame], sampImg);
                //pitchHz = pitch_zero_cross(dataFrames[sampleFrame]);
                //pitchHz = auto_correlate(dataFrames[sampleFrame]);
                pitchHz = pitch_auto_fft(dataFrames[sampleFrame]);
                
                // Unlocks the frame
                frameLocked[sampleFrame] = false;
                
                //int note = NoteSnap(noteTable, pitchHz, curKey, curScale);
                int note = lastNote;
                
                if(pitchHz < 600 && pitchHz > 80){  //eliminate extreme, unintentional freqs
                    if (midi_note_changed(pitchHz, lastNote, noteTable)) {
                        note = NoteSnap(noteTable, pitchHz, curKey, curScale);
                        //note = midi_note_from_freq(pitchHz);
                    }
                }
                
                // If the new note is not the same as the last and does not = -1, the error value from note snap
                if (note != lastNote && note != -1) {
                    // If not the initial condition, send a note off signal when new note is detected
                    if (lastNote != -1) {
                        midiMsg[0] = USB_MIDI_NOTE_OFF;
                        midiMsg[1] = lastNote;
                        midiMsg[2] = 0u;        
                        
                        UART_PutChar(midiMsg[0]);
                        UART_PutChar(midiMsg[1]);
                        UART_PutChar(midiMsg[2]);
                        //USB_PutUsbMidiIn(3u, midiMsg, USB_MIDI_CABLE_00);
                        
                        
                    }
                    
                    midiMsg[0] = USB_MIDI_NOTE_ON;
                    midiMsg[1] = note;
                    midiMsg[2] = 100u;
                    
                    UART_PutChar(midiMsg[0]);
                    UART_PutChar(midiMsg[1]);
                    UART_PutChar(midiMsg[2]);
                    //USB_PutUsbMidiIn(3u, midiMsg, USB_MIDI_CABLE_00);                                       
                    
                    lastNote = note;
                }
         
                // Updates display for debugging
                CharLCD_ClearDisplay();
                CharLCD_Position(0,0);
                CharLCD_PrintNumber(pitchHz);
                CharLCD_Position(1,0);
                CharLCD_PrintString(midi_note_basename(midiMsg[1]));
                CharLCD_Position(1,2);
                CharLCD_PrintNumber(midiMsg[1]);
                
                /**** TEST: Output for UI ADC (Disabled for testing note on/off functionallity)****/
                curScale = UpdateScaleLCD();
                curKey = UpdateKeyLCD();
                                            
                
            } // If the frameReady was low, meaning no note is being hummed, send MIDI note off
                if(!frameReady[sampleFrame])
                {
                    midiMsg[0] = USB_MIDI_NOTE_OFF;
                    midiMsg[1] = lastNote;
                    midiMsg[2] = 0u;
                    
                    UART_PutChar(midiMsg[0]);
                    UART_PutChar(midiMsg[1]);
                    UART_PutChar(midiMsg[2]);

                    //USB_PutUsbMidiIn(3u, midiMsg, USB_MIDI_CABLE_00);  
                }
           

                #if 0
                #if(USB_EP_MM == USB__EP_DMAAUTO) 
                   #if (USB_MIDI_EXT_MODE >= USB_ONE_EXT_INTRF)
                        MIDI1_UART_DisableRxInt();
                        #if (USB_MIDI_EXT_MODE >= USB_TWO_EXT_INTRF)
                            MIDI2_UART_DisableRxInt();
                        #endif /* End USB_MIDI_EXT_MODE >= USB_TWO_EXT_INTRF */
                    #endif /* End USB_MIDI_EXT_MODE >= USB_ONE_EXT_INTRF */            
                    USB_MIDI_IN_Service();
                    #if (USB_MIDI_EXT_MODE >= USB_ONE_EXT_INTRF)
                        MIDI1_UART_EnableRxInt();
                        #if (USB_MIDI_EXT_MODE >= USB_TWO_EXT_INTRF)
                            MIDI2_UART_EnableRxInt();
                        #endif /* End USB_MIDI_EXT_MODE >= USB_TWO_EXT_INTRF */
                    #endif /* End USB_MIDI_EXT_MODE >= USB_ONE_EXT_INTRF */                
                #endif
                #endif
        } /* END USB CHECK */
        
        if( usbActivityCounter >= 2u ) 
        {
            MIDI1_UART_Sleep();
            MIDI2_UART_Sleep();
            MIDI_PWR_Write(1u);     /* Power OFF CY8CKIT-044 board */
                
            /*******************************************************************
            * Disable the USBFS block and set DP Interrupt for wake-up 
            * from sleep mode. 
            *******************************************************************/
            USB_Suspend(); 
            /* Prepares system clocks for the Sleep mode */
            CyPmSaveClocks();
            /*******************************************************************
            * Switch to the Sleep Mode for the PSoC 3 or PSoC 5LP devices:
            *  - PM_SLEEP_TIME_NONE: wakeup time is defined by PICU source
            *  - PM_SLEEP_SRC_PICU: PICU wakeup source 
            *******************************************************************/
            CyPmSleep(PM_SLEEP_TIME_NONE, PM_SLEEP_SRC_PICU);
            /* Restore clock configuration */
            CyPmRestoreClocks();
            /* Enable the USBFS block after power down mode */
            USB_Resume();
            
            /* Enable the output endpoint */
            USB_MIDI_EP_Init();
            MIDI_PWR_Write(0u);     /* Power ON CY8CKIT-044 board */
            MIDI1_UART_Wakeup();
            MIDI2_UART_Wakeup();
            usbActivityCounter = 0u; /* Re-init USB Activity Counter*/
        }
    } /* END Service USB MIDI when device configured */
    
    return 0;
} /**** END MAIN LOOP ****/    


/* Local processing of USB MIDI out events here */
void USB_callbackLocalMidiEvent(uint8 cable, uint8 *midiMsg) CYREENTRANT
{
    /* Support General System On/Off Message. */
    if(((USB_MIDI1_InqFlags & USB_INQ_SYSEX_FLAG) == 0u) && ((inqFlags_old & USB_INQ_SYSEX_FLAG) != 0u))
    {
        if(midiMsg[USB_EVENT_BYTE0] == USB_MIDI_SYSEX_GEN_MESSAGE)
        {
            if(midiMsg[USB_EVENT_BYTE1] == USB_MIDI_SYSEX_SYSTEM_ON)
            {
                MIDI_PWR_Write(0u); /* Power ON */
            }
            else if(midiMsg[USB_EVENT_BYTE1] == USB_MIDI_SYSEX_SYSTEM_OFF)
            {
                MIDI_PWR_Write(1u); /* Power OFF */
            }
        }
    }
    inqFlags_old = USB_MIDI1_InqFlags;
    cable = cable;
}    

// ***** GetSample ISR *****
// This ISR fills each audio frame. It runs on a timer which gives us our sampling rate.
// Each frame is 1024 samples stored in an array.

CY_ISR(GetSample){
    /* Clear pending Interrupt */
    //isr_1_ClearPending();
    Timer_1_STATUS;
    
    if (ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT)) {
        if (!frameLocked[currFrame]) {
            ADCoutput = ADC_SAR_1_GetResult16();
            
            if (ADCoutput > max_value) {                        // Updates the max value if applicable.
                max_value = ADCoutput;
            }
            
            if (frameIndex < FRAME_LEN) {
                dataFrames[currFrame][frameIndex] = ADCoutput;
                frameIndex++;
            } else {                                            // Frame is getting the last value before switching.
                frameReady[currFrame] = max_value >= THRESHHOLD;  // Sets the frameReady (note is on) high if the voice went over the
                                                                    //  noise threshold
                test_max = max_value;
                frameIndex = 0;
                max_value = 0;
                currFrame = currFrame ^ 0b01;                   // Swap current frame index.
                frameProcessed = false;                         // Signals to main that there is a new frame to process
            }
        } else {
            currFrame = currFrame ^ 0b01;                       // If a frame is processing, update a single frame only.
        }
    }
    
}
//UI_ISR(UserInterfaceISR){
//    UI_ISR_ClearPending();
    /* Clear pending Interrupt */
//    isr_1_ClearPending();
//    
//    if(ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT)) {
//        if((currFrame==1)&&(!frame1InUse)){    // Populates the first frame when it's the current frame and we aren't using it in main
//            ADCoutput = ADC_SAR_1_GetResult16();
//            // Pushes the sample onto the frame if we have room
//            if(frameIndex < DATA_LENGTH){
//                dataFrame1[frameIndex] = ADCoutput;    
//                frameIndex++;
//                
//            }else{          // Tells the main our frame1 is full, resets frame index
//                frameIndex = 0; 
//                currFrame  = 2; // Switches to frame 2
//            }
//        }
//        else if((currFrame==2)&&(!frame2InUse)){       // If the current frame is frame2 and It's not being processed
//               ADCoutput = ADC_SAR_1_GetResult16();
//            // Pushes the sample onto the frame if we have room
//            if(frameIndex < DATA_LENGTH){
//                dataFrame2[frameIndex] = ADCoutput;    
//                frameIndex++;
//                
//            }else{          // Tells the main our frame1 is full, resets frame index
//                frameIndex = 0; 
//                currFrame  = 1; // Switches to frame 1
//        }
//    }  
// }
//}


/* [] END OF FILE */
