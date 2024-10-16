/*
 * _ADCn_INx_Offset.h
 *
 *  Created on: Oct 1, 2024
 *  Author: Mwangi Alex. W
 */

#ifndef INC__ADCN_INX_OFFSET_H_
#define INC__ADCN_INX_OFFSET_H_


//INCLUDES
#include "_ADCn_INx_MA.h"


//FUNCTION DECLARATIONS
float32_t  ADC1_IN1_OffsetCalc(ADC1_IN1_MA *ADC1_IN1_Offset_ptr); // Calculates the offset (mean of the baseline signal) for ADC1 channel 1 in a specified number of iterations. The offset is subtracted from data during muscle activation

float32_t  ADC1_IN2_OffsetCalc(ADC1_IN2_MA *ADC1_IN2_Offset_ptr);

float32_t  ADC2_IN3_OffsetCalc(ADC2_IN3_MA *ADC2_IN3_Offset_ptr);

float32_t  ADC2_IN4_OffsetCalc(ADC2_IN4_MA *ADC2_IN4_Offset_ptr);

float32_t  ADC3_IN1_OffsetCalc(ADC3_IN1_MA *ADC3_IN1_Offset_ptr);

float32_t  ADC3_IN2_OffsetCalc(ADC3_IN2_MA *ADC3_IN2_Offset_ptr);


#endif /* INC__ADCN_INX_OFFSET_H_ */
