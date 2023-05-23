/**************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							      */
/*File Name   : KPD_interface.h                                           */
/*Layer       : HAL											 		      */
/*Description : This file contains interfacing parameters of KPD module   */
/*Date        : 23 May 2023     	                                      */
/**************************************************************************/

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_

/*************************************************************************/
/*************************Functions' prototypes***************************/
/*************************************************************************/

/* Function to Initialize KPD */
void KPD_voidInit(void);

/* Function to Return Value of Pressed Key */
u8 KPD_u8GetPressedKey(void);

#endif /* HAL_KPD_KPD_INTERFACE_H_ */
