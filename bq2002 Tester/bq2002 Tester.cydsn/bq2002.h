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

typedef enum TM_Mode TM_Mode_t;

enum TM_Mode {
    TM_Mode_Half_C,
    TM_Mode_1C,
    TM_Mode_2C
};

TM_Mode_t TM_Mode_GetMode();
void TM_Mode_SetMode(TM_Mode_t newMode);


/* [] END OF FILE */
