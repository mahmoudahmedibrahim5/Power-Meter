/*
 * INA219_Config.h
 *
 *  Created on: Jul 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef INA219_INA219_CONFIG_H_
#define INA219_INA219_CONFIG_H_

/*********** INA219 Address *************
 * Check Table 1 page 14 in the datasheet
 * There are many addresses depends on A0 and A1 connections
 * If A0 and A1 connected to ground Address = 0x40
 * */

typedef struct{
	st_I2C_RegDef_t* I2Cn;
	u8 slaveAddress;
}INA219_t;

#define INA219_SHUNT_RESISTANCE		100	// mΩ
#define INA219_MAX_CURRENT			250 // mA

#endif /* INA219_INA219_CONFIG_H_ */
