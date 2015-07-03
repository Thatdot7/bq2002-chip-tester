/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "bq2002.h"

static TM_Mode_t currentMode = TM_Mode_1C;

TM_Mode_t TM_Mode_GetMode()
{
    return currentMode;
}

void TM_Mode_SetMode(TM_Mode_t newMode)
{
    currentMode = newMode;
    switch(newMode)
    {
        case TM_Mode_1C:
            TM_SetDriveMode(TM_DM_STRONG);
            TM_Write(0);
            break;
        case TM_Mode_2C:
            TM_SetDriveMode(TM_DM_STRONG);
            TM_Write(1);
            break;
        case TM_Mode_Half_C:
            TM_SetDriveMode(TM_DM_ALG_HIZ);
            break;
        default:
            break;
    }
}

uint16 CC_CheckPWM()
{
    TCPWM_TriggerCommand(TCPWM_MASK, TCPWM_CMD_RELOAD);
    TCPWM_TriggerCommand(TCPWM_MASK, TCPWM_CMD_START);
    CyDelay(70);
    return TCPWM_ReadCapture();
}

/* [] END OF FILE */
