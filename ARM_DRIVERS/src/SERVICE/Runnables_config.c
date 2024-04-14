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
void RunnableLCD(void);
void LCDTest_Runnable(void);
void Runnable_HSWITCH(void);
void Runnable_HSWITCH_TEST(void);

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
					},
 [Runnable_traffic]=
					{
					 .Runnable_Name="Traffic runnable",
					 .PeriodicityMS=2000,
					 .CB=RunnableTraffic,
					 .DelayMs=0,
					},
[Runnable_LCD]=
					{
					 .Runnable_Name="LCD SM",
					 .PeriodicityMS=2,
					 .CB=RunnableLCD,
					 .DelayMs=0,
					},
[LCD_TEST]=
					{
					 .Runnable_Name="LCDtest",
					 .PeriodicityMS=1000,
					 .CB=LCDTest_Runnable,
					 .DelayMs=0,
					},*/
[HSWITCH]=
					{
					 .Runnable_Name="HSWITCH",
					 .PeriodicityMS=5,
					 .CB=Runnable_HSWITCH,
					 .DelayMs=0,
					},
[HSWITCH_TEST]=
					{
					 .Runnable_Name="HSWITCH_TEST",
					 .PeriodicityMS=200,
					 .CB=Runnable_HSWITCH_TEST,
					 .DelayMs=0,
					},


};

