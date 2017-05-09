/*******************************************************************************
* File Name: CharLCD_1_I2C.c
* Version 2.0
*
* Description:
*  This file provides source code for the CharLCD_I2C component's API.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CyLib.h"
#include "CharLCD_1_I2C.h"

#if(CY_PSOC4)
	#include "I2C_CharLCD_1_PVT.h"
	#include "I2C_CharLCD_1_I2C_PVT.h"
#else
	#include "I2C_CharLCD_1.h"
	#include "I2C_CharLCD_1_PVT.h"
#endif /*PSOC4*/

/* Stores the state of conponent. Indicates wherewer component is 
* in enabled state or not.
*/
uint8 CharLCD_1_enableState = 0u;

uint8 CharLCD_1_initVar = 0u;


/*******************************************************************************
* Function Name: CharLCD_1_Init
********************************************************************************
*
* Summary:
*  Perform initialization required for components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enable 4-bit interface
*        Clear the display
*        Enable auto cursor increment
*        Resets the cursor to start position
*  Also loads custom character set to LCD if it was defined in the customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void CharLCD_1_Init(void) 
{
    /* INIT CODE */
    CyDelay(CharLCD_1_INIT_DELAY);									/* Delay 20 ms */
    CharLCD_1_WrtCntrlUpNib(CharLCD_1_DISPLAY_8_BIT_INIT);   	/* Selects 8-bit mode */
    CyDelay(CharLCD_1_INIT_UP_NIB_DELAY);								/* Delay 5 ms */
	CharLCD_1_WrtCntrlUpNib(CharLCD_1_DISPLAY_8_BIT_INIT);  	/* Selects 8-bit mode */
    CyDelay(CharLCD_1_INIT_UP_NIB_DELAY);								/* Delay 5 ms */
	CharLCD_1_WrtCntrlUpNib(CharLCD_1_DISPLAY_8_BIT_INIT);  	/* Selects 8-bit mode */
	CyDelay(CharLCD_1_INIT_UP_NIB_DELAY);								/* Delay 5 ms */
	CharLCD_1_WrtCntrlUpNib(CharLCD_1_DISPLAY_4_BIT_INIT);   	/* Selects 4-bit mode */
	CyDelay(CharLCD_1_INIT_UP_NIB_DELAY);								/* Delay 5 ms */

	CharLCD_1_WriteControl(CharLCD_1_DISPLAY_4_BIT_INIT);		/* Write 4-bit Mode 2x16 or 4x20 Char */
	CyDelay(CharLCD_1_INIT_CMD_DELAY);								/* Delay 5 ms */
    CharLCD_1_WriteControl(CharLCD_1_CLEAR_DISPLAY);			/* Clear LCD Screen */
	CyDelay(CharLCD_1_INIT_CMD_DELAY);								/* Delay 5 ms */
    CharLCD_1_WriteControl(CharLCD_1_CURSOR_AUTO_INCR_ON);		/* Incr Cursor One Space to Right After Writes */
	CyDelay(CharLCD_1_INIT_CMD_DELAY);								/* Delay 5 ms */
	CharLCD_1_WriteControl(CharLCD_1_DISPLAY_ON_CURSOR_OFF);	/* Display ON Cursor OFF */
 	CyDelay(CharLCD_1_INIT_CMD_DELAY);								/* Delay 5 ms */  
	
	#if(CharLCD_1_CUSTOM_CHAR_SET != CharLCD_1_NONE)
        CharLCD_1_LoadCustomFonts(CharLCD_1_customFonts);
    #endif /* CharLCD_1_CUSTOM_CHAR_SET != CharLCD_1_NONE */
}


/*******************************************************************************
* Function Name: CharLCD_1_Enable									   *
********************************************************************************
*
* Summary:
*  Turns on the display.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
* Theory:
*  This finction has no effect when it called first time as
*  CharLCD_1_Init() turns on the LCD.
*
*******************************************************************************/
void CharLCD_1_Enable(void) 
{
    CharLCD_1_DisplayOn();
    CharLCD_1_enableState = 1u;
}


/*******************************************************************************
* Function Name: CharLCD_1_Start
********************************************************************************
*
* Summary:
*  Perform initialization required for components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enable 4-bit interface
*        Clear the display
*        Enable auto cursor increment
*        Resets the cursor to start position
*  Also loads custom character set to LCD if it was defined in the customizer.
*  If it was not the first call in this project then it just turns on the
*  display
*
*
* Parameters:
*  CharLCD_1_initVar - global variable.
*
* Return:
*  CharLCD_1_initVar - global variable.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void CharLCD_1_Start(void) 
{
    /* If not initialized then perform initialization */
    if(CharLCD_1_initVar == 0u)
    {
        CharLCD_1_Init();
        CharLCD_1_initVar = 1u;
    }

    /* Turn on the LCD */
    CharLCD_1_Enable();
}


/*******************************************************************************
* Function Name: CharLCD_1_Stop
********************************************************************************
*
* Summary:
*  Turns off the display of the LCD screen.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void CharLCD_1_Stop(void) 
{
    /* Calls LCD Off Macro */
    CharLCD_1_DisplayOff();
    CharLCD_1_enableState = 0u;
}


/*******************************************************************************
*  Function Name: CharLCD_1_Position
********************************************************************************
*
* Summary:
*  Moves active cursor location to a point specified by the input arguments
*
* Parameters:
*  row:     Specific row of LCD module to be written
*  column:  Column of LCD module to be written
*
* Return:
*  None.
*
* Note:
*  This only applies for LCD displays which use the 2X40 address mode.
*  This results in Row 2 offset from row one by 0x28.
*  When there are more than 2 rows, each row must be fewer than 20 characters.
*
*******************************************************************************/
void CharLCD_1_Position(uint8 row, uint8 column) 
{
    switch (row)
    {
        case (uint8)0:
            CharLCD_1_WriteControl(CharLCD_1_ROW_0_START + column);
            break;
        case (uint8) 1:
            CharLCD_1_WriteControl(CharLCD_1_ROW_1_START + column);
            break;
        case (uint8) 2:
            CharLCD_1_WriteControl(CharLCD_1_ROW_2_START + column);
            break;
        case (uint8) 3:
            CharLCD_1_WriteControl(CharLCD_1_ROW_3_START + column);
            break;
        default:
            /* if default case is hit, invalid row argument was passed.*/
            break;
    }
}


/*******************************************************************************
* Function Name: CharLCD_1_PrintString
********************************************************************************
*
* Summary:
*  Writes a zero terminated string to the LCD.
*
* Parameters:
*  string:  pointer to head of char8 array to be written to the LCD module
*
* Return:
*  None.
*
*******************************************************************************/
void CharLCD_1_PrintString(char8 const string[]) 
{
    uint8 indexU8 = 1u;
    char8 current = *string;

    /* Until null is reached, print next character */
    while((char8) '\0' != current)
    {
        CharLCD_1_WriteData((uint8)current);
        current = string[indexU8];
        indexU8++;
    }
}


/*******************************************************************************
*  Function Name: CharLCD_1_PutChar
********************************************************************************
*
* Summary:
*  Writes a single character to the current cursor position of the LCD module.
*  Custom character names (_CUSTOM_0 through
*  _CUSTOM_7) are acceptable as inputs.
*
* Parameters:
*  character:  character to be written to the LCD
*
* Return:
*  None.
*
*******************************************************************************/
void CharLCD_1_PutChar(char8 character) 
{
    CharLCD_1_WriteData((uint8)character);
}


/*******************************************************************************
*  Function Name: CharLCD_1_WriteData
********************************************************************************
*
* Summary:
*   Writes a DATA Command to the LCD by sending the Upper Nibble and
*   the Lower Nibble twice, once with the E input High and once with the 
*	E input Low with the the RS input held High and the RW input held Low 
*	while the K input or Back Light (BL) input is held High.
*
*******************************************************************************/	

void CharLCD_1_WriteData(uint8 dByte) 

{
    uint8 buffer[CharLCD_1_BUFFER_SIZE], UPPER_NIB, LOWER_NIB;
	uint8 BLH_EH_RWL_RSH, BLH_EL_RWL_RSH;
	
	UPPER_NIB = dByte & CharLCD_1_UPPER_NIB_MASK;
   	LOWER_NIB = (dByte & CharLCD_1_LOWER_NIB_MASK) << CharLCD_1_LOWER_NIB_SHIFT;
	
	BLH_EH_RWL_RSH = CharLCD_1_BLH + CharLCD_1_EH + CharLCD_1_RSH;
	BLH_EL_RWL_RSH = CharLCD_1_BLH + CharLCD_1_RSH;
	
	/* Initialize buffer with packet */
   
	buffer[CharLCD_1_PACKET_0_POS] = UPPER_NIB | BLH_EH_RWL_RSH;
    buffer[CharLCD_1_PACKET_1_POS] = UPPER_NIB | BLH_EL_RWL_RSH;
    buffer[CharLCD_1_PACKET_2_POS] = LOWER_NIB | BLH_EH_RWL_RSH;
    buffer[CharLCD_1_PACKET_3_POS] = LOWER_NIB | BLH_EL_RWL_RSH;
    
#if(CY_PSOC4)
	
	(void) I2C_CharLCD_1_I2CMasterWriteBuf(CharLCD_1_I2C_SLAVE_ADDR, buffer, CharLCD_1_PACKET_SIZE, \
                                  I2C_CharLCD_1_I2C_MODE_COMPLETE_XFER);

#else    
   	
	(void) I2C_CharLCD_1_MasterWriteBuf(CharLCD_1_I2C_SLAVE_ADDR, buffer, CharLCD_1_PACKET_SIZE, \
                                  I2C_CharLCD_1_MODE_COMPLETE_XFER);

#endif /*PSOC4*/ 

	CyDelayUs(CharLCD_1_DATA_DELAY_US);
}

/*******************************************************************************
*  Function Name: CharLCD_1_WriteControl
********************************************************************************
*
* Summary:
*   Writes a CONTROL Command to the LCD by sending the Upper Nibble and
*   the Lower Nibble twice, once with the E input High and once with the 
*	E input Low with the the RS and the RW input held Low while the
*	K input or Back Light (BL) input is held High.
*
*******************************************************************************/	

void CharLCD_1_WriteControl(uint8 cByte) 
{
    uint8 buffer[CharLCD_1_BUFFER_SIZE], UPPER_NIB, LOWER_NIB;
	uint8 BLH_EH_RWL_RSL, BLH_EL_RWL_RSL;
	
	UPPER_NIB = cByte & CharLCD_1_UPPER_NIB_MASK;
   	LOWER_NIB = (cByte & CharLCD_1_LOWER_NIB_MASK) << CharLCD_1_LOWER_NIB_SHIFT;
	
	BLH_EH_RWL_RSL = CharLCD_1_BLH + CharLCD_1_EH;
	BLH_EL_RWL_RSL = CharLCD_1_BLH;
	
	/* Initialize buffer with packet */
   
	buffer[CharLCD_1_PACKET_0_POS] = UPPER_NIB | BLH_EH_RWL_RSL;
    buffer[CharLCD_1_PACKET_1_POS] = UPPER_NIB | BLH_EL_RWL_RSL;
    buffer[CharLCD_1_PACKET_2_POS] = LOWER_NIB | BLH_EH_RWL_RSL;
    buffer[CharLCD_1_PACKET_3_POS] = LOWER_NIB | BLH_EL_RWL_RSL;
     
#if(CY_PSOC4)
	
	(void) I2C_CharLCD_1_I2CMasterWriteBuf(CharLCD_1_I2C_SLAVE_ADDR, buffer, CharLCD_1_PACKET_SIZE, \
                                  I2C_CharLCD_1_I2C_MODE_COMPLETE_XFER);
#else    
   	
	(void) I2C_CharLCD_1_MasterWriteBuf(CharLCD_1_I2C_SLAVE_ADDR, buffer, CharLCD_1_PACKET_SIZE, \
                                  I2C_CharLCD_1_MODE_COMPLETE_XFER);

#endif /*PSOC4*/ 

	CyDelayUs(CharLCD_1_CMD_DELAY_US);
}

/*******************************************************************************
*  Function Name: CharLCD_1_WrtCntrlUpNib
********************************************************************************
*
* Summary:
*   Writes a CONTROL Command to the LCD by sending only the UPPER NIBBLE twice,
*	once with the E input High and once with the E input Low with the RS input 
*	and RW input held Low while the K input or Back Light (BL) input is held High.
*
*******************************************************************************/
void CharLCD_1_WrtCntrlUpNib(uint8 cByte) 
{
    uint8 buffer[CharLCD_1_UPPER_NIB_BUFFER_SIZE], UPPER_NIB;
	uint8 BLH_EH_RWL_RSL, BLH_EL_RWL_RSL;
	
	UPPER_NIB = cByte & CharLCD_1_UPPER_NIB_MASK;
	
	BLH_EH_RWL_RSL = CharLCD_1_BLH + CharLCD_1_EH;
	BLH_EL_RWL_RSL = CharLCD_1_BLH;
	
	/* Initialize buffer with packet */
   
	buffer[CharLCD_1_PACKET_0_POS] = UPPER_NIB | BLH_EH_RWL_RSL;
    buffer[CharLCD_1_PACKET_1_POS] = UPPER_NIB | BLH_EL_RWL_RSL;
     
#if(CY_PSOC4)
	
	(void) I2C_CharLCD_1_I2CMasterWriteBuf(CharLCD_1_I2C_SLAVE_ADDR, buffer, CharLCD_1_UPPER_NIB_PACKET_SIZE, \
                                  I2C_CharLCD_1_I2C_MODE_COMPLETE_XFER);
	
#else    
   	
	(void) I2C_CharLCD_1_MasterWriteBuf(CharLCD_1_I2C_SLAVE_ADDR, buffer, CharLCD_1_UPPER_NIB_PACKET_SIZE, \
                                  I2C_CharLCD_1_MODE_COMPLETE_XFER);

#endif /*PSOC4*/ 
	
	CyDelayUs(CharLCD_1_CMD_DELAY_US);

}
/*******************************************************************************
* Function Name: CharLCD_1_IsReady
********************************************************************************
*
* Summary:
*  Polls LCD until the ready bit is set.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  Changes pins to High-Z.
*
*******************************************************************************/
void CharLCD_1_IsReady(void) 
{
   
	CyDelay(1u);
	
}

#if(CharLCD_1_CONVERSION_ROUTINES == 1u)

    /*******************************************************************************
    *  Function Name: CharLCD_1_PrintInt8
    ********************************************************************************
    *
    * Summary:
    *  Print a byte as two ASCII characters.
    *
    * Parameters:
    *  value:  The byte to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void CharLCD_1_PrintInt8(uint8 value) 
    {
        static char8 const CYCODE CharLCD_1_hex[16u] = "0123456789ABCDEF";
        
        CharLCD_1_PutChar((char8) CharLCD_1_hex[value >> CharLCD_1_BYTE_UPPER_NIBBLE_SHIFT]);
        CharLCD_1_PutChar((char8) CharLCD_1_hex[value & CharLCD_1_BYTE_LOWER_NIBBLE_MASK]);
    }


    /*******************************************************************************
    *  Function Name: CharLCD_1_PrintInt16
    ********************************************************************************
    *
    * Summary:
    *  Print a uint16 as four ASCII characters.
    *
    * Parameters:
    *  value:   The uint16 to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void CharLCD_1_PrintInt16(uint16 value) 
    {
        CharLCD_1_PrintInt8((uint8)(value >> CharLCD_1_U16_UPPER_BYTE_SHIFT));
        CharLCD_1_PrintInt8((uint8)(value & CharLCD_1_U16_LOWER_BYTE_MASK));
    }


    /*******************************************************************************
    *  Function Name: CharLCD_1_PrintNumber
    ********************************************************************************
    *
    * Summary:
    *  Print an uint32 value as a left-justified decimal value.
    *
    * Parameters:
    *  value:  The byte to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void CharLCD_1_PrintNumber(uint16 value) 
    {

        char8 number[CharLCD_1_NUMBER_OF_REMAINDERS];
        char8 temp[CharLCD_1_NUMBER_OF_REMAINDERS];

        uint8 digIndex = 0u;
        uint8 numDigits;

        /* Load these in reverse order */
        while(value >= CharLCD_1_TEN)
        {
            temp[digIndex] = (value % CharLCD_1_TEN) + '0';
            value /= CharLCD_1_TEN;
            digIndex++;
        }

        temp[digIndex] = (value % CharLCD_1_TEN) + '0';
        numDigits = digIndex;

        /* While index is greater than or equal to zero copy number
        * from temporary array to number[].
        */
        while (digIndex != 0u)
        {
            number[numDigits - digIndex] = temp[digIndex];
            digIndex--;
        }
        
        /* Copy last digit */
        number[numDigits] = temp[0u];

        /* Null Termination */
        number[numDigits + 1u] = (char8) '\0';

        /* Print out number */
        CharLCD_1_PrintString(&number[0u]);
    }

#endif /* CharLCD_1_CONVERSION_ROUTINES == 1u */


/* [] END OF FILE */
