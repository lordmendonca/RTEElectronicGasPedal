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

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/

#include "watchdog.h"
#include "intToASCII.h"

/**
* \brief Watchdog status register
*/
uint8_t aliveWD_st = {0};

/**
* \brief Watchdog timer test variable
*/
boolean_t wdt_test;

/**
* Activate the Watchdog Trigger
* \param WDT_TimeOut_t timeout - [IN] Timeout Period
* @return RC_SUCCESS
*/
RC_t WD_Start(WDT_TimeOut_t timeout)
{
    CyResetStatus &= (~CY_RESET_WD);
    CyWdtStart(timeout, CYWDT_LPMODE_NOCHANGE);
    aliveWD_st &= RUNNABLES_NOT_ALIVE;
    
    return RC_SUCCESS;
}

/**
* Service the Watchdog Trigger
* @return RC_SUCCESS
*/
RC_t WD_Trigger()
{    
    CyWdtClear();   
    return RC_SUCCESS;
}

/**
* Checks the watchdog bit
* @return TRUE if watchdog reset bit was set
*/
boolean_t WD_CheckResetBit()
{  
    return  ((CyResetStatus & CY_RESET_WD) == CY_RESET_WD);
}

/**
* Updates the alive status register
* @return RC_SUCCESS
*/
RC_t WD_Alive(uint8_t myBitPosition)
{  
    switch(myBitPosition)
    {
        case 0 : aliveWD_st |= RUNNABLE_READJOYSTICK;
        break;
        case 1 : aliveWD_st |= RUNNABLE_CALCCONTROL;
        break;
        case 2 : aliveWD_st |= RUNNABLE_SETENGINE;;
        break;
        case 3 : aliveWD_st |= RUNNABLE_SETBRAKELIGHT;
        break;
        default : return RC_ERROR_BAD_DATA;
        break;
    }
    return  RC_SUCCESS;
}

/* [] END OF FILE */
