/*
 * NVIC.h
 *
 *  Created on: Mar 5, 2024
 *      Author: ahmed tarek
 */

#ifndef NVIC_H_
#define NVIC_H_

#include "LIB/STM32F401CC.h"
#include "LIB/STD_TYPES.h"

#define NULL ((void*)0)
/* STM USES ONLY THE HIGH 4 bits from (4 -> 7) for GROUP PRIORITY AND SUB PRIORITY BASED ON CONFIG*/

#define PRIORITY_GROUP0		0x05FA0000 /*[4] bits Preempt Group &  [0] bits Subpriority Group*/
#define PRIORITY_GROUP1		0x05FA0400 /*[3] bits Preempt Group &  [1] bits Subpriority Group*/
#define PRIORITY_GROUP2		0x05FA0500 /*[2] bits Preempt Group &  [2] bits Subpriority Group*/
#define PRIORITY_GROUP3		0x05FA0600 /*[1] bits Preempt Group &  [3] bits Subpriority Group*/
#define PRIORITY_GROUP4   	0x05FA0700 /*[0] bits Preempt Group &  [4] bits Subpriority Group*/


typedef enum
{
	NVIC_enuOK,
	NVIC_enuNOK,

}NVIC_enuErrorStatus_t;

/*
 * @brief    : function to enable interrupt
 * @param[in]: interrupt number
 * @return   : Error status (NVIC_enuOk,NVIC_enuNOK)
 * @details  : Enables the desired interrupt
 */
NVIC_enuErrorStatus_t  Enable_NVIC_IRQ(IRQn_t IRQn);

/*
 * @brief    : function to Disable interrupt
 * @param[in]: interrupt number
 * @return   : Error status (NVIC_enuOk,NVIC_enuNOK)
 * @details  : Disable the desired interrupt
 */
NVIC_enuErrorStatus_t  Disable_NVIC_IRQ(IRQn_t IRQn);

/*
 * @brief    : function to SET interrupt pending IRQ
 * @param[in]: interrupt number
 * @return   : Error status (NVIC_enuOk,NVIC_enuNOK)
 * @details  : SETthe desired interrupt as pending
 */
NVIC_enuErrorStatus_t  SetPendingIRQ(IRQn_t IRQn);

/*
 * @brief    : function to CLEAR interrupt pending IRQ
 * @param[in]: interrupt number
 * @return   : Error status (NVIC_enuOk,NVIC_enuNOK)
 * @details  : Clear the desired interrupt as pending
 */
NVIC_enuErrorStatus_t  ClearPendingIRQ(IRQn_t IRQn);

/*
 * @brief    : function to GET interrupt pending IRQ
 * @param[in]: interrupt number,pointer to save the status
 * @return   : Error status (NVIC_enuOk,NVIC_enuNOK)
 * @details  : GET the desired interrupt req Pending state
 */
NVIC_enuErrorStatus_t  GetPendingIRQ(IRQn_t IRQn, u8 *ptr_status);

/*
 * @brief    : function to GET interrupt ACTIVE IRQ
 * @param[in]: interrupt number, pointer to save the status
 * @return   : Error status (NVIC_enuOk,NVIC_enuNOK)
 * @details  : GET the desired interrupt req active state
 */
NVIC_enuErrorStatus_t  GetActiveStatusIRQ(IRQn_t IRQn, u8 *ptr_status);

/*
 * @brief    : function to SET interrupt PRIORITY
 * @param[in]: interrupt number,preemtion priority group,priority value,subprioritygroup
 * @return   : Error status (NVIC_enuOk,NVIC_enuNOK)
 * @details  : SET the desired interrupt Priority
 */
NVIC_enuErrorStatus_t  SetPriority(IRQn_t IRQn, u8 PreemptionGroup ,u8 SubpriorityGroup ,u32 Priority );


/*
 * @brief    : function to GET interrupt PRIORITY
 * @param[in]: interrupt number,pointer to save the status
 * @return   : Error status (NVIC_enuOk,NVIC_enuNOK)
 * @details  : GET the desired interrupt Priority
 */
NVIC_enuErrorStatus_t  GetPriority(IRQn_t IRQn, u8 *ptr_status);


/*
 * @brief    : Generate sw interrupt
 * @param[in]: interrupt number
 * @return   : Error status (NVIC_enuOk,NVIC_enuNOK)
 * @details  : generate sw interrupt by writing the IRQ number on the register
 */
NVIC_enuErrorStatus_t  Generate_SW_Interrupt(IRQn_t IRQn);






#endif /* NVIC_H_ */
