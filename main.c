#include<stdio.h>
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

int main(void)
{
	int i=0;
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC->APB2ENR |= (1 << 2);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHZ;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	while(1)
	{
		//GPIO_ResetBits(GPIOA,GPIO_Pin_8);
		PAout(8) = 0;
		//printf("on");
		for(i=0;i<1000000;i++);
		//GPIO_SetBits(GPIOA,GPIO_Pin_8);
		PAout(8) = 1;
		//printf("off");
		for(i=0;i<1000000;i++);
	}
}

void SystemInit(void)
{	
	//none
}
