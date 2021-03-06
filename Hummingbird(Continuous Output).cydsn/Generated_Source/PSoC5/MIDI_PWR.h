/*******************************************************************************
* File Name: MIDI_PWR.h  
* Version 2.5
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MIDI_PWR_H) /* Pins MIDI_PWR_H */
#define CY_PINS_MIDI_PWR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MIDI_PWR_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MIDI_PWR__PORT == 15 && ((MIDI_PWR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    MIDI_PWR_Write(uint8 value) ;
void    MIDI_PWR_SetDriveMode(uint8 mode) ;
uint8   MIDI_PWR_ReadDataReg(void) ;
uint8   MIDI_PWR_Read(void) ;
uint8   MIDI_PWR_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MIDI_PWR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MIDI_PWR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MIDI_PWR_DM_RES_UP          PIN_DM_RES_UP
#define MIDI_PWR_DM_RES_DWN         PIN_DM_RES_DWN
#define MIDI_PWR_DM_OD_LO           PIN_DM_OD_LO
#define MIDI_PWR_DM_OD_HI           PIN_DM_OD_HI
#define MIDI_PWR_DM_STRONG          PIN_DM_STRONG
#define MIDI_PWR_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MIDI_PWR_MASK               MIDI_PWR__MASK
#define MIDI_PWR_SHIFT              MIDI_PWR__SHIFT
#define MIDI_PWR_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MIDI_PWR_PS                     (* (reg8 *) MIDI_PWR__PS)
/* Data Register */
#define MIDI_PWR_DR                     (* (reg8 *) MIDI_PWR__DR)
/* Port Number */
#define MIDI_PWR_PRT_NUM                (* (reg8 *) MIDI_PWR__PRT) 
/* Connect to Analog Globals */                                                  
#define MIDI_PWR_AG                     (* (reg8 *) MIDI_PWR__AG)                       
/* Analog MUX bux enable */
#define MIDI_PWR_AMUX                   (* (reg8 *) MIDI_PWR__AMUX) 
/* Bidirectional Enable */                                                        
#define MIDI_PWR_BIE                    (* (reg8 *) MIDI_PWR__BIE)
/* Bit-mask for Aliased Register Access */
#define MIDI_PWR_BIT_MASK               (* (reg8 *) MIDI_PWR__BIT_MASK)
/* Bypass Enable */
#define MIDI_PWR_BYP                    (* (reg8 *) MIDI_PWR__BYP)
/* Port wide control signals */                                                   
#define MIDI_PWR_CTL                    (* (reg8 *) MIDI_PWR__CTL)
/* Drive Modes */
#define MIDI_PWR_DM0                    (* (reg8 *) MIDI_PWR__DM0) 
#define MIDI_PWR_DM1                    (* (reg8 *) MIDI_PWR__DM1)
#define MIDI_PWR_DM2                    (* (reg8 *) MIDI_PWR__DM2) 
/* Input Buffer Disable Override */
#define MIDI_PWR_INP_DIS                (* (reg8 *) MIDI_PWR__INP_DIS)
/* LCD Common or Segment Drive */
#define MIDI_PWR_LCD_COM_SEG            (* (reg8 *) MIDI_PWR__LCD_COM_SEG)
/* Enable Segment LCD */
#define MIDI_PWR_LCD_EN                 (* (reg8 *) MIDI_PWR__LCD_EN)
/* Slew Rate Control */
#define MIDI_PWR_SLW                    (* (reg8 *) MIDI_PWR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MIDI_PWR_PRTDSI__CAPS_SEL       (* (reg8 *) MIDI_PWR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MIDI_PWR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MIDI_PWR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MIDI_PWR_PRTDSI__OE_SEL0        (* (reg8 *) MIDI_PWR__PRTDSI__OE_SEL0) 
#define MIDI_PWR_PRTDSI__OE_SEL1        (* (reg8 *) MIDI_PWR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MIDI_PWR_PRTDSI__OUT_SEL0       (* (reg8 *) MIDI_PWR__PRTDSI__OUT_SEL0) 
#define MIDI_PWR_PRTDSI__OUT_SEL1       (* (reg8 *) MIDI_PWR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MIDI_PWR_PRTDSI__SYNC_OUT       (* (reg8 *) MIDI_PWR__PRTDSI__SYNC_OUT) 


#if defined(MIDI_PWR__INTSTAT)  /* Interrupt Registers */

    #define MIDI_PWR_INTSTAT                (* (reg8 *) MIDI_PWR__INTSTAT)
    #define MIDI_PWR_SNAP                   (* (reg8 *) MIDI_PWR__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MIDI_PWR_H */


/* [] END OF FILE */
