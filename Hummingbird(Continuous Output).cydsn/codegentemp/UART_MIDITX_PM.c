/*******************************************************************************
* File Name: UART_MIDITX_PM.c
* Version 2.50
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UART_MIDITX.h"


/***************************************
* Local data allocation
***************************************/

static UART_MIDITX_BACKUP_STRUCT  UART_MIDITX_backup =
{
    /* enableState - disabled */
    0u,
};



/*******************************************************************************
* Function Name: UART_MIDITX_SaveConfig
********************************************************************************
*
* Summary:
*  This function saves the component nonretention control register.
*  Does not save the FIFO which is a set of nonretention registers.
*  This function is called by the UART_MIDITX_Sleep() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  UART_MIDITX_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UART_MIDITX_SaveConfig(void)
{
    #if(UART_MIDITX_CONTROL_REG_REMOVED == 0u)
        UART_MIDITX_backup.cr = UART_MIDITX_CONTROL_REG;
    #endif /* End UART_MIDITX_CONTROL_REG_REMOVED */
}


/*******************************************************************************
* Function Name: UART_MIDITX_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the nonretention control register except FIFO.
*  Does not restore the FIFO which is a set of nonretention registers.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  UART_MIDITX_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
* Notes:
*  If this function is called without calling UART_MIDITX_SaveConfig() 
*  first, the data loaded may be incorrect.
*
*******************************************************************************/
void UART_MIDITX_RestoreConfig(void)
{
    #if(UART_MIDITX_CONTROL_REG_REMOVED == 0u)
        UART_MIDITX_CONTROL_REG = UART_MIDITX_backup.cr;
    #endif /* End UART_MIDITX_CONTROL_REG_REMOVED */
}


/*******************************************************************************
* Function Name: UART_MIDITX_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for sleep. 
*  The UART_MIDITX_Sleep() API saves the current component state. Then it
*  calls the UART_MIDITX_Stop() function and calls 
*  UART_MIDITX_SaveConfig() to save the hardware configuration.
*  Call the UART_MIDITX_Sleep() function before calling the CyPmSleep() 
*  or the CyPmHibernate() function. 
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  UART_MIDITX_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UART_MIDITX_Sleep(void)
{
    #if(UART_MIDITX_RX_ENABLED || UART_MIDITX_HD_ENABLED)
        if((UART_MIDITX_RXSTATUS_ACTL_REG  & UART_MIDITX_INT_ENABLE) != 0u)
        {
            UART_MIDITX_backup.enableState = 1u;
        }
        else
        {
            UART_MIDITX_backup.enableState = 0u;
        }
    #else
        if((UART_MIDITX_TXSTATUS_ACTL_REG  & UART_MIDITX_INT_ENABLE) !=0u)
        {
            UART_MIDITX_backup.enableState = 1u;
        }
        else
        {
            UART_MIDITX_backup.enableState = 0u;
        }
    #endif /* End UART_MIDITX_RX_ENABLED || UART_MIDITX_HD_ENABLED*/

    UART_MIDITX_Stop();
    UART_MIDITX_SaveConfig();
}


/*******************************************************************************
* Function Name: UART_MIDITX_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when 
*  UART_MIDITX_Sleep() was called. The UART_MIDITX_Wakeup() function
*  calls the UART_MIDITX_RestoreConfig() function to restore the 
*  configuration. If the component was enabled before the 
*  UART_MIDITX_Sleep() function was called, the UART_MIDITX_Wakeup()
*  function will also re-enable the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  UART_MIDITX_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UART_MIDITX_Wakeup(void)
{
    UART_MIDITX_RestoreConfig();
    #if( (UART_MIDITX_RX_ENABLED) || (UART_MIDITX_HD_ENABLED) )
        UART_MIDITX_ClearRxBuffer();
    #endif /* End (UART_MIDITX_RX_ENABLED) || (UART_MIDITX_HD_ENABLED) */
    #if(UART_MIDITX_TX_ENABLED || UART_MIDITX_HD_ENABLED)
        UART_MIDITX_ClearTxBuffer();
    #endif /* End UART_MIDITX_TX_ENABLED || UART_MIDITX_HD_ENABLED */

    if(UART_MIDITX_backup.enableState != 0u)
    {
        UART_MIDITX_Enable();
    }
}


/* [] END OF FILE */
