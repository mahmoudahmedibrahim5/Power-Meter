/*
 * APP.h
 *
 *  Created on: Sep 1, 2023
 *      Author: Mahmoud Ahmed
 */

#ifndef APP_H_
#define APP_H_

#include "../ECUAL/INA219/INA219_Interface.h"
#include "../ECUAL/TFT-LCD/TFT_Interface.h"
#include "../ECUAL/BT_Module/BT_Interface.h"
#include "../ECUAL/Button/Button_Interface.h"
#include "../ECUAL/LED/LED_Interface.h"

#include "../MCAL/RCC/RCC_Interface.h"
#include "../MCAL/TIMERS/TIMERS_Interface.h"

typedef struct{
	u16 BusVolage;
	u16 Power;
	s16 Current;
}ST_SensorReading_t;

typedef enum{
	POWER,
	VOLT,
	CURRENT
}EN_Message_t;

void APP_voidInit(void);

void APP_voidSensorRead(void);
void APP_voidScreenPrint(EN_Message_t msg);
void APP_voidCheckInput(void);
void APP_voidBluetoothSend();


#endif /* APP_H_ */
