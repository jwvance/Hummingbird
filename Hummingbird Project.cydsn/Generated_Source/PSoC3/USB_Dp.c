/*******************************************************************************
* File Name: USB_Dp.c  
* Version 2.0
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
#include "USB_Dp.h"


/*******************************************************************************
* Function Name: USB_Dp_Write
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
void USB_Dp_Write(uint8 value) 
{
    uint8 staticBits = (USB_Dp_DR & (uint8)(~USB_Dp_MASK));
    USB_Dp_DR = staticBits | ((uint8)(value << USB_Dp_SHIFT) & USB_Dp_MASK);
}


/*******************************************************************************
* Function Name: USB_Dp_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  USB_Dp_DM_STRONG     Strong Drive 
*  USB_Dp_DM_OD_HI      Open Drain, Drives High 
*  USB_Dp_DM_OD_LO      Open Drain, Drives Low 
*  USB_Dp_DM_RES_UP     Resistive Pull Up 
*  USB_Dp_DM_RES_DWN    Resistive Pull Down 
*  USB_Dp_DM_RES_UPDWN  Resistive Pull Up/Down 
*  USB_Dp_DM_DIG_HIZ    High Impedance Digital 
*  USB_Dp_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void USB_Dp_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(USB_Dp_0, mode);
}


/*******************************************************************************
* Function Name: USB_Dp_Read
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
*  Macro USB_Dp_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 USB_Dp_Read(void) 
{
    return (USB_Dp_PS & USB_Dp_MASK) >> USB_Dp_SHIFT;
}


/*******************************************************************************
* Function Name: USB_Dp_ReadDataReg
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
uint8 USB_Dp_ReadDataReg(void) 
{
    return (USB_Dp_DR & USB_Dp_MASK) >> USB_Dp_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(USB_Dp_INTSTAT) 

    /*******************************************************************************
    * Function Name: USB_Dp_ClearInterrupt
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
    uint8 USB_Dp_ClearInterrupt(void) 
    {
        return (USB_Dp_INTSTAT & USB_Dp_MASK) >> USB_Dp_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
