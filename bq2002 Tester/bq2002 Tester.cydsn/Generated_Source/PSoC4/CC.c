/*******************************************************************************
* File Name: CC.c  
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
#include "CC.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        CC_PC =   (CC_PC & \
                                (uint32)(~(uint32)(CC_DRIVE_MODE_IND_MASK << (CC_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (CC_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: CC_Write
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
void CC_Write(uint8 value) 
{
    uint8 drVal = (uint8)(CC_DR & (uint8)(~CC_MASK));
    drVal = (drVal | ((uint8)(value << CC_SHIFT) & CC_MASK));
    CC_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: CC_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  CC_DM_STRONG     Strong Drive 
*  CC_DM_OD_HI      Open Drain, Drives High 
*  CC_DM_OD_LO      Open Drain, Drives Low 
*  CC_DM_RES_UP     Resistive Pull Up 
*  CC_DM_RES_DWN    Resistive Pull Down 
*  CC_DM_RES_UPDWN  Resistive Pull Up/Down 
*  CC_DM_DIG_HIZ    High Impedance Digital 
*  CC_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void CC_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(CC__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: CC_Read
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
*  Macro CC_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 CC_Read(void) 
{
    return (uint8)((CC_PS & CC_MASK) >> CC_SHIFT);
}


/*******************************************************************************
* Function Name: CC_ReadDataReg
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
uint8 CC_ReadDataReg(void) 
{
    return (uint8)((CC_DR & CC_MASK) >> CC_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(CC_INTSTAT) 

    /*******************************************************************************
    * Function Name: CC_ClearInterrupt
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
    uint8 CC_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(CC_INTSTAT & CC_MASK);
		CC_INTSTAT = maskedStatus;
        return maskedStatus >> CC_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
