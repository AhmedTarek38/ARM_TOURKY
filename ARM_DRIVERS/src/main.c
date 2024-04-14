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
#include "HAL/LED.h"
#include "HAL/SWITCH_Interface.h"
#include "HAL/HSWITCH.h"
#include "MCAL/NVIC.h"
#include "MCAL/SYSTICK.h"
#include "SERVICE/SCHED.h"
#include "HAL/LED_Config.h"
#include "HAL/SWITCH_Config.h"
//#include "APP/Traffic.h"
//#include "HAL/CLCD.h"


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
/*
 int main(void)
{
       RCC_EnableClk(CLOCK_enuHSI,CSS_enuON);
       RCC_SelectSysClk(CLOCK_enuHSI);
       //RCC_ConfigurePresc(AHB_PRESCALER,AHB_DIVISION_BY_64);
       //RCC_ControlPeripheral(RCC_AHB1,GPIOA,ENABLE);
       RCC_ControlPeripheral(RCC_AHB1,GPIOB,ENABLE);
	   LED_Init();

	  SWITCH_Init();
	   u32 s1=0;
	   u32 s2=0;


  while (1)
    {
	 SWITCH_GetStatus(SWITCH_1, &s1);
	 SWITCH_GetStatus(SWITCH_2, &s2);


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
  /****************************************************************************************/
//NVIC_TEST

/*void delay_ms(u32 ms)
 {
    for (volatile u32 i = 0; i < ms * 16000; ++i)
    {

    }
}
 void EXTI0_IRQHandler(void)
 {

	  LED_SetStatus(LED_1, LED_ON);

 }

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
}*/
/**************************************************************************************************/
/*
//SCHED_TEST

int main (void)
{
 Traffic_light_init();
  Sched_Init();
  Sched_Start();

  return 0;
}*/
/************************************************************************************************/
  //SYSTICK_TEST
/*void LEDON()
{
static u8 flag=0;

if (flag == 0)
{
		LED_SetStatus(LED_1,LED_ON);
		flag=1;
}
   else
  {
		LED_SetStatus(LED_1,LED_OFF);
			flag=0;
  }

}
int main (void)
{
	       RCC_EnableClk(CLOCK_enuHSI,CSS_enuON);
	       RCC_SelectSysClk(CLOCK_enuHSI);

	       RCC_ControlPeripheral(RCC_AHB1,GPIOA,ENABLE);
	       LED_Init();
	       STK_SetConfig(CLKSRC_AHB_EXC_EN);
	       STK_SetTimeMS(1000);
	       STK_SetCallBack(LEDON);

	       STK_Start();

	       while (1)
	       {


	       }



  return 0;
}*/

/***********************************************************************************************/
//LCD_TEST
/*
void LCDTest_Runnable(void)
{

	 static u32 Count=0;
	    if (Count==2)
	    {
	    CLCD_WriteStringAsynch("Ahmed",5);
	    }
	    else if (Count==5)
	    {
	      CLCD_ClearDisplayAsynch();
	    }

	     else if (Count==6)
	    {
	      CLCD_SetCursorAsynch(LINE2,COL1);
	    }
	    else if (Count==7)
	    {
	    	CLCD_WriteStringAsynch("WELCOME HOME",12);
	    }
	    	    Count++ ;




}

int main ()
{
   RCC_EnableClk(CLOCK_enuHSI,CSS_enuON);
   RCC_SelectSysClk(CLOCK_enuHSI);
   RCC_ControlPeripheral(RCC_AHB1,GPIOA,ENABLE);

	 CLCD_InitAsynch();
	 Sched_Init();
	 Sched_Start();

}*/
//HSWITCH
/*
void Runnable_HSWITCH_TEST(void)
{
	u8 FIRST_SWITCH_STATUS;
	u8 SECOND_SWITCH_STATUS;
	u8 THIRD_SWITCH_STATUS;

	HSWITCH_GetStatus(HSWITCH_1,&FIRST_SWITCH_STATUS);
	HSWITCH_GetStatus(HSWITCH_2,&SECOND_SWITCH_STATUS);
	HSWITCH_GetStatus(HSWITCH_3,&THIRD_SWITCH_STATUS);


		if (FIRST_SWITCH_STATUS==HSWITCH_PRESSED)
		{
			LED_SetStatus(LED_1,LED_ON);

		}
	 else if (FIRST_SWITCH_STATUS==HSWITCH_RELEASED)
	    {
		LED_SetStatus(LED_1,LED_OFF);
	    }


	 if (SECOND_SWITCH_STATUS==HSWITCH_PRESSED)
		{
			LED_SetStatus(LED_2,LED_ON);

		}
	else if (SECOND_SWITCH_STATUS==HSWITCH_RELEASED)
		{
			LED_SetStatus(LED_2,LED_OFF);
		}

	if (THIRD_SWITCH_STATUS==HSWITCH_PRESSED)
		{
			LED_SetStatus(LED_3,LED_ON);

		}
	else if (THIRD_SWITCH_STATUS==HSWITCH_RELEASED)
		{
			LED_SetStatus(LED_3,LED_OFF);
		}

}

int main()
{
	   RCC_EnableClk(CLOCK_enuHSI,CSS_enuON);
	   RCC_SelectSysClk(CLOCK_enuHSI);
	   //RCC_ControlPeripheral(RCC_AHB1,GPIOA,ENABLE);
	   RCC_ControlPeripheral(RCC_AHB1,GPIOB,ENABLE);

		 LED_Init();
		 HSWITCH_Init();
		 Sched_Init();
		 Sched_Start();
}*/



#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
