#include <stm32f10x.h>

volatile uint32_t count=0;

void SysTick_Handler(void) {
	count++;
}

int main(void) {
	RCC->APB2ENR|=1<<4;  		//Подать питание на порт C
	GPIOC->CRH&=0xFFFFFFF0; //Настроить режим контакта 8 в порту C
	GPIOC->CRH|=0x2;		 		//на режим General purpose output push pull
	__disable_irq();
	SysTick_Config(16000000);			//Таймер для прерывания на 0.25 с
	__enable_irq();
	while(1) {
		if(count > 8) {       //Каждые 2 секунды
			GPIOC->ODR^= 1<<8;
			count = 0;
		}
	}
	return 0;
}