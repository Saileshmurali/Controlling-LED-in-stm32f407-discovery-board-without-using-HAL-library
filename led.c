#include "stm32f4xx.h"
void configureLED(void);
void msDelay(uint32_t msTime);
int main(void)
{
	//Configure LED
	configureLED();
	//Define Delay function
	msDelay(1000);
	while(1)
	{
		GPIOD->ODR ^= (0xAUL<<12);
		msDelay(1000);
		GPIOD->ODR ^= (0xFUL<<12);
		msDelay(1000);
		GPIOD->ODR ^= (0x5UL<<12);
		//GPIOD->ODR ^= (0xFUL<<12);
	}
}
void configureLED(void)
{
	RCC->AHB1ENR |=(1UL<<3);
	GPIOD->MODER &= ~(0xFFUL<<12*2);
	GPIOD->MODER |= (0x55UL<<12*2);
	
}
void msDelay(uint32_t msTime)
{
	/* For loop takes 4 clock cycles to get executed. Clock frequency of stm32f407 by default is 16MHz
	So, 16MHz/4=4MHz. If we want 1000ms delay, 4MHz/1000=4000, so we have to multiply by 4000 to get a delay of 1s
	*/
	for(uint32_t i=0;i<msTime*4000;i++)
	{
		__NOP();
	}
	
}
