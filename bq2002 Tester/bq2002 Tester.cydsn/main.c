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

#include "bq2002.h"
#include "uart.h"

static volatile CYBIT isr_flag = 0;     // Flag to indicate button press
uint16 pulse_width = 0;

CY_ISR(Button1_Press)
{
    ISR_Button1_Disable();
    isr_flag = 1;
}
CY_ISR(update_pulse_width)
{
    uint16 interruptHandler;
    interruptHandler = TCPWM_GetInterruptSourceMasked();
    if(interruptHandler == TCPWM_INTR_MASK_CC_MATCH)
    {
        TCPWM_ClearInterrupt(TCPWM_INTR_MASK_CC_MATCH);
        pulse_width = TCPWM_ReadCapture();
    }
    else
    {
        TCPWM_ClearInterrupt(TCPWM_INTR_MASK_TC);
        pulse_width = 0;
    }
}

void init()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    TCPWM_Start();
    TCPWM_TriggerCommand(TCPWM_MASK, TCPWM_CMD_START);
    ISR_Button1_StartEx(Button1_Press);
    ISR_TCPWM_StartEx(update_pulse_width);
    IDAC_1_Start();
    Comp_1_Start();
    
    LED_Result_Reg_Write(0);
    CyGlobalIntEnable; /* Enable global interrupts. */
}

int main()
{
    bool test_success;
    bool global_success;
    uint16 current_pulse_width_ms;
    
    init();
    
    for(;;)
    {
        if(isr_flag != 0)
        {
            isr_flag = 0;
            global_success = true;
            LED_Result_Reg_Write(0x6);
            UART_1_UartPutString("\033[2J");        // Clear Screen
            UART_1_UartPutString("\033[2H");        // Set Cursor back to home
            UART_1_UartPutString("Starting Testing Procedure\r\n");
            UART_1_UartPutString("==========================\r\n");
            
            UART_1_UartPutString("\r\nTesting chip in C/2 mode\r\n");
            TM_Mode_SetMode(TM_Mode_Half_C);
            INH_Write(0);
            TS_Write(1);
            V_CC_Write(0);
            IDAC_1_SetValue(90);
            V_CC_Write(1);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = (current_pulse_width_ms == 0);
            global_success &= test_success;
            UART_printCheck("Initial Boot to Fast Charge Mode\r\n", test_success);

            INH_Write(1);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = (current_pulse_width_ms == 9);
            global_success &= test_success;
            UART_printCheck("Inhibit to Pulse-Trickle Mode\r\n", test_success);
            
            INH_Write(0);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = (current_pulse_width_ms == 0);
            global_success &= test_success;
            UART_printCheck("Uninhibit back to Fast Charge Mode\r\n", test_success);
            
            IDAC_1_SetValue(200);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = (current_pulse_width_ms == 9);
            global_success &= test_success;
            UART_printCheck("V_BAT > 2V to Pulse-Trickle Mode\r\n", test_success);

            V_CC_Write(0);
            V_CC_Write(1);
            CyDelay(10);
            TS_Write(0);
            CyDelay(50);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = (current_pulse_width_ms == 9);
            global_success &= test_success;
            UART_printCheck("Temperature Trigger to Pulse-Trickle Mode\r\n", test_success);
            
            
            UART_1_UartPutString("\r\nTesting chip in 1C Mode\r\n");
            TM_Mode_SetMode(TM_Mode_1C);
            INH_Write(0);
            TS_Write(1);
            V_CC_Write(0);
            IDAC_1_SetValue(90);
            V_CC_Write(1);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = (current_pulse_width_ms == 0);
            global_success &= test_success;
            UART_printCheck("Initial Boot to Fast Charge Mode\r\n", test_success);

            INH_Write(1);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = ((current_pulse_width_ms >= 17) && (current_pulse_width_ms <= 19));
            global_success &= test_success;
            UART_printCheck("Inhibit to Pulse-Trickle Mode\r\n", test_success);
            
            INH_Write(0);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = (current_pulse_width_ms == 0);
            global_success &= test_success;
            UART_printCheck("Uninhibit back to Fast Charge Mode\r\n", test_success);
            
            IDAC_1_SetValue(200);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = ((current_pulse_width_ms >= 17) && (current_pulse_width_ms <= 19));
            global_success &= test_success;
            UART_printCheck("V_BAT > 2V to Pulse-Trickle Mode\r\n", test_success);

            V_CC_Write(0);
            V_CC_Write(1);
            CyDelay(10);
            TS_Write(0);
            CyDelay(50);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = ((current_pulse_width_ms >= 17) && (current_pulse_width_ms <= 19));
            global_success &= test_success;
            UART_printCheck("Temperature Trigger to Pulse-Trickle Mode\r\n", test_success);
            
            UART_1_UartPutString("\r\nTesting chip in 2C Mode\r\n");
            TM_Mode_SetMode(TM_Mode_2C);
            INH_Write(0);
            TS_Write(1);
            V_CC_Write(0);
            IDAC_1_SetValue(90);
            V_CC_Write(1);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = (current_pulse_width_ms == 0);
            global_success &= test_success;
            UART_printCheck("Initial Boot to Fast Charge Mode\r\n", test_success);

            INH_Write(1);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = ((current_pulse_width_ms >= 17) && (current_pulse_width_ms <= 19));
            global_success &= test_success;
            UART_printCheck("Inhibit to Pulse-Trickle Mode\r\n", test_success);
            
            INH_Write(0);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = (current_pulse_width_ms == 0);
            global_success &= test_success;
            UART_printCheck("Uninhibit back to Fast Charge Mode\r\n", test_success);
            
            IDAC_1_SetValue(200);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = ((current_pulse_width_ms >= 17) && (current_pulse_width_ms <= 19));
            global_success &= test_success;
            UART_printCheck("V_BAT > 2V to Pulse-Trickle Mode\r\n", test_success);

            V_CC_Write(0);
            V_CC_Write(1);
            CyDelay(10);
            TS_Write(0);
            CyDelay(50);
            current_pulse_width_ms = CC_CheckPWM() / 1000;
            test_success = ((current_pulse_width_ms >= 17) && (current_pulse_width_ms <= 19));
            global_success &= test_success;
            UART_printCheck("Temperature Trigger to Pulse-Trickle Mode\r\n", test_success);
            
            if(global_success)
                LED_Result_Reg_Write(0x3);
            else
                LED_Result_Reg_Write(0x2);
                
            ISR_Button1_Enable();
            CyDelay(2000);
            LED_Result_Reg_Write(0x0);
        
        }
    }
}

/* [] END OF FILE */
