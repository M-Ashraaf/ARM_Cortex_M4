/***************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							       */
/*File Name   : LED_program.c                                              */
/*Layer 	  : HAL										  		           */
/*Description : This file contains functions' implementation of LED module */
/*Date        : 18 May 2023	                                               */
/***************************************************************************/

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void LED_voidPinLedInit(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
	/* Initializing LED Connected Pin to be Output */
	GPIO_voidInitOutputPin(Copy_u8PortID , Copy_u8PinID , GPIO_PIN_PUSH_PULL , GPIO_PIN_LOW_SPEED);
}

void LED_voidPortLedInit(u8 Copy_u8PortID)
{
	/* Initializing LEDS Connected Port to be Output */
	GPIO_voidInitOutputPort(Copy_u8PortID , GPIO_PORT_PUSH_PULL , GPIO_PORT_LOW_SPEED);
}

void LED_voidLedOn(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
	/* Turning LED On */
	GPIO_voidSetOutputPinValue(Copy_u8PortID , Copy_u8PinID , GPIO_OUTPUT_HIGH);
}

void LED_voidLedOff(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
	/* Turning LED Off */
	GPIO_voidSetOutputPinValue(Copy_u8PortID , Copy_u8PinID , GPIO_OUTPUT_LOW);
}

void LED_voidToggleLed(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
	/* Toggling LED */
	GPIO_voidToggleOutputPinValue(Copy_u8PortID , Copy_u8PinID);
}
