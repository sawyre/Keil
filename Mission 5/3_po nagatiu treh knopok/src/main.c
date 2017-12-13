#include <stm32f10x.h>

int main(void)
{
	RCC->APB2ENR|=1<<2; 		//Подать питание на порт A
	GPIOA->CRL&=0x0000000F;	//Настроить режим 
	GPIOA->CRH&=0xFFFFFFF0;	//контактов с 1 по 8 
	GPIOA->CRL|=0x22222220;	//в порту А
	GPIOA->CRH|=0x2;				//на режим General purpose output push pull
	
	RCC->APB2ENR|=1<<3;			//Подать питание на порт B
	GPIOB->CRL&=0xFFFFF000;	//Настроить режим контактов с 1 по 8 
	GPIOB->CRL|=0x00000444;	//в порту B на режим Floating input
	while(1){
		GPIOA->ODR&=0xFFFFFE01;														//Вывести на контакт закодированный кнопками
		GPIOA->ODR|=0x000001FE&(1<<((GPIOB->IDR&7)+1));		//(и только на него) высокий уровень
	}
	return 0;
}
