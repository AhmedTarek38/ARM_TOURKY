#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include "RCC_Private.h"




typedef enum
{
	RCC_enuOK,
	RCC_enuNOK,
	RCC_enuWrong_Prescalar_DivisionFactor,
	RCC_enuWRONGBusID
}RCC_enuErrorStatus_t;

typedef enum
{
	CLOCK_enuHSI,
	CLOCK_enuHSE_RC,
	CLOCK_enuHSE_Crystal,
	CLOCK_enuPLL
}RCC_Clock_t;

typedef enum
{
	 CSS_enuON,
	 CSS_enuOFF
}RCC_CSS_State_t;

typedef enum{
	RCC_CR_enuHSION=0,
	RCC_CR_enuHSIRDY,
	RCC_CR_enuReserved2,
	RCC_CR_enuHSITRIM_0,
	RCC_CR_enuHSITRIM_1,
	RCC_CR_enuHSITRIM_2,
	RCC_CR_enuHSITRIM_3,
	RCC_CR_enuHSITRIM_4,
	RCC_CR_enuHSICAL_0 ,
	RCC_CR_enuHSICAL_1 ,
	RCC_CR_enuHSICAL_2 ,
	RCC_CR_enuHSICAL_3 ,
	RCC_CR_enuHSICAL_4 ,
	RCC_CR_enuHSICAL_5 ,
	RCC_CR_enuHSICAL_6 ,
	RCC_CR_enuHSICAL_7 ,
	RCC_CR_enuHSEON ,
	RCC_CR_enuHSERDY ,
	RCC_CR_enuHSEBYP ,
	RCC_CR_enuCSSON ,
	RCC_CR_enuReserved20,
	RCC_CR_enuReserved21,
	RCC_CR_enuReserved22,
	RCC_CR_enuReserved23,
	RCC_CR_enuPLLON 	,
	RCC_CR_enuPLLRDY 	,
	RCC_CR_enuPLLI2SON 	,
	RCC_CR_enuPLLI2SRDY ,
	RCC_CR_enuReserved28,
	RCC_CR_enuReserved29,
	RCC_CR_enuReserved30,
	RCC_CR_enuReserved31
}RCC_CRBits_t;

typedef enum{
	RCC_PLLCFGR_enuPLLM0=0,
	RCC_PLLCFGR_enuPLLM1,
	RCC_PLLCFGR_enuPLLM2,
	RCC_PLLCFGR_enuPLLM3,
	RCC_PLLCFGR_enuPLLM4,
	RCC_PLLCFGR_enuPLLM5,
	RCC_PLLCFGR_enuPLLN0,
	RCC_PLLCFGR_enuPLLN1,
	RCC_PLLCFGR_enuPLLN2,
	RCC_PLLCFGR_enuPLLN3,
	RCC_PLLCFGR_enuPLLN4,
	RCC_PLLCFGR_enuPLLN5,
	RCC_PLLCFGR_enuPLLN6,
	RCC_PLLCFGR_enuPLLN7,
	RCC_PLLCFGR_enuPLLN8,
	RCC_PLLCFGR_enuReserved15,
	RCC_PLLCFGR_enuPLLP0,
	RCC_PLLCFGR_enuPLLP1,
	RCC_PLLCFGR_enuReserved18,
	RCC_PLLCFGR_enuReserved19,
	RCC_PLLCFGR_enuReserved20,
	RCC_PLLCFGR_enuReserved21,
	RCC_PLLCFGR_enuPLLSRC	 ,
	RCC_PLLCFGR_enuReserved23,
	RCC_PLLCFGR_enuPLLQ0     ,
	RCC_PLLCFGR_enuPLLQ1     ,
	RCC_PLLCFGR_enuPLLQ2     ,
	RCC_PLLCFGR_enuPLLQ3     ,
	RCC_PLLCFGR_enuReserved28,
	RCC_PLLCFGR_enuReserved29,
	RCC_PLLCFGR_enuReserved30,
	RCC_PLLCFGR_enuReserved31
	
 }RCC_PLLCFGRBits_t;
 
 typedef enum	{
 	RCC_CFGR_enuSW0=0 ,
 	RCC_CFGR_enuSW1,
 	RCC_CFGR_enuSWS0,
 	RCC_CFGR_enuSWS1,
 	RCC_CFGR_enuHPRE0,
 	RCC_CFGR_enuHPRE1,
 	RCC_CFGR_enuHPRE2,
 	RCC_CFGR_enuHPRE3,
 	RCC_CFGR_enuReserved8,
 	RCC_CFGR_enuReserved9,
 	RCC_CFGR_enuPPRE10	 ,
 	RCC_CFGR_enuPPRE11	 ,
 	RCC_CFGR_enuPPRE12	 ,
 	RCC_CFGR_enuPPRE20	 ,
 	RCC_CFGR_enuPPRE21	 ,
 	RCC_CFGR_enuPPRE22	 ,
 	RCC_CFGR_enuRTCPRE0	 ,
 	RCC_CFGR_enuRTCPRE1	 ,
 	RCC_CFGR_enuRTCPRE2	 ,
 	RCC_CFGR_enuRTCPRE3	 ,
 	RCC_CFGR_enuRTCPRE4	 ,
 	RCC_CFGR_enuMCO10	 ,
 	RCC_CFGR_enuMCO11	 ,
 	RCC_CFGR_enuI2SSRC	 ,
 	RCC_CFGR_enuMCO1PRE0 ,
 	RCC_CFGR_enuMCO1PRE1 ,
 	RCC_CFGR_enuMCO1PRE2 ,
 	RCC_CFGR_enuMCO2PRE0 ,
 	RCC_CFGR_enuMCO2PRE1 ,
 	RCC_CFGR_enuMCO2PRE2 ,
 	RCC_CFGR_enuMCO20	 ,
 	RCC_CFGR_enuMCO21	
	
  }RCC_CFGR_Bits_t;

  typedef enum
  {
  RCC_AHB1ENR_enuGPIOAEN=0,
  RCC_AHB1ENR_enuGPIOBEN,
  RCC_AHB1ENR_enuGPIOCEN,
  RCC_AHB1ENR_enuGPIODEN,
  RCC_AHB1ENR_enuGPIOEEN,
  RCC_AHB1ENR_enuReserved00,
  RCC_AHB1ENR_enuReserved01,
  RCC_AHB1ENR_enuGPIOHEN,
  RCC_AHB1ENR_enuReserved02,
  RCC_AHB1ENR_enuReserved03,
  RCC_AHB1ENR_enuReserved04,
  RCC_AHB1ENR_enuReserved05,
  RCC_AHB1ENR_enuCRCEN,
  RCC_AHB1ENR_enuReserved06,
  RCC_AHB1ENR_enuReserved07,
  RCC_AHB1ENR_enuReserved08,
  RCC_AHB1ENR_enuReserved09,
  RCC_AHB1ENR_enuReserved10,
  RCC_AHB1ENR_enuReserved11,
  RCC_AHB1ENR_enuReserved12,
  RCC_AHB1ENR_enuReserved13,
  RCC_AHB1ENR_enuDMA1EN,
  RCC_AHB1ENR_enuDMA2EN,
  RCC_AHB1ENR_enuReserved14,
  RCC_AHB1ENR_enuReserved15,
  RCC_AHB1ENR_enuReserved16,
  RCC_AHB1ENR_enuReserved17,
  RCC_AHB1ENR_enuReserved18,
  RCC_AHB1ENR_enuReserved19,
  RCC_AHB1ENR_enuReserved20,
  RCC_AHB1ENR_enuReserved21,
  RCC_AHB1ENR_enuReserved22
  }RCC_AHB1ENR_Bits_t;

  typedef enum
   {
  	RCC_AHB2ENR_enuReserved0=0,
  	RCC_AHB2ENR_enuReserved1,
  	RCC_AHB2ENR_enuReserved2,
  	RCC_AHB2ENR_enuReserved3,
  	RCC_AHB2ENR_enuReserved4,
  	RCC_AHB2ENR_enuReserved5,
  	RCC_AHB2ENR_enuReserved06,
  	RCC_AHB2ENR_enuOTGFSEN,
  	RCC_AHB2ENR_enuReserved07,
  	RCC_AHB2ENR_enuReserved08,
  	RCC_AHB2ENR_enuReserved09,
  	RCC_AHB2ENR_enuReserved10,
  	RCC_AHB2ENR_enuReserved11,
  	RCC_AHB2ENR_enuReserved12,
  	RCC_AHB2ENR_enuReserved13,
  	RCC_AHB2ENR_enuReserved14,
  	RCC_AHB2ENR_enuReserved15,
  	RCC_AHB2ENR_enuReserved16,
  	RCC_AHB2ENR_enuReserved17,
  	RCC_AHB2ENR_enuReserved18,
  	RCC_AHB2ENR_enuReserved19,
  	RCC_AHB2ENR_enuReserved20,
  	RCC_AHB2ENR_enuReserved21,
  	RCC_AHB2ENR_enuReserved22,
      RCC_AHB2ENR_enuReserved23,
  	RCC_AHB2ENR_enuReserved24,
  	RCC_AHB2ENR_enuReserved25,
      RCC_AHB2ENR_enuReserved26,
      RCC_AHB2ENR_enuReserved27,
      RCC_AHB2ENR_enuReserved28,
      RCC_AHB2ENR_enuReserved29,
      RCC_AHB2ENR_enuReserved30
     }RCC_AHB2ENR_Bits_t;

     typedef enum{
     	RCC_APB1ENR_enuTIM2EN=0,
     	RCC_APB1ENR_enuTIM3EN,
     	RCC_APB1ENR_enuTIM4EN,
     	RCC_APB1ENR_enuTIM5EN,
     	RCC_APB1ENR_enuReserved00,
     	RCC_APB1ENR_enuReserved01,
     	RCC_APB1ENR_enuReserved02,
     	RCC_APB1ENR_enuReserved03,
     	RCC_APB1ENR_enuReserved04,
     	RCC_APB1ENR_enuReserved05,
     	RCC_APB1ENR_enuReserved06,
     	RCC_APB1ENR_enuWWDGEN,
     	RCC_APB1ENR_enuReserved07,
     	RCC_APB1ENR_enuReserved08,
     	RCC_APB1ENR_enuSPI2EN,
     	RCC_APB1ENR_enuSPI3EN,
     	RCC_APB1ENR_enuReserved09,
     	RCC_APB1ENR_enuUSART2EN,
     	RCC_APB1ENR_enuReserved10,
     	RCC_APB1ENR_enuReserved11,
     	RCC_APB1ENR_enuReserved12,
     	RCC_APB1ENR_enuI2C1EN,
     	RCC_APB1ENR_enuI2C2EN,
     	RCC_APB1ENR_enuI2C3EN,
     	RCC_APB1ENR_enuReserved13,
     	RCC_APB1ENR_enuReserved14,
     	RCC_APB1ENR_enuReserved15,
     	RCC_APB1ENR_enuReserved16,
     	RCC_APB1ENR_enuPWREN,
     	RCC_APB1ENR_enuReserved17,
     	RCC_APB1ENR_enuReserved18,
     	RCC_APB1ENR_enuReserved19
     }RCC_APB1ENR_Bits_t;

     typedef enum{
     	RCC_APB2ENR_enuTIM1EN=0,
     	RCC_APB2ENR_enuReserved00,
     	RCC_APB2ENR_enuReserved01,
     	RCC_APB2ENR_enuReserved02,
     	RCC_APB2ENR_enuUSART1EN,
     	RCC_APB2ENR_enuUSART6EN,
     	RCC_APB2ENR_enuReserved03,
     	RCC_APB2ENR_enuReserved04,
     	RCC_APB2ENR_enuADC1EN,
     	RCC_APB2ENR_enuReserved05,
     	RCC_APB2ENR_enuReserved06,
     	RCC_APB2ENR_enuSDIOEN,
     	RCC_APB2ENR_enuSPI1EN,
     	RCC_APB2ENR_enuSPI4EN,
     	RCC_APB2ENR_enuSYSCFGEN,
     	RCC_APB2ENR_enuReserved07,
     	RCC_APB2ENR_enuTIM9EN,
     	RCC_APB2ENR_enuTIM10EN,
     	RCC_APB2ENR_enuTIM11EN,
     	RCC_APB2ENR_enuReserved08,
     	RCC_APB2ENR_enuReserved09,
     	RCC_APB2ENR_enuReserved10,
     	RCC_APB2ENR_enuReserved11,
     	RCC_APB2ENR_enuReserved12,
     	RCC_APB2ENR_enuReserved13,
     	RCC_APB2ENR_enuReserved14,
     	RCC_APB2ENR_enuReserved15,
     	RCC_APB2ENR_enuReserved16,
     	RCC_APB2ENR_enuReserved17,
     	RCC_APB2ENR_enuReserved18,
     	RCC_APB2ENR_enuReserved19,
     	RCC_APB2ENR_enuReserved20
     }RCC_APB2ENR_Bits_t;



RCC_enuErrorStatus_t RCC_EnableClk(RCC_Clock_t Clock,  RCC_CSS_State_t CSS);
RCC_enuErrorStatus_t RCC_DisableClk(RCC_Clock_t Clock);
RCC_enuErrorStatus_t RCC_SelectSysClk(RCC_Clock_t SysClock);
RCC_enuErrorStatus_t RCC_ConfigurePLL(u32 PLLSRC, u32 PLLM, u32 PLLN, u32 PLLP,u32 PLLQ );
RCC_enuErrorStatus_t RCC_ControlPeripheral(u8 BusID, RCC_AHB1ENR_Bits_t Peripheral,u8 state);
RCC_enuErrorStatus_t RCC_ConfigurePresc(u8 Presacaler_Type, u8 Division_Factor);

#endif







