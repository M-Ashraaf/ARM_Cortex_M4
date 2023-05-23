/***************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							       */
/*File Name   : KPD_program.c                                              */
/*Layer 	  : HAL										  		           */
/*Description : This file contains functions' implementation of KPD module */
/*Date        : 23 May 2023	                                               */
/***************************************************************************/

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

/******************************************************************************/
/*************************Functions' implementation****************************/
/******************************************************************************/

void KPD_voidInit(void)
{
	/* Initialize All Rows to be Input Pull up */
	GPIO_voidInitInputPin(KPD_ROW0_PORT , KPD_ROW0_PIN , GPIO_INPUT_PULL_UP);
	GPIO_voidInitInputPin(KPD_ROW1_PORT , KPD_ROW1_PIN , GPIO_INPUT_PULL_UP);
	GPIO_voidInitInputPin(KPD_ROW2_PORT , KPD_ROW2_PIN , GPIO_INPUT_PULL_UP);
	GPIO_voidInitInputPin(KPD_ROW3_PORT , KPD_ROW3_PIN , GPIO_INPUT_PULL_UP);

	/* Initialize All Columns to be Output */
	GPIO_voidInitOutputPin(KPD_COL0_PORT , KPD_COL0_PIN , GPIO_PIN_PUSH_PULL , GPIO_PIN_LOW_SPEED);
	GPIO_voidInitOutputPin(KPD_COL1_PORT , KPD_COL1_PIN , GPIO_PIN_PUSH_PULL , GPIO_PIN_LOW_SPEED);
	GPIO_voidInitOutputPin(KPD_COL2_PORT , KPD_COL2_PIN , GPIO_PIN_PUSH_PULL , GPIO_PIN_LOW_SPEED);
	GPIO_voidInitOutputPin(KPD_COL3_PORT , KPD_COL3_PIN , GPIO_PIN_PUSH_PULL , GPIO_PIN_LOW_SPEED);

	/* Setting Columns to be High */
	GPIO_voidSetOutputPinValueFast(KPD_COL0_PORT , KPD_COL0_PIN , GPIO_OUTPUT_HIGH);
	GPIO_voidSetOutputPinValueFast(KPD_COL1_PORT , KPD_COL1_PIN , GPIO_OUTPUT_HIGH);
	GPIO_voidSetOutputPinValueFast(KPD_COL2_PORT , KPD_COL2_PIN , GPIO_OUTPUT_HIGH);
	GPIO_voidSetOutputPinValueFast(KPD_COL3_PORT , KPD_COL3_PIN , GPIO_OUTPUT_HIGH);
}

u8 KPD_u8GetPressedKey(void)
{
	/* Local Variable to Check Whether The Switch is Pressed or Not */
	u8 Local_u8KeyState;

	/* Local Variable to Store The Value of The Pressed Key */
	u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY;

	/* Local Variables to Iterate Over Rows & Columns */
	u8 Local_u8RowIterator;
	u8 Local_u8ColIterator;

	/* Rows & Columns Pins Arrays */
	u8 Local_au8RowsPins[KPD_ROW_NUM] = {KPD_ROW0_PIN , KPD_ROW1_PIN , KPD_ROW2_PIN , KPD_ROW3_PIN};
	u8 Local_au8ColsPins[KPD_COL_NUM] = {KPD_COL0_PIN , KPD_COL1_PIN , KPD_COL2_PIN , KPD_COL3_PIN};

	/* Rows & Columns Ports Arrays */
	u8 Local_au8RowsPorts[KPD_ROW_NUM] = {KPD_ROW0_PORT , KPD_ROW1_PORT , KPD_ROW2_PORT , KPD_ROW3_PORT};
	u8 Local_au8ColsPorts[KPD_COL_NUM] = {KPD_COL0_PORT , KPD_COL1_PORT , KPD_COL2_PORT , KPD_COL3_PORT};

	/* KPD 2D Array */
	u8 Local_au8KPD[KPD_ROW_NUM][KPD_COL_NUM] = KPD_VALUES;

	/* Looping Over Columns to Activate Them */
	for(Local_u8ColIterator = 0 ; Local_u8ColIterator < KPD_COL_NUM ; Local_u8ColIterator++)
	{
		/* Activate Column by Column */
		GPIO_voidSetOutputPinValueFast(Local_au8ColsPorts[Local_u8ColIterator] , Local_au8ColsPins[Local_u8ColIterator] , GPIO_OUTPUT_LOW);

		/* Looping Over Rows to Read Them */
		for(Local_u8RowIterator = 0 ; Local_u8RowIterator < KPD_ROW_NUM ; Local_u8RowIterator++)
		{
			/* Checking Whether Any Switch is Pressed or Not */
			Local_u8KeyState = GPIO_u8GetInputPinValue(Local_au8RowsPorts[Local_u8RowIterator] , Local_au8RowsPins[Local_u8RowIterator]);

			/* In Case of a Key is Pressed */
			if(Local_u8KeyState == 0)
			{
				/* Getting The Value of The Pressed Key */
				Local_u8PressedKey = Local_au8KPD[Local_u8RowIterator][Local_u8ColIterator];

				/* Polling Till The User Releases The Switch */
				while(Local_u8KeyState == 0)
				{
					/* Getting Key State */
					Local_u8KeyState = GPIO_u8GetInputPinValue(Local_au8RowsPorts[Local_u8RowIterator] , Local_au8RowsPins[Local_u8RowIterator]);
				}

				/* Deactivate The Recent Column Before Return */
				GPIO_voidSetOutputPinValueFast(Local_au8ColsPorts[Local_u8ColIterator] , Local_au8ColsPins[Local_u8ColIterator] , GPIO_OUTPUT_HIGH);

				/* Ending The Loop */
				return Local_u8PressedKey;
			}
		}

		/* Deactivate Column by Column */
		GPIO_voidSetOutputPinValueFast(Local_au8ColsPorts[Local_u8ColIterator] , Local_au8ColsPins[Local_u8ColIterator] , GPIO_OUTPUT_HIGH);
	}

	/* Returning Pressed Key */
	return Local_u8PressedKey;
}
