/**************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							      */
/*File Name   : LED_interface.h                                           */
/*Layer       : HAL											 		      */
/*Description : This file contains interfacing parameters of LED module   */
/*Date        : 18 May 2023     	                                      */
/**************************************************************************/

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

/*************************************************************************/
/*************************Functions' Prototypes***************************/
/*************************************************************************/

/* Function to Initialize LED Pin */
void LED_voidPinLedInit(u8 Copy_u8PortID , u8 Copy_u8PinID);

/* Function to Initialize LED Port */
void LED_voidPortLedInit(u8 Copy_u8PortID);

/* Function to Set Led On */
void LED_voidLedOn(u8 Copy_u8PortID , u8 Copy_u8PinID);

/* Function to Set Led Off */
void LED_voidLedOff(u8 Copy_u8PortID , u8 Copy_u8PinID);

/* Function to Toggle Led */
void LED_voidToggleLed(u8 Copy_u8PortID , u8 Copy_u8PinID);

#endif /* HAL_LED_LED_INTERFACE_H_ */
