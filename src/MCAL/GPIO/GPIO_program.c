/***************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							       */
/*File Name   : GPIO_program.c                                             */
/*Layer 	  : MCAL									  		           */
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
			GPIOA -> MODER &= ~(0b11 << (Copy_u8PinID * 2));
			GPIOA -> MODER |= (0b01 << (Copy_u8PinID * 2));

			/* Set Speed of The Output Pin */
			/* Bit Masking */
			GPIOA -> OSPEEDR &= ~(0b11 << (Copy_u8PinID * 2));
			GPIOA -> OSPEEDR |= (Copy_u8PinSpeed << (Copy_u8PinID * 2));

			/* Set Type of Output Pin*/
			WRT_BIT(GPIOA -> OTYPER , Copy_u8PinID , Copy_u8PinType);

			break;

		case GPIO_PORTB :

			/* Set Direction of The Pin to be Output */
			/* Bit Masking */
			GPIOB -> MODER &= ~(0b11 << (Copy_u8PinID * 2));
			GPIOB -> MODER |= (0b01 << (Copy_u8PinID * 2));

			/* Set Speed of The Output Pin */
			/* Bit Masking */
			GPIOB -> OSPEEDR &= ~(0b11 << (Copy_u8PinID * 2));
			GPIOB -> OSPEEDR |= (Copy_u8PinSpeed << (Copy_u8PinID * 2));

			/* Set Type of Output Pin*/
			WRT_BIT(GPIOB -> OTYPER , Copy_u8PinID , Copy_u8PinType);

			break;

		case GPIO_PORTC :

			/* Set Direction of The Pin to be Output */
			/* Bit Masking */
			GPIOC -> MODER &= ~(0b11 << (Copy_u8PinID * 2));
			GPIOC -> MODER |= (0b01 << (Copy_u8PinID * 2));

			/* Set Speed of The Output Pin */
			/* Bit Masking */
			GPIOC -> OSPEEDR &= ~(0b11 << (Copy_u8PinID * 2));
			GPIOC -> OSPEEDR |= (Copy_u8PinSpeed << (Copy_u8PinID * 2));

			/* Set Type of Output Pin*/
			WRT_BIT(GPIOC -> OTYPER , Copy_u8PinID , Copy_u8PinType);

			break;
	}
}

void GPIO_voidInitInputPin(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PullMode)
{
	switch(Copy_u8PortID)
	{
		case GPIO_PORTA :

			/* Set Direction of The Pin to be Input */
			/* Bit Masking */
			GPIOA -> MODER &= ~(0b11 << (Copy_u8PinID * 2));

			/* Set Mode of The Input Pin */
			/* Bit Masking */
			GPIOA -> PUPDR &= ~(0b11 << (Copy_u8PinID * 2));
			GPIOA -> PUPDR |= (Copy_u8PullMode << (Copy_u8PinID * 2));

			break;

		case GPIO_PORTB :

			/* Set Direction of The Pin to be Input */
			/* Bit Masking */
			GPIOB -> MODER &= ~(0b11 << (Copy_u8PinID * 2));

			/* Set Mode of The Input Pin */
			/* Bit Masking */
			GPIOB -> PUPDR &= ~(0b11 << (Copy_u8PinID * 2));
			GPIOB -> PUPDR |= (Copy_u8PullMode << (Copy_u8PinID * 2));

			break;

		case GPIO_PORTC :
			/* Set Direction of The Pin to be Input */
			/* Bit Masking */
			GPIOC -> MODER &= ~(0b11 << (Copy_u8PinID * 2));

			/* Set Mode of The Input Pin */
			/* Bit Masking */
			GPIOC -> PUPDR &= ~(0b11 << (Copy_u8PinID * 2));
			GPIOC -> PUPDR |= (Copy_u8PullMode << (Copy_u8PinID * 2));

			break;
	}
}

void GPIO_voidSetOutputPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value)
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
	u8 Local_u8PinValue = 0;

	switch(Copy_u8PortID)
	{
		case GPIO_PORTA :

			Local_u8PinValue = GET_BIT(GPIOA -> IDR , Copy_u8PinID);
			break;

		case GPIO_PORTB :

			Local_u8PinValue = GET_BIT(GPIOB -> IDR , Copy_u8PinID);
			break;

		case GPIO_PORTC :

			Local_u8PinValue = GET_BIT(GPIOC -> IDR , Copy_u8PinID);
			break;
	}

	return Local_u8PinValue;
}

void GPIO_voidSetOutputPinValueFast(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value)
{
	u32 Local_u32RegisterValue = 0;

	switch(Copy_u8PortID)
	{
		case GPIO_PORTA :

			switch(Copy_u8Value)
			{
				/* Set Pin Value  */
				/* Accessing Bits From 0 to 15 */
				case GPIO_OUTPUT_HIGH :

					Local_u32RegisterValue = 1 << Copy_u8PinID;
					break;

				/* Reset Pin Value */
				/* Accessing Bits From 16 to 31 */
				case GPIO_OUTPUT_LOW :

					Local_u32RegisterValue = 1 << (Copy_u8PinID + 16);
					break;
			}

			GPIOA -> BSRR = Local_u32RegisterValue;
			break;

		case GPIO_PORTB :

			switch(Copy_u8Value)
			{
				/* Set Pin Value  */
				/* Accessing Bits From 0 to 15 */
				case GPIO_OUTPUT_HIGH :

					Local_u32RegisterValue = 1 << Copy_u8PinID;
					break;

				/* Reset Pin Value */
				/* Accessing Bits From 16 to 31 */
				case GPIO_OUTPUT_LOW :

					Local_u32RegisterValue = 1 << (Copy_u8PinID + 16);
					break;
			}

			GPIOB -> BSRR = Local_u32RegisterValue;
			break;

		case GPIO_PORTC :

			switch(Copy_u8Value)
			{
				/* Set Pin Value  */
				/* Accessing Bits From 0 to 15 */
				case GPIO_OUTPUT_HIGH :

					Local_u32RegisterValue = 1 << Copy_u8PinID;
					break;

				/* Reset Pin Value */
				/* Accessing Bits From 16 to 31 */
				case GPIO_OUTPUT_LOW :

					Local_u32RegisterValue = 1 << (Copy_u8PinID + 16);
					break;
			}

			GPIOC -> BSRR = Local_u32RegisterValue;
			break;
	}
}

void GPIO_voidInitOutputPort(u8 Copy_u8PortID , u16 Copy_u16PortType , u32 Copy_u32PortSpeed)
{
	switch(Copy_u8PortID)
	{
		case GPIO_PORTA :

			/* Set Direction of The Port to be Output */
			GPIOA -> MODER = 0b01010101010101010101010101010101;

			/* Set Speed of The Output Port */
			GPIOA -> OSPEEDR = Copy_u32PortSpeed;

			/* Set Type of Output Port*/
			GPIOA -> OTYPER = Copy_u16PortType;

			break;

		case GPIO_PORTB :

			/* Set Direction of The Port to be Output */
			GPIOB -> MODER = 0b01010101010101010101010101010101;

			/* Set Speed of The Output Port */
			GPIOB -> OSPEEDR = Copy_u32PortSpeed;

			/* Set Type of Output Port*/
			GPIOB -> OTYPER = Copy_u16PortType;

			break;

		case GPIO_PORTC :

			/* Set Direction of The Port to be Output */
			GPIOC -> MODER = 0b01010101010101010101010101010101;

			/* Set Speed of The Output Port */
			GPIOC -> OSPEEDR = Copy_u32PortSpeed;

			/* Set Type of Output Port*/
			GPIOC -> OTYPER = Copy_u16PortType;

			break;
	}
}

void GPIO_voidSetOutputPortValue(u8 Copy_u8PortID , u16 Copy_u16PortValue)
{
	switch(Copy_u8PortID)
	{
		case GPIO_PORTA :
			GPIOA -> ODR = Copy_u16PortValue;
			break;

		case GPIO_PORTB :
			GPIOB -> ODR = Copy_u16PortValue;
			break;

		case GPIO_PORTC :
			GPIOC -> ODR = Copy_u16PortValue;
			break;
	}
}

void GPIO_voidSetPinAlternativeFunction(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8AlternativeFunction)
{
	switch(Copy_u8PortID)
	{
		case GPIO_PORTA :

			/* Set Mode of The Pin to be Alternative Function */
			/* Bit Masking */
			GPIOA -> MODER &= ~(0b11 << (Copy_u8PinID * 2));
			GPIOA -> MODER |= (0b10 << (Copy_u8PinID * 2));

			if(Copy_u8PinID < 8)
			{
				GPIOA -> AFRL &= ~(0b1111 << (Copy_u8PinID * 4));
				GPIOA -> AFRL |= (Copy_u8AlternativeFunction << (Copy_u8PinID * 4));
			}
			else if(Copy_u8PinID >= 8 && Copy_u8PinID < 16)
			{
				GPIOA -> AFRH &= ~(0b1111 << (Copy_u8PinID * 4));
				GPIOA -> AFRH |= (Copy_u8AlternativeFunction << (Copy_u8PinID * 4));
			}

			break;

		case GPIO_PORTB :

			/* Set Mode of The Pin to be Alternative Function */
			/* Bit Masking */
			GPIOB -> MODER &= ~(0b11 << (Copy_u8PinID * 2));
			GPIOB -> MODER |= (0b10 << (Copy_u8PinID * 2));

			if(Copy_u8PinID < 8)
			{
				GPIOB -> AFRL &= ~(0b1111 << (Copy_u8PinID * 4));
				GPIOB -> AFRL |= (Copy_u8AlternativeFunction << (Copy_u8PinID * 4));
			}
			else if(Copy_u8PinID >= 8 && Copy_u8PinID < 16)
			{
				GPIOB -> AFRH &= ~(0b1111 << (Copy_u8PinID * 4));
				GPIOB -> AFRH |= (Copy_u8AlternativeFunction << (Copy_u8PinID * 4));
			}

			break;

		case GPIO_PORTC :

			/* Set Mode of The Pin to be Alternative Function */
			/* Bit Masking */
			GPIOC -> MODER &= ~(0b11 << (Copy_u8PinID * 2));
			GPIOC -> MODER |= (0b10 << (Copy_u8PinID * 2));

			if(Copy_u8PinID < 8)
			{
				GPIOC -> AFRL &= ~(0b1111 << (Copy_u8PinID * 4));
				GPIOC -> AFRL |= (Copy_u8AlternativeFunction << (Copy_u8PinID * 4));
			}
			else if(Copy_u8PinID >= 8 && Copy_u8PinID < 16)
			{
				GPIOC -> AFRH &= ~(0b1111 << (Copy_u8PinID * 4));
				GPIOC -> AFRH |= (Copy_u8AlternativeFunction << (Copy_u8PinID * 4));
			}

			break;
	}
}

void GPIO_voidToggleOutputPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
	switch(Copy_u8PortID)
	{
		case GPIO_PORTA :

			TGL_BIT(GPIOA -> ODR , Copy_u8PinID);
			break;

		case GPIO_PORTB :

			TGL_BIT(GPIOB -> ODR , Copy_u8PinID);
			break;

		case GPIO_PORTC :

			TGL_BIT(GPIOC -> ODR , Copy_u8PinID);
			break;
	}
}
