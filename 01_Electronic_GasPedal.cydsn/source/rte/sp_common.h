
/*
 * Filename: sp_common.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 */

#ifndef _H_DEFINE_SP_COMMON
#define _H_DEFINE_SP_COMMON

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START SP_COMMON_INCLUDES */

/* USER CODE END SP_COMMON_INCLUDES */



#include "sc_joystick.h"
#include "sc_speed.h"
#include "sc_engine.h"
#include "sc_brakelight.h"



/*
* description: A Signal representing the joystick.
* indriver: default
* name: so_joystick
* onDataError: 0
* onDataUpdate: ev_joystick_onData
* outdriver: 0
* resource: None
* shortname: joystick
* signalclass: sc_joystick
* signalpool: sp_common
*/
extern SC_JOYSTICK_t SO_JOYSTICK_signal;


/*
* description: A Signal representing the speed.
* indriver: 0
* name: so_speed
* onDataError: 0
* onDataUpdate: ev_speed_onData
* outdriver: 0
* resource: None
* shortname: speed
* signalclass: sc_speed
* signalpool: sp_common
*/
extern SC_SPEED_t SO_SPEED_signal;


/*
* description: A Signal representing the engine.
* indriver: 0
* name: so_engine
* onDataError: 0
* onDataUpdate: 0
* outdriver: default
* resource: None
* shortname: engine
* signalclass: sc_engine
* signalpool: sp_common
*/
extern SC_ENGINE_t SO_ENGINE_signal;


/*
* description: A Signal representing the brake light.
* indriver: 0
* name: so_brakeLight
* onDataError: 0
* onDataUpdate: 0
* outdriver: default
* resource: None
* shortname: brakeLight
* signalclass: sc_brakeLight
* signalpool: sp_common
*/
extern SC_BRAKELIGHT_t SO_BRAKELIGHT_signal;



/*
 * Increments the age of the signals in this pool 
 */
void RTE_timertick_sp_common_tick(uint32_t tick);

#endif