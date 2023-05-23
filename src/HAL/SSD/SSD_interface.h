/**************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							      */
/*File Name   : SSD_interface.h                                           */
/*Layer       : HAL											 		      */
/*Description : This file contains interfacing parameters of SSD module   */
/*Date        : 18 May 2023     	                                      */
/**************************************************************************/

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

/********************************************************************************************/
/*************************************Interfacing Macros*************************************/
/********************************************************************************************/

/* Available Connections */
#define SSD_COMMON_CATHODE  0
#define SSD_COMMON_ANODE 	1

/* Available Common Cathode Numbers */
#define COMMON_CATHODE_NUMBER0 0b00111111
#define COMMON_CATHODE_NUMBER1 0b00000110
#define	COMMON_CATHODE_NUMBER2 0b01011011
#define COMMON_CATHODE_NUMBER3 0b01001111
#define COMMON_CATHODE_NUMBER4 0b01100110
#define COMMON_CATHODE_NUMBER5 0b01101101
#define COMMON_CATHODE_NUMBER6 0b01111101
#define COMMON_CATHODE_NUMBER7 0b00000111
#define COMMON_CATHODE_NUMBER8 0b01111111
#define COMMON_CATHODE_NUMBER9 0b01101111

/* Available Common Anode Numbers */
#define COMMON_ANODE_NUMBER0 0b11000000
#define COMMON_ANODE_NUMBER1 0b11111001
#define COMMON_ANODE_NUMBER2 0b10100100
#define COMMON_ANODE_NUMBER3 0b10110000
#define COMMON_ANODE_NUMBER4 0b10011001
#define COMMON_ANODE_NUMBER5 0b10010010
#define COMMON_ANODE_NUMBER6 0b10000010
#define COMMON_ANODE_NUMBER7 0b11111000
#define COMMON_ANODE_NUMBER8 0b10000000
#define COMMON_ANODE_NUMBER9 0b10010000

/*********************************************************************************************/
/***********************************Functions' Prototypes*************************************/
/*********************************************************************************************/

//This Function is to Initialize Seven Segment Display
void SSD_voidSSDInit(void);

//This Function is to Turn Seven Segment Display ON
void SSD_voidSSDOn(u8 Copy_u8Connection);

//This Function is to Display Number on Seven Segment Display
void SSD_voidSSDDisplayNumber(u8 Copy_u8Number);

//This function is to Turn Seven Segment Display OFF
void SSD_voidSSDOff(u8 Copy_u8Connection);

#endif /* HAL_SSD_SSD_INTERFACE_H_ */
