/*
 * stm32f401xx.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef INC_STM32F401XX_H_
#define INC_STM32F401XX_H_

#include "DataTypes.h"

/* Base addresses of memory sections */
#define FLASH_BASE_ADDR					0x08000000U
#define SRAM1_BASE_ADDR					0x20000000U
#define SRAM							SRAM1_BASE_ADDR
#define ROM								0x1FFF0000U
#define OTP								0x1FFF7800U

/* Base addresses of memory buses */

#define APB1_BASE_ADDR					0x40000000U
#define APB2_BASE_ADDR					0x40010000U
#define AHB1_BASE_ADDR					0x40020000U
#define AHB2_BASE_ADDR					0x50000000U

/* Base addresses of peripherals */

/////////////////////////// AHB1 BUS /////////////////////////////
#define GPIOA_BASE_ADDR					(AHB1_BASE_ADDR + 0x0000U)
#define GPIOB_BASE_ADDR					(AHB1_BASE_ADDR + 0x0400U)
#define GPIOC_BASE_ADDR					(AHB1_BASE_ADDR + 0x0800U)
#define GPIOD_BASE_ADDR					(AHB1_BASE_ADDR + 0x0C00U)
#define GPIOE_BASE_ADDR					(AHB1_BASE_ADDR + 0x1000U)
#define GPIOH_BASE_ADDR					(AHB1_BASE_ADDR + 0x1C00U)

#define CRC_BASE_ADDR					(AHB1_BASE_ADDR + 0x3000U)
#define RCC_BASE_ADDR					(AHB1_BASE_ADDR + 0x3800U)

#define DMA1_BASE_ADDR					(AHB1_BASE_ADDR + 0x6000U)
#define DMA2_BASE_ADDR					(AHB1_BASE_ADDR + 0x6400U)

#define TIM2_BASE_ADDR					(APB1_BASE_ADDR + 0x0000U)
#define TIM3_BASE_ADDR					(APB1_BASE_ADDR + 0x0400U)
#define TIM4_BASE_ADDR					(APB1_BASE_ADDR + 0x0800U)
#define TIM5_BASE_ADDR					(APB1_BASE_ADDR + 0x0C00U)

/////////////////////////// AHB2 BUS /////////////////////////////
#define USB_OTG_FS						(AHB2_BASE_ADDR + 0x0000U)

/////////////////////////// APB1 BUS /////////////////////////////
#define TIM2_BASE_ADDR					(APB1_BASE_ADDR + 0x0000U)
#define TIM3_BASE_ADDR					(APB1_BASE_ADDR + 0x0400U)
#define TIM4_BASE_ADDR					(APB1_BASE_ADDR + 0x0800U)
#define TIM5_BASE_ADDR					(APB1_BASE_ADDR + 0x0C00U)

#define RTC_BASE_ADDR					(APB1_BASE_ADDR + 0x2800U)
#define WWDG_BASE_ADDR					(APB1_BASE_ADDR + 0x2C00U)
#define IWDG_BASE_ADDR					(APB1_BASE_ADDR + 0x3000U)
#define I2S2EXT_BASE_ADDR				(APB1_BASE_ADDR + 0x3400U)
#define SPI2_BASE_ADDR					(APB1_BASE_ADDR + 0x3800U)
#define I2S2_BASE_ADDR					SPI2_BASE_ADDR
#define SPI3_BASE_ADDR					(APB1_BASE_ADDR + 0x3C00U)
#define I2S3_BASE_ADDR					SPI3_BASE_ADDR
#define I2S3EXT_BASE_ADDR				(APB1_BASE_ADDR + 0x4000U)

#define USART2_BASE_ADDR 				(APB1_BASE_ADDR + 0x4400U)
#define I2C1_BASE_ADDR 					(APB1_BASE_ADDR + 0x5400U)
#define I2C2_BASE_ADDR 					(APB1_BASE_ADDR + 0x5800U)
#define I2C3_BASE_ADDR 					(APB1_BASE_ADDR + 0x5C00U)

#define PWR_BASE_ADDR 					(APB1_BASE_ADDR + 0x7000U)

/////////////////////////// APB2 BUS /////////////////////////////
#define TIM1_BASE_ADDR					(APB2_BASE_ADDR + 0x0000)
#define TIM8_BASE_ADDR					(APB2_BASE_ADDR + 0x0400)

#define USART1_BASE_ADDR				(APB2_BASE_ADDR + 0x1000)
#define USART6_BASE_ADDR				(APB2_BASE_ADDR + 0x1400)

#define ADC1_BASE_ADDR					(APB2_BASE_ADDR + 0x2000)
#define SDIO_BASE_ADDR					(APB2_BASE_ADDR + 0x2C00)
#define SPI1_BASE_ADDR					(APB2_BASE_ADDR + 0x3000)

#define SPI4_BASE_ADDR					(APB2_BASE_ADDR + 0x3400)
#define I2S4_BASE_ADDR					SPI4_BASE_ADDR

#define SYSCFG_BASE_ADDR				(APB2_BASE_ADDR + 0x3800)
#define EXTI_BASE_ADDR					(APB2_BASE_ADDR + 0x3C00)

#define TIM9_BASE_ADDR					(APB2_BASE_ADDR + 0x4000)
#define TIM10_BASE_ADDR					(APB2_BASE_ADDR + 0x4400)
#define TIM11_BASE_ADDR					(APB2_BASE_ADDR + 0x4800)

#endif /* INC_STM32F401XX_H_ */
