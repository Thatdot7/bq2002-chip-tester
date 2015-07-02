/*******************************************************************************
* File Name: TS.c  
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
#include "TS.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        TS_PC =   (TS_PC & \
                                (uint32)(~(uint32)(TS_DRIVE_MODE_IND_MASK << (TS_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (TS_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: TS_Write
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
void TS_Write(uint8 value) 
{
    uint8 drVal = (uint8)(TS_DR & (uint8)(~TS_MASK));
    drVal = (drVal | ((uint8)(value << TS_SHIFT) & TS_MASK));
    TS_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: TS_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  TS_DM_STRONG     Strong Drive 
*  TS_DM_OD_HI      Open Drain, Drives High 
*  TS_DM_OD_LO      Open Drain, Drives Low 
*  TS_DM_RES_UP     Resistive Pull Up 
*  TS_DM_RES_DWN    Resistive Pull Down 
*  TS_DM_RES_UPDWN  Resistive Pull Up/Down 
*  TS_DM_DIG_HIZ    High Impedance Digital 
*  TS_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void TS_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(TS__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: TS_Read
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
*  Macro TS_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 TS_Read(void) 
{
    return (uint8)((TS_PS & TS_MASK) >> TS_SHIFT);
}


/*******************************************************************************
* Function Name: TS_ReadDataReg
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
uint8 TS_ReadDataReg(void) 
{
    return (uint8)((TS_DR & TS_MASK) >> TS_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(TS_INTSTAT) 

    /*******************************************************************************
    * Function Name: TS_ClearInterrupt
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
    uint8 TS_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(TS_INTSTAT & TS_MASK);
		TS_INTSTAT = maskedStatus;
        return maskedStatus >> TS_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
