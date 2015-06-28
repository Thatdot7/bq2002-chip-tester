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

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    IDAC_1_Start();
    uint8_t IDAC_VAL = 0;
    
    for(;;)
    {
        /* Place your application code here. */
        //TM_Mode_SetMode((TM_Mode_GetMode() + 1) % 3);
        //CyDelay(2000);
        
        IDAC_1_SetValue(IDAC_VAL);
        IDAC_VAL++;
        CyDelay(1);
    }
}

/* [] END OF FILE */
