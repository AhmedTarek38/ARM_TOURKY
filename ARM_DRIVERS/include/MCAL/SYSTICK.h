/*
 * SYSTICK.h
 *
 *  Created on: Mar 12, 2024
 *      Author: ahmed tarek
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_
#include "LIB/STD_TYPES.h"
#include "STK_Config.h"

//#define NULL ((void*)0)


#define STK_START_MASK 0x00000001
/*clk source AHB with exception request disabled (no assert)*/
#define CLKSRC_AHB_EXC_DIS    0x00000004
/*clk source AHB with exception request enabled (assert)*/
#define CLKSRC_AHB_EXC_EN     0x00000006
/*clk source AHB/8 with exception request disabled (no assert)*/
#define CLKSRC_AHB_8_EXC_DIS  0x00000000
/*clk source AHB/8 with exception request enabled (assert)*/
#define CLKSRC_AHB_8_EXC_EN   0x00000002



typedef void (*STK_CBF_t)(void);
#define NULL ((STK_CBF_t)0)

typedef enum
{
	STK_enuOK,
	STK_enuNOK,

}STK_enuErrorStatus_t;


/*
 * @brief    : start the systick timer
 * @param[in]: void
 * @return   : Error status (STK_enuOk,STK_enuNOK)
 * @details  : Starts the systick timer to fire interrupt according to specific time
 */

STK_enuErrorStatus_t STK_Start(void);

/*
 * @brief    : stops the systick timer
 * @param[in]: void
 * @return   : Error status (STK_enuOk,STK_enuNOK)
 * @details  : Stopsthe systick timer to fire interrupt
 */

STK_enuErrorStatus_t STK_Stop(void);

/*
 * @brief    : Sets config for systick timer
 * @param[in]: Mode
 * @return   : Error status (STK_enuOk,STK_enuNOK)
 * @details  : configure the systick timer based on the mode entered
 */
STK_enuErrorStatus_t STK_SetConfig(u32 MODE);

/*
 * @brief    : Set time for the systicktimer
 * @param[in]: time in millisecs
 * @return   : Error status (STK_enuOk,STK_enuNOK)
 * @details  : Set the time in which the timer would generate interrupts
 */

STK_enuErrorStatus_t STK_SetTimeMS(u32 TimeMs);

/*
 * @brief    : set the callback function for the systick
 * @param[in]: pointer to callback
 * @return   : Error status (STK_enuOk,STK_enuNOK)
 * @details  : sets the call back function that would be
 *             executed whenever an interrupt is fired by the timer
 */

STK_enuErrorStatus_t STK_SetCallBack(STK_CBF_t Call_Back);



#endif /* SYSTICK_H_ */
