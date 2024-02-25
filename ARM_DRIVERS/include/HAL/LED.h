/*
 * LED.h
 *
 *  Created on: Feb 19, 2024
 *      Author: ahmed tarek
 */

#ifndef LED_H_
#define LED_H_

#include"LIB/STD_TYPES.h"
#include "LED_Config.h"

#define LED_ON            0X00000001
#define LED_OFF           0x00000000

#define LED_FORWARD       0x00000000
#define LED_REVERSE       0x00000001


typedef struct
{
	u32 PIN;
	void* PORT;
	u32 Connection;
	u32 Default_state;

}LED_CFG_t;

typedef enum

{
	LED_enuOK,
	LED_enuNOK


}LED_enuErrorStatus_t;

/*
 * @brief    : function to initialize the pin based on user configuration
 * @param[in]: none (void)
 * @return   : Error status (LED_enuOk,LED_enuNOK)
 * @details  : This function initializes a LED pin according to the provided configuration.
 */
LED_enuErrorStatus_t LED_Init(void);

/*
 * @brief    : Function to set the value of a specified lED to a specific state
 * @param[in]: LED , LEDState
 * @return   : Error status (LED_enuOk,LED_enuNOK)
 * @details  : Function to set the value of a specified lED to a specific state either HIGH OR LOW
 */

LED_enuErrorStatus_t LED_SetStatus(LEDS_t LED, u32 LEDStatus);




#endif /* LED_H_ */
