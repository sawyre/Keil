#include <stm32f10x.h>

int main(void)
{
	RCC->APB2ENR|=1<<4;
	GPIOC->CRH=0x22;
	while(1){
		GPIOC->ODR|=1<<8;
		GPIOC->ODR&=~(1<<8); 
		GPIOC->ODR|=1<<9;
		GPIOC->ODR&=~(1<<9); 
	}
	return 0;
}
