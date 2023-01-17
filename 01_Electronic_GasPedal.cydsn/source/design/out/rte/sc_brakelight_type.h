
/*
 * Filename: sc_brakelight_type.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 */

#ifndef _H_DEFINE_SC_BRAKELIGHT_TYPE
#define _H_DEFINE_SC_BRAKELIGHT_TYPE

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START SC_BRAKELIGHT_INCLUDES */

/* USER CODE END SC_BRAKELIGHT_INCLUDES */



/**********************************************************************
 *       Type Definition for SC_BRAKELIGHT signal    
 **********************************************************************/

/* USER CODE START SC_BRAKELIGHT_USERDEFINITIONS */

/* USER CODE END SC_BRAKELIGHT_USERDEFINITIONS */

typedef 
/* USER CODE START SC_BRAKELIGHT_SIGNALDATADEFINITION */
struct
{
	#error "Provide your data structure"
} 
/* USER CODE END SC_BRAKELIGHT_SIGNALDATADEFINITION */
SC_BRAKELIGHT_data_t;

/* USER CODE START InitSC_BRAKELIGHT */
#error "Provide a sensible init value"
#define SC_BRAKELIGHT_INIT_DATA ((SC_BRAKELIGHT_data_t){})
/* USER CODE END InitSC_BRAKELIGHT */




/**
 * Default OUT driver API
 * \param const SC_BRAKELIGHT_data_t  *const data : [IN] signal data for the driver, will be scaled in this function
 * \return RC_SUCCESS is all was ok, error code otherwise
 */
RC_t SC_BRAKELIGHT_driverOut(const SC_BRAKELIGHT_data_t  *const data);


/* USER CODE START SC_BRAKELIGHT_USERFUNCTIONS */

/* USER CODE END SC_BRAKELIGHT_USERFUNCTIONS */


#endif