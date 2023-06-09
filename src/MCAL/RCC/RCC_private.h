/**************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							      */
/*File Name   : RCC_private.h                                             */
/*Bus     	  : AHB1									  		          */
/*Description : This file contains private parameters of RCC module		  */
/*Date        : 5 May 2023                                                */
/**************************************************************************/

#ifndef RCC_PRIVATE_H_
#define	RCC_PRIVATE_H_

////////////////////////////////////////////////////////////////////////Available System Clock Values////////////////////////////////////////////////////////////////////////

#define	HSI			 1
#define HSE_RC		 2
#define HSE_CRYSTAL	 3
#define	PLL			 4

////////////////////////////////////////////////////////////////////////////////RCC Registers////////////////////////////////////////////////////////////////////////////////

#define RCC_CR 			*((volatile u32 *)(0x40023800))
#define RCC_PLLCFGR		*((volatile u32 *)(0x40023804))
#define RCC_CFGR 		*((volatile u32 *)(0x40023808))
#define RCC_CIR			*((volatile u32 *)(0x4002380C))
#define RCC_AHB1RSTR	*((volatile u32 *)(0x40023810))
#define RCC_AHB2RSTR	*((volatile u32 *)(0x40023814))
#define RCC_APB1RSTR	*((volatile u32 *)(0x40023820))
#define RCC_APB2RSTR	*((volatile u32 *)(0x40023824))
#define RCC_AHB1ENR 	*((volatile u32 *)(0x40023830))
#define RCC_AHB2ENR 	*((volatile u32 *)(0x40023834))
#define RCC_APB1ENR 	*((volatile u32 *)(0x40023840))
#define RCC_APB2ENR 	*((volatile u32 *)(0x40023844))
#define RCC_AHB1LPENR	*((volatile u32 *)(0x40023850))
#define RCC_AHB2LPENR	*((volatile u32 *)(0x40023854))
#define RCC_APB1LPENR	*((volatile u32 *)(0x40023860))
#define RCC_APB2LPENR	*((volatile u32 *)(0x40023864))
#define RCC_BDCR		*((volatile u32 *)(0x40023870))
#define RCC_CSR			*((volatile u32 *)(0x40023874))
#define RCC_SSCGR		*((volatile u32 *)(0x40023880))
#define RCC_PLLI2SCFGR	*((volatile u32 *)(0x40023884))
#define RCC_DCKCFGR		*((volatile u32 *)(0x4002388C))

#endif
