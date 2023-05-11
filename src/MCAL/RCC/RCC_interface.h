/**************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							      */
/*File Name   : RCC_interface.h                                           */
/*Bus         : AHB1										 		      */
/*Description : This file contains interfacing parameters of RCC module   */
/*Date        : 5 May 2023     	                                          */
/**************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/////////////////////////////////////////////////////////////////////////////Error State ENUM/////////////////////////////////////////////////////////////////////////////

typedef enum
{

	Ok,
	InvalidBusID,
	InvalidPeripheralID

}RCC_ErrorState_t;

/////////////////////////////////////////////////////////////////////////////Interfacing Macros/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////Available Controllers' Buses////////////////////////////////////////////////////////////////////////

#define	RCC_AHB1	1
#define RCC_AHB2	2
#define	RCC_APB1	3
#define	RCC_APB2	4

////////////////////////////////////////////////////////////////////////Available Buses' Peripherals////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////AHB1 Peripherals//////////////////////////////////////////////////////////////////////////////

#define AHB1_GPIOA 	0
#define AHB1_GPIOB 	1
#define AHB1_GPIOC 	2
#define AHB1_GPIOD 	3
#define AHB1_GPIOE 	4

#define AHB1_GPIOH 	7

#define AHB1_CRC	12

#define AHB1_DMA1	21
#define AHB1_DMA2	22

//////////////////////////////////////////////////////////////////////////////AHB2 Peripherals//////////////////////////////////////////////////////////////////////////////

#define AHB2_OTGFS  7

//////////////////////////////////////////////////////////////////////////////APB1 Peripherals//////////////////////////////////////////////////////////////////////////////

#define APB1_TIM2		0
#define APB1_TIM3		1
#define APB1_TIM4		2
#define APB1_TIM5		3

#define APB1_WWDG		11

#define APB1_SPI2		14
#define APB1_SPI3		15

#define APB1_USART2		17

#define APB1_I2C1		21
#define APB1_I2C2		22
#define APB1_I2C3		23

#define APB1_PWR		28

//////////////////////////////////////////////////////////////////////////////APB2 Peripherals//////////////////////////////////////////////////////////////////////////////

#define APB2_TIM1		0

#define APB2_USART1		4
#define APB2_USART6		5

#define APB2_ADC1		8

#define APB2_SDIO		11
#define APB2_SPI1		12
#define APB2_SPI4		13
#define APB2_SYSCFG		14

#define APB2_TIM9		16
#define APB2_TIM10		17
#define APB2_TIM11		18

////////////////////////////////////////////////////////////////////////////Functions' Prototypes////////////////////////////////////////////////////////////////////////////

// Function to Enable Peripheral Clock
RCC_ErrorState_t RCC_EnablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID);

// Function to Disable Peripheral Clock
RCC_ErrorState_t RCC_DisablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID);

// Function to Set System Clock
void RCC_voidSetSystemClock(void);

#endif