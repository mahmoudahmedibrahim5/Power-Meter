<div align="center">
  
  # Power-Meter with a protection mode

</div>

<br>

## Features
- Reading Bus Voltage, Current and power.
- Switch the unit automatically (micro, milli, and real unit)
- Set maximum value for each reading.
- LEDs and buzzer to indicate if the reading exceeds the maximum value.

<br>

## Implementation
This is a Layered Architecture Embedded C program where everything is written from scratch. You can find more details in the documentation.

## MCAL Layer
RCC, GPIO, TIMERS, USART, I2C

## ECUAL Layer
INA219, Bluetooth Module, LED

## Application Layer
The main functions of the program

<br>

## Testing
I've made a small circuit with a potentiometer to simulate the load to test the project.
You can find a video testing the project in this link 
https://www.linkedin.com/posts/mahmoud158699216_embeddedsystems-arm-stm32-activity-7104739210397384705-sLWA?utm_source=share&utm_medium=member_desktop
