/**************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							      */
/*File Name   : GPIO_interface.h                                          */
/*Bus         : AHB1										 		      */
/*Description : This file contains interfacing parameters of GPIO module  */
/*Date        : 11 May 2023     	                                      */
/**************************************************************************/

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

/* Microcontroller's Ports */
#define GPIO_PORTA		1
#define GPIO_PORTB		2
#define GPIO_PORTC		3

/* Output Pin Types */
#define GPIO_PUSH_PULL		0
#define GPIO_OPEN_DRAIN		1

/* Output Pin Speed */
#define GPIO_LOW_SPEED			0
#define GPIO_MED_SPEED			1
#define GPIO_HIGH_SPEED			2
#define GPIO_VERY_HIGH_SPEED	3

/* Output Pin Value */
#define GPIO_OUTPUT_HIGH		1
#define GPIO_OUTPUT_LOW			0

/* This Function is to Initialize any pin to be an Output Pin */
void GPIO_voidInitOutputPin(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinType , u8 Copy_u8PinSpeed);

/* This Function is to initialize any pin to be an Input Pin */
void GPIO_voidInitInputPin(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PullMode);

/* This Function is to Set The Value of Any Output Pin (High-Low) */
void GPIO_voidSetOutPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value);

/* This Function is to Get The Value of Any Input Pin */
u8 GPIO_u8GetInputPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
