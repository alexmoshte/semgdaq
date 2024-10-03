/*
 * _ADCn_INx_Offset.c
 *
 *  Created on: Oct 1, 2024
 *  Author: Mwangi Alex. W
 *
 *  Calculates the mean for the baseline signal (signal without muscle activation-arm(s) still) and uses
 *  this value as the offset to the signal(s) for each channel once muscle activation occurs
 */

//INCLUDES
#include "_ADCn_INx_Offset.h"

float32_t  ADC1_IN1_OffsetCalc(ADC1_IN1_MA *ADC1_IN1_Offset_ptr)
{
	float32_t Sum_1 = 0.0f; // Initialize the sum to zero

	for (uint32_t h=0; h<ADC_DMA_SIXTEENTHBUFFERSIZE; h++)
	{
		Sum_1 += ADC1_IN1_Offset_ptr->MA_ADC1_IN1_OutBfr[h];  // Accumulate the sum of all values in the moving average buffer
	}

	return Sum_1/ADC_DMA_SIXTEENTHBUFFERSIZE; // Return the mean (baseline)
}



float32_t  ADC1_IN2_OffsetCalc(ADC1_IN2_MA *ADC1_IN2_Offset_ptr)
{
	float32_t Sum_2 = 0.0f;

	for (uint32_t h=0; h<ADC_DMA_SIXTEENTHBUFFERSIZE; h++)
	{
		Sum_2 += ADC1_IN2_Offset_ptr->MA_ADC1_IN2_OutBfr[h];
	}

	return Sum_2/ADC_DMA_SIXTEENTHBUFFERSIZE;
}



float32_t  ADC2_IN3_OffsetCalc(ADC2_IN3_MA *ADC2_IN3_Offset_ptr)
{
	float32_t Sum_3 = 0.0f;

	for (uint32_t h=0; h<ADC_DMA_SIXTEENTHBUFFERSIZE; h++)
	{
		Sum_3 += ADC2_IN3_Offset_ptr->MA_ADC2_IN3_OutBfr[h];
	}

	return Sum_3/ADC_DMA_SIXTEENTHBUFFERSIZE;
}



float32_t  ADC2_IN4_OffsetCalc(ADC2_IN4_MA *ADC2_IN4_Offset_ptr)
{
	float32_t Sum_4 = 0.0f;

	for (uint32_t h=0; h<ADC_DMA_SIXTEENTHBUFFERSIZE; h++)
	{
		Sum_4 += ADC2_IN4_Offset_ptr->MA_ADC2_IN4_OutBfr[h];
	}

	return Sum_4/ADC_DMA_SIXTEENTHBUFFERSIZE;
}



float32_t  ADC3_IN1_OffsetCalc(ADC3_IN1_MA *ADC3_IN1_Offset_ptr)
{
	float32_t Sum_5 = 0.0f; // Initialize the sum to zero

	for (uint32_t h=0; h<ADC_DMA_SIXTEENTHBUFFERSIZE; h++)
	{
		Sum_5 += ADC3_IN1_Offset_ptr->MA_ADC3_IN1_OutBfr[h];  // Accumulate the sum of all values in the buffer
	}

	return Sum_5/ADC_DMA_SIXTEENTHBUFFERSIZE; // Return the mean (baseline)
}



float32_t  ADC3_IN2_OffsetCalc(ADC3_IN2_MA *ADC3_IN2_Offset_ptr)
{
	float32_t Sum_6 = 0.0f;

	for (uint32_t h=0; h<ADC_DMA_SIXTEENTHBUFFERSIZE; h++)
	{
		Sum_6 += ADC3_IN2_Offset_ptr->MA_ADC3_IN2_OutBfr[h];
	}

	return Sum_6/ADC_DMA_SIXTEENTHBUFFERSIZE;
}
