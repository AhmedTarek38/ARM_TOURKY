#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#include "LIB/STD_TYPES.h"

/*src bit for pll config*/
#define PLL_HSI 0
#define PLL_HSE 1

#define LOW_SPEED_PRESCALER_PPRE1    0
#define HIGH_SPEED_PRESCALER_PPRE2   1
#define AHB_PRESCALER                3


#define AHB_NO_DIVISION       0x00000000
#define AHB_DIVISION_BY_2     0x00000004
#define AHB_DIVISION_BY_4     0x00000005
#define AHB_DIVISION_BY_8     0x00000006
#define AHB_DIVISION_BY_16    0x00000007
#define AHB_DIVISION_BY_64    0x0000000C
#define AHB_DIVISION_BY_128   0x0000000D
#define AHB_DIVISION_BY_256   0x0000000E
#define AHB_DIVISION_BY_512   0x0000000F

#define AHB_PRE  4
#define PPRE1   10
#define PPRE2   13


/*enable HSI with 0 trimming with no css*/
#define HSION_MASK_CSSOFF 0x00000001
/*enable HSE_crystal with noByPass*/
#define HSEON_CRYSTAL_MASK_CSSOFF 0x00010000
/*enable HSE_RC with ByPass*/
#define HSEON_RC_MASK_CSSOFF 0x00050000
/*Enabe PLL*/
#define PLLON_MASK_CSSOFF 0x01000000

/*enable HSI with 0 trimming*/
#define HSION_MASK_CSSON 0x00080001
/*enable HSE_crystal with noByPass*/
#define HSEON_CRYSTAL_MASK_CSSON 0x00090000
/*enable HSE_RC with ByPass*/
#define HSEON_RC_MASK_CSSON 0x000D0000
/*Enabe PLL*/
#define PLLON_MASK_CSSON 0x01080000



/*choosing the systemclock*/
#define SW_HSI_MASK  0x00000000
#define SW_HSE_MASK  0x00000001
#define SW_PLL_MASK  0x00000002

/*busesnames*/
#define RCC_AHB1  0
#define RCC_AHB2  1
#define RCC_APB1  2
#define RCC_APB2  3

/*register defintions */

#define PERI_BASE_ADD      (0x40023800)

#define PLLM_ 0
#define PLLN_ 6
#define PLLP_ 16
#define PLLQ_ 24

#define        DMA2     22    //AHB1
#define        DMA1     21    //AHB1
#define        CRC      12    //AHB1
#define        GPIOH    7     //AHB1
#define        GPIOE    4     //AHB1
#define        GPIOD    3     //AHB1
#define        GPIOC    2     //AHB1
#define        GPIOB    1     //AHB1
#define        GPIOA    0     //AHB1

#define        USB      7     //AHB2

#define        PWR      28    //APB1
#define        I2C3     23    //APB1
#define        I2C2     22    //APB1
#define        I2C1     21    //APB1
#define        USART2   17    //APB1
#define        SPI3     15    //APB1
#define        SPI2     14    //APB1
#define        WWDG     11    //APB1
#define        TIM5     3     //APB1
#define        TIM4     2     //APB1
#define        TIM3     1     //APB1
#define        TIM2     0     //APB1

#define        TIM11    18   //APB2
#define        TIM10    17   //APB2
#define        TIM9     16   //APB2
#define        SYSCFG   14   //APB2
#define        SPI4     13   //APB2
#define        SPI1     12   //APB2
#define        SDIO     11   //APB2
#define        ADC1     8    //APB2
#define        USART6   5    //APB2
#define        USART1   4    //APB2
#define        TIM1     0    //APB2


typedef struct {
	u32 RCC_CR;
	u32 RCC_PLLCFGR;
	u32 RCC_CFGR;
	u32 RCC_CIR;
	u32 RCC_AHB1RSTR;
	u32 RCC_AHB2RSTR;
	u32 RCC_RES1;
	u32 RCC_RES2;
	u32 RCC_APB1RSTR;
	u32 RCC_APB2RSTR;
	u32 RCC_RES3;
	u32 RCC_RES4;
	u32 RCC_AHB1ENR;
	u32 RCC_AHB2ENR;
	u32 RCC_RES5;
	u32 RCC_RES6;
	u32 RCC_APB1ENR;
	u32 RCC_APB2ENR;
	u32 RCC_RES7;
	u32 RCC_RES8;
	u32 RCC_AHB1LPENR;
	u32 RCC_AHB2LPENR;
	u32 RCC_RES9;
	u32 RCC_RES10;
	u32 RCC_APB1LPENR;
	u32 RCC_APB2LPENR;
	u32 RCC_RES11;
	u32 RCC_RES12;
	u32 RCC_BDCR;
	u32 RCC_CSR;
	u32 RCC_RES13;
	u32 RCC_RES14;
	u32 RCC_SSCGR;
	u32 RCC_PLLI2SCFGR;
	u32 RCC_RES15;
	u32 RCC_DCKCFGR;
}Peri_t;

static Peri_t *rcc = (Peri_t*)PERI_BASE_ADD;


#endif
