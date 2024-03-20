/*
 * STM32F401CC.h
 *
 *  Created on: Mar 5, 2024
 *      Author: ahmed tarek
 */

#ifndef STM32F401CC_H_
#define STM32F401CC_H_

typedef enum
{
    WWDG_=0,
    EXTI16_PVD,
    EXTI21_TAMP_STAMP,
    EXTI22_RTC_WKUP,
    FLASH,
    RCC,
    EXTI0,
    EXTI1,
    EXTI2,
    EXTI3,
    EXTI4,
    DMA1_Stream0,
    DMA1_Stream1,
    DMA1_Stream2,
    DMA1_Stream3,
    DMA1_Stream4,
    DMA1_Stream5,
    DMA1_Stream6,
    ADC,
    EXTI9_5 = 23,
    TIM1_BRK_TIM9,
    TIM1_UP_TIM10,
    TIM1_TRG_COM_TIM11,
    TIM1_CC,
    TIM2_,
    TIM3_,
    TIM4_,
    I2C1_EV,
    I2C1_ER,
    I2C2_EV,
    I2C2_ER,
    SPI1_,
    SPI2_,
    USART1_,
    USART2_,
    EXTI15_10=40,
    EXTI17_RTC_Alarm,
    EXTI18_OTG_FS_WKUP,
    DMA1_Stream7=47,
    SDIO_=49,
    TIM5_,
    SPI3_,
    DMA2_Stream0=56,
    DMA2_Stream1,
    DMA2_Stream2,
    DMA2_Stream3,
    DMA2_Stream4,
    OTG_FS=67,
    DMA2_Stream5,
    DMA2_Stream6,
    DMA2_Stream7,
    USART6_,
    I2C3_EV,
    I2C3_ER,
    FPU_ = 81,
    SPI4_ = 84,
    _INT_Num
} IRQn_t;

#endif /* STM32F401CC_H_ */
