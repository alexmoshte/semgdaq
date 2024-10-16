/*
 * _ADCn_INx_TKEO.h
 *
 * Created on: Oct 2, 2024
 * Author: Mwangi Alex. W
 *
 * Header file for the functions that perform windowing on each channel using the Teager Kaiser energy operator (TKEO) to
 * monitor when muscle activation has occurred
 */

#ifndef INC__ADCN_INX_TKEO_H_
#define INC__ADCN_INX_TKEO_H_

//INCLUDES
#include "_ADCn_INx_SD_BL.h"

//FUNCTION DECLARATIONS
uint8_t ADC1_IN1_TKEO(ADC1_IN1_MA *ADC1_IN1_TKEO_ptr, float32_t StnDev_BL_1);
uint8_t ADC1_IN2_TKEO(ADC1_IN2_MA *ADC1_IN2_TKEO_ptr, float32_t StnDev_BL_2);
uint8_t ADC2_IN3_TKEO(ADC2_IN3_MA *ADC2_IN3_TKEO_ptr, float32_t StnDev_BL_3);
uint8_t ADC2_IN4_TKEO(ADC2_IN4_MA *ADC2_IN4_TKEO_ptr, float32_t StnDev_BL_4);
uint8_t ADC3_IN1_TKEO(ADC3_IN1_MA *ADC3_IN1_TKEO_ptr, float32_t StnDev_BL_5);
uint8_t ADC3_IN2_TKEO(ADC3_IN2_MA *ADC3_IN2_TKEO_ptr, float32_t StnDev_BL_6);

#endif /* INC__ADCN_INX_TKEO_H_ */
