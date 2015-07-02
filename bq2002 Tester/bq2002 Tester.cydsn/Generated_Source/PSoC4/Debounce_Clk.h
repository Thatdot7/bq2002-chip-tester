/*******************************************************************************
* File Name: Debounce_Clk.h
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

#if !defined(CY_CLOCK_Debounce_Clk_H)
#define CY_CLOCK_Debounce_Clk_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Debounce_Clk_StartEx(uint32 alignClkDiv);
#define Debounce_Clk_Start() \
    Debounce_Clk_StartEx(Debounce_Clk__PA_DIV_ID)

#else

void Debounce_Clk_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Debounce_Clk_Stop(void);

void Debounce_Clk_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Debounce_Clk_GetDividerRegister(void);
uint8  Debounce_Clk_GetFractionalDividerRegister(void);

#define Debounce_Clk_Enable()                         Debounce_Clk_Start()
#define Debounce_Clk_Disable()                        Debounce_Clk_Stop()
#define Debounce_Clk_SetDividerRegister(clkDivider, reset)  \
    Debounce_Clk_SetFractionalDividerRegister((clkDivider), 0u)
#define Debounce_Clk_SetDivider(clkDivider)           Debounce_Clk_SetDividerRegister((clkDivider), 1u)
#define Debounce_Clk_SetDividerValue(clkDivider)      Debounce_Clk_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Debounce_Clk_DIV_ID     Debounce_Clk__DIV_ID

#define Debounce_Clk_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Debounce_Clk_CTRL_REG   (*(reg32 *)Debounce_Clk__CTRL_REGISTER)
#define Debounce_Clk_DIV_REG    (*(reg32 *)Debounce_Clk__DIV_REGISTER)

#define Debounce_Clk_CMD_DIV_SHIFT          (0u)
#define Debounce_Clk_CMD_PA_DIV_SHIFT       (8u)
#define Debounce_Clk_CMD_DISABLE_SHIFT      (30u)
#define Debounce_Clk_CMD_ENABLE_SHIFT       (31u)

#define Debounce_Clk_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Debounce_Clk_CMD_DISABLE_SHIFT))
#define Debounce_Clk_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Debounce_Clk_CMD_ENABLE_SHIFT))

#define Debounce_Clk_DIV_FRAC_MASK  (0x000000F8u)
#define Debounce_Clk_DIV_FRAC_SHIFT (3u)
#define Debounce_Clk_DIV_INT_MASK   (0xFFFFFF00u)
#define Debounce_Clk_DIV_INT_SHIFT  (8u)

#else 

#define Debounce_Clk_DIV_REG        (*(reg32 *)Debounce_Clk__REGISTER)
#define Debounce_Clk_ENABLE_REG     Debounce_Clk_DIV_REG
#define Debounce_Clk_DIV_FRAC_MASK  Debounce_Clk__FRAC_MASK
#define Debounce_Clk_DIV_FRAC_SHIFT (16u)
#define Debounce_Clk_DIV_INT_MASK   Debounce_Clk__DIVIDER_MASK
#define Debounce_Clk_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Debounce_Clk_H) */

/* [] END OF FILE */
