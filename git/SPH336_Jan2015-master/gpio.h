/*
 * gpio.h
 *
 *  Created on: Mar 2, 2015
 *      Author: karibe
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "Mk60.h"


void gpio_init(void);
/*void toggle_LED0(void);
void toggle_LED1(void);
void toggle_LED2(void);
void toggle_LED3(void);
void toggle_LED4(void);
void toggle_LED5(void);
void toggle_LED6(void);
void toggle_LED7(void);
void toggle_LED8(void);
void toggle_LED9(void);*/
extern void put(uint8_t *s);
extern void SystemInit(void);
/*
	brief PORTA initialization
*/
void gpio_init(void)
{
	//PTA19 as a button input
	PA->PCR[19].mux = 0x01; //PortA pin 19 as GPIO
	PA->PCR[19].irqc = 0xA; //Interrupt on falling edge
	PA->PCR[19].pe = 0x01; //pull-up enable
	PA->PCR[19].ps = 0x01; //select internal pull-up resistor
	//PortA pins 10, 11, 28 and 29 as alt1=GPIO
	PA->PCR[10].mux = 0x01;
	PA->PCR[11].mux = 0x01;
	PA->PCR[28].mux = 0x01;
	PA->PCR[29].mux = 0x01;
	//PTE8 and PTE9 as UART5
	PE->PCR[8].mux = 0x0;	//clear default function
	PE->PCR[9].mux = 0x0;	//clear default function
	PE->PCR[8].mux = 0x3;	//alt3 = UART5_TX
	PE->PCR[9].mux = 0x3; 	//alt3 = UART5_RX
	//GPIO port data direction Port A as output for LEDs (pin 11, 28, 29 and 10), Port E UART5(PTE8 TX, PTE9 RX)
	GPIOA->PDDR.bit_reg.bit11 = out;
	GPIOA->PDDR.bit_reg.bit28 = out;
	GPIOA->PDDR.bit_reg.bit29 = out;
	GPIOA->PDDR.bit_reg.bit10 = out;
	GPIOE->PDDR.bit_reg.bit8 = out; //UART5_TX is an output
	//No need to configure GPIO for as an input, by default all pins are inputs
	//GPIOA->PDDR.bit_reg.bit19 = IN;
	//GPIOE->PDDR.bit_reg.bit9 = IN //UART5_RX is an input
}

/*void toggle_LED1(void){
	GPIOA->PTOR.bit_reg.bit11 = on;
	GPIOA->PTOR.bit_reg.bit29 = on;
}

void toggle_LED2(void){
	//GPIOA->PTOR.bit_reg.bit28 = on;
	//GPIOA->PTOR.bit_reg.bit10 = on;
	puts((uint8_t*)("All LEDs off\r\n"));
}
*/
/*
void toggle_LED0(void){
	GPIOA->PTOR.bit_reg.bit10 = 0;
	GPIOA->PTOR.bit_reg.bit11 = 0;
	GPIOA->PTOR.bit_reg.bit28 = 0;
	GPIOA->PTOR.bit_reg.bit29 = 0;
	puts((uint8_t*)("Number default\r\n"));
}

void toggle_LED1(void){
	GPIOA->PTOR.bit_reg.bit10 = 1;
	GPIOA->PTOR.bit_reg.bit11 = 0;
	GPIOA->PTOR.bit_reg.bit28 = 0;
	GPIOA->PTOR.bit_reg.bit29 = 0;
	puts((uint8_t*)("Number 1\r\n"));
}

void toggle_LED2(void){
	GPIOA->PTOR.bit_reg.bit29 = 1;
	GPIOA->PTOR.bit_reg.bit28 = 0;
	GPIOA->PTOR.bit_reg.bit11 = 0;
	GPIOA->PTOR.bit_reg.bit10 = 0;
	puts((uint8_t*)("Number 2\r\n"));
}

void toggle_LED3(void){
	GPIOA->PTOR.bit_reg.bit10 = 1;
	GPIOA->PTOR.bit_reg.bit29 = 1;
	GPIOA->PTOR.bit_reg.bit18 = 0;
	GPIOA->PTOR.bit_reg.bit11 = 0;
	puts((uint8_t*)("Number 3\r\n"));
}

void toggle_LED4(void){
	GPIOA->PTOR.bit_reg.bit28 = 1;
	GPIOA->PTOR.bit_reg.bit10 = 0;
	GPIOA->PTOR.bit_reg.bit11 = 0;
	GPIOA->PTOR.bit_reg.bit29 = 0;
	puts((uint8_t*)("Number 4\r\n"));
}

void toggle_LED5(void){
	GPIOA->PTOR.bit_reg.bit28 = 1;
	GPIOA->PTOR.bit_reg.bit10 = 1;
	GPIOA->PTOR.bit_reg.bit11 = 0;
	GPIOA->PTOR.bit_reg.bit29 = 0;
	puts((uint8_t*)("Number 5\r\n"));
}

void toggle_LED6(void){
	GPIOA->PTOR.bit_reg.bit28 = 1;
	GPIOA->PTOR.bit_reg.bit29 = 1;
	GPIOA->PTOR.bit_reg.bit10 = 0;
	GPIOA->PTOR.bit_reg.bit11 = 0;
	puts((uint8_t*)("Number 6\r\n"));
}

void toggle_LED7(void){
	GPIOA->PTOR.bit_reg.bit28 = 1;
	GPIOA->PTOR.bit_reg.bit29 = 1;
	GPIOA->PTOR.bit_reg.bit10 = 1;
	GPIOA->PTOR.bit_reg.bit11 = 0;
	puts((uint8_t*)("Number 7\r\n"));
}

void toggle_LED8(void){
	GPIOA->PTOR.bit_reg.bit11 = 1;
	GPIOA->PTOR.bit_reg.bit10 = 0;
	GPIOA->PTOR.bit_reg.bit28 = 0;
	GPIOA->PTOR.bit_reg.bit29 = 0;
	puts((uint8_t*)("Number 8\r\n"));
}

void toggle_LED9(void){
	GPIOA->PTOR.bit_reg.bit11 = 1;
	GPIOA->PTOR.bit_reg.bit10 = 1;
	GPIOA->PTOR.bit_reg.bit28 = 0;
	GPIOA->PTOR.bit_reg.bit29 = 0;
	puts((uint8_t*)("Number 9\r\n"));
}
*/
/*
	brief  Port A ISR Handler
 */
void PORTA_IRQHandler(void)
{
	PA->ISFR.word_reg = 0xFFFFFFFF; //clear Interrupt Status Register by writing ones in all bits --- why???
	//toggle_LED2(); //toggle the second LED to indicate interrupt serviced
}



#endif /* GPIO_H_ */
