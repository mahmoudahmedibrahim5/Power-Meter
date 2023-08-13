/*
 * LCD.c
 *
 *  Created on: Jul 4, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "LCD_Interface.h"

LCD_Config_t defaultConfig = {LCD_MODE_8, LCD_TWO_LINE, LCD_5_8, LCD_CURSOR_VISIBLE_NO_BLINKING, LCD_CURSOR_DIRECT};
static GPIO_Config_t pinConfig = {OUT, PUSH_PULL, LOW_SPEED};
static void LCD_delay(void);
static void LCD_sendData(LCD_t* lcd, uint8_t data);

static void LCD_delay(void)
{
	for(uint32_t i=0; i<5*1080; i++);
}

static void LCD_sendData(LCD_t* lcd, uint8_t data)
{
	uint8_t i;
	for(i=0; i<8; i++){
		GPIO_setPinValue(lcd->port, lcd->D[i], ((data & (1<<i))>>i));
	}
	GPIO_setPinValue(lcd->port, lcd->En, HIGH);
	LCD_delay();
	GPIO_setPinValue(lcd->port, lcd->En, LOW);
	LCD_delay();
}

void LCD_init(LCD_t* lcd)
{
	LCD_initWithConfig(lcd, &defaultConfig);
}

void LCD_initWithConfig(LCD_t* lcd, LCD_Config_t* config)
{
	uint8_t i, data;

	// Initialize LCD pins
	for(i=0; i<8; i++){
		GPIO_initPin(lcd->port, lcd->D[i], &pinConfig);
	}
	GPIO_initPin(lcd->port, lcd->En, &pinConfig);
	GPIO_initPin(lcd->port, lcd->RS, &pinConfig);
	GPIO_initPin(lcd->port, lcd->RW, &pinConfig);

	// Start Initializing
	GPIO_setPinValue(lcd->port, lcd->RS, LCD_REG_COMMAND);
	GPIO_setPinValue(lcd->port, lcd->RW, LCD_WRITE);


	// Send first instruction
	data = 0x30;
	if(config->mode != LCD_MODE_4)
		data |= (1<<4);
	if(config->lines != LCD_ONE_LINE)
		data |= (1<<3);
	if(config->resolution != LCD_5_11)
		data |= (1<<2);
	LCD_sendData(lcd, data);

	// Send Second instruction
	LCD_sendData(lcd, data);

	// Send third instruction
	data = 0x0C;
	if(config->cursor == LCD_CURSOR_VISIBLE_NO_BLINKING){
		data |= (1<<1);
	}
	else if(config->cursor == LCD_CURSOR_VISIBLE_BLINKINIG){
		data |= (1<<1);
		data |= (1<<0);
	}
	LCD_sendData(lcd, data);

	// Send Fourth instruction (clear display)
	LCD_sendData(lcd, 0x01);
	LCD_delay();

	// Send Fifth instruction (Entry mode set)
	data = 0x04;
	if(config->direction != LCD_CURSOR_DIRECT)
		data |= (1<<1);
	LCD_sendData(lcd, 0x01);

}

void LCD_dataWrite(LCD_t* lcd, uint8_t data)
{
	GPIO_setPinValue(lcd->port, lcd->RS, LCD_REG_DATA);
	GPIO_setPinValue(lcd->port, lcd->RW, LCD_WRITE);

	LCD_sendData(lcd, data);
}

void LCD_commandWrite(LCD_t* lcd, uint8_t cmd)
{
	GPIO_setPinValue(lcd->port, lcd->RS, LCD_REG_COMMAND);
	GPIO_setPinValue(lcd->port, lcd->RW, LCD_WRITE);

	LCD_sendData(lcd, cmd);
}
