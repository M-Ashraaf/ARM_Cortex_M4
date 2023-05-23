/**************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							      */
/*File Name   : GPIO_private.h                                            */
/*Layer       : MCAL									  		          */
/*Description : This file contains private parameters of GPIO module	  */
/*Date        : 11 May 2023                                               */
/**************************************************************************/

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

typedef struct
{
	u32 MODER;			//This Register is to Set The Mode of Any Pin.
	u32 OTYPER;			//This Register is to Set The Type of Output Pins(PP/OD).
	u32 OSPEEDR;		//This Register is to Set The Speed of Output Pins.
	u32 PUPDR ;			//This Register is to Select Either Pull Up or Pull Down Input.
	u32 IDR;			//This Register is to Get The Value of Input Pins.
	u32 ODR;			//This Register is to Set The Value of Output Pins.
	u32 BSRR;           //This Register is to Set/Reset Any Pin in Atomic Access
	u32 LCKR;			//This Register is to Lock The Configuration of Any Pin
	u32	AFRL;			//This Register is to Set The Alternative Function of Pins (0:7)
	u32	AFRH;			//This Register is to Set The Alternative Function of Pins (8:15)

}GPIO_REG_t;

/*Pointer to Struct */
#define	GPIOA ((volatile GPIO_REG_t *)(0x40020000))
#define GPIOB ((volatile GPIO_REG_t *)(0x40020400))
#define GPIOC ((volatile GPIO_REG_t *)(0x40020800))

#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
