/*******************************************************************************
* File Name: UI_ADC_IRQ.h
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
#if !defined(CY_ISR_UI_ADC_IRQ_H)
#define CY_ISR_UI_ADC_IRQ_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void UI_ADC_IRQ_Start(void);
void UI_ADC_IRQ_StartEx(cyisraddress address);
void UI_ADC_IRQ_Stop(void);

CY_ISR_PROTO(UI_ADC_IRQ_Interrupt);

void UI_ADC_IRQ_SetVector(cyisraddress address);
cyisraddress UI_ADC_IRQ_GetVector(void);

void UI_ADC_IRQ_SetPriority(uint8 priority);
uint8 UI_ADC_IRQ_GetPriority(void);

void UI_ADC_IRQ_Enable(void);
uint8 UI_ADC_IRQ_GetState(void);
void UI_ADC_IRQ_Disable(void);

void UI_ADC_IRQ_SetPending(void);
void UI_ADC_IRQ_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the UI_ADC_IRQ ISR. */
#define UI_ADC_IRQ_INTC_VECTOR            ((reg32 *) UI_ADC_IRQ__INTC_VECT)

/* Address of the UI_ADC_IRQ ISR priority. */
#define UI_ADC_IRQ_INTC_PRIOR             ((reg8 *) UI_ADC_IRQ__INTC_PRIOR_REG)

/* Priority of the UI_ADC_IRQ interrupt. */
#define UI_ADC_IRQ_INTC_PRIOR_NUMBER      UI_ADC_IRQ__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable UI_ADC_IRQ interrupt. */
#define UI_ADC_IRQ_INTC_SET_EN            ((reg32 *) UI_ADC_IRQ__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the UI_ADC_IRQ interrupt. */
#define UI_ADC_IRQ_INTC_CLR_EN            ((reg32 *) UI_ADC_IRQ__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the UI_ADC_IRQ interrupt state to pending. */
#define UI_ADC_IRQ_INTC_SET_PD            ((reg32 *) UI_ADC_IRQ__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the UI_ADC_IRQ interrupt. */
#define UI_ADC_IRQ_INTC_CLR_PD            ((reg32 *) UI_ADC_IRQ__INTC_CLR_PD_REG)


#endif /* CY_ISR_UI_ADC_IRQ_H */


/* [] END OF FILE */
