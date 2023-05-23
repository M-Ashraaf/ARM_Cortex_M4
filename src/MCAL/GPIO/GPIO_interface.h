/**************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							      */
/*File Name   : GPIO_interface.h                                          */
/*Layer       : MCAL										 		      */
/*Description : This file contains interfacing parameters of GPIO module  */
/*Date        : 11 May 2023     	                                      */
/**************************************************************************/

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

/* Microcontroller's Ports */
#define GPIO_PORTA		1
#define GPIO_PORTB		2
#define GPIO_PORTC		3

/* Microcontroller's Pins */
#define	GPIO_PIN0		0
#define	GPIO_PIN1		1
#define	GPIO_PIN2		2
#define	GPIO_PIN3		3
#define	GPIO_PIN4		4
#define	GPIO_PIN5		5
#define	GPIO_PIN6		6
#define	GPIO_PIN7		7
#define	GPIO_PIN8		8
#define	GPIO_PIN9		9
#define	GPIO_PIN10		10
#define	GPIO_PIN11		11
#define	GPIO_PIN12		12
#define	GPIO_PIN13		13
#define	GPIO_PIN14		14
#define	GPIO_PIN15		15

/* Output Pin Types */
#define GPIO_PIN_PUSH_PULL		0
#define GPIO_PIN_OPEN_DRAIN		1

/* Output Port Types */
#define GPIO_PORT_PUSH_PULL		0
#define GPIO_PORT_OPEN_DRAIN	65535

/* Output Pin Speeds */
#define GPIO_PIN_LOW_SPEED				0
#define GPIO_PIN_MED_SPEED				1
#define GPIO_PIN_HIGH_SPEED				2
#define GPIO_PIN_VERY_HIGH_SPEED		3

/* Output Port Speeds */
#define GPIO_PORT_LOW_SPEED				0
#define GPIO_PORT_MED_SPEED				1431655765
#define GPIO_PORT_HIGH_SPEED			2863311530
#define GPIO_PORT_VERY_HIGH_SPEED		4294967295

/* Output Pin Values */
#define GPIO_OUTPUT_HIGH		1
#define GPIO_OUTPUT_LOW			0

/* Input Pin Pull Modes */
#define GPIO_INPUT_FLOAT		0
#define GPIO_INPUT_PULL_UP		1
#define GPIO_INPUT_PULL_DOWN	2

/* Pin Alternative Functions */
#define	GPIO_AF0	0
#define	GPIO_AF1	1
#define	GPIO_AF2	2
#define	GPIO_AF3	3
#define	GPIO_AF4	4
#define	GPIO_AF5	5
#define	GPIO_AF6	6
#define	GPIO_AF7	7
#define	GPIO_AF8	8
#define	GPIO_AF9	9
#define	GPIO_AF10	10
#define	GPIO_AF11	11
#define	GPIO_AF12	12
#define	GPIO_AF13	13
#define	GPIO_AF14	14
#define	GPIO_AF15	15

/* This Function is to Initialize Any Pin to be an Output Pin */
void GPIO_voidInitOutputPin(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinType , u8 Copy_u8PinSpeed);

/* This Function is to initialize Any Pin to be an Input Pin */
void GPIO_voidInitInputPin(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PullMode);

/* This Function is to Set The Value of Any Output Pin (High-Low) */
void GPIO_voidSetOutputPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value);

/* This Function is to Get The Value of Any Input Pin */
u8 GPIO_u8GetInputPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID);

/* This Function is to Set The Value of Any Output Pin (High-Low) Fast */
void GPIO_voidSetOutputPinValueFast(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value);

/* This Function is to Initialize Any Port to be an Output Port */
void GPIO_voidInitOutputPort(u8 Copy_u8PortID , u16 Copy_u16PortType , u32 Copy_u32PortSpeed);

/* This Function is to Set The Value of Any Output Port (High-Low) */
void GPIO_voidSetOutputPortValue(u8 Copy_u8PortID , u16 Copy_u16PortValue);

/* This Function is to Set Alternative Function of Any Pin */
void GPIO_voidSetPinAlternativeFunction(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8AlternativeFunction);

/* This Function is to Toggle The Value of Any Output Pin */
void GPIO_voidToggleOutputPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
