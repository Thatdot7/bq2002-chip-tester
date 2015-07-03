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
#include <project.h>
#include <stdio.h>
#include "bq2002.h"

static volatile CYBIT isr_flag = 0;     // Flag to indicate button press

CY_ISR(Button1_Press)
{
    ISR_Button1_Disable();
    isr_flag = 1;
}

void init()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    TCPWM_Start();
    TCPWM_TriggerCommand(TCPWM_MASK, TCPWM_CMD_START);
    ISR_Button1_StartEx(Button1_Press);
    IDAC_1_Start();
    
    CyGlobalIntEnable; /* Enable global interrupts. */
}

void UART_PutInt16(uint16 message)
{
    char uart_message[5];
            
    sprintf(uart_message, "%d\r\n", message);
    UART_1_UartPutString(uart_message);
}

int main()
{
    init();
    
    for(;;)
    {
        if(isr_flag != 0)
        {
            isr_flag = 0;
            
            UART_1_UartPutString("Starting Testing Procedure\r\n");
            UART_1_UartPutString("==========================\r\n");
            
            TM_Mode_SetMode(TM_Mode_1C);
            INH_Write(0);
            TS_Write(1);
            V_CC_Write(0);
            CyDelay(500);
            V_CC_Write(1);
            CyDelay(100);
            
            UART_1_UartPutString("Fast Charge: ");
            UART_PutInt16(CC_CheckPWM());
            TS_Write(0);
            CyDelay(100);
            UART_1_UartPutString("Trickle Charge: ");
            UART_PutInt16(CC_CheckPWM());

            /*
            TS_Write(1);
            V_CC_Write(0);
            CyDelay(70);
            V_CC_Write(1);
            CyDelay(70);
            UART_PutInt16(TCPWM_ReadCapture());*/

            ISR_Button1_Enable();
        
        }
    }
}

/* [] END OF FILE */
