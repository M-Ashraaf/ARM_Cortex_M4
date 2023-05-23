/***************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							       */
/*File Name   : SSD_program.c                                              */
/*Layer 	  : HAL										  		           */
/*Description : This file contains functions' implementation of SSD module */
/*Date        : 18 May 2023	                                               */
/***************************************************************************/

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

void SSD_voidSSDInit(void)
{
	/* Initializing SSD Connected Pins to be Output */
	GPIO_voidInitOutputPin(SSD_PIN0_PORT , SSD_PIN0_PIN , GPIO_PIN_PUSH_PULL , GPIO_PIN_LOW_SPEED);
	GPIO_voidInitOutputPin(SSD_PIN1_PORT , SSD_PIN1_PIN , GPIO_PIN_PUSH_PULL , GPIO_PIN_LOW_SPEED);
	GPIO_voidInitOutputPin(SSD_PIN2_PORT , SSD_PIN2_PIN , GPIO_PIN_PUSH_PULL , GPIO_PIN_LOW_SPEED);
	GPIO_voidInitOutputPin(SSD_PIN3_PORT , SSD_PIN3_PIN , GPIO_PIN_PUSH_PULL , GPIO_PIN_LOW_SPEED);
	GPIO_voidInitOutputPin(SSD_PIN4_PORT , SSD_PIN4_PIN , GPIO_PIN_PUSH_PULL , GPIO_PIN_LOW_SPEED);
	GPIO_voidInitOutputPin(SSD_PIN5_PORT , SSD_PIN5_PIN , GPIO_PIN_PUSH_PULL , GPIO_PIN_LOW_SPEED);
	GPIO_voidInitOutputPin(SSD_PIN6_PORT , SSD_PIN6_PIN , GPIO_PIN_PUSH_PULL , GPIO_PIN_LOW_SPEED);
	GPIO_voidInitOutputPin(SSD_PIN7_PORT , SSD_PIN7_PIN , GPIO_PIN_PUSH_PULL , GPIO_PIN_LOW_SPEED);

	GPIO_voidInitOutputPin(SSD_COMMONPIN_PORT , SSD_COMMONPIN_PIN , GPIO_PIN_PUSH_PULL , GPIO_PIN_LOW_SPEED);
}

void SSD_voidSSDOn(u8 Copy_u8Connection)
{
	/* Turning SSD On Based on Connection (Common Anode , Common Cathode) */
	GPIO_voidSetOutputPinValue(SSD_COMMONPIN_PORT , SSD_COMMONPIN_PIN , Copy_u8Connection);
}

void SSD_voidSSDDisplayNumber(u8 Copy_u8Number)
{
	/* Displaying Number on SSD */
	GPIO_voidSetOutputPinValue(SSD_PIN0_PORT , SSD_PIN0_PIN , GET_BIT(Copy_u8Number , 0));
	GPIO_voidSetOutputPinValue(SSD_PIN1_PORT , SSD_PIN1_PIN , GET_BIT(Copy_u8Number , 1));
	GPIO_voidSetOutputPinValue(SSD_PIN2_PORT , SSD_PIN2_PIN , GET_BIT(Copy_u8Number , 2));
	GPIO_voidSetOutputPinValue(SSD_PIN3_PORT , SSD_PIN3_PIN , GET_BIT(Copy_u8Number , 3));
	GPIO_voidSetOutputPinValue(SSD_PIN4_PORT , SSD_PIN4_PIN , GET_BIT(Copy_u8Number , 4));
	GPIO_voidSetOutputPinValue(SSD_PIN5_PORT , SSD_PIN5_PIN , GET_BIT(Copy_u8Number , 5));
	GPIO_voidSetOutputPinValue(SSD_PIN6_PORT , SSD_PIN6_PIN , GET_BIT(Copy_u8Number , 6));
	GPIO_voidSetOutputPinValue(SSD_PIN7_PORT , SSD_PIN7_PIN , GET_BIT(Copy_u8Number , 7));
}

void SSD_voidSSDOff(u8 Copy_u8Connection)
{
	/* In Case of Common Cathode Connection */
	if(Copy_u8Connection == SSD_COMMON_CATHODE)
	{
		/* Turning SSD Off */
		GPIO_voidSetOutputPinValue(SSD_COMMONPIN_PORT , SSD_COMMONPIN_PIN , SSD_COMMON_ANODE);
	}

	/* In Case of Common Anode Connection */
	else if(Copy_u8Connection == SSD_COMMON_ANODE)
	{
		/* Turning SSD Off */
		GPIO_voidSetOutputPinValue(SSD_COMMONPIN_PORT , SSD_COMMONPIN_PIN , SSD_COMMON_CATHODE);
	}
}
