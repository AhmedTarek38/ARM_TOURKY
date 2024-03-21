/*
 * Runnables.c
 *
 *  Created on: Mar 17, 2024
 *      Author: ahmed tarek
 */
#include "Service/Runnables_config.h"
#include "SERVICE/SCHED.h"


void RunnableSwitch(void);
void RunnableLed(void);
void RunnableTraffic(void);

/*ARRAY FOR THE USER TO CONFIGURE THE RUNNABLES*/

Runnable_t RunnableList[_Runnables_Number]=

{
 /* [Runnable_switch]=
                    {
		             .Runnable_Name="switch runnable",
		             .PeriodicityMS=500,
					 .CB=RunnableSwitch,
					 .DelayMs=0,
                    },
 [Runnable_Led]=
					{
					 .Runnable_Name="Led runnable",
					 .PeriodicityMS=700,
					 .CB=RunnableSwitch,
					 .DelayMs=0,
					},*/
 [Runnable_traffic]=
					{
					 .Runnable_Name="Traffic runnable",
					 .PeriodicityMS=2000,
					 .CB=RunnableTraffic,
					 .DelayMs=0,
					},


};

