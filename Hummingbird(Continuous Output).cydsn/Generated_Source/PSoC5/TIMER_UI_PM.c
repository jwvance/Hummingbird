/*******************************************************************************
* File Name: TIMER_UI_PM.c
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

#include "TIMER_UI.h"

static TIMER_UI_backupStruct TIMER_UI_backup;


/*******************************************************************************
* Function Name: TIMER_UI_SaveConfig
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
*  TIMER_UI_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void TIMER_UI_SaveConfig(void) 
{
    #if (!TIMER_UI_UsingFixedFunction)
        TIMER_UI_backup.TimerUdb = TIMER_UI_ReadCounter();
        TIMER_UI_backup.InterruptMaskValue = TIMER_UI_STATUS_MASK;
        #if (TIMER_UI_UsingHWCaptureCounter)
            TIMER_UI_backup.TimerCaptureCounter = TIMER_UI_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!TIMER_UI_UDB_CONTROL_REG_REMOVED)
            TIMER_UI_backup.TimerControlRegister = TIMER_UI_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: TIMER_UI_RestoreConfig
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
*  TIMER_UI_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void TIMER_UI_RestoreConfig(void) 
{   
    #if (!TIMER_UI_UsingFixedFunction)

        TIMER_UI_WriteCounter(TIMER_UI_backup.TimerUdb);
        TIMER_UI_STATUS_MASK =TIMER_UI_backup.InterruptMaskValue;
        #if (TIMER_UI_UsingHWCaptureCounter)
            TIMER_UI_SetCaptureCount(TIMER_UI_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!TIMER_UI_UDB_CONTROL_REG_REMOVED)
            TIMER_UI_WriteControlRegister(TIMER_UI_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: TIMER_UI_Sleep
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
*  TIMER_UI_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void TIMER_UI_Sleep(void) 
{
    #if(!TIMER_UI_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(TIMER_UI_CTRL_ENABLE == (TIMER_UI_CONTROL & TIMER_UI_CTRL_ENABLE))
        {
            /* Timer is enabled */
            TIMER_UI_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            TIMER_UI_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    TIMER_UI_Stop();
    TIMER_UI_SaveConfig();
}


/*******************************************************************************
* Function Name: TIMER_UI_Wakeup
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
*  TIMER_UI_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void TIMER_UI_Wakeup(void) 
{
    TIMER_UI_RestoreConfig();
    #if(!TIMER_UI_UDB_CONTROL_REG_REMOVED)
        if(TIMER_UI_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                TIMER_UI_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
