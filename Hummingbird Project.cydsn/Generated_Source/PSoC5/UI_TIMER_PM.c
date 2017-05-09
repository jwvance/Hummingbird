/*******************************************************************************
* File Name: UI_TIMER_PM.c
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

#include "UI_TIMER.h"

static UI_TIMER_backupStruct UI_TIMER_backup;


/*******************************************************************************
* Function Name: UI_TIMER_SaveConfig
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
*  UI_TIMER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void UI_TIMER_SaveConfig(void) 
{
    #if (!UI_TIMER_UsingFixedFunction)
        UI_TIMER_backup.TimerUdb = UI_TIMER_ReadCounter();
        UI_TIMER_backup.InterruptMaskValue = UI_TIMER_STATUS_MASK;
        #if (UI_TIMER_UsingHWCaptureCounter)
            UI_TIMER_backup.TimerCaptureCounter = UI_TIMER_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!UI_TIMER_UDB_CONTROL_REG_REMOVED)
            UI_TIMER_backup.TimerControlRegister = UI_TIMER_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: UI_TIMER_RestoreConfig
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
*  UI_TIMER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void UI_TIMER_RestoreConfig(void) 
{   
    #if (!UI_TIMER_UsingFixedFunction)

        UI_TIMER_WriteCounter(UI_TIMER_backup.TimerUdb);
        UI_TIMER_STATUS_MASK =UI_TIMER_backup.InterruptMaskValue;
        #if (UI_TIMER_UsingHWCaptureCounter)
            UI_TIMER_SetCaptureCount(UI_TIMER_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!UI_TIMER_UDB_CONTROL_REG_REMOVED)
            UI_TIMER_WriteControlRegister(UI_TIMER_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: UI_TIMER_Sleep
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
*  UI_TIMER_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void UI_TIMER_Sleep(void) 
{
    #if(!UI_TIMER_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(UI_TIMER_CTRL_ENABLE == (UI_TIMER_CONTROL & UI_TIMER_CTRL_ENABLE))
        {
            /* Timer is enabled */
            UI_TIMER_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            UI_TIMER_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    UI_TIMER_Stop();
    UI_TIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: UI_TIMER_Wakeup
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
*  UI_TIMER_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void UI_TIMER_Wakeup(void) 
{
    UI_TIMER_RestoreConfig();
    #if(!UI_TIMER_UDB_CONTROL_REG_REMOVED)
        if(UI_TIMER_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                UI_TIMER_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
