/*******************************************************************************
* File Name: Debug_Out.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Debug_Out_H) /* Pins Debug_Out_H */
#define CY_PINS_Debug_Out_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Debug_Out_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Debug_Out_Write(uint8 value) ;
void    Debug_Out_SetDriveMode(uint8 mode) ;
uint8   Debug_Out_ReadDataReg(void) ;
uint8   Debug_Out_Read(void) ;
uint8   Debug_Out_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Debug_Out_DRIVE_MODE_BITS        (3)
#define Debug_Out_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Debug_Out_DRIVE_MODE_BITS))

#define Debug_Out_DM_ALG_HIZ         (0x00u)
#define Debug_Out_DM_DIG_HIZ         (0x01u)
#define Debug_Out_DM_RES_UP          (0x02u)
#define Debug_Out_DM_RES_DWN         (0x03u)
#define Debug_Out_DM_OD_LO           (0x04u)
#define Debug_Out_DM_OD_HI           (0x05u)
#define Debug_Out_DM_STRONG          (0x06u)
#define Debug_Out_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Debug_Out_MASK               Debug_Out__MASK
#define Debug_Out_SHIFT              Debug_Out__SHIFT
#define Debug_Out_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Debug_Out_PS                     (* (reg32 *) Debug_Out__PS)
/* Port Configuration */
#define Debug_Out_PC                     (* (reg32 *) Debug_Out__PC)
/* Data Register */
#define Debug_Out_DR                     (* (reg32 *) Debug_Out__DR)
/* Input Buffer Disable Override */
#define Debug_Out_INP_DIS                (* (reg32 *) Debug_Out__PC2)


#if defined(Debug_Out__INTSTAT)  /* Interrupt Registers */

    #define Debug_Out_INTSTAT                (* (reg32 *) Debug_Out__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Debug_Out_DRIVE_MODE_SHIFT       (0x00u)
#define Debug_Out_DRIVE_MODE_MASK        (0x07u << Debug_Out_DRIVE_MODE_SHIFT)


#endif /* End Pins Debug_Out_H */


/* [] END OF FILE */
