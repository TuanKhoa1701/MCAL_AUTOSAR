#include "PWM_Lcfg.h"

void TIM3_IRQHandler(void)
{
    Pwm_IsrHandler(TIM3);
}

