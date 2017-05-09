/*******************************************************************************
* File Name: LED_InB.c  
* Version 2.5
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "LED_InB.h"


/*******************************************************************************
* Function Name: LED_InB_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void LED_InB_Write(uint8 value) 
{
    uint8 staticBits = (LED_InB_DR & (uint8)(~LED_InB_MASK));
    LED_InB_DR = staticBits | ((uint8)(value << LED_InB_SHIFT) & LED_InB_MASK);
}


/*******************************************************************************
* Function Name: LED_InB_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LED_InB_DM_STRONG     Strong Drive 
*  LED_InB_DM_OD_HI      Open Drain, Drives High 
*  LED_InB_DM_OD_LO      Open Drain, Drives Low 
*  LED_InB_DM_RES_UP     Resistive Pull Up 
*  LED_InB_DM_RES_DWN    Resistive Pull Down 
*  LED_InB_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LED_InB_DM_DIG_HIZ    High Impedance Digital 
*  LED_InB_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LED_InB_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LED_InB_0, mode);
}


/*******************************************************************************
* Function Name: LED_InB_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro LED_InB_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LED_InB_Read(void) 
{
    return (LED_InB_PS & LED_InB_MASK) >> LED_InB_SHIFT;
}


/*******************************************************************************
* Function Name: LED_InB_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 LED_InB_ReadDataReg(void) 
{
    return (LED_InB_DR & LED_InB_MASK) >> LED_InB_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LED_InB_INTSTAT) 

    /*******************************************************************************
    * Function Name: LED_InB_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 LED_InB_ClearInterrupt(void) 
    {
        return (LED_InB_INTSTAT & LED_InB_MASK) >> LED_InB_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
