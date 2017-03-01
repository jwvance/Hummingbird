/*******************************************************************************
* File Name: SDCard_PM.c
* Version 1.20
*
* Description:
*  This file provides the API source code for Power Management of the emFile
*  component.
*
* Note:
*
*******************************************************************************
* Copyright 2011-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <project.h>
#include "SDCard.h"


/*******************************************************************************
* Function Name: SDCard_SaveConfig
********************************************************************************
*
* Summary:
*  Saves SPI Masters configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void SDCard_SaveConfig(void) 
{
    #if(SDCard_NUMBER_SD_CARDS == 4u)
        SDCard_SPI0_SaveConfig();
        SDCard_SPI1_SaveConfig();
        SDCard_SPI2_SaveConfig();
        SDCard_SPI3_SaveConfig();
    #elif(SDCard_NUMBER_SD_CARDS == 3u)
        SDCard_SPI0_SaveConfig();
        SDCard_SPI1_SaveConfig();
        SDCard_SPI2_SaveConfig();
    #elif(SDCard_NUMBER_SD_CARDS == 2u)
        SDCard_SPI0_SaveConfig();
        SDCard_SPI1_SaveConfig();
    #else
        SDCard_SPI0_SaveConfig();
    #endif /* (SDCard_NUMBER_SD_CARDS == 4u) */
}


/*******************************************************************************
* Function Name: SDCard_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores SPI Masters configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  If this API is called without first calling SaveConfig then in the following
*  registers will be default values from Customizer:
*
*******************************************************************************/
void SDCard_RestoreConfig(void) 
{
    #if(SDCard_NUMBER_SD_CARDS == 4u)
        SDCard_SPI0_RestoreConfig();
        SDCard_SPI1_RestoreConfig();
        SDCard_SPI2_RestoreConfig();
        SDCard_SPI3_RestoreConfig();
    #elif(SDCard_NUMBER_SD_CARDS == 3u)
        SDCard_SPI0_SaveConfig();
        SDCard_SPI1_SaveConfig();
        SDCard_SPI2_SaveConfig();
    #elif(SDCard_NUMBER_SD_CARDS == 2u)
        SDCard_SPI0_SaveConfig();
        SDCard_SPI1_SaveConfig();
    #else
        SDCard_SPI0_SaveConfig();
    #endif /* (SDCard_NUMBER_SD_CARDS == 4u) */
}


/*******************************************************************************
* Function Name: SDCard_Sleep
********************************************************************************
*
* Summary:
*  Prepare emFile to go to sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void SDCard_Sleep(void) 
{
    #if(SDCard_NUMBER_SD_CARDS == 4u)
        SDCard_SPI0_Sleep();
        SDCard_SPI1_Sleep();
        SDCard_SPI2_Sleep();
        SDCard_SPI3_Sleep();
    #elif(SDCard_NUMBER_SD_CARDS == 3u)
        SDCard_SPI0_Sleep();
        SDCard_SPI1_Sleep();
        SDCard_SPI2_Sleep();
    #elif(SDCard_NUMBER_SD_CARDS == 2u)
        SDCard_SPI0_Sleep();
        SDCard_SPI1_Sleep();
    #else
        SDCard_SPI0_Sleep();
    #endif /* (SDCard_NUMBER_SD_CARDS == 4u) */
}


/*******************************************************************************
* Function Name: SDCard_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Components to wake up.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void SDCard_Wakeup(void) 
{
    #if(SDCard_NUMBER_SD_CARDS == 4u)
        SDCard_SPI0_Wakeup();
        SDCard_SPI1_Wakeup();
        SDCard_SPI2_Wakeup();
        SDCard_SPI3_Wakeup();
    #elif(SDCard_NUMBER_SD_CARDS == 3u)
        SDCard_SPI0_Wakeup();
        SDCard_SPI1_Wakeup();
        SDCard_SPI2_Wakeup();
    #elif(SDCard_NUMBER_SD_CARDS == 2u)
        SDCard_SPI0_Wakeup();
        SDCard_SPI1_Wakeup();
    #else
        SDCard_SPI0_Wakeup();
    #endif /* (SDCard_NUMBER_SD_CARDS == 4u) */
}


/* [] END OF FILE */
