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

/* [] END OF FILE */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"

#include "watchdog.h"

#include "sp_common.h"

TASK(tsk_background)
{
    while(1)
    {
        /**
         * When the bits 0 to 3 of the alive monitoring status register were set to '1' by the respective 
         * runnables, the watchdog timer is services such that the timer is restarted.
         * If any of the bits were not set then by not servicing the watchdog timer, a timeout after a pre-defined
         * timeout period will occur.
         * It is necessary to clear the status register after each servicing of the watchdog timer and for
         * the verification of the alive monitoring.
         */
        if((aliveWD_st & RUNNABLES_ALIVE) == RUNNABLES_ALIVE)
        {
            WD_Trigger();
            aliveWD_st &= RUNNABLES_NOT_ALIVE;
        }
    }    
}