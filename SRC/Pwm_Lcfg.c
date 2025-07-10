/**********************************************************
 * @file    Pwm_Lcfg.c
 * @brief   PWM Driver Configuration Source File (AUTOSAR)
 * @details Cấu hình các kênh PWM dùng cho STM32F103 (ví dụ: TIM2_CH1/PA0, TIM3_CH2/PA7)
 * @version 1.0
 * @date    2024-06-27
 * @author  HALA Academy
 **********************************************************/

#include "Pwm.h"
#include "Pwm_Lcfg.h"
#include <stdio.h> // Nếu muốn test bằng printf hoặc debug trong callback

/* ==== Ví dụ hàm callback cho PWM notification ==== */
void Pwm_Channel0_Notification(void)
{
    // Ví dụ: đặt breakpoint, bật LED, debug, v.v.
    // printf("PWM Channel 0 interrupt/callback!\n");
    // GPIO_SetBits(GPIOC, GPIO_Pin_13);
    // ngắt quay lại học, nhưng cũng nói qua, thằng này kiểu khi có ngắt xảy ra, cụ thể là hàm
    // Pwm_EnableNotification(0, PWM_BOTH_EDGES); // hoặc PWM_RISING_EDGE, PWM_FALLING_EDGE
    // sẽ kích hoạt ngắt
}
void PWM_isrHandler(TIM_TypeDef* TIMx)
{
    for(uint8_t i = 0 ; i < PWM_NUM_CHANNELS;i++)
    {
        const Pwm_ChannelConfigType* cfg = &PwmChannelsConfig[i];
    // Kiểm tra xem TIMx có phải là TIM2 hay TIM3 không
    if (cfg -> TIMx == TIMx) {
        uint16_t flag = TIM_IT_CC1 << (cfg->channel - 1); // Tính toán cờ ngắt dựa trên channel
        if(TIM_GetITStatus(TIMx,flag) != RESET){
            // Xóa cờ ngắt
            TIM_ClearITPendingBit(TIMx, flag);
            if(cfg -> notificationEnabled && cfg -> NotificationCb != NULL) 
                // Gọi callback nếu được bật
                cfg -> NotificationCb(); 
        }
        if(TIM_GetITStatus(TIMx, TIM_IT_Update) != RESET) {
            // Xóa cờ ngắt cập nhật
            TIM_ClearITPendingBit(TIMx, TIM_IT_Update);
            if(cfg -> notificationEnabled && cfg -> NotificationCb != NULL) 
                // Gọi callback nếu được bật
                cfg -> NotificationCb();
        }
    }

    }
}

/* ==== Cấu hình từng kênh PWM ==== */
const Pwm_ChannelConfigType PwmChannelsConfig[] = {
    
    {
        .TIMx             = TIM2,
        .channel          = 1,
        .classType        = PWM_VARIABLE_PERIOD,
        .defaultPeriod    = 999,          // 1ms (72MHz/72/1000)
        .defaultDutyCycle = 0x0000,       // Duty 0%
        .polarity         = PWM_HIGH,
        .idleState        = PWM_LOW,
        .notificationEnabled = 0, // Bật thông báo ngắt
        .NotificationCb   = Pwm_Channel0_Notification   // Callback không NULL!
    },
    
    /* Channel 1: PA7 - TIM3_CH2, không dùng callback */
    {
        .TIMx             = TIM3,
        .channel          = 2,
        .Prescaler        = 0,             // Không dùng prescaler  s
        .classType        = PWM_VARIABLE_PERIOD,
        .defaultPeriod    = 999,
        .defaultDutyCycle = 0x0000,
        .polarity         = PWM_HIGH,
        .idleState        = PWM_LOW,
        .notificationEnabled = 0, // Không bật thông báo ngắt
        .NotificationCb   = NULL
    }
};

/* ==== Cấu hình tổng PWM driver ==== */
const Pwm_ConfigType PwmDriverConfig = {
    .Channels    = PwmChannelsConfig,
    .NumChannels = sizeof(PwmChannelsConfig) / sizeof(Pwm_ChannelConfigType)
};
