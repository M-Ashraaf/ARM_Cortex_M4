/**************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							      */
/*File Name   : KPD_config.h                                          	  */
/*Layer	      : HAL										  		          */
/*Description : This file contains configurable parameters of KPD module  */
/*Date        : 23 May 2023	                                              */
/**************************************************************************/

#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_

////////////////////////////////////////////////// Available Port Configurations: (GPIO_PORTA , GPIO_PORTB , GPIO_PORTC) //////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// Available Pin Configurations: //////////////////////////////////////////////////////////////////////
//(GPIO_PIN0,GPIO_PIN1,GPIO_PIN2,GPIO_PIN3,GPIO_PIN4,GPIO_PIN5,GPIO_PIN6,GPIO_PIN7,GPIO_PIN8,GPIO_PIN9,GPIO_PIN10,GPIO_PIN11,GPIO_PIN12,GPIO_PIN13,GPIO_PIN14,GPIO_PIN15)//

/* KPD ROW 0 Configurations */
#define KPD_ROW0_PORT  		GPIO_PORTA
#define KPD_ROW0_PIN   		GPIO_PIN0

/* KPD ROW 1 Configurations */
#define KPD_ROW1_PORT  		GPIO_PORTA
#define KPD_ROW1_PIN   		GPIO_PIN1

/* KPD ROW 2 Configurations */
#define KPD_ROW2_PORT  		GPIO_PORTA
#define KPD_ROW2_PIN   		GPIO_PIN2

/* KPD ROW 3 Configurations */
#define KPD_ROW3_PORT  		GPIO_PORTA
#define KPD_ROW3_PIN  		GPIO_PIN3

/* KPD COL 0 Configurations */
#define KPD_COL0_PORT  		GPIO_PORTA
#define KPD_COL0_PIN   		GPIO_PIN4

/* KPD COL 1 Configurations */
#define KPD_COL1_PORT  		GPIO_PORTA
#define KPD_COL1_PIN   		GPIO_PIN5

/* KPD COL 2 Configurations */
#define KPD_COL2_PORT  		GPIO_PORTA
#define KPD_COL2_PIN   		GPIO_PIN6

/* KPD COL 3 Configurations */
#define KPD_COL3_PORT  		GPIO_PORTA
#define KPD_COL3_PIN   		GPIO_PIN7

/* KPD Rows & Columns Configurations */
#define KPD_ROW_NUM 		4
#define KPD_COL_NUM			4

/* KPD No Pressed Key Configurations */
#define KPD_NO_PRESSED_KEY 	1

/* KPD Values Configurations */
#define KPD_VALUES {{'a' , 'b' , 'c' , 'd'} , {'e' , 'f' , 'g' , 'h'} , {'i' , 'j' , 'k' , 'l'} , {'m' , 'n' , 'o' , 'p'}}

#endif /* HAL_KPD_KPD_CONFIG_H_ */
