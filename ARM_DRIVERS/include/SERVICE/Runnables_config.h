/*
 * Runnabled.h
 *
 *  Created on: Mar 17, 2024
 *      Author: ahmed tarek
 */

#ifndef RUNNABLED_H_
#define RUNNABLED_H_

/* Configure tick period to be equal to or less than the period of the smallest period in all runnables */
#define TICK_TIME_MS       2
/*Enum defines number of runnables in the system to be run by sched*/

typedef enum
{
	//Runnable_switch,
	//Runnable_Led,
	//Runnable_traffic,
	Runnable_LCD,
	LCD_TEST,
   _Runnables_Number

}RunnablesNUM_t;


#endif /* RUNNABLED_H_ */
