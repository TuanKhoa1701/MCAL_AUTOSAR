#include "PWM_Lcfg.h"
#include "Adc_cfg.h"
void TIM2_IRQHandler(void)
{
    PWM_isrHandler(TIM2);
}
void TIM3_IRQHandler(void)
{
    PWM_isrHandler(TIM3);
}
ADC1_2_IRQHandler(void){
    ADC_isrHandler();
}