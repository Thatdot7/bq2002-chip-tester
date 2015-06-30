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

CY_ISR(debug)
{
    TCPWM_ClearInterrupt(TCPWM_INTR_MASK_CC_MATCH);
    UART_1_UartPutString("Hello\r\n");
}

int main()
{

    UART_1_Start();
    isr_1_StartEx(debug);
    PWM_1_Start();
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    IDAC_1_Start();
    uint8_t IDAC_VAL = 0;
    
    TCPWM_TriggerCommand(TCPWM_MASK, TCPWM_CMD_START);
    
    for(;;)
    {
        /* Place your application code here. */
        //TM_Mode_SetMode((TM_Mode_GetMode() + 1) % 3);
        
        //TCPWM_TriggerCommand(TCPWM_MASK, TCPWM_CMD_RELOAD);
        //TCPWM_TriggerCommand(TCPWM_MASK, TCPWM_CMD_START);
        
        //CyDelay(130);
        
       // TCPWM_TriggerCommand(TCPWM_MASK, TCPWM_CMD_STOP);
        
        uint16 pulse_width = TCPWM_ReadCapture();
        
        char uart_message[5];
        sprintf(uart_message, "%d\r\n", pulse_width);
        
        UART_1_UartPutString(uart_message);
        CyDelay(2000);
        
    }
}

/* [] END OF FILE */
