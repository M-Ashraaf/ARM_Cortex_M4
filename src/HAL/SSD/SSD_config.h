/**************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							      */
/*File Name   : SSD_config.h                                          	  */
/*Layer	      : HAL										  		          */
/*Description : This file contains configurable parameters of SSD module  */
/*Date        : 18 May 2023	                                              */
/**************************************************************************/

#ifndef HAL_SSD_SSD_CONFIG_H_
#define HAL_SSD_SSD_CONFIG_H_

////////////////////////////////////////////////// Available Port Configurations: (GPIO_PORTA , GPIO_PORTB , GPIO_PORTC) //////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// Available Pin Configurations: //////////////////////////////////////////////////////////////////////
//(GPIO_PIN0,GPIO_PIN1,GPIO_PIN2,GPIO_PIN3,GPIO_PIN4,GPIO_PIN5,GPIO_PIN6,GPIO_PIN7,GPIO_PIN8,GPIO_PIN9,GPIO_PIN10,GPIO_PIN11,GPIO_PIN12,GPIO_PIN13,GPIO_PIN14,GPIO_PIN15)//

/* SSD Pin 0 Configurations */
#define SSD_PIN0_PORT  		GPIO_PORTA
#define SSD_PIN0_PIN   		GPIO_PIN0

/* SSD Pin 1 Configurations */
#define SSD_PIN1_PORT  		GPIO_PORTA
#define SSD_PIN1_PIN   		GPIO_PIN1

/* SSD Pin 2 Configurations */
#define SSD_PIN2_PORT  		GPIO_PORTA
#define SSD_PIN2_PIN   		GPIO_PIN2

/* SSD Pin 3 Configurations */
#define SSD_PIN3_PORT  		GPIO_PORTA
#define SSD_PIN3_PIN  		GPIO_PIN3

/* SSD Pin 4 Configurations */
#define SSD_PIN4_PORT  		GPIO_PORTA
#define SSD_PIN4_PIN   		GPIO_PIN4

/* SSD Pin 5 Configurations */
#define SSD_PIN5_PORT  		GPIO_PORTA
#define SSD_PIN5_PIN   		GPIO_PIN5

/* SSD Pin 6 Configurations */
#define SSD_PIN6_PORT  		GPIO_PORTA
#define SSD_PIN6_PIN   		GPIO_PIN6

/* SSD Pin 7 Configurations */
#define SSD_PIN7_PORT  		GPIO_PORTA
#define SSD_PIN7_PIN   		GPIO_PIN7

/* SSD Common Pin Configurations */
#define SSD_COMMONPIN_PORT  GPIO_PORTA
#define SSD_COMMONPIN_PIN   GPIO_PIN8

#endif /* HAL_SSD_SSD_CONFIG_H_ */
