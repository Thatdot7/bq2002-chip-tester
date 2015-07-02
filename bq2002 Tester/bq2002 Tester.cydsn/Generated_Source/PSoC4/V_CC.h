/*******************************************************************************
* File Name: V_CC.h  
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

#if !defined(CY_PINS_V_CC_H) /* Pins V_CC_H */
#define CY_PINS_V_CC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "V_CC_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    V_CC_Write(uint8 value) ;
void    V_CC_SetDriveMode(uint8 mode) ;
uint8   V_CC_ReadDataReg(void) ;
uint8   V_CC_Read(void) ;
uint8   V_CC_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define V_CC_DRIVE_MODE_BITS        (3)
#define V_CC_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - V_CC_DRIVE_MODE_BITS))

#define V_CC_DM_ALG_HIZ         (0x00u)
#define V_CC_DM_DIG_HIZ         (0x01u)
#define V_CC_DM_RES_UP          (0x02u)
#define V_CC_DM_RES_DWN         (0x03u)
#define V_CC_DM_OD_LO           (0x04u)
#define V_CC_DM_OD_HI           (0x05u)
#define V_CC_DM_STRONG          (0x06u)
#define V_CC_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define V_CC_MASK               V_CC__MASK
#define V_CC_SHIFT              V_CC__SHIFT
#define V_CC_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define V_CC_PS                     (* (reg32 *) V_CC__PS)
/* Port Configuration */
#define V_CC_PC                     (* (reg32 *) V_CC__PC)
/* Data Register */
#define V_CC_DR                     (* (reg32 *) V_CC__DR)
/* Input Buffer Disable Override */
#define V_CC_INP_DIS                (* (reg32 *) V_CC__PC2)


#if defined(V_CC__INTSTAT)  /* Interrupt Registers */

    #define V_CC_INTSTAT                (* (reg32 *) V_CC__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define V_CC_DRIVE_MODE_SHIFT       (0x00u)
#define V_CC_DRIVE_MODE_MASK        (0x07u << V_CC_DRIVE_MODE_SHIFT)


#endif /* End Pins V_CC_H */


/* [] END OF FILE */
