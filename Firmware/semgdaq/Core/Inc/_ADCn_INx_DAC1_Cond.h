/*
 * _ADCn_INx_DAC1_Cond.h
 *
 *  Created on: Oct 15, 2024
 *  Author: Mwangi Alex. W
 *
 *  Header file for the that handles the conditional compilation for channel monitoring using DAC1
 */

#ifndef INC__ADCN_INX_DAC1_COND_H_
#define INC__ADCN_INX_DAC1_COND_H_

//INCLUDES
#include "_ADCn_INx_STFT.h"

//DEFINES
/* Change the definition depending on which channel you want to monitor */
#define  MONITOR_CHANNEL_2_LEFT
#define MONITOR_CHANNEL_4_RIGHT

//VARIABLES, STRUCTS & INSTANCES
extern DAC_HandleTypeDef hdac1;
extern DMA_HandleTypeDef hdma_dac1_ch1;
extern DMA_HandleTypeDef hdma_dac1_ch2;

//FUNCTION DECLARATIONS
/* The functions below takes values from the moving average buffer of each channel and ports them to the DAC where the output from the DSP schemes is monitored using an oscilloscope */
void ADC1_IN1_DAC_Update(ADC1_IN1_MA *ADC1_IN1_DAC_ptr);
void ADC1_IN2_DAC_Update(ADC1_IN2_MA *ADC1_IN2_DAC_ptr);
void ADC2_IN3_DAC_Update(ADC2_IN3_MA *ADC2_IN3_DAC_ptr);
void ADC2_IN4_DAC_Update(ADC2_IN4_MA *ADC2_IN4_DAC_ptr);
void ADC3_IN1_DAC_Update(ADC3_IN1_MA *ADC3_IN1_DAC_ptr);
void ADC3_IN2_DAC_Update(ADC3_IN2_MA *ADC3_IN2_DAC_ptr);

#endif /* INC__ADCN_INX_DAC1_COND_H_ */
