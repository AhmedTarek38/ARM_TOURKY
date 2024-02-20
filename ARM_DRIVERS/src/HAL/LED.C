/* *  LED.C
 *
 *  Created on: Feb 19, 2024
 *      Author: ahmed tarek
 */

#include "HAL/LED.h"
#include "MCAL/GPIO_Interface.h"

extern LED_CFG_t LEDS [_LED_NUM];

/*
 * @brief    : function to initialize the pin based on user configuration
 * @param[in]: none (void)
 * @return   : Error status (LED_enuOk,LED_enuNOK)
 * @details  : This function initializes a LED pin according to the provided configuration.
 */
LED_enuErrorStatus_t LED_Init(void)

{
	LED_enuErrorStatus_t Ret_enuErrorStatusLED = LED_enuOK;

	GPIO_PinConfig_t Led;
	Led.Mode=GPIO_OUTPUT_PP;
	Led.Speed=GPIO_HIGH_SPEED;
	u8 Loc_iter=0;

	for (Loc_iter=0;Loc_iter<_LED_NUM;Loc_iter++)
	{
		Led.Pin=LEDS[Loc_iter].PIN;
		Led.Port=LEDS[Loc_iter].PORT;
		GPIO_InitPin(&Led);
		GPIO_Set_PinValue(LEDS[Loc_iter].PORT, LEDS[Loc_iter].PIN, (LEDS[Loc_iter].Connection)^(LEDS[Loc_iter].Default_state));

	}

	return Ret_enuErrorStatusLED;


}

/*
* @brief    : Function to set the value of a specified lED to a specific state
* @param[in]: LED , LEDState
* @return   : Error status (LED_enuOk,LED_enuNOK)
* @details  : Function to set the value of a specified lED to a specific state either HIGH OR LOW
*/

LED_enuErrorStatus_t LED_SetStatus(u32 LED, u32 LEDStatus)


{
	LED_enuErrorStatus_t Ret_enuErrorStatusLED = LED_enuOK;

	GPIO_Set_PinValue(LEDS[LED].PORT, LEDS[LED].PIN, (LEDS[LED].Connection)^LEDStatus);

return Ret_enuErrorStatusLED;

}

