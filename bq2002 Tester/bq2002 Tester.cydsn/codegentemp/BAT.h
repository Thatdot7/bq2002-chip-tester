/*******************************************************************************
* File Name: BAT.h  
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

#if !defined(CY_PINS_BAT_H) /* Pins BAT_H */
#define CY_PINS_BAT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BAT_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    BAT_Write(uint8 value) ;
void    BAT_SetDriveMode(uint8 mode) ;
uint8   BAT_ReadDataReg(void) ;
uint8   BAT_Read(void) ;
uint8   BAT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BAT_DRIVE_MODE_BITS        (3)
#define BAT_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BAT_DRIVE_MODE_BITS))

#define BAT_DM_ALG_HIZ         (0x00u)
#define BAT_DM_DIG_HIZ         (0x01u)
#define BAT_DM_RES_UP          (0x02u)
#define BAT_DM_RES_DWN         (0x03u)
#define BAT_DM_OD_LO           (0x04u)
#define BAT_DM_OD_HI           (0x05u)
#define BAT_DM_STRONG          (0x06u)
#define BAT_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define BAT_MASK               BAT__MASK
#define BAT_SHIFT              BAT__SHIFT
#define BAT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BAT_PS                     (* (reg32 *) BAT__PS)
/* Port Configuration */
#define BAT_PC                     (* (reg32 *) BAT__PC)
/* Data Register */
#define BAT_DR                     (* (reg32 *) BAT__DR)
/* Input Buffer Disable Override */
#define BAT_INP_DIS                (* (reg32 *) BAT__PC2)


#if defined(BAT__INTSTAT)  /* Interrupt Registers */

    #define BAT_INTSTAT                (* (reg32 *) BAT__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define BAT_DRIVE_MODE_SHIFT       (0x00u)
#define BAT_DRIVE_MODE_MASK        (0x07u << BAT_DRIVE_MODE_SHIFT)


#endif /* End Pins BAT_H */


/* [] END OF FILE */
