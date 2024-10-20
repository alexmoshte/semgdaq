/*
 * _ADCn_INx_SSC.h
 *
 *  Created on: Oct 3, 2024
 *  Author: Mwangi Alex. W
 *
 *  Header file for the functions that calculate the slope sign change for the sEMG data in the moving average output buffer
 */

#ifndef INC__ADCN_INX_SSC_H_
#define INC__ADCN_INX_SSC_H_

//INCLUDES
#include "_ADCn_INx_TKEO.h"

//FUNCTION DECLARATIONS
 float32_t ADC1_IN1_SSC(ADC1_IN1_MA *ADC1_IN1_SSC_ptr, float32_t Threshold_1);
 float32_t ADC1_IN2_SSC(ADC1_IN2_MA *ADC1_IN2_SSC_ptr, float32_t Threshold_2);
 float32_t ADC2_IN3_SSC(ADC2_IN3_MA *ADC2_IN3_SSC_ptr, float32_t Threshold_3);
 float32_t ADC2_IN4_SSC(ADC2_IN4_MA *ADC2_IN4_SSC_ptr, float32_t Threshold_4);
 float32_t ADC3_IN1_SSC(ADC3_IN1_MA *ADC3_IN1_SSC_ptr, float32_t Threshold_5);
 float32_t ADC3_IN2_SSC(ADC3_IN2_MA *ADC3_IN2_SSC_ptr, float32_t Threshold_6);

#endif /* INC__ADCN_INX_SSC_H_ */
