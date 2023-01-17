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

#ifndef WATCHDOG_H
#define WATCHDOG_H

#include "project.h"
#include "global.h"
#include "CyLib.h"
    
/**
* \brief Enumeration of the Watchdog Timeout Period
*
*/
enum eWDT_TimeOut
{
    TIMEOUT_2_TICKS = CYWDT_2_TICKS,
    TIMEOUT_16_TICKS = CYWDT_16_TICKS,
    TIMEOUT_128_TICKS = CYWDT_128_TICKS,
    TIMEOUT_1024_TICKS = CYWDT_1024_TICKS,
} ;
typedef enum eWDT_TimeOut WDT_TimeOut_t;

/**
* \brief Bit fields of alive watchdog status register
*/
#define RUNNABLES_NOT_ALIVE                     (0x00u)
#define RUNNABLE_READJOYSTICK                   (0x01u)
#define RUNNABLE_CALCCONTROL                    (0x02u)
#define RUNNABLE_SETENGINE                      (0x04u)
#define RUNNABLE_SETBRAKELIGHT                  (0x08u)
#define RUNNABLES_ALIVE                         (0x0Fu)

/**
* \brief Watchdog status register
*/
extern uint8_t aliveWD_st;

/**
* \brief Watchdog timer test variable
*/
extern boolean_t wdt_test;

/**
* Activate the Watchdog Trigger
* \param WDT_TimeOut_t timeout - [IN] Timeout Period
* @return RC_SUCCESS
*/
RC_t WD_Start(WDT_TimeOut_t timeout);

/**
* Service the Watchdog Trigger
* @return RC_SUCCESS
*/
RC_t WD_Trigger();

/**
* Checks the watchdog bit
* @return TRUE if watchdog reset bit was set
*/
boolean_t WD_CheckResetBit();

/**
* Updates the alive status register
* @return RC_SUCCESS
*/
RC_t WD_Alive(uint8_t myBitPosition);

#endif  /* [] END OF FILE */
