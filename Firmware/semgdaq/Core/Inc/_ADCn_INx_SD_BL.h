/*
 * _ADCn_INx_SD_BL.h
 *
 *  Created on: Oct 1, 2024
 *  Author: Mwangi Alex. W
 *
 *  Header file for the functions that calculate the estimate of the standard deviation for the baseline signal before the onset of muscle
 *  activation.
 */

#ifndef INC__ADCN_INX_SD_BL_H_
#define INC__ADCN_INX_SD_BL_H_

//INCLUDES
#include "_ADCn_INx_Offset.h"

//FUNCTION DECLARATIONS
float32_t  ADC1_IN1_SD_BL(ADC1_IN1_MA *ADC1_IN1_SD_BL_ptr, float32_t Mean_1);
float32_t  ADC1_IN2_SD_BL(ADC1_IN2_MA *ADC1_IN2_SD_BL_ptr, float32_t Mean_2);
float32_t  ADC2_IN3_SD_BL(ADC2_IN3_MA *ADC2_IN3_SD_BL_ptr, float32_t Mean_3);
float32_t  ADC2_IN4_SD_BL(ADC2_IN4_MA *ADC2_IN4_SD_BL_ptr, float32_t Mean_4);
float32_t  ADC3_IN1_SD_BL(ADC3_IN1_MA *ADC3_IN1_SD_BL_ptr, float32_t Mean_5);
float32_t  ADC3_IN2_SD_BL(ADC3_IN2_MA *ADC3_IN2_SD_BL_ptr, float32_t Mean_6);

#endif /* INC__ADCN_INX_SD_BL_H_ */
