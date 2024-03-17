/*
 * main.c
 *
 *  Created on: Feb 25, 2024
 *      Author: ahmed tarek
 */


/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/trace.h"
#include "MCAL/RCC_Interface.h"
#include "MCAL/GPIO_Interface.h"
#include "HAL/SWITCH_Interface.h"
#include "HAL/LED.h"
#include "MCAL/NVIC.h"


#define ENABLE 1
#define DISABLE 0
// ----------------------------------------------------------------------------
//
// Standalone STM32F4 empty sample (trace via DEBUG).
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace-impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"


//LED,SWITCH,RCC _TEST
 /* int main(void)
{
       RCC_EnableClk(CLOCK_enuHSI,CSS_enuON);
       RCC_SelectSysClk(CLOCK_enuHSI);
       RCC_ConfigurePresc(AHB_PRESCALER,AHB_DIVISION_BY_64);
       RCC_ControlPeripheral(RCC_AHB1,GPIOA,ENABLE);
       RCC_ControlPeripheral(RCC_AHB1,GPIOB,ENABLE);

	   LED_Init();
	   SWITCH_Init();
	   u32 s1=0;
	   u32 s2=0;



  while (1)
    {
	  SWITCH_SetStatus(SWITCH_1, &s1);
	  SWITCH_SetStatus(SWITCH_2, &s2);


	 if (s1== SWITCH_PRESSED)
	  {

		  LED_SetStatus(LED_1, LED_ON);
		  LED_SetStatus(LED_1, LED_OFF);
	  }

	  if (s2== SWITCH_PRESSED)
	 	  {

	 	  LED_SetStatus(LED_2, LED_ON);
	 	 LED_SetStatus(LED_2, LED_OFF);
	 	  }





    }
  return 0;
}*/

//NVIC_TEST

/*void delay_ms(u32 ms)
 {
    for (volatile u32 i = 0; i < ms * 16000; ++i)
    {

    }
}*/
 void EXTI0_IRQHandler(void)
 {

	  LED_SetStatus(LED_1, LED_ON);

 }

 /*void EXTI1_IRQHandler (void)
  {

 	  LED_SetStatus(LED_1, LED_OFF);

  }*/
int main (void)
{
    RCC_EnableClk(CLOCK_enuHSI,CSS_enuON);
	RCC_SelectSysClk(CLOCK_enuHSI);
    RCC_ConfigurePresc(AHB_PRESCALER,AHB_DIVISION_BY_64);
	RCC_ControlPeripheral(RCC_AHB1,GPIOA,ENABLE);
    LED_Init();
    Enable_NVIC_IRQ(EXTI0);
    SetPendingIRQ(EXTI0);
    //Generate_SW_Interrupt(EXTI0);



while (1)
{

}

	return 0;
}




#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
