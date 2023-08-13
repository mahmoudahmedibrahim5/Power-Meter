/*
 * APP.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef APP_H_
#define APP_H_

#include "FreeRTOS.h"
#include "task.h"

#include "../ECUAL/LED/LED.h"
#include "../ECUAL/Button/Button.h"
#include "../ECUAL/INA219/INA219_Interface.h"
#include "../ECUAL/BT_Module/BT.h"
#include "../ECUAL/LCD/LCD_Interface.h"
#include "../ECUAL/KeyPad/KEYPAD.h"
#include "../MCAL/TIMERS/TIMERS_Interface.h"

typedef struct{
	sint16_t ShuntVoltage;
	uint16_t BusVoltage;
	sint16_t Current;
	uint16_t Power;
}st_sensor_readings_t;

void System_init(void);
void createTasks(void);

void sensorTask(void* par);
void bluetoothTask(void* par);
void screenTask(void* par);

#endif /* APP_H_ */
