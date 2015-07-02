/*******************************************************************************
* File Name: INH.h  
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

#if !defined(CY_PINS_INH_H) /* Pins INH_H */
#define CY_PINS_INH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "INH_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    INH_Write(uint8 value) ;
void    INH_SetDriveMode(uint8 mode) ;
uint8   INH_ReadDataReg(void) ;
uint8   INH_Read(void) ;
uint8   INH_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define INH_DRIVE_MODE_BITS        (3)
#define INH_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - INH_DRIVE_MODE_BITS))

#define INH_DM_ALG_HIZ         (0x00u)
#define INH_DM_DIG_HIZ         (0x01u)
#define INH_DM_RES_UP          (0x02u)
#define INH_DM_RES_DWN         (0x03u)
#define INH_DM_OD_LO           (0x04u)
#define INH_DM_OD_HI           (0x05u)
#define INH_DM_STRONG          (0x06u)
#define INH_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define INH_MASK               INH__MASK
#define INH_SHIFT              INH__SHIFT
#define INH_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define INH_PS                     (* (reg32 *) INH__PS)
/* Port Configuration */
#define INH_PC                     (* (reg32 *) INH__PC)
/* Data Register */
#define INH_DR                     (* (reg32 *) INH__DR)
/* Input Buffer Disable Override */
#define INH_INP_DIS                (* (reg32 *) INH__PC2)


#if defined(INH__INTSTAT)  /* Interrupt Registers */

    #define INH_INTSTAT                (* (reg32 *) INH__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define INH_DRIVE_MODE_SHIFT       (0x00u)
#define INH_DRIVE_MODE_MASK        (0x07u << INH_DRIVE_MODE_SHIFT)


#endif /* End Pins INH_H */


/* [] END OF FILE */
