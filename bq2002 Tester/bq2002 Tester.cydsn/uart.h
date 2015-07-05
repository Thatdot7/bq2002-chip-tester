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

#ifndef UART_H
#define UART_H
    
#include <stdbool.h>
#include <project.h>
    
void UART_printCheck(char* message, bool success);
void UART_printInt(uint16 number);
    
#endif

/* [] END OF FILE */
