/*******************************************************************************
* File Name: ResolutionClk.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_ResolutionClk_H)
#define CY_CLOCK_ResolutionClk_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void ResolutionClk_StartEx(uint32 alignClkDiv);
#define ResolutionClk_Start() \
    ResolutionClk_StartEx(ResolutionClk__PA_DIV_ID)

#else

void ResolutionClk_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void ResolutionClk_Stop(void);

void ResolutionClk_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 ResolutionClk_GetDividerRegister(void);
uint8  ResolutionClk_GetFractionalDividerRegister(void);

#define ResolutionClk_Enable()                         ResolutionClk_Start()
#define ResolutionClk_Disable()                        ResolutionClk_Stop()
#define ResolutionClk_SetDividerRegister(clkDivider, reset)  \
    ResolutionClk_SetFractionalDividerRegister((clkDivider), 0u)
#define ResolutionClk_SetDivider(clkDivider)           ResolutionClk_SetDividerRegister((clkDivider), 1u)
#define ResolutionClk_SetDividerValue(clkDivider)      ResolutionClk_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define ResolutionClk_DIV_ID     ResolutionClk__DIV_ID

#define ResolutionClk_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define ResolutionClk_CTRL_REG   (*(reg32 *)ResolutionClk__CTRL_REGISTER)
#define ResolutionClk_DIV_REG    (*(reg32 *)ResolutionClk__DIV_REGISTER)

#define ResolutionClk_CMD_DIV_SHIFT          (0u)
#define ResolutionClk_CMD_PA_DIV_SHIFT       (8u)
#define ResolutionClk_CMD_DISABLE_SHIFT      (30u)
#define ResolutionClk_CMD_ENABLE_SHIFT       (31u)

#define ResolutionClk_CMD_DISABLE_MASK       ((uint32)((uint32)1u << ResolutionClk_CMD_DISABLE_SHIFT))
#define ResolutionClk_CMD_ENABLE_MASK        ((uint32)((uint32)1u << ResolutionClk_CMD_ENABLE_SHIFT))

#define ResolutionClk_DIV_FRAC_MASK  (0x000000F8u)
#define ResolutionClk_DIV_FRAC_SHIFT (3u)
#define ResolutionClk_DIV_INT_MASK   (0xFFFFFF00u)
#define ResolutionClk_DIV_INT_SHIFT  (8u)

#else 

#define ResolutionClk_DIV_REG        (*(reg32 *)ResolutionClk__REGISTER)
#define ResolutionClk_ENABLE_REG     ResolutionClk_DIV_REG
#define ResolutionClk_DIV_FRAC_MASK  ResolutionClk__FRAC_MASK
#define ResolutionClk_DIV_FRAC_SHIFT (16u)
#define ResolutionClk_DIV_INT_MASK   ResolutionClk__DIVIDER_MASK
#define ResolutionClk_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_ResolutionClk_H) */

/* [] END OF FILE */
