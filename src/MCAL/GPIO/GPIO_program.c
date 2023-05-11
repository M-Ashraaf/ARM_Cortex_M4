/***************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							       */
/*File Name   : GPIO_program.c                                             */
/*Bus 	      : AHB1									  		           */
/*Description : This file contains functions' implementation of GPIO module*/
/*Date        : 11 May 2023	                                               */
/***************************************************************************/

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidInitOutputPin(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinType , u8 Copy_u8PinSpeed)
{
	switch(Copy_u8PortID)
	{
		case GPIO_PORTA :

			/* Set Direction of The Pin to be Output */
			/* Bit Masking */
			GPIOA -> MODER  &= ~(0b11<<(Copy_u8PinID*2));
			GPIOA -> MODER |= (0b01<<(Copy_u8PinID*2));

			/* Set Speed of The Output Pin */
			/* Bit Masking */
			GPIOA -> OSPEEDR &= ~(0b11<<(Copy_u8PinID*2));
			GPIOA -> OSPEEDR |= (Copy_u8PinSpeed<<(Copy_u8PinID*2));

			/* Set Type of Output Pin*/
			WRT_BIT(GPIOA -> OTYPER , Copy_u8PinID , Copy_u8PinType);

			break;

		case GPIO_PORTB :

			/* Set Direction of The Pin to be Output */
			/* Bit Masking */
			GPIOB -> MODER  &= ~(0b11<<(Copy_u8PinID*2));
			GPIOB -> MODER |= (0b01<<(Copy_u8PinID*2));

			/* Set Speed of The Output Pin */
			/* Bit Masking */
			GPIOB -> OSPEEDR &= ~(0b11<<(Copy_u8PinID*2));
			GPIOB -> OSPEEDR |= (Copy_u8PinSpeed<<(Copy_u8PinID*2));

			/* Set Type of Output Pin*/
			WRT_BIT(GPIOB -> OTYPER , Copy_u8PinID , Copy_u8PinType);

			break;

		case GPIO_PORTC :

			/* Set Direction of The Pin to be Output */
			/* Bit Masking */
			GPIOC -> MODER  &= ~(0b11<<(Copy_u8PinID*2));
			GPIOC -> MODER |= (0b01<<(Copy_u8PinID*2));

			/* Set Speed of The Output Pin */
			/* Bit Masking */
			GPIOC -> OSPEEDR &= ~(0b11<<(Copy_u8PinID*2));
			GPIOC -> OSPEEDR |= (Copy_u8PinSpeed<<(Copy_u8PinID*2));

			/* Set Type of Output Pin*/
			WRT_BIT(GPIOC -> OTYPER , Copy_u8PinID , Copy_u8PinType);

			break;
	}
}

void GPIO_voidInitInputPin(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PullMode)
{

}

void GPIO_voidSetOutPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value)
{
	switch(Copy_u8PortID)
	{
		case GPIO_PORTA :
			WRT_BIT(GPIOA -> ODR , Copy_u8PinID , Copy_u8Value);
			break;

		case GPIO_PORTB :
			WRT_BIT(GPIOB -> ODR , Copy_u8PinID , Copy_u8Value);
			break;

		case GPIO_PORTC :
			WRT_BIT(GPIOC -> ODR , Copy_u8PinID , Copy_u8Value);
			break;
	}
}

u8 GPIO_u8GetInputPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID)
{

}
