#include "stm32f10x_rcc.h"          
#include "stm32f10x.h"       
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"  
#include "DIO.h"
#include "Port.h"
#include "Port_cfg.h"
#include "PWM.h"
#include "Pwm_LCfg.h"
#include <stdint.h>
void RCC_Config()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
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


int hala() {
	RCC_Config(); 
	TIM_Config();
	    Port_ConfigType portConfig = {
        .PinConfigs = PortCfg_Pins,
        .PinCount = PortCfg_PinsCount
    };
    Port_Init(&portConfig);
	Pwm_Init(&PwmDriverConfig);
	  uint16_t dutyCh0 = 0;
  uint16_t dutyCh1 = 0;
  uint8_t dir0 = 1;
  uint8_t dir1 = 0;
	while (1)
	{
		/* code */
	
	
	        /* Tăng giảm duty channel 0 (PA0 - TIM2_CH1) */
        Pwm_SetDutyCycle(0, dutyCh0);

        /* Tăng giảm duty channel 1 (PA7 - TIM3_CH2) */
        Pwm_SetDutyCycle(1, dutyCh1);

		delay_ms(10);

        /* Đổi hướng khi đạt 0 hoặc max */
        if (dir0) {
            dutyCh0 += 0x0200;
            if (dutyCh0 >= 0x8000) {
                dutyCh0 = 0x8000;
                dir0 = 0;
            }
        } else {
            if (dutyCh0 >= 0x0200) dutyCh0 -= 0x0200;
            else dutyCh0 = 0;
            if (dutyCh0 == 0) dir0 = 1;
        }

        /* Channel 1 thì làm ngược lại (fade lệch pha) */
        if (dir1) {
            dutyCh1 += 0x0200;
            if (dutyCh1 >= 0x8000) {
                dutyCh1 = 0x8000;
                dir1 = 0;
            }
        } else {
            if (dutyCh1 >= 0x0200) dutyCh1 -= 0x0200;
            else dutyCh1 = 0;
            if (dutyCh1 == 0) dir1 = 1;
        }
    }
}


