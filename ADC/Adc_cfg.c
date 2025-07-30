#include "Adc_cfg.h"
#include "Adc.h"
#include <stdio.h>
void Adc_Notification_callback(void)
{
    // Ví dụ: bật LED khi có thông báo từ ADC
    Adc_ReadGroup(0, &Adc_Group_Buffer[0]);
    // printf("ADC Notification callback!\n");
}
void ADC_isrHandler(void)
{
    for (uint8_t group = 0; group < ADC_MAX_GROUPS; group++)
    {
        Adc_GroupDefType *grp = &Adc_GroupConfigs[group];
        Adc_ConfigType *cfg = &Adc_Configs[grp->AdcInstance];

        if (cfg->NotificationEnabled == ADC_NOTIFICATION_ENABLED)
        {
            if (grp->AdcInstance == ADC_INSTANCE_1 && ADC_GetITStatus(ADC1, ADC_IT_EOC))
            {
                ADC_ClearITPendingBit(ADC1, ADC_IT_EOC);

                if (cfg->InitCallback)
                    cfg->InitCallback();
            }
            else if (grp->AdcInstance == ADC_INSTANCE_2 && ADC_GetITStatus(ADC2, ADC_IT_EOC))
            {
                ADC_ClearITPendingBit(ADC2, ADC_IT_EOC);

                if (cfg->InitCallback)
                    cfg->InitCallback();
            }
        }
    }
}
 const Adc_ConfigType Adc_Configs[1] ={
     {   .AdcInstance = ADC_INSTANCE_1,
         .ClockPrescaler = 2,
         .ConversionMode = ADC_CONV_MODE_CONTINUOUS,
         .TriggerSource = ADC_TRIGGER_SOFTWARE,
         .NotificationEnabled = ADC_NOTIFICATION_DISABLED,
         .NumChannels = 1,
         .ResultAlignment = ADC_RESULT_ALIGNMENT_RIGHT,
         .InitCallback = NULL,
         .Channels = {
             { .Channel = ADC_Channel_1, .SamplingTime = ADC_SampleTime_1Cycles5  , .Rank = 1 }
         }
     }
 };
 const Adc_GroupDefType Adc_GroupConfigs[ADC_MAX_GROUPS] = {
     {   
         .id = 0,
         .AdcInstance = ADC_INSTANCE_1,
         .Channels = {ADC_Channel_0},
         .Priority = 0,
         .NumChannels = 1,
         .Status = ADC_IDLE,
         .Result = Adc_Group_Buffer,
         .Adc_StreamEnableType = 0,
         .Adc_StreamBufferSize = 0,
         .Adc_StreamBufferMode = ADC_STREAM_BUFFER_LINEAR
     }
 };
