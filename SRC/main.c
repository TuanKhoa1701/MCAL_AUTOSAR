#include "stm32f10x_rcc.h"          
#include "stm32f10x.h"       
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"  
#include "DIO.h"
#include "Port.h"
#include "Port_cfg.h"
#include "Pwm_LCfg.h"
#include "Pwm.h"
#include "isr.h"
/*
extern uint8_t Pwm_IsInitialized;
Pwm_IsInitialized = 0;
*/

int hala() {


	Port_ConfigType portConfig = {
        .PinConfigs = PortCfg_Pins,
        .PinCount   = PortCfg_PinsCount
    };
    Port_Init(&portConfig);
    Pwm_Init(&PwmDriverConfig);
    // Enable both edges for channel 0
    Pwm_EnableNotification(0, PWM_BOTH_EDGES);
    // khi có ngắt xảy ra tự động vào trong thằng Pwm_Channel0_Notification();
    	while (1)
	{
    }
}
