/*
 * GPIO_Registers.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef GPIO_GPIO_REGISTERS_H_
#define GPIO_GPIO_REGISTERS_H_

typedef struct{
	volatile uint32_t MODER;	// GPIO port mode register
	volatile uint32_t OTYPER;	// GPIO port output type register
	volatile uint32_t OSPEEDR;	// GPIO port output speed register
	volatile uint32_t PUPDR;	// GPIO port pull-up/pull-down register
	volatile uint32_t IDR;		// GPIO port input data register
	volatile uint32_t ODR;		// GPIO port output data register
	volatile uint32_t BSRR;		// GPIO port bit set/reset register
	volatile uint32_t LCKR;		// GPIO port configuration lock register
	volatile uint32_t AFRL;		// GPIO alternate function low register
	volatile uint32_t AFRH;		// GPIO alternate function high register
}st_GPIO_RegDef_t;



#define GPIOA		((st_GPIO_RegDef_t *)GPIOA_BASE_ADDR)
#define GPIOB		((st_GPIO_RegDef_t *)GPIOB_BASE_ADDR)
#define GPIOC		((st_GPIO_RegDef_t *)GPIOC_BASE_ADDR)
#define GPIOD		((st_GPIO_RegDef_t *)GPIOD_BASE_ADDR)
#define GPIOE		((st_GPIO_RegDef_t *)GPIOE_BASE_ADDR)
#define GPIOH		((st_GPIO_RegDef_t *)GPIOH_BASE_ADDR)

#endif /* GPIO_GPIO_REGISTERS_H_ */
