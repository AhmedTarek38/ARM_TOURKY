/*
 * Traffic.h
 *
 *  Created on: Mar 18, 2024
 *      Author: ahmed tarek
 */

#ifndef TRAFFIC_H_
#define TRAFFIC_H_

#include "HAL/LED.h"
#include "MCAL/RCC_Interface.h"

#define PERIODICIY_SEC 2
typedef enum
{
	LED1_Green,
	LED2_Yellow,
	LED3_RED


}Traffic_CFG_t;

void Traffic_light_init(void);


#endif /* TRAFFIC_H_ */
