/*******************************************************************************
* File Name: TIMER_SAMPLERATE_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "TIMER_SAMPLERATE.h"

static TIMER_SAMPLERATE_backupStruct TIMER_SAMPLERATE_backup;


/*******************************************************************************
* Function Name: TIMER_SAMPLERATE_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TIMER_SAMPLERATE_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void TIMER_SAMPLERATE_SaveConfig(void) 
{
    #if (!TIMER_SAMPLERATE_UsingFixedFunction)
        TIMER_SAMPLERATE_backup.TimerUdb = TIMER_SAMPLERATE_ReadCounter();
        TIMER_SAMPLERATE_backup.InterruptMaskValue = TIMER_SAMPLERATE_STATUS_MASK;
        #if (TIMER_SAMPLERATE_UsingHWCaptureCounter)
            TIMER_SAMPLERATE_backup.TimerCaptureCounter = TIMER_SAMPLERATE_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!TIMER_SAMPLERATE_UDB_CONTROL_REG_REMOVED)
            TIMER_SAMPLERATE_backup.TimerControlRegister = TIMER_SAMPLERATE_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: TIMER_SAMPLERATE_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TIMER_SAMPLERATE_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void TIMER_SAMPLERATE_RestoreConfig(void) 
{   
    #if (!TIMER_SAMPLERATE_UsingFixedFunction)

        TIMER_SAMPLERATE_WriteCounter(TIMER_SAMPLERATE_backup.TimerUdb);
        TIMER_SAMPLERATE_STATUS_MASK =TIMER_SAMPLERATE_backup.InterruptMaskValue;
        #if (TIMER_SAMPLERATE_UsingHWCaptureCounter)
            TIMER_SAMPLERATE_SetCaptureCount(TIMER_SAMPLERATE_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!TIMER_SAMPLERATE_UDB_CONTROL_REG_REMOVED)
            TIMER_SAMPLERATE_WriteControlRegister(TIMER_SAMPLERATE_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: TIMER_SAMPLERATE_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TIMER_SAMPLERATE_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void TIMER_SAMPLERATE_Sleep(void) 
{
    #if(!TIMER_SAMPLERATE_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(TIMER_SAMPLERATE_CTRL_ENABLE == (TIMER_SAMPLERATE_CONTROL & TIMER_SAMPLERATE_CTRL_ENABLE))
        {
            /* Timer is enabled */
            TIMER_SAMPLERATE_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            TIMER_SAMPLERATE_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    TIMER_SAMPLERATE_Stop();
    TIMER_SAMPLERATE_SaveConfig();
}


/*******************************************************************************
* Function Name: TIMER_SAMPLERATE_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TIMER_SAMPLERATE_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void TIMER_SAMPLERATE_Wakeup(void) 
{
    TIMER_SAMPLERATE_RestoreConfig();
    #if(!TIMER_SAMPLERATE_UDB_CONTROL_REG_REMOVED)
        if(TIMER_SAMPLERATE_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                TIMER_SAMPLERATE_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
