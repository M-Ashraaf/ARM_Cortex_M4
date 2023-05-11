/**************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							      */
/*File Name   : GPIO_private.h                                            */
/*Bus     	  : AHB1									  		          */
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

}GPIO_REG_t;

/*Pointer to Struct */
#define	GPIOA ((volatile GPIO_REG_t *)(0x40020000))
#define GPIOB ((volatile GPIO_REG_t *)(0x40020400))
#define GPIOC ((volatile GPIO_REG_t *)(0x40020800))

#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
