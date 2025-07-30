#include "stm32f10x_rcc.h"          
#include "stm32f10x.h"       
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"  
#include "DIO.h"
#include "Port.h"
#include "Port_cfg.h"
#include "Pwm_LCfg.h"
#include "Pwm.h"
#include "Adc.h"
#include "Adc_cfg.h"
#include "isr.h"
Adc_ValueGroupType Adc_Group_Buffer[ADC_MAX_GROUPS];

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
    //Pwm_Init(&PwmDriverConfig);
    // Enable both edges for channel 0
    //Pwm_EnableNotification(0, PWM_BOTH_EDGES);
    // khi có ng?t x?y ra t? d?ng vào trong th?ng Pwm_Channel0_Notification();
    Adc_Init(&Adc_Configs[0]);
    Adc_EnableGroupNotification(0);
    Adc_StartGroupConversion(0);
    	while (1)
	{
        
    }
}
