#include <stm32f10x.h>

int main(void)
{
	RCC->APB2ENR|=1<<4;  //Подать питание на порт C
	GPIOC->CRH|=0x22;		 //Настроить режим контактов 8 и 9 в порту C на режим General purpose output push pull
	while(1){
		GPIOC->ODR|=1<<8;	 //Подать высокий уровень
		for(int32_t i=0;i<1000000000;i++)
		{}
		GPIOC->ODR&=~(1<<8);
		GPIOC->ODR|=1<<9;		//Подать высокий уровень
		for(int32_t i=0;i<1000000000;i++)
		{}
		GPIOC->ODR&=~(1<<9); 
	}
	return 0;
}
