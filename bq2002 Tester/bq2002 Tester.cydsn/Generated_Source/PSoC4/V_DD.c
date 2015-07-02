/*******************************************************************************
* File Name: V_DD.c  
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
#include "V_DD.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        V_DD_PC =   (V_DD_PC & \
                                (uint32)(~(uint32)(V_DD_DRIVE_MODE_IND_MASK << (V_DD_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (V_DD_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: V_DD_Write
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
void V_DD_Write(uint8 value) 
{
    uint8 drVal = (uint8)(V_DD_DR & (uint8)(~V_DD_MASK));
    drVal = (drVal | ((uint8)(value << V_DD_SHIFT) & V_DD_MASK));
    V_DD_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: V_DD_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  V_DD_DM_STRONG     Strong Drive 
*  V_DD_DM_OD_HI      Open Drain, Drives High 
*  V_DD_DM_OD_LO      Open Drain, Drives Low 
*  V_DD_DM_RES_UP     Resistive Pull Up 
*  V_DD_DM_RES_DWN    Resistive Pull Down 
*  V_DD_DM_RES_UPDWN  Resistive Pull Up/Down 
*  V_DD_DM_DIG_HIZ    High Impedance Digital 
*  V_DD_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void V_DD_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(V_DD__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: V_DD_Read
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
*  Macro V_DD_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 V_DD_Read(void) 
{
    return (uint8)((V_DD_PS & V_DD_MASK) >> V_DD_SHIFT);
}


/*******************************************************************************
* Function Name: V_DD_ReadDataReg
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
uint8 V_DD_ReadDataReg(void) 
{
    return (uint8)((V_DD_DR & V_DD_MASK) >> V_DD_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(V_DD_INTSTAT) 

    /*******************************************************************************
    * Function Name: V_DD_ClearInterrupt
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
    uint8 V_DD_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(V_DD_INTSTAT & V_DD_MASK);
		V_DD_INTSTAT = maskedStatus;
        return maskedStatus >> V_DD_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
