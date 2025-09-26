#ifndef ADC_CFG_H
#define ADC_CFG_H
/**********************************************************
 * @file    Adc_cfg.h
 * @brief   ADC Driver Configuration Header File (AUTOSAR)
 * @details Cấu hình mô-đun ADC cho STM32F103.
 * @version 1.0
 * @author  Nguyen Tuan Khoa 
 ***********************************************************/
#include "Adc.h"
#include "stm32f10x.h"
#include "stm32f10x_adc.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_dma.h"
extern Adc_ValueGroupType Adc_Group_Buffer[ADC_MAX_GROUPS];

/* ============================= */
/* ==== Global Config Array ==== */
/* ============================= */
extern const Adc_ConfigType Adc_Configs[ADC_MAX_HW];
extern const Adc_GroupDefType Adc_GroupConfigs[ADC_MAX_GROUPS];
void Adc_Notification_callback(void);
void ADC_isrHandler(void);


#endif
