#include "stm32f10x_rcc.h"          
#include "stm32f10x.h"       
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"  
#include "DIO.h"

void RCC_Config()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
}

void GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_All;	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC,&GPIO_InitStruct);
}

void TIM_Config()
{
	TIM_TimeBaseInitTypeDef TIM_InitStruct;
	
	TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_InitStruct.TIM_Prescaler = 7200 - 1;
	TIM_InitStruct.TIM_Period = 0xFFFF;
	TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM2,&TIM_InitStruct);
	TIM_Cmd(TIM2,ENABLE);
}

void delay_ms(uint32_t time)
{
	TIM_SetCounter(TIM2,0);
	while(TIM_GetCounter(TIM2)< time * 10) {}
}

uint16_t a;
Std_VersionInfoType Version;
int hala() {
    RCC_Config();
    GPIO_Config();
    TIM_Config();
	while (1) {
	    Dio_MaskedWritePort(DIO_CHANNEL_C3, 0x00F0, 0x00E0);
		delay_ms(1000);
    }
}


