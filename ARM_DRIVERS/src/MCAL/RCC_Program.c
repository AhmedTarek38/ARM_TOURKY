#include "MCAL/RCC_Interface.h"


#define ENABLE  1
#define DISABLE 0


RCC_enuErrorStatus_t RCC_EnableClk(RCC_Clock_t Clock, RCC_CSS_State_t CSS)
{
	RCC_enuErrorStatus_t Ret_enuErrorStatusRCC = RCC_enuOK;

	switch (CSS)
	{
	case CSS_enuOFF:

	switch (Clock)
	{
	   case CLOCK_enuHSI:
		   rcc->RCC_CR=HSION_MASK_CSSOFF;
		   while ((rcc->RCC_CR >> RCC_CR_enuHSIRDY) == DISABLE);
		   break;

	   case CLOCK_enuHSE_Crystal:
	   		   rcc->RCC_CR=HSEON_CRYSTAL_MASK_CSSOFF;
	   		   while ((rcc->RCC_CR >> RCC_CR_enuHSERDY) == DISABLE);
	   		   break;

	   case CLOCK_enuHSE_RC:
	   		   rcc->RCC_CR=HSION_MASK_CSSOFF;
	   		   while ((rcc->RCC_CR >> RCC_CR_enuHSERDY) == DISABLE);
	   		   break;

	   case CLOCK_enuPLL:
	   		   rcc->RCC_CR=PLLON_MASK_CSSOFF;
	   		   while ((rcc->RCC_CR >> RCC_CR_enuPLLRDY) == DISABLE);
	   		   break;
	   default : break;


	} break;

	case CSS_enuON :
		switch (Clock)
			{
			   case CLOCK_enuHSI:
				   rcc->RCC_CR=HSION_MASK_CSSON;
				   while ((rcc->RCC_CR >> RCC_CR_enuHSIRDY) == DISABLE);
				   break;

			   case CLOCK_enuHSE_Crystal:
			   		   rcc->RCC_CR=HSEON_CRYSTAL_MASK_CSSON;
			   		   while ((rcc->RCC_CR >> RCC_CR_enuHSERDY) == DISABLE);
			   		   break;

			   case CLOCK_enuHSE_RC:
			   		   rcc->RCC_CR=HSION_MASK_CSSON;
			   		   while ((rcc->RCC_CR >> RCC_CR_enuHSERDY) == DISABLE);
			   		   break;

			   case CLOCK_enuPLL:
			   		   rcc->RCC_CR=PLLON_MASK_CSSON;
			   		   while ((rcc->RCC_CR >> RCC_CR_enuPLLRDY) == DISABLE);
			   		   break;
			   default : break;


			} break;
		default : break;
	}
		 return Ret_enuErrorStatusRCC;
}


RCC_enuErrorStatus_t RCC_DisableClk(RCC_Clock_t Clock)
{
	u8 LocTemp_config=rcc->RCC_CR;
	RCC_enuErrorStatus_t Ret_enuErrorStatusRCC = RCC_enuOK;

	switch (Clock)
		{
		   case CLOCK_enuHSI:
			   LocTemp_config &=~(1<<RCC_CR_enuHSION); //ClR bit
			   rcc->RCC_CR=LocTemp_config;
			   break;

		   case CLOCK_enuHSE_Crystal:

			   LocTemp_config &=~(1<<RCC_CR_enuHSEON);
			    rcc->RCC_CR=LocTemp_config;//ClR bit
		   		   break;

		   case CLOCK_enuHSE_RC:

			   LocTemp_config &=~(1<<RCC_CR_enuHSEON); //ClR bit
			   rcc->RCC_CR=LocTemp_config;
		   		   break;

		   case CLOCK_enuPLL:

			   LocTemp_config &=~(1<<RCC_CR_enuPLLON); //ClR bit
		   	   rcc->RCC_CR=LocTemp_config;
		   		   break;
		   default : break;


		}


	 return Ret_enuErrorStatusRCC;
}


RCC_enuErrorStatus_t RCC_SelectSysClk(RCC_Clock_t SysClock)
{
	RCC_enuErrorStatus_t Ret_enuErrorStatusRCC = RCC_enuOK;

	switch (SysClock)
	{
	   case CLOCK_enuHSI:
		   rcc->RCC_CFGR=SW_HSI_MASK;
		   break;
	   case CLOCK_enuHSE_Crystal:
	   		   rcc->RCC_CFGR=SW_HSE_MASK;
	   	   break;
	   case CLOCK_enuHSE_RC:
	   	   		   rcc->RCC_CFGR=SW_HSE_MASK;
	   	   	   break;
	   case CLOCK_enuPLL:
	   		   rcc->RCC_CFGR=SW_PLL_MASK;
	   	   break;
	}

	 return Ret_enuErrorStatusRCC;

}



RCC_enuErrorStatus_t RCC_ConfigurePLL(u32 PLLSRC, u32 PLLM, u32 PLLN, u32 PLLP,u32 PLLQ )
{
	RCC_enuErrorStatus_t Ret_enuErrorStatusRCC = RCC_enuNOK;

    u16 LocTemp_config=rcc->RCC_PLLCFGR;
	u8 LocTemp= (rcc->RCC_CR >> RCC_CR_enuPLLRDY) & 0x01; //get bit

	if (PLLQ<=2||PLLQ>15||PLLP!=2||PLLP!=4||PLLP!=6||PLLP!=8||PLLN<192||PLLN>432||PLLM<2||PLLM>63)
	{Ret_enuErrorStatusRCC = RCC_enuNOK;}
	else
	{
		Ret_enuErrorStatusRCC = RCC_enuOK;

	if ( LocTemp == ENABLE)
	{

		RCC_SelectSysClk(CLOCK_enuHSI);
		RCC_DisableClk(CLOCK_enuPLL);

		switch (PLLSRC)
		{
         case PLL_HSI: rcc->RCC_PLLCFGR &=~(1<<RCC_PLLCFGR_enuPLLSRC); break;
         case PLL_HSE: rcc->RCC_PLLCFGR |=(1<<RCC_PLLCFGR_enuPLLSRC); break;
         default:   break;
		}


        	 LocTemp_config |=(PLLM<<PLLM_);
        	 LocTemp_config |=(PLLN <<PLLN_);
        	 LocTemp_config |=(((PLLP/2)-1)<<PLLP_);
        	 LocTemp_config |=(PLLQ<<PLLQ_);
        	 rcc->RCC_PLLCFGR=LocTemp_config;


		        // Enable PLL
		        RCC_EnableClk(CLOCK_enuPLL,CSS_enuOFF);

		        // Wait until PLL is ready
		        while ((rcc->RCC_CR & RCC_CR_enuPLLRDY) == DISABLE)
		        {

		        }

		        // Switch to PLL as system clock
		        RCC_SelectSysClk(CLOCK_enuPLL);
		    }

	else

	{
		switch (PLLSRC)
				{
		         case PLL_HSI: rcc->RCC_PLLCFGR &=~(1<<RCC_PLLCFGR_enuPLLSRC); break;
		         case PLL_HSE: rcc->RCC_PLLCFGR |=(1<<RCC_PLLCFGR_enuPLLSRC); break;
		         default:   break;
				}


		        	 LocTemp_config |=(PLLM<<PLLM_);
		        	 LocTemp_config |=(PLLN <<PLLN_);
		        	 LocTemp_config |=(((PLLP/2)-1)<<PLLP_);
		        	 LocTemp_config |=(PLLQ<<PLLQ_);
		        	 rcc->RCC_PLLCFGR=LocTemp_config;
	}
	}
		    return Ret_enuErrorStatusRCC;
		}

RCC_enuErrorStatus_t RCC_ControlPeripheral(u8 BusID, u8 Peripheral,u8 state)
{
  u8 Loc1Control_periph=rcc->RCC_AHB1ENR;
  u8 Loc2Control_periph=rcc->RCC_AHB2ENR;
  u8 Loc3Control_periph=rcc->RCC_APB1ENR;
  u8 Loc4Control_periph=rcc->RCC_APB2ENR;

	RCC_enuErrorStatus_t Ret_enuErrorStatusRCC = RCC_enuNOK;
	if     (  BusID!=RCC_AHB1
			&&BusID!=RCC_AHB2
			&&BusID!=RCC_APB1
			&&BusID!=RCC_APB2 )
	{Ret_enuErrorStatusRCC=RCC_enuWRONGBusID;}
	else
{
		Ret_enuErrorStatusRCC=RCC_enuOK;

	if (state == ENABLE)
	{
      switch (BusID)
      {
        case RCC_AHB1:  Loc1Control_periph |=(1<<Peripheral);
                        rcc->RCC_AHB1ENR=Loc1Control_periph;        break;

        case RCC_AHB2:  Loc2Control_periph |=(1<<Peripheral);
                        rcc->RCC_AHB2ENR=Loc2Control_periph;        break;

        case RCC_APB1:  Loc3Control_periph |=(1<<Peripheral);
                        rcc->RCC_APB1ENR=Loc3Control_periph ;       break;

        case RCC_APB2:  Loc4Control_periph |=(1<<Peripheral);
                        rcc->RCC_APB2ENR=Loc4Control_periph ;       break;
        default:   break;

      }
	}

  if (state == DISABLE)
	{
	switch (BusID)
	{
		   case RCC_AHB1:  Loc1Control_periph  &=~(1<<Peripheral);
							rcc->RCC_AHB1ENR=Loc1Control_periph;       break;

			case RCC_AHB2:  Loc2Control_periph &=~(1<<Peripheral);
							rcc->RCC_AHB2ENR=Loc2Control_periph;      break;

			case RCC_APB1:  Loc3Control_periph &=~(1<<Peripheral);
							rcc->RCC_APB1ENR=Loc3Control_periph  ;      break;

			case RCC_APB2:  Loc4Control_periph &=~(1<<Peripheral);
							rcc->RCC_APB2ENR=Loc4Control_periph ;       break;
			default:   break;

	}

	}

}
      return Ret_enuErrorStatusRCC;

}

RCC_enuErrorStatus_t RCC_ConfigurePresc(u8 Presacaler_Type, u8 Division_Factor)

{ u8 LocPresc_config=rcc->RCC_CFGR;
	RCC_enuErrorStatus_t Ret_enuErrorStatusRCC=RCC_enuOK;
	if ((Division_Factor!=AHB_NO_DIVISION)
	        && (Division_Factor!=AHB_DIVISION_BY_2)
	        && (Division_Factor!=AHB_DIVISION_BY_4)
	        && (Division_Factor!=AHB_DIVISION_BY_8)
	        && (Division_Factor!=AHB_DIVISION_BY_16)
	        && (Division_Factor!=AHB_DIVISION_BY_64)
	        && (Division_Factor!=AHB_DIVISION_BY_128)
	        && (Division_Factor!=AHB_DIVISION_BY_256)
	        && (Division_Factor!=AHB_DIVISION_BY_512))

	{Ret_enuErrorStatusRCC=RCC_enuWrong_Prescalar_DivisionFactor;}
	else
 {
		Ret_enuErrorStatusRCC=RCC_enuOK;

	switch (Presacaler_Type)
	{
	  case LOW_SPEED_PRESCALER_PPRE1:

		  LocPresc_config |=(Division_Factor<<PPRE1);
          rcc->RCC_CFGR=LocPresc_config;     break;

	  case HIGH_SPEED_PRESCALER_PPRE2:

		  LocPresc_config |=(Division_Factor<<PPRE2);
          rcc->RCC_CFGR=LocPresc_config;     break;

	  case AHB_PRESCALER:
		  LocPresc_config |=(Division_Factor<<AHB_PRE);
		  rcc->RCC_CFGR=LocPresc_config;     break;

	}
 }

return Ret_enuErrorStatusRCC;

}




