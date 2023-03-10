

/*
 * Filename: swc_joystick.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "swc_joystick.h"



/* USER CODE START SWC_JOYSTICK_INCLUDE */
#include "intToASCII.h"
#include "watchdog.h"

/* USER CODE END SWC_JOYSTICK_INCLUDE */


#include "sp_common.h"

/* USER CODE START SWC_JOYSTICK_USERDEFINITIONS */

/* USER CODE END SWC_JOYSTICK_USERDEFINITIONS */



/*
* component: swc_joystick
* cycletime: 10
* description: Runnable for the joystick.
* events: 
* name: JOYSTICK_readJoystick_run
* shortname: readJoystick
* signalIN: 
* signalOUT: so_joystick
* task: tsk_inputoutput
*/
void JOYSTICK_readJoystick_run(RTE_event ev){
	
	/* USER CODE START JOYSTICK_readJoystick_run */
    
    static RC_t res = RC_SUCCESS;
    static char asciiConvert[30];
    
    /*
     * Updating the Alive Monitoring register. 
     * Bit Position 0 - RUNNABLE_READJOYSTICK
     **/
    WD_Alive(0);
    /**
     * Error Handling
     **/
    if(res != RC_SUCCESS)
    {
        UART_LOG_PutString("Watchdog Status register update failed. \n");   
    }
    
    /* 
     * Reads the Joystick values. 
     * The function also sets the event 'ev_joystick_onData' for the 'tsk_control'. 
     **/
    res = RTE_SC_JOYSTICK_pullPort(&SO_JOYSTICK_signal);
    
    /**
     *  Error Handling
     */
    
    if(res != RC_SUCCESS)
    {
        UART_LOG_PutString("Joystick Data Invalid. Signal Status Error Code : ");
        intToASCII((uint32_t)RTE_SC_JOYSTICK_getStatus(&SO_JOYSTICK_signal), (uint8_t*)&asciiConvert, 4);
        UART_LOG_PutString(asciiConvert);
        UART_LOG_PutString(". \n");
    }

    /* USER CODE END JOYSTICK_readJoystick_run */
}

/* USER CODE START SWC_JOYSTICK_FUNCTIONS */

/* USER CODE END SWC_JOYSTICK_FUNCTIONS */

