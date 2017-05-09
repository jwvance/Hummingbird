/*******************************************************************************
* File Name: LED_InB.h  
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

#if !defined(CY_PINS_LED_InB_H) /* Pins LED_InB_H */
#define CY_PINS_LED_InB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LED_InB_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED_InB_Write(uint8 value) ;
void    LED_InB_SetDriveMode(uint8 mode) ;
uint8   LED_InB_ReadDataReg(void) ;
uint8   LED_InB_Read(void) ;
uint8   LED_InB_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED_InB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LED_InB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LED_InB_DM_RES_UP          PIN_DM_RES_UP
#define LED_InB_DM_RES_DWN         PIN_DM_RES_DWN
#define LED_InB_DM_OD_LO           PIN_DM_OD_LO
#define LED_InB_DM_OD_HI           PIN_DM_OD_HI
#define LED_InB_DM_STRONG          PIN_DM_STRONG
#define LED_InB_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LED_InB_MASK               LED_InB__MASK
#define LED_InB_SHIFT              LED_InB__SHIFT
#define LED_InB_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED_InB_PS                     (* (reg8 *) LED_InB__PS)
/* Data Register */
#define LED_InB_DR                     (* (reg8 *) LED_InB__DR)
/* Port Number */
#define LED_InB_PRT_NUM                (* (reg8 *) LED_InB__PRT) 
/* Connect to Analog Globals */                                                  
#define LED_InB_AG                     (* (reg8 *) LED_InB__AG)                       
/* Analog MUX bux enable */
#define LED_InB_AMUX                   (* (reg8 *) LED_InB__AMUX) 
/* Bidirectional Enable */                                                        
#define LED_InB_BIE                    (* (reg8 *) LED_InB__BIE)
/* Bit-mask for Aliased Register Access */
#define LED_InB_BIT_MASK               (* (reg8 *) LED_InB__BIT_MASK)
/* Bypass Enable */
#define LED_InB_BYP                    (* (reg8 *) LED_InB__BYP)
/* Port wide control signals */                                                   
#define LED_InB_CTL                    (* (reg8 *) LED_InB__CTL)
/* Drive Modes */
#define LED_InB_DM0                    (* (reg8 *) LED_InB__DM0) 
#define LED_InB_DM1                    (* (reg8 *) LED_InB__DM1)
#define LED_InB_DM2                    (* (reg8 *) LED_InB__DM2) 
/* Input Buffer Disable Override */
#define LED_InB_INP_DIS                (* (reg8 *) LED_InB__INP_DIS)
/* LCD Common or Segment Drive */
#define LED_InB_LCD_COM_SEG            (* (reg8 *) LED_InB__LCD_COM_SEG)
/* Enable Segment LCD */
#define LED_InB_LCD_EN                 (* (reg8 *) LED_InB__LCD_EN)
/* Slew Rate Control */
#define LED_InB_SLW                    (* (reg8 *) LED_InB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LED_InB_PRTDSI__CAPS_SEL       (* (reg8 *) LED_InB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LED_InB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LED_InB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LED_InB_PRTDSI__OE_SEL0        (* (reg8 *) LED_InB__PRTDSI__OE_SEL0) 
#define LED_InB_PRTDSI__OE_SEL1        (* (reg8 *) LED_InB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LED_InB_PRTDSI__OUT_SEL0       (* (reg8 *) LED_InB__PRTDSI__OUT_SEL0) 
#define LED_InB_PRTDSI__OUT_SEL1       (* (reg8 *) LED_InB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LED_InB_PRTDSI__SYNC_OUT       (* (reg8 *) LED_InB__PRTDSI__SYNC_OUT) 


#if defined(LED_InB__INTSTAT)  /* Interrupt Registers */

    #define LED_InB_INTSTAT                (* (reg8 *) LED_InB__INTSTAT)
    #define LED_InB_SNAP                   (* (reg8 *) LED_InB__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins LED_InB_H */


/* [] END OF FILE */
