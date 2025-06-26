#include "stm32f10x_rcc.h"          
#include "stm32f10x.h"       
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"  
#include "DIO.h"
#include "Port.h"
#include "Port_cfg.h"


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
	    Port_ConfigType portConfig = {
        .PinConfigs = PortCfg_Pins,
        .PinCount = PortCfg_PinsCount
    };
    Port_Init(&portConfig);
	TIM_Config();
	while (1) {
	Port_ApplyPinConfig(&PortCfg_Pins[0]); // Cấu hình chân PA0
	Port_ApplyPinConfig(&PortCfg_Pins[1]); // Cấu hình chân PA1
	Port_ApplyPinConfig(&PortCfg_Pins[2]); // Cấu hình chân PB0
	Port_ApplyPinConfig(&PortCfg_Pins[3]); // Cấu hình chân PC13
		DIO_FlipChannel(DIO_CHANNEL_C13); // Đảo trạng thái chân PA0
		delay_ms(500); // Đợi 500ms
    }
}


