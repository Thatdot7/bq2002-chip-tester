/*******************************************************************************
* File Name: V_DD.h  
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

#if !defined(CY_PINS_V_DD_H) /* Pins V_DD_H */
#define CY_PINS_V_DD_H

#include "cytypes.h"
#include "cyfitter.h"
#include "V_DD_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    V_DD_Write(uint8 value) ;
void    V_DD_SetDriveMode(uint8 mode) ;
uint8   V_DD_ReadDataReg(void) ;
uint8   V_DD_Read(void) ;
uint8   V_DD_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define V_DD_DRIVE_MODE_BITS        (3)
#define V_DD_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - V_DD_DRIVE_MODE_BITS))

#define V_DD_DM_ALG_HIZ         (0x00u)
#define V_DD_DM_DIG_HIZ         (0x01u)
#define V_DD_DM_RES_UP          (0x02u)
#define V_DD_DM_RES_DWN         (0x03u)
#define V_DD_DM_OD_LO           (0x04u)
#define V_DD_DM_OD_HI           (0x05u)
#define V_DD_DM_STRONG          (0x06u)
#define V_DD_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define V_DD_MASK               V_DD__MASK
#define V_DD_SHIFT              V_DD__SHIFT
#define V_DD_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define V_DD_PS                     (* (reg32 *) V_DD__PS)
/* Port Configuration */
#define V_DD_PC                     (* (reg32 *) V_DD__PC)
/* Data Register */
#define V_DD_DR                     (* (reg32 *) V_DD__DR)
/* Input Buffer Disable Override */
#define V_DD_INP_DIS                (* (reg32 *) V_DD__PC2)


#if defined(V_DD__INTSTAT)  /* Interrupt Registers */

    #define V_DD_INTSTAT                (* (reg32 *) V_DD__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define V_DD_DRIVE_MODE_SHIFT       (0x00u)
#define V_DD_DRIVE_MODE_MASK        (0x07u << V_DD_DRIVE_MODE_SHIFT)


#endif /* End Pins V_DD_H */


/* [] END OF FILE */
