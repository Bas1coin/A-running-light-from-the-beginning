#include "stm32f4xx.h"
#include "math.h"


const int led_states[6] = {
	(1<<6),
	(1<<1),
	(1<<2),
	(1<<3),
	(1<<4),
	(1<<5)
};


void delay(int time) {
    for (int i = 0; i < time; i++) {
        for (int j = 0; j < 1000; j++) {
            __NOP();
        }
    }
}

void GPIO_INIT(){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOCEN;

	GPIOA->MODER |= GPIO_MODER_MODER1_0;
	GPIOA->MODER &= ~GPIO_MODER_MODER1_1;
	
	GPIOA->MODER |= GPIO_MODER_MODER2_0;
	GPIOA->MODER &= ~GPIO_MODER_MODER2_1;
	
	GPIOA->MODER |= GPIO_MODER_MODER3_0;
	GPIOA->MODER &= ~GPIO_MODER_MODER3_1;
	
	GPIOA->MODER |= GPIO_MODER_MODER4_0;
	GPIOA->MODER &= ~GPIO_MODER_MODER4_1;
	
	GPIOA->MODER |= GPIO_MODER_MODER5_0;
	GPIOA->MODER &= ~GPIO_MODER_MODER5_1;
	
	GPIOA->MODER |= GPIO_MODER_MODER6_0;
	GPIOA->MODER &= ~GPIO_MODER_MODER6_1;
	
	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT3 | GPIO_OTYPER_OT1 | GPIO_OTYPER_OT2 |
	GPIO_OTYPER_OT4 | GPIO_OTYPER_OT5 | GPIO_OTYPER_OT6);
	
	//Speed is medium 
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED6_0 | GPIO_OSPEEDR_OSPEED1_0 | GPIO_OSPEEDR_OSPEED2_0 | 
	GPIO_OSPEEDR_OSPEED3_0 | GPIO_OSPEEDR_OSPEED4_0 |GPIO_OSPEEDR_OSPEED5_0;
	
	GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED6_1 | GPIO_OSPEEDR_OSPEED1_1 | GPIO_OSPEEDR_OSPEED2_1 |
	GPIO_OSPEEDR_OSPEED3_1 | GPIO_OSPEEDR_OSPEED4_1 | GPIO_OSPEEDR_OSPEED5_1);


	GPIOA->MODER &= ~(3 << 0);
	GPIOA->PUPDR |= (1 << 0);
	GPIOA->ODR = 0;
}



int main(void) {
		GPIO_INIT();
		int step = 0;
    
    while (1) {
				if(GPIOA->IDR & GPIO_IDR_ID0){
					GPIOA->ODR = led_states[step];
					step++;
					if(step >= 6) step = 0;
					delay(5000);
				}else{
					GPIOA->ODR = 0;
					step = 0;
				}
    }
}








