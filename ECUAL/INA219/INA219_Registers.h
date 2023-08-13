/*
 * INA219_Registers.h
 *
 *  Created on: Jul 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef INA219_INA219_REGISTERS_H_
#define INA219_INA219_REGISTERS_H_

/* Registers Addresses */
#define INA219_REG_CONFIGURAION		0x00
#define INA219_REG_SHUNT_VOLTAGE	0x01
#define INA219_REG_BUS_VOLTAGE		0x02
#define INA219_REG_POWER			0x03
#define INA219_REG_CURRENT			0x04
#define INA219_REG_CALIBRATION		0x05

/* Configuration Bits */
#define INA219_BIT_MODE		0
#define INA219_BIT_SADC		3
#define INA219_BIT_BADC		7
#define INA219_BIT_PGA		11
#define INA219_BIT_BRNG		13
#define INA219_BIT_RESET	15
/* Bus Voltage Bits */
#define INA219_BIT_OVF		0
#define INA219_BIT_CNVR		1

#endif /* INA219_INA219_REGISTERS_H_ */
