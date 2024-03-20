/*
 * SCHED.c
 *
 *  Created on: Mar 17, 2024
 *      Author: ahmed tarek
 */
#include "SERVICE/SCHED.h"


extern Runnable_t RunnableList[_Runnables_Number];
static volatile u32 PendingTicks;

static void Sched();
static void TickCb();


typedef struct
{
    const Runnable_t *  runnable;
    u32 remainingTimeMs;

}RunnableInfo_RunTime_t;

static RunnableInfo_RunTime_t RunnablesList_RunTime[_Runnables_Number];


SCHED_enuErrorStatus_t Sched_Init(void)
{
	SCHED_enuErrorStatus_t Ret_enuErrorStatusSCHED = SCHED_enuOK;

	u32 index;
	for (index=0;index<_Runnables_Number;index++)
	{
		RunnablesList_RunTime[index].runnable= &RunnableList[index];
		RunnablesList_RunTime[index].remainingTimeMs=RunnableList[index].DelayMs;
	}
	STK_SetConfig(CLKSRC_AHB_EXC_EN);
	STK_SetTimeMS(TICK_TIME_MS);
	STK_SetCallBack(TickCb);

	return Ret_enuErrorStatusSCHED;

}


SCHED_enuErrorStatus_t Sched_Start(void)
{
	SCHED_enuErrorStatus_t Ret_enuErrorStatusSCHED = SCHED_enuOK;
	STK_Start();
	while (1)
	{
		if (PendingTicks)
		{
			PendingTicks--;

			Sched();

		}


	}

    return Ret_enuErrorStatusSCHED;

}

static void Sched()

{
	u32 index;
	for (index=0;index<_Runnables_Number;index++)
		{
		  if((RunnableList[index].CB)&&(RunnablesList_RunTime[index].remainingTimeMs==0))
		  {
			  RunnableList[index].CB();
			  RunnablesList_RunTime[index].remainingTimeMs=RunnableList[index].PeriodicityMS;

		  }

		  RunnablesList_RunTime[index].remainingTimeMs-=TICK_TIME_MS;
		}

}

static void TickCb()
{
	PendingTicks++;
}

