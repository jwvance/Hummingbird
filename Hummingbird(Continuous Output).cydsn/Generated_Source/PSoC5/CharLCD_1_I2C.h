/*******************************************************************************
* File Name: CharLCD_1_I2C.h
* Version 2.0
*
* Description:
*  This header file contains registers and constants associated with the
* CharLCD_I2C component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CHARLCD_CharLCD_1_H)

#define CY_CHARLCD_CharLCD_1_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define CharLCD_1_CONVERSION_ROUTINES     (1u)
#define CharLCD_1_CUSTOM_CHAR_SET         (0u)

/* Custom character set types */
#define CharLCD_1_NONE                     (0u)    /* No Custom Fonts      */
#define CharLCD_1_HORIZONTAL_BG            (1u)    /* Horizontal Bar Graph */
#define CharLCD_1_VERTICAL_BG              (2u)    /* Vertical Bar Graph   */
#define CharLCD_1_USER_DEFINED             (3u)    /* User Defined Fonts   */


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} 
CharLCD_1_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void CharLCD_1_Init(void) ;
void CharLCD_1_Enable(void) ;
void CharLCD_1_Start(void) ;
void CharLCD_1_Stop(void) ;
void CharLCD_1_WrtCntrlUpNib(uint8 cByte) ;
void CharLCD_1_WriteControl(uint8 cByte) ;
void CharLCD_1_WriteData(uint8 dByte) ;
void CharLCD_1_PrintString(char8 const string[]) ;
void CharLCD_1_Position(uint8 row, uint8 column) ;
void CharLCD_1_PutChar(char8 character) ;
void CharLCD_1_IsReady(void) ;
void CharLCD_1_SaveConfig(void) ;
void CharLCD_1_RestoreConfig(void) ;
void CharLCD_1_Sleep(void) ;
void CharLCD_1_Wakeup(void) ;

#define CharLCD_1_PosPrintString(row, col, string) CharLCD_1_Position(row, col); CharLCD_1_PrintString(string); 
#define CharLCD_1_PosPutChar(row, col, character) CharLCD_1_Position(row, col); CharLCD_1_PutChar(character); 

#if((CharLCD_1_CUSTOM_CHAR_SET == CharLCD_1_VERTICAL_BG) || \
                (CharLCD_1_CUSTOM_CHAR_SET == CharLCD_1_HORIZONTAL_BG))

    void  CharLCD_1_LoadCustomFonts(uint8 const customData[])
                        ;

    void  CharLCD_1_DrawHorizontalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                         ;

    void CharLCD_1_DrawVerticalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                        ;

#endif /* ((CharLCD_1_CUSTOM_CHAR_SET == CharLCD_1_VERTICAL_BG) */

#if(CharLCD_1_CUSTOM_CHAR_SET == CharLCD_1_USER_DEFINED)

    void CharLCD_1_LoadCustomFonts(uint8 const customData[])
                            ;

#endif /* ((CharLCD_1_CUSTOM_CHAR_SET == CharLCD_1_USER_DEFINED) */

#if(CharLCD_1_CONVERSION_ROUTINES == 1u)

    /* ASCII Conversion Routines */
    void CharLCD_1_PrintInt8(uint8 value) ;
    void CharLCD_1_PrintInt16(uint16 value) ;
    void CharLCD_1_PrintNumber(uint16 value) ; 
	
	#define CharLCD_1_PosPrintInt8(row, col, value) CharLCD_1_Position(row, col); CharLCD_1_PrintInt8(value); 
	#define CharLCD_1_PosPrintInt16(row, col, value) CharLCD_1_Position(row, col); CharLCD_1_PrintInt16(value);
	#define CharLCD_1_PosPrintNumber(row, col, value) CharLCD_1_Position(row, col); CharLCD_1_PrintNumber(value);

#endif /* CharLCD_1_CONVERSION_ROUTINES == 1u */

/* Clear Macro */
#define CharLCD_1_ClearDisplay() CharLCD_1_WriteControl(CharLCD_1_CLEAR_DISPLAY)

/* Off Macro */
#define CharLCD_1_DisplayOff() CharLCD_1_WriteControl(CharLCD_1_DISPLAY_CURSOR_OFF)

/* On Macro */
#define CharLCD_1_DisplayOn() CharLCD_1_WriteControl(CharLCD_1_DISPLAY_ON_CURSOR_OFF)


/***************************************
*           Global Variables
***************************************/

extern uint8 CharLCD_1_initVar;
extern uint8 CharLCD_1_enableState;
extern uint8 const CYCODE CharLCD_1_customFonts[64u];


/***************************************
*           API Constants
***************************************/

/* Full Byte Commands Sent as Two Nibbles */

/* 2 Lines 5x7 Characters 8 bit mode*/
#define CharLCD_1_DISPLAY_8_BIT_INIT       (0x38u)
/* 2 lines 5x7 Charcaters 4 bit mode*/
#define CharLCD_1_DISPLAY_4_BIT_INIT       (0x28u)

#define CharLCD_1_DISPLAY_CURSOR_OFF       (0x08u)
#define CharLCD_1_CLEAR_DISPLAY            (0x01u)
#define CharLCD_1_CURSOR_AUTO_INCR_ON      (0x06u)
#define CharLCD_1_DISPLAY_CURSOR_ON        (0x0Eu)
#define CharLCD_1_DISPLAY_ON_CURSOR_OFF    (0x0Cu)
#define CharLCD_1_DISPLAY_2_LINES_5x10     (0x2Cu)

#define CharLCD_1_RESET_CURSOR_POSITION    (0x03u)
#define CharLCD_1_CURSOR_WINK              (0x0Du)
#define CharLCD_1_CURSOR_BLINK             (0x0Fu)
#define CharLCD_1_CURSOR_SH_LEFT           (0x10u)
#define CharLCD_1_CURSOR_SH_RIGHT          (0x14u)
#define CharLCD_1_CURSOR_HOME              (0x02u)
#define CharLCD_1_CURSOR_LEFT              (0x04u)
#define CharLCD_1_CURSOR_RIGHT             (0x06u)

/* Point to Character Generator Ram 0 */
#define CharLCD_1_CGRAM_0                  (0x40u)

/* Point to Display Data Ram 0 */
#define CharLCD_1_DDRAM_0                  (0x80u)

/* LCD Characteristics */
#define CharLCD_1_CHARACTER_WIDTH          (0x05u)
#define CharLCD_1_CHARACTER_HEIGHT         (0x08u)

#if(CharLCD_1_CONVERSION_ROUTINES == 1u)
    #define CharLCD_1_NUMBER_OF_REMAINDERS (0x05u)
    #define CharLCD_1_TEN                  (0x0Au)
#endif /* CharLCD_1_CONVERSION_ROUTINES == 1u */

/* Nibble Offset and Mask */
#define CharLCD_1_NIBBLE_SHIFT             (0x04u)
#define CharLCD_1_NIBBLE_MASK              (0x0Fu)

/* LCD Module Address Constants */
#define CharLCD_1_ROW_0_START              (0x80u)
#define CharLCD_1_ROW_1_START              (0xC0u)
#define CharLCD_1_ROW_2_START              (0x94u)
#define CharLCD_1_ROW_3_START              (0xD4u)

/* Custom Character References */
#define CharLCD_1_CUSTOM_0                 (0x00u)
#define CharLCD_1_CUSTOM_1                 (0x01u)
#define CharLCD_1_CUSTOM_2                 (0x02u)
#define CharLCD_1_CUSTOM_3                 (0x03u)
#define CharLCD_1_CUSTOM_4                 (0x04u)
#define CharLCD_1_CUSTOM_5                 (0x05u)
#define CharLCD_1_CUSTOM_6                 (0x06u)
#define CharLCD_1_CUSTOM_7                 (0x07u)

/* Other constants */
#define CharLCD_1_BYTE_UPPER_NIBBLE_SHIFT  (0x04u)
#define CharLCD_1_BYTE_LOWER_NIBBLE_MASK   (0x0Fu)
#define CharLCD_1_U16_UPPER_BYTE_SHIFT     (0x08u)
#define CharLCD_1_U16_LOWER_BYTE_MASK      (0xFFu)
#define CharLCD_1_CUSTOM_CHAR_SET_LEN      (0x40u)

#define CharLCD_1_CMD_DELAY_US			 (2000u)/*  2.0 msec Delay  */
#define CharLCD_1_DATA_DELAY_US			 (500u) /*  0.50 msec Delay */
#define CharLCD_1_NIB_DELAY_US			 (100u) /*  0.10 msec Delay */
#define CharLCD_1_INIT_DELAY			  	 (20u)  /*  20.0 msec Delay */
#define CharLCD_1_INIT_UP_NIB_DELAY	  	 (5u)   /*  5.0 msec Delay  */
#define CharLCD_1_INIT_CMD_DELAY		  	 (5u)   /*  5.0 msec Delay  */

/**************************************
*             Registers               *
***************************************/
/* I2C 7 bit slave address for the PCF8574A A0=1,A1=1,A2=1*/

#define CharLCD_1_I2C_SLAVE_ADDR  		(0x3Fu)

/* Buffer and packet size */
#define CharLCD_1_UPPER_NIB_BUFFER_SIZE	(2u)
#define CharLCD_1_UPPER_NIB_PACKET_SIZE	(CharLCD_1_UPPER_NIB_BUFFER_SIZE)
#define CharLCD_1_BUFFER_SIZE     		(4u)
#define CharLCD_1_PACKET_SIZE     		(CharLCD_1_BUFFER_SIZE)

/* Packet positions */
#define CharLCD_1_PACKET_0_POS  (0u)
#define CharLCD_1_PACKET_1_POS  (1u)
#define CharLCD_1_PACKET_2_POS  (2u)
#define CharLCD_1_PACKET_3_POS  (3u)

/* Nibble Offset and Mask */

#define CharLCD_1_LOWER_NIB_SHIFT        (0x04u)
#define CharLCD_1_LOWER_NIB_MASK         (0x0Fu)
#define CharLCD_1_UPPER_NIB_MASK         (0xF0u)

/* I2C LOGIC CONSTANTS */

#define CharLCD_1_BLH				    (0x08u)/* Back Light On */
#define CharLCD_1_EH					(0x04u)/* E Input High */
#define CharLCD_1_RWH				    (0x02u)/* RW Input High */
#define CharLCD_1_RSH				    (0x01u)/* RS Input High */


/***************************************
*       Obsolete function names
***************************************/
#if(CharLCD_1_CONVERSION_ROUTINES == 1u)
    /* This function names are obsolete an they will be removed in future 
    * revisions of component.
    */
    #define CharLCD_1_PrintDecUint16(x)   CharLCD_1_PrintNumber(x)  
    #define CharLCD_1_PrintHexUint8(x)    CharLCD_1_PrintInt8(x)
    #define CharLCD_1_PrintHexUint16(x)   CharLCD_1_PrintInt16(x)        

#endif /* CharLCD_1_CONVERSION_ROUTINES == 1u */

#endif /* CY_CHARLCD_CharLCD_1_H */


/* [] END OF FILE */
