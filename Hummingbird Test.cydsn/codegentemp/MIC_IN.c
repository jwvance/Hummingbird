/*******************************************************************************
* File Name: MIC_IN.c  
* Version 2.10
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
#include "MIC_IN.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 MIC_IN__PORT == 15 && ((MIC_IN__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: MIC_IN_Write
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
void MIC_IN_Write(uint8 value) 
{
    uint8 staticBits = (MIC_IN_DR & (uint8)(~MIC_IN_MASK));
    MIC_IN_DR = staticBits | ((uint8)(value << MIC_IN_SHIFT) & MIC_IN_MASK);
}


/*******************************************************************************
* Function Name: MIC_IN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  MIC_IN_DM_STRONG     Strong Drive 
*  MIC_IN_DM_OD_HI      Open Drain, Drives High 
*  MIC_IN_DM_OD_LO      Open Drain, Drives Low 
*  MIC_IN_DM_RES_UP     Resistive Pull Up 
*  MIC_IN_DM_RES_DWN    Resistive Pull Down 
*  MIC_IN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  MIC_IN_DM_DIG_HIZ    High Impedance Digital 
*  MIC_IN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void MIC_IN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(MIC_IN_0, mode);
}


/*******************************************************************************
* Function Name: MIC_IN_Read
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
*  Macro MIC_IN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MIC_IN_Read(void) 
{
    return (MIC_IN_PS & MIC_IN_MASK) >> MIC_IN_SHIFT;
}


/*******************************************************************************
* Function Name: MIC_IN_ReadDataReg
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
uint8 MIC_IN_ReadDataReg(void) 
{
    return (MIC_IN_DR & MIC_IN_MASK) >> MIC_IN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MIC_IN_INTSTAT) 

    /*******************************************************************************
    * Function Name: MIC_IN_ClearInterrupt
    ********************************************************************************
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
    uint8 MIC_IN_ClearInterrupt(void) 
    {
        return (MIC_IN_INTSTAT & MIC_IN_MASK) >> MIC_IN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
