/*******************************************************************************
* File Name: LED_OutA.h  
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

#if !defined(CY_PINS_LED_OutA_H) /* Pins LED_OutA_H */
#define CY_PINS_LED_OutA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LED_OutA_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED_OutA_Write(uint8 value) CYREENTRANT;
void    LED_OutA_SetDriveMode(uint8 mode) ;
uint8   LED_OutA_ReadDataReg(void) ;
uint8   LED_OutA_Read(void) ;
uint8   LED_OutA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED_OutA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LED_OutA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LED_OutA_DM_RES_UP          PIN_DM_RES_UP
#define LED_OutA_DM_RES_DWN         PIN_DM_RES_DWN
#define LED_OutA_DM_OD_LO           PIN_DM_OD_LO
#define LED_OutA_DM_OD_HI           PIN_DM_OD_HI
#define LED_OutA_DM_STRONG          PIN_DM_STRONG
#define LED_OutA_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LED_OutA_MASK               LED_OutA__MASK
#define LED_OutA_SHIFT              LED_OutA__SHIFT
#define LED_OutA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED_OutA_PS                     (* (reg8 *) LED_OutA__PS)
/* Data Register */
#define LED_OutA_DR                     (* (reg8 *) LED_OutA__DR)
/* Port Number */
#define LED_OutA_PRT_NUM                (* (reg8 *) LED_OutA__PRT) 
/* Connect to Analog Globals */                                                  
#define LED_OutA_AG                     (* (reg8 *) LED_OutA__AG)                       
/* Analog MUX bux enable */
#define LED_OutA_AMUX                   (* (reg8 *) LED_OutA__AMUX) 
/* Bidirectional Enable */                                                        
#define LED_OutA_BIE                    (* (reg8 *) LED_OutA__BIE)
/* Bit-mask for Aliased Register Access */
#define LED_OutA_BIT_MASK               (* (reg8 *) LED_OutA__BIT_MASK)
/* Bypass Enable */
#define LED_OutA_BYP                    (* (reg8 *) LED_OutA__BYP)
/* Port wide control signals */                                                   
#define LED_OutA_CTL                    (* (reg8 *) LED_OutA__CTL)
/* Drive Modes */
#define LED_OutA_DM0                    (* (reg8 *) LED_OutA__DM0) 
#define LED_OutA_DM1                    (* (reg8 *) LED_OutA__DM1)
#define LED_OutA_DM2                    (* (reg8 *) LED_OutA__DM2) 
/* Input Buffer Disable Override */
#define LED_OutA_INP_DIS                (* (reg8 *) LED_OutA__INP_DIS)
/* LCD Common or Segment Drive */
#define LED_OutA_LCD_COM_SEG            (* (reg8 *) LED_OutA__LCD_COM_SEG)
/* Enable Segment LCD */
#define LED_OutA_LCD_EN                 (* (reg8 *) LED_OutA__LCD_EN)
/* Slew Rate Control */
#define LED_OutA_SLW                    (* (reg8 *) LED_OutA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LED_OutA_PRTDSI__CAPS_SEL       (* (reg8 *) LED_OutA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LED_OutA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LED_OutA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LED_OutA_PRTDSI__OE_SEL0        (* (reg8 *) LED_OutA__PRTDSI__OE_SEL0) 
#define LED_OutA_PRTDSI__OE_SEL1        (* (reg8 *) LED_OutA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LED_OutA_PRTDSI__OUT_SEL0       (* (reg8 *) LED_OutA__PRTDSI__OUT_SEL0) 
#define LED_OutA_PRTDSI__OUT_SEL1       (* (reg8 *) LED_OutA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LED_OutA_PRTDSI__SYNC_OUT       (* (reg8 *) LED_OutA__PRTDSI__SYNC_OUT) 


#if defined(LED_OutA__INTSTAT)  /* Interrupt Registers */

    #define LED_OutA_INTSTAT                (* (reg8 *) LED_OutA__INTSTAT)
    #define LED_OutA_SNAP                   (* (reg8 *) LED_OutA__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins LED_OutA_H */


/* [] END OF FILE */
