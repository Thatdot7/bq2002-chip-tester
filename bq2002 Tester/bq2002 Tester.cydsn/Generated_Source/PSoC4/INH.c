/*******************************************************************************
* File Name: INH.c  
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
#include "INH.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        INH_PC =   (INH_PC & \
                                (uint32)(~(uint32)(INH_DRIVE_MODE_IND_MASK << (INH_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (INH_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: INH_Write
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
void INH_Write(uint8 value) 
{
    uint8 drVal = (uint8)(INH_DR & (uint8)(~INH_MASK));
    drVal = (drVal | ((uint8)(value << INH_SHIFT) & INH_MASK));
    INH_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: INH_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  INH_DM_STRONG     Strong Drive 
*  INH_DM_OD_HI      Open Drain, Drives High 
*  INH_DM_OD_LO      Open Drain, Drives Low 
*  INH_DM_RES_UP     Resistive Pull Up 
*  INH_DM_RES_DWN    Resistive Pull Down 
*  INH_DM_RES_UPDWN  Resistive Pull Up/Down 
*  INH_DM_DIG_HIZ    High Impedance Digital 
*  INH_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void INH_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(INH__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: INH_Read
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
*  Macro INH_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 INH_Read(void) 
{
    return (uint8)((INH_PS & INH_MASK) >> INH_SHIFT);
}


/*******************************************************************************
* Function Name: INH_ReadDataReg
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
uint8 INH_ReadDataReg(void) 
{
    return (uint8)((INH_DR & INH_MASK) >> INH_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(INH_INTSTAT) 

    /*******************************************************************************
    * Function Name: INH_ClearInterrupt
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
    uint8 INH_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(INH_INTSTAT & INH_MASK);
		INH_INTSTAT = maskedStatus;
        return maskedStatus >> INH_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
