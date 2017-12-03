#include <stm32f10x.h>

int main(void)
{
	RCC->APB2ENR|=1<<2; 		//Подать питание на порт A
	GPIOA->CRL=0x22222220;	//Настроить режим контактов с 1 по 7 в порту C на режим General purpose output push pull
	GPIOA->CRH=0x2;					//Настроить режим контакта 8 в порту C на режим General purpose output push pull
	
	RCC->APB2ENR|=1<<3;			//Подать питание на порт B
	GPIOB->CRL=0x444;				//Настроить режим контакта 0 в порту C на режим Floating input (reset state)
	while(1){
		GPIOA->ODR=1<<(GPIOB->IDR&7);		//Вывести на контакт закодированный кнопками (и только на него) высокий уровень
	}
	return 0;
}
