/*******************************************************************************
* File Name: UI_ADC_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UI_ADC.h"
#include "UI_ADC_SAR.h"
#if(UI_ADC_CLOCK_SOURCE == UI_ADC_CLOCK_INTERNAL)
    #include "UI_ADC_IntClock.h"
#endif   /* UI_ADC_CLOCK_SOURCE == UI_ADC_CLOCK_INTERNAL */


/*******************************************************************************
* Function Name: UI_ADC_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UI_ADC_Sleep(void)
{
    UI_ADC_SAR_Stop();
    UI_ADC_SAR_Sleep();
    UI_ADC_Disable();

    #if(UI_ADC_CLOCK_SOURCE == UI_ADC_CLOCK_INTERNAL)
        UI_ADC_IntClock_Stop();
    #endif   /* UI_ADC_CLOCK_SOURCE == UI_ADC_CLOCK_INTERNAL */
}


/*******************************************************************************
* Function Name: UI_ADC_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers. This should
*  be called just after awaking from sleep mode
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UI_ADC_Wakeup(void)
{
    UI_ADC_SAR_Wakeup();
    UI_ADC_SAR_Enable();

    #if(UI_ADC_CLOCK_SOURCE == UI_ADC_CLOCK_INTERNAL)
        UI_ADC_IntClock_Start();
    #endif   /* UI_ADC_CLOCK_SOURCE == UI_ADC_CLOCK_INTERNAL */

    /* The block is ready to use 10 us after the SAR enable signal is set high. */
    CyDelayUs(10u);
    
    UI_ADC_Enable();

    #if(UI_ADC_SAMPLE_MODE == UI_ADC_SAMPLE_MODE_FREE_RUNNING)
        UI_ADC_SAR_StartConvert();
    #endif /* (UI_ADC_SAMPLE_MODE == UI_ADC_SAMPLE_MODE_FREE_RUNNING) */

    (void) CY_GET_REG8(UI_ADC_STATUS_PTR);
}


/*******************************************************************************
* Function Name: UI_ADC_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UI_ADC_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: UI_ADC_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UI_ADC_RestoreConfig(void)
{

}


/* [] END OF FILE */
