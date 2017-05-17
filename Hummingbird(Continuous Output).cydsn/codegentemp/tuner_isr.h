/*******************************************************************************
* File Name: tuner_isr.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_tuner_isr_H)
#define CY_ISR_tuner_isr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void tuner_isr_Start(void);
void tuner_isr_StartEx(cyisraddress address);
void tuner_isr_Stop(void);

CY_ISR_PROTO(tuner_isr_Interrupt);

void tuner_isr_SetVector(cyisraddress address);
cyisraddress tuner_isr_GetVector(void);

void tuner_isr_SetPriority(uint8 priority);
uint8 tuner_isr_GetPriority(void);

void tuner_isr_Enable(void);
uint8 tuner_isr_GetState(void);
void tuner_isr_Disable(void);

void tuner_isr_SetPending(void);
void tuner_isr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the tuner_isr ISR. */
#define tuner_isr_INTC_VECTOR            ((reg32 *) tuner_isr__INTC_VECT)

/* Address of the tuner_isr ISR priority. */
#define tuner_isr_INTC_PRIOR             ((reg8 *) tuner_isr__INTC_PRIOR_REG)

/* Priority of the tuner_isr interrupt. */
#define tuner_isr_INTC_PRIOR_NUMBER      tuner_isr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable tuner_isr interrupt. */
#define tuner_isr_INTC_SET_EN            ((reg32 *) tuner_isr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the tuner_isr interrupt. */
#define tuner_isr_INTC_CLR_EN            ((reg32 *) tuner_isr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the tuner_isr interrupt state to pending. */
#define tuner_isr_INTC_SET_PD            ((reg32 *) tuner_isr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the tuner_isr interrupt. */
#define tuner_isr_INTC_CLR_PD            ((reg32 *) tuner_isr__INTC_CLR_PD_REG)


#endif /* CY_ISR_tuner_isr_H */


/* [] END OF FILE */
