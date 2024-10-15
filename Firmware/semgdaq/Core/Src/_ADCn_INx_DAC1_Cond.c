/*
 * _ADCn_INx_DAC1_Cond.c
 *
 *  Created on: Oct 15, 2024
 *  Author: Mwangi Alex. W
 *
 *  The functions defined here within port data from the moving average output buffer for all channels to DAC1.
 *  The functions run under conditional compilation such that only one channel on the right and on the left of the semgdaq
 *  are ported to channel one and two of DAC1 respectively. That way, we can only monitor two channels at the same time but can
 *  monitor other channel combinations simply by changing the definitions
 */

//INCLUDES
#include "_ADCn_INx_DAC1_Cond.h"

//VARIABLES, STRUCTS & INSTANCES
 DAC_HandleTypeDef hdac1;
 DMA_HandleTypeDef hdma_dac1_ch1;
 DMA_HandleTypeDef hdma_dac1_ch2;


//FUNCTION DEFINITIONS

#define MONITOR_CHANNEL_1_LEFT
#ifdef MONITOR_CHANNEL_1_LEFT
void ADC1_IN1_DAC_Update(ADC1_IN1_MA *ADC1_IN1_DAC_ptr)
{
   HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_1, (uint32_t* )ADC1_IN1_DAC_ptr->MA_ADC1_IN1_OutBfr, ADC_DMA_SIXTEENTHBUFFERSIZE, DAC_ALIGN_12B_R);
}
#endif

#ifdef MONITOR_CHANNEL_2_LEFT
void ADC2_IN3_DAC_Update(ADC2_IN3_MA *ADC2_IN3_DAC_ptr)
{
   HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_1, (uint32_t* )ADC2_IN3_DAC_ptr->MA_ADC2_IN3_OutBfr, ADC_DMA_SIXTEENTHBUFFERSIZE, DAC_ALIGN_12B_R);
}
#endif

#ifdef MONITOR_CHANNEL_3_LEFT
void ADC3_IN1_DAC_Update(ADC3_IN1_MA *ADC3_IN1_DAC_ptr)
{
   HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_1, (uint32_t* )ADC3_IN1_DAC_ptr->MA_ADC3_IN1_OutBfr, ADC_DMA_SIXTEENTHBUFFERSIZE, DAC_ALIGN_12B_R);
}
#endif


#define MONITOR_CHANNEL_4_RIGHT
#ifdef MONITOR_CHANNEL_4_RIGHT
void ADC1_IN2_DAC_Update(ADC1_IN2_MA *ADC1_IN2_DAC_ptr)
{
   HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_2, (uint32_t* )ADC1_IN2_DAC_ptr->MA_ADC1_IN2_OutBfr, ADC_DMA_SIXTEENTHBUFFERSIZE, DAC_ALIGN_12B_R);
}
#endif

#ifdef MONITOR_CHANNEL_5_RIGHT
void ADC2_IN4_DAC_Update(ADC2_IN4_MA *ADC2_IN4_DAC_ptr)
{
   HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_2, (uint32_t* )ADC2_IN3_DAC_ptr->MA_ADC2_IN3_OutBfr, ADC_DMA_SIXTEENTHBUFFERSIZE, DAC_ALIGN_12B_R);
}
#endif

#ifdef MONITOR_CHANNEL_6_RIGHT
void ADC3_IN2_DAC_Update(ADC3_IN2_MA *ADC3_IN2_DAC_ptr)
{
   HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_2, (uint32_t* )ADC3_IN2_DAC_ptr->MA_ADC3_IN2_OutBfr, ADC_DMA_SIXTEENTHBUFFERSIZE, DAC_ALIGN_12B_R);
}
#endif
