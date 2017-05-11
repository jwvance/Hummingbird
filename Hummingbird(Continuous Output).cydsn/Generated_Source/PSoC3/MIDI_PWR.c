/*******************************************************************************
* File Name: MIDI_PWR.c  
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
#include "MIDI_PWR.h"


/*******************************************************************************
* Function Name: MIDI_PWR_Write
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
void MIDI_PWR_Write(uint8 value) CYREENTRANT
{
    uint8 staticBits = (MIDI_PWR_DR & (uint8)(~MIDI_PWR_MASK));
    MIDI_PWR_DR = staticBits | ((uint8)(value << MIDI_PWR_SHIFT) & MIDI_PWR_MASK);
}


/*******************************************************************************
* Function Name: MIDI_PWR_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  MIDI_PWR_DM_STRONG     Strong Drive 
*  MIDI_PWR_DM_OD_HI      Open Drain, Drives High 
*  MIDI_PWR_DM_OD_LO      Open Drain, Drives Low 
*  MIDI_PWR_DM_RES_UP     Resistive Pull Up 
*  MIDI_PWR_DM_RES_DWN    Resistive Pull Down 
*  MIDI_PWR_DM_RES_UPDWN  Resistive Pull Up/Down 
*  MIDI_PWR_DM_DIG_HIZ    High Impedance Digital 
*  MIDI_PWR_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void MIDI_PWR_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(MIDI_PWR_0, mode);
}


/*******************************************************************************
* Function Name: MIDI_PWR_Read
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
*  Macro MIDI_PWR_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MIDI_PWR_Read(void) 
{
    return (MIDI_PWR_PS & MIDI_PWR_MASK) >> MIDI_PWR_SHIFT;
}


/*******************************************************************************
* Function Name: MIDI_PWR_ReadDataReg
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
uint8 MIDI_PWR_ReadDataReg(void) 
{
    return (MIDI_PWR_DR & MIDI_PWR_MASK) >> MIDI_PWR_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MIDI_PWR_INTSTAT) 

    /*******************************************************************************
    * Function Name: MIDI_PWR_ClearInterrupt
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
    uint8 MIDI_PWR_ClearInterrupt(void) 
    {
        return (MIDI_PWR_INTSTAT & MIDI_PWR_MASK) >> MIDI_PWR_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */