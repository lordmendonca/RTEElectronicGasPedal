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
#include "project.h"
#include "global.h"

#include "led.h"
#include "joystick.h"
#include "watchdog.h"

#include "tsk_inputoutput.h"
#include "tsk_control.h"
#include "tsk_system.h"
#include "tsk_background.h"

//ISR which will increment the systick counter every ms
ISR(systick_handler)
{
    CounterTick(cnt_systick);
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
   
    //Set systick period to 1 ms. Enable the INT and start it.
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, BCLK__BUS_CLK__HZ));
	EE_systick_enable_int();
   
    // Start Operating System
    for(;;)	    
    	StartOS(OSDEFAULTAPPMODE);
}

void unhandledException()
{
    //Ooops, something terrible happened....check the call stack to see how we got here...
    __asm("bkpt");
}

/********************************************************************************
 * Task Definitions
 ********************************************************************************/

TASK(tsk_init)
{
    //Init MCAL Drivers
    LED_Init();
    JOYSTICK_Init();
    UART_LOG_Start();
    
    /**
     * Printing the type of reset that occured.
     **/
    if(WD_CheckResetBit() == TRUE)
    {
        UART_LOG_PutString("\n RESTARTED AFTER WATCHDOG RESET. \n");   
    }
    else
    {
        UART_LOG_PutString("\n STARTED WITH POWER ON RESET. \n");
    }
    
    // Watchdog Timer initialization
    WD_Start(TIMEOUT_1024_TICKS);
    
    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
	
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start();  
	
    //Start the alarm with 1ms cycle time
    SetRelAlarm(alrm_cyclic_1ms,1,1);
    SetRelAlarm(alrm_system_1ms,1,1);
    
    //Tasks that need to be activated
    ActivateTask(tsk_inputoutput);
    ActivateTask(tsk_control);
    ActivateTask(tsk_background);
    
    TerminateTask();
    
}

/********************************************************************************
 * ISR Definitions
 ********************************************************************************/

/**
 * ISR to test the watchdog timeout.
 **/
ISR2(isr_testWDT)
{
    if((TRUE == testWDT_Read()))
    {
        wdt_test =  TRUE;
    }
}

/**
 * ISR that shuts down the system through watchdog timeout.
 **/
ISR2(isr_OSShutdown)
{
    if((TRUE == OSShutdown_Read()))
    {
        ShutdownOS(E_OS_PROTECTION_TIME);
    }
}

/* [] END OF FILE */
