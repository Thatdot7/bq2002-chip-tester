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

#include <stdio.h>
#include "uart.h"

void UART_printCheck(char* message, bool success)
{
    
    if(success)
        // Prints an [ OK ] message with green "OK"
        UART_1_UartPutString("\033[1m[\033[32m OK \033[39m]\033[0m ");
    else
        // Prints an [FAIL] message with red "FAIL"
        UART_1_UartPutString("\033[1m[\033[31mFAIL\033[39m]\033[0m ");
    
    
    UART_1_UartPutString(message);
}

void UART_printInt(uint16 number)
{
    char message[5];
    sprintf(message, "%d", number);
    UART_1_UartPutString(message);
}
/* [] END OF FILE */
