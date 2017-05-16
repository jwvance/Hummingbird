/*******************************************************************************
* File Name: TIMER_TUNER_PM.c
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

#include "TIMER_TUNER.h"

static TIMER_TUNER_backupStruct TIMER_TUNER_backup;


/*******************************************************************************
* Function Name: TIMER_TUNER_SaveConfig
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
*  TIMER_TUNER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void TIMER_TUNER_SaveConfig(void) 
{
    #if (!TIMER_TUNER_UsingFixedFunction)
        TIMER_TUNER_backup.TimerUdb = TIMER_TUNER_ReadCounter();
        TIMER_TUNER_backup.InterruptMaskValue = TIMER_TUNER_STATUS_MASK;
        #if (TIMER_TUNER_UsingHWCaptureCounter)
            TIMER_TUNER_backup.TimerCaptureCounter = TIMER_TUNER_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!TIMER_TUNER_UDB_CONTROL_REG_REMOVED)
            TIMER_TUNER_backup.TimerControlRegister = TIMER_TUNER_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: TIMER_TUNER_RestoreConfig
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
*  TIMER_TUNER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void TIMER_TUNER_RestoreConfig(void) 
{   
    #if (!TIMER_TUNER_UsingFixedFunction)

        TIMER_TUNER_WriteCounter(TIMER_TUNER_backup.TimerUdb);
        TIMER_TUNER_STATUS_MASK =TIMER_TUNER_backup.InterruptMaskValue;
        #if (TIMER_TUNER_UsingHWCaptureCounter)
            TIMER_TUNER_SetCaptureCount(TIMER_TUNER_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!TIMER_TUNER_UDB_CONTROL_REG_REMOVED)
            TIMER_TUNER_WriteControlRegister(TIMER_TUNER_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: TIMER_TUNER_Sleep
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
*  TIMER_TUNER_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void TIMER_TUNER_Sleep(void) 
{
    #if(!TIMER_TUNER_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(TIMER_TUNER_CTRL_ENABLE == (TIMER_TUNER_CONTROL & TIMER_TUNER_CTRL_ENABLE))
        {
            /* Timer is enabled */
            TIMER_TUNER_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            TIMER_TUNER_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    TIMER_TUNER_Stop();
    TIMER_TUNER_SaveConfig();
}


/*******************************************************************************
* Function Name: TIMER_TUNER_Wakeup
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
*  TIMER_TUNER_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void TIMER_TUNER_Wakeup(void) 
{
    TIMER_TUNER_RestoreConfig();
    #if(!TIMER_TUNER_UDB_CONTROL_REG_REMOVED)
        if(TIMER_TUNER_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                TIMER_TUNER_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
