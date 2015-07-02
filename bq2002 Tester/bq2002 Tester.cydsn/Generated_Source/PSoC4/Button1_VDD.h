/*******************************************************************************
* File Name: Button1_VDD.h  
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

#if !defined(CY_PINS_Button1_VDD_H) /* Pins Button1_VDD_H */
#define CY_PINS_Button1_VDD_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Button1_VDD_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Button1_VDD_Write(uint8 value) ;
void    Button1_VDD_SetDriveMode(uint8 mode) ;
uint8   Button1_VDD_ReadDataReg(void) ;
uint8   Button1_VDD_Read(void) ;
uint8   Button1_VDD_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Button1_VDD_DRIVE_MODE_BITS        (3)
#define Button1_VDD_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Button1_VDD_DRIVE_MODE_BITS))

#define Button1_VDD_DM_ALG_HIZ         (0x00u)
#define Button1_VDD_DM_DIG_HIZ         (0x01u)
#define Button1_VDD_DM_RES_UP          (0x02u)
#define Button1_VDD_DM_RES_DWN         (0x03u)
#define Button1_VDD_DM_OD_LO           (0x04u)
#define Button1_VDD_DM_OD_HI           (0x05u)
#define Button1_VDD_DM_STRONG          (0x06u)
#define Button1_VDD_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Button1_VDD_MASK               Button1_VDD__MASK
#define Button1_VDD_SHIFT              Button1_VDD__SHIFT
#define Button1_VDD_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Button1_VDD_PS                     (* (reg32 *) Button1_VDD__PS)
/* Port Configuration */
#define Button1_VDD_PC                     (* (reg32 *) Button1_VDD__PC)
/* Data Register */
#define Button1_VDD_DR                     (* (reg32 *) Button1_VDD__DR)
/* Input Buffer Disable Override */
#define Button1_VDD_INP_DIS                (* (reg32 *) Button1_VDD__PC2)


#if defined(Button1_VDD__INTSTAT)  /* Interrupt Registers */

    #define Button1_VDD_INTSTAT                (* (reg32 *) Button1_VDD__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Button1_VDD_DRIVE_MODE_SHIFT       (0x00u)
#define Button1_VDD_DRIVE_MODE_MASK        (0x07u << Button1_VDD_DRIVE_MODE_SHIFT)


#endif /* End Pins Button1_VDD_H */


/* [] END OF FILE */
