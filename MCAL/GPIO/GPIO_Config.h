/*
 * GPIO_Config.h
 *
 *  Created on: Jul 1, 2023
 *      Author: ADMIN
 */

#ifndef GPIO_GPIO_CONFIG_H_
#define GPIO_GPIO_CONFIG_H_

typedef struct{
	uint8_t mode;		// pin modes
	uint8_t outType;	// Output types
	uint8_t speed;		// speed levels
	uint8_t pupdState;	// Pull up pull down states
	uint8_t AltFuncMode;// Alternate functions modes
}GPIO_Config_t;

/* pin modes */
#define IN	 			0
#define OUT	 			1
#define ALT_FN 			2
#define ANALOG 			3
/* Output types */
#define PUSH_PULL		0
#define OPEN_DRAIN		1
/* Speed levels */
#define LOW_SPEED		0
#define MEDUIM_SPEED	1
#define HIGH_SPEED		2
#define VERY_HIGH_SPEED	3
/* Pull up pull down states */
#define NO_PUPD 		0
#define PULL_UP 		1
#define PULL_DOWN		2
/* Alternate functions modes */
typedef enum{
	AF0,AF1,AF2,AF3,AF4,AF5,AF6,AF7,AF8,AF9,AF10,AF11,AF12,AF13,AF14,AF15
}EN_AlternateFunctions_t;

#endif /* GPIO_GPIO_CONFIG_H_ */
