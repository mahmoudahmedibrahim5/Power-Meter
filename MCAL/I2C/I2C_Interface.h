/*
 * I2C_Interface.h
 *
 *  Created on: Jun 22, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef I2C_I2C_INTERFACE_H_
#define I2C_I2C_INTERFACE_H_

#include "../../Std Libraries/stm32f401xx.h"
#include "../GPIO/GPIO_Interface.h"
#include "../NVIC/NVIC_Interface.h"
#include "I2C_Registers.h"
#include "I2C_Config.h"

void I2C_init(st_I2C_RegDef_t* I2Cn, I2C_Config_t* config);
void I2C_configurePins(st_I2C_RegDef_t* I2Cn);
void I2C_reset(st_I2C_RegDef_t* I2Cn);

/* Repeated Start */
#define I2C_RS_DISABLE	0
#define I2C_RS_ENABLE	1

/* Master Polling Functions */
void I2C_masterSendData(st_I2C_RegDef_t* I2Cn, uint8_t address, uint8_t* data, uint32_t len, uint8_t repeatedStart);
void I2C_masterReceiveData(st_I2C_RegDef_t* I2Cn,  uint8_t address, uint8_t* data, uint32_t len, uint8_t repeatedStart);

/* Interrupt Control */
#define I2C_INT_DIS		0
#define I2C_INT_EN		1

/* Master Interrupt Functions */
void I2C_masterSendDataIT(st_I2C_RegDef_t* I2Cn, I2C_HandleIT_t* handle);
void I2C_masterReceiveDataIT(st_I2C_RegDef_t* I2Cn, I2C_HandleIT_t* handle);

/* Interrupt Functions */
void I2C_interruptControl(st_I2C_RegDef_t* I2Cn, uint8_t state);
void I2C_eventInterruptHandler(st_I2C_RegDef_t* I2Cn, I2C_HandleIT_t* handle);
void I2C_errorInterruptHandler(st_I2C_RegDef_t* I2Cn, I2C_HandleIT_t* handle);

/* Slave Functions */
void I2C_slaveSendData(st_I2C_RegDef_t* I2Cn, uint8_t data);
void I2C_slaveReceiveData(st_I2C_RegDef_t* I2Cn, uint8_t* data);
void I2C_slaveHandleCallBackFunction(st_I2C_RegDef_t* I2Cn, uint8_t state);

/* Events */
#define I2C_EVENT_RECEPTION_FINISHED 	0
#define I2C_EVENT_TRANSMISSION_FINISHED 1
#define I2C_EVENT_REQUEST_DATA 			2
#define I2C_EVENT_RECEIVE_DATA 			3

#endif /* I2C_I2C_INTERFACE_H_ */
