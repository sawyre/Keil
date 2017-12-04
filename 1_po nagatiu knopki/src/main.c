#include <stm32f10x.h>

int main(void)
{
	RCC->APB2ENR|=1<<4; 		//Подать питание на порт C
	GPIOC->CRH|=1<<1;				//Настроить режим контакта 8 в порту C на режим General purpose output push pull
	
	RCC->APB2ENR|=1<<2;			//Подать питание на порт A
	GPIOA->CRL|=1<<2;				//Настроить режим контакта 0 в порту C на режим Floating input (reset state)
	while(1){
		if(GPIOA->IDR&1)	//Проверить значение контакта 0 в порту A(нажата ли клавиша)
			GPIOC->ODR|=1<<8;		//Вывести на контакт 8 высокий уровень, если кнопка нажата
		else
			GPIOC->ODR&=~(1<<8);//Вывести на контакт 8 низкий уровень, если кнопка не нажата
	}
	return 0;
}
