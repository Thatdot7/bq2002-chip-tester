/*******************************************************************************
* File Name: TM.h  
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

#if !defined(CY_PINS_TM_H) /* Pins TM_H */
#define CY_PINS_TM_H

#include "cytypes.h"
#include "cyfitter.h"
#include "TM_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    TM_Write(uint8 value) ;
void    TM_SetDriveMode(uint8 mode) ;
uint8   TM_ReadDataReg(void) ;
uint8   TM_Read(void) ;
uint8   TM_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TM_DRIVE_MODE_BITS        (3)
#define TM_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - TM_DRIVE_MODE_BITS))

#define TM_DM_ALG_HIZ         (0x00u)
#define TM_DM_DIG_HIZ         (0x01u)
#define TM_DM_RES_UP          (0x02u)
#define TM_DM_RES_DWN         (0x03u)
#define TM_DM_OD_LO           (0x04u)
#define TM_DM_OD_HI           (0x05u)
#define TM_DM_STRONG          (0x06u)
#define TM_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define TM_MASK               TM__MASK
#define TM_SHIFT              TM__SHIFT
#define TM_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TM_PS                     (* (reg32 *) TM__PS)
/* Port Configuration */
#define TM_PC                     (* (reg32 *) TM__PC)
/* Data Register */
#define TM_DR                     (* (reg32 *) TM__DR)
/* Input Buffer Disable Override */
#define TM_INP_DIS                (* (reg32 *) TM__PC2)


#if defined(TM__INTSTAT)  /* Interrupt Registers */

    #define TM_INTSTAT                (* (reg32 *) TM__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define TM_DRIVE_MODE_SHIFT       (0x00u)
#define TM_DRIVE_MODE_MASK        (0x07u << TM_DRIVE_MODE_SHIFT)


#endif /* End Pins TM_H */


/* [] END OF FILE */
