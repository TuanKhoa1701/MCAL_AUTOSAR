#include "PWM_Lcfg.h"

void TIM2_IRQHandler(void)
{
    PWM_isrHandler(TIM2);
}
void TIM3_IRQHandler(void)
{
    PWM_isrHandler(TIM3);
}