/*******************************************************************************
* File Name: MIDI1_UART_PM.c
* Version 2.30
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "MIDI1_UART.h"


/***************************************
* Local data allocation
***************************************/

static MIDI1_UART_BACKUP_STRUCT  MIDI1_UART_backup =
{
    /* enableState - disabled */
    0u,
};



/*******************************************************************************
* Function Name: MIDI1_UART_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  MIDI1_UART_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void MIDI1_UART_SaveConfig(void)
{
    #if (CY_UDB_V0)

        #if(MIDI1_UART_CONTROL_REG_REMOVED == 0u)
            MIDI1_UART_backup.cr = MIDI1_UART_CONTROL_REG;
        #endif /* End MIDI1_UART_CONTROL_REG_REMOVED */

        #if( (MIDI1_UART_RX_ENABLED) || (MIDI1_UART_HD_ENABLED) )
            MIDI1_UART_backup.rx_period = MIDI1_UART_RXBITCTR_PERIOD_REG;
            MIDI1_UART_backup.rx_mask = MIDI1_UART_RXSTATUS_MASK_REG;
            #if (MIDI1_UART_RXHW_ADDRESS_ENABLED)
                MIDI1_UART_backup.rx_addr1 = MIDI1_UART_RXADDRESS1_REG;
                MIDI1_UART_backup.rx_addr2 = MIDI1_UART_RXADDRESS2_REG;
            #endif /* End MIDI1_UART_RXHW_ADDRESS_ENABLED */
        #endif /* End MIDI1_UART_RX_ENABLED | MIDI1_UART_HD_ENABLED*/

        #if(MIDI1_UART_TX_ENABLED)
            #if(MIDI1_UART_TXCLKGEN_DP)
                MIDI1_UART_backup.tx_clk_ctr = MIDI1_UART_TXBITCLKGEN_CTR_REG;
                MIDI1_UART_backup.tx_clk_compl = MIDI1_UART_TXBITCLKTX_COMPLETE_REG;
            #else
                MIDI1_UART_backup.tx_period = MIDI1_UART_TXBITCTR_PERIOD_REG;
            #endif /*End MIDI1_UART_TXCLKGEN_DP */
            MIDI1_UART_backup.tx_mask = MIDI1_UART_TXSTATUS_MASK_REG;
        #endif /*End MIDI1_UART_TX_ENABLED */


    #else /* CY_UDB_V1 */

        #if(MIDI1_UART_CONTROL_REG_REMOVED == 0u)
            MIDI1_UART_backup.cr = MIDI1_UART_CONTROL_REG;
        #endif /* End MIDI1_UART_CONTROL_REG_REMOVED */

    #endif  /* End CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: MIDI1_UART_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  MIDI1_UART_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void MIDI1_UART_RestoreConfig(void)
{

    #if (CY_UDB_V0)

        #if(MIDI1_UART_CONTROL_REG_REMOVED == 0u)
            MIDI1_UART_CONTROL_REG = MIDI1_UART_backup.cr;
        #endif /* End MIDI1_UART_CONTROL_REG_REMOVED */

        #if( (MIDI1_UART_RX_ENABLED) || (MIDI1_UART_HD_ENABLED) )
            MIDI1_UART_RXBITCTR_PERIOD_REG = MIDI1_UART_backup.rx_period;
            MIDI1_UART_RXSTATUS_MASK_REG = MIDI1_UART_backup.rx_mask;
            #if (MIDI1_UART_RXHW_ADDRESS_ENABLED)
                MIDI1_UART_RXADDRESS1_REG = MIDI1_UART_backup.rx_addr1;
                MIDI1_UART_RXADDRESS2_REG = MIDI1_UART_backup.rx_addr2;
            #endif /* End MIDI1_UART_RXHW_ADDRESS_ENABLED */
        #endif  /* End (MIDI1_UART_RX_ENABLED) || (MIDI1_UART_HD_ENABLED) */

        #if(MIDI1_UART_TX_ENABLED)
            #if(MIDI1_UART_TXCLKGEN_DP)
                MIDI1_UART_TXBITCLKGEN_CTR_REG = MIDI1_UART_backup.tx_clk_ctr;
                MIDI1_UART_TXBITCLKTX_COMPLETE_REG = MIDI1_UART_backup.tx_clk_compl;
            #else
                MIDI1_UART_TXBITCTR_PERIOD_REG = MIDI1_UART_backup.tx_period;
            #endif /*End MIDI1_UART_TXCLKGEN_DP */
            MIDI1_UART_TXSTATUS_MASK_REG = MIDI1_UART_backup.tx_mask;
        #endif /*End MIDI1_UART_TX_ENABLED */

    #else /* CY_UDB_V1 */

        #if(MIDI1_UART_CONTROL_REG_REMOVED == 0u)
            MIDI1_UART_CONTROL_REG = MIDI1_UART_backup.cr;
        #endif /* End MIDI1_UART_CONTROL_REG_REMOVED */

    #endif  /* End CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: MIDI1_UART_Sleep
********************************************************************************
*
* Summary:
*  Stops and saves the user configuration. Should be called
*  just prior to entering sleep.
*
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  MIDI1_UART_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void MIDI1_UART_Sleep(void)
{

    #if(MIDI1_UART_RX_ENABLED || MIDI1_UART_HD_ENABLED)
        if((MIDI1_UART_RXSTATUS_ACTL_REG  & MIDI1_UART_INT_ENABLE) != 0u)
        {
            MIDI1_UART_backup.enableState = 1u;
        }
        else
        {
            MIDI1_UART_backup.enableState = 0u;
        }
    #else
        if((MIDI1_UART_TXSTATUS_ACTL_REG  & MIDI1_UART_INT_ENABLE) !=0u)
        {
            MIDI1_UART_backup.enableState = 1u;
        }
        else
        {
            MIDI1_UART_backup.enableState = 0u;
        }
    #endif /* End MIDI1_UART_RX_ENABLED || MIDI1_UART_HD_ENABLED*/

    MIDI1_UART_Stop();
    MIDI1_UART_SaveConfig();
}


/*******************************************************************************
* Function Name: MIDI1_UART_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  MIDI1_UART_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void MIDI1_UART_Wakeup(void)
{
    MIDI1_UART_RestoreConfig();
    #if( (MIDI1_UART_RX_ENABLED) || (MIDI1_UART_HD_ENABLED) )
        MIDI1_UART_ClearRxBuffer();
    #endif /* End (MIDI1_UART_RX_ENABLED) || (MIDI1_UART_HD_ENABLED) */
    #if(MIDI1_UART_TX_ENABLED || MIDI1_UART_HD_ENABLED)
        MIDI1_UART_ClearTxBuffer();
    #endif /* End MIDI1_UART_TX_ENABLED || MIDI1_UART_HD_ENABLED */

    if(MIDI1_UART_backup.enableState != 0u)
    {
        MIDI1_UART_Enable();
    }
}


/* [] END OF FILE */
