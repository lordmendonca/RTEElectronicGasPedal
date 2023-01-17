
/*
 * Filename: tsk_inputoutput.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 */

#ifndef _H_DEFINE_TSK_INPUTOUTPUT
#define _H_DEFINE_TSK_INPUTOUTPUT

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START TSK_INPUTOUTPUT_INCLUDES */

/* USER CODE END TSK_INPUTOUTPUT_INCLUDES */



/*
* description: Task that handles the input and output signals.
* events: ev_speed_onData|ev_cyclic_1ms
* mode: Cyclic and Event
* name: tsk_inputoutput
* shortname: inputoutput
* signalpoolsRO: sp_common
* signalpoolsRW: sp_common
* tickEvent: ev_cyclic_1ms
* timertickperiod: 1
*/
DeclareTask(tsk_inputoutput);


#endif