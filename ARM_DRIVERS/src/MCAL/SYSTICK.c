/*
 * SYSTICK.c
 *
 *  Created on: Mar 12, 2024
 *      Author: ahmed tarek
 */

#include "MCAL/SYSTICK.h"

#define CLR_CONFIG_BITS_CTRL  0xFFFFFFF9
#define EXTRACT_CLK_SRC_MASK  0x00000004


#define SYSTICK_BASE_ADD 0xE000E010


typedef struct
{
	u32 STK_CTRL;
	u32 STK_LOAD;
	u32 STK_VAL;
	u32 STK_CALIB;

}STK_PERI_t;

volatile STK_PERI_t *const STK= (volatile STK_PERI_t *)SYSTICK_BASE_ADD;

static STK_CBF_t APP_CALLBACK=NULL ;

STK_enuErrorStatus_t STK_Start(void)
{
	STK_enuErrorStatus_t Ret_enuErrorStatusSTK = STK_enuOK;

	u32 Loc_Regconfig=STK->STK_CTRL;

	/* set the bit number 0 by 1 in the CTRL register to enable the systick*/
    Loc_Regconfig|=STK_START_MASK;

    STK->STK_CTRL=Loc_Regconfig;

    return Ret_enuErrorStatusSTK;

}
STK_enuErrorStatus_t STK_Stop(void)
{
	STK_enuErrorStatus_t Ret_enuErrorStatusSTK = STK_enuOK;

	u32 Loc_Regconfig=STK->STK_CTRL;

	/* clear the bit number 0 by 0 in the CTRL register to disable the systick*/
    Loc_Regconfig &= ~(STK_START_MASK);

    STK->STK_CTRL=Loc_Regconfig;

    return Ret_enuErrorStatusSTK;
}
STK_enuErrorStatus_t STK_SetConfig(u32 MODE)
{
	STK_enuErrorStatus_t Ret_enuErrorStatusSTK = STK_enuOK;
	u32 Loc_Regconfig=STK->STK_CTRL;

	if (MODE!=CLKSRC_AHB_8_EXC_DIS &&
		MODE!=CLKSRC_AHB_8_EXC_EN  &&
		MODE!=CLKSRC_AHB_EXC_DIS   &&
		MODE!=CLKSRC_AHB_EXC_EN)
	{Ret_enuErrorStatusSTK= STK_enuNOK;}
	else
	{

		Loc_Regconfig &= CLR_CONFIG_BITS_CTRL;
		Loc_Regconfig |= MODE;
		STK->STK_CTRL= Loc_Regconfig;


	}
	return Ret_enuErrorStatusSTK;
}
STK_enuErrorStatus_t STK_SetTimeMS(u32 TimeMs)
{
	STK_enuErrorStatus_t Ret_enuErrorStatusSTK = STK_enuOK;

	u32 Loc_MicroClkFreq ;
	u32 Loc_Temp ;

	if ((STK->STK_CTRL) & (EXTRACT_CLK_SRC_MASK))
	{
		Loc_MicroClkFreq=CLK_FREQ_MHZ;

	}
	else
	{
		Loc_MicroClkFreq=CLK_FREQ_MHZ/8;

	}
	/*calculate the reload value*/
    Loc_Temp=((Loc_MicroClkFreq/1000) * TimeMs)-1;

    if (Loc_Temp<0x000000001 || Loc_Temp>0x00FFFFFF)
    {
        Ret_enuErrorStatusSTK = STK_enuNOK;
    }
    else
    {
    	STK->STK_LOAD=Loc_Temp;
    	STK->STK_VAL=0;

    }
    return Ret_enuErrorStatusSTK;
}
STK_enuErrorStatus_t STK_SetCallBack(STK_CBF_t Call_Back)
{
	STK_enuErrorStatus_t Ret_enuErrorStatusSTK = STK_enuOK;
	if (Call_Back==NULL)
	{
		Ret_enuErrorStatusSTK=STK_enuNOK;
	}
	else
	{

		APP_CALLBACK=Call_Back;

	}
	return Ret_enuErrorStatusSTK;
}

void SysTick_Handler (void)
{
	if (APP_CALLBACK)
	{
		APP_CALLBACK();
	}

}





