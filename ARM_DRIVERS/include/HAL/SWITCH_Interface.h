/*
 * SWITCH_Interface.h
 *
 *  Created on: Feb 20, 2024
 *      Author: ahmed tarek
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

#include "LIB/STD_TYPES.h"
#include "HAL/SWITCH_Config.h"

#define SWITCH_PRESSED  0x00000001
#define SWITCH_RELEASED 0x00000000

typedef struct
{
	u32   PIN;
	void* PORT;
	u32 Connection;

}SWITCH_CFG_t;

typedef enum

{
	SWITCH_enuOK,
	SWITCH_enuNOK


}SWITCH_enuErrorStatus_t;

/*
 * @brief    : function to initialize the SWITCH based on user configuration
 * @param[in]: none (void)
 * @return   : Error status (SWITCH_enuOk,SWITCH_enuNOK)
 * @details  : This function initializes a SWITCH pin according to the provided configuration.
 */
SWITCH_enuErrorStatus_t SWITCH_Init(void);

/*
 * @brief    : Function to set the value of a specified SWITCH to a specific state
 * @param[in]: SWITCH NAME , SWITCHState(PRESSED OR RELEASED)
 * @return   : Error status (SWITCH_enuOk,SWITCH_enuNOK)
 * @details  : Function to set the value of a specified SWItCH to a specific state either HIGH OR LOW
 */

SWITCH_enuErrorStatus_t SWITCH_SetStatus(u32 SWITCH_NAME, u32 * ptr_TO_SWITCHStatus);



#endif /* SWITCH_INTERFACE_H_ */
