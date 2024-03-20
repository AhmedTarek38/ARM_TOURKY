/*
 * SCHED.h
 *
 *  Created on: Mar 17, 2024
 *      Author: ahmed tarek
 */

#ifndef SCHED_H_
#define SCHED_H_

#include "LIB/STD_TYPES.h"
#include "SERVICE/Runnables_config.h"
#include "MCAL/STK_Config.h"
#include "MCAL/SYSTICK.h"

typedef void (*RunnableCb_t)(void);

typedef struct

{
	char *Runnable_Name;
	u32  PeriodicityMS;
	RunnableCb_t CB;
	u32 DelayMs;
}Runnable_t;

typedef enum
{
	SCHED_enuOK,
	SCHED_enuNOK

}SCHED_enuErrorStatus_t;


/*
 * @brief    : function to Intialize the Schedular
 * @param[in]: VOID
 * @return   : Error status (SCHED_enuOk,SCHED_enuNOK)
 * @details  : Intialize the schedular Depending On the configuration(system time,ticktime)
 */
SCHED_enuErrorStatus_t Sched_Init(void);

/*
 * @brief    : function to Start the Schedular
 * @param[in]: VOID
 * @return   : Error status (SCHED_enuOk,SCHED_enuNOK)
 * @details  : Starts the schedular By starts the system timer then enter a loop
 * where it checks for pending ticks and execute the sched function
 */
SCHED_enuErrorStatus_t Sched_Start(void);




#endif /* SCHED_H_ */
