/*
 * LCD.h
 *
 *  Created on: Jul 4, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_

#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "LCD_Config.h"

typedef struct{
	EN_Port_t port;
	uint8_t RS;
	uint8_t RW;
	uint8_t En;
	uint8_t D[8];
}LCD_t;

void LCD_init(LCD_t* lcd);
void LCD_initWithConfig(LCD_t* lcd, LCD_Config_t* config);
void LCD_dataWrite(LCD_t* lcd, uint8_t data);
void LCD_commandWrite(LCD_t* lcd, uint8_t cmd);

/* LCD Commands */
#define LCD_CLR_DISPLAY		0x01
#define LCD_RETURN_HOME		0x02
#define LCD_SECOND_LINE		0xC0
#define LCD_FIRST_LINE		0x80

#endif /* LCD_LCD_INTERFACE_H_ */
