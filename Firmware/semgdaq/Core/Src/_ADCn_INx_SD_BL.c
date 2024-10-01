/*
 * _ADCn_INx_SD_BL.c
 *
 *  Created on: Oct 1, 2024
 *  Author: Mwangi Alex. W
 */

//INCLUSIONS
#include "_ADCn_INx_SD_BL.h"

//FUNCTION DEFINITIONS
float32_t  ADC1_IN1_SD_BL(ADC1_IN1_MA *ADC1_IN1_SD_BL_ptr, float32_t Mean_1)
{
  float32_t Variance_1 = 0.0f;
  for (uint32_t  q=0; q<ADC_DMA_SIXTEENTHBUFFERSIZE; q++)
  {
	  float32_t Diff_1 = ADC1_IN1_SD_BL_ptr->MA_ADC1_IN1_OutBfr[q] - Mean_1;
	  Variance_1 += Diff_1 * Diff_1;
  }

  Variance_1 /= ADC_DMA_SIXTEENTHBUFFERSIZE; // Average the squared differences

  return sqrt(Variance_1); //Square root of variance
}


float32_t  ADC1_IN2_SD_BL(ADC1_IN2_MA *ADC1_IN2_SD_BL_ptr, float32_t Mean_2)
{
  float32_t Variance_2 = 0.0f;
  for (uint32_t  s=0; s<ADC_DMA_SIXTEENTHBUFFERSIZE; s++)
  {
	  float32_t Diff_2 = ADC1_IN2_SD_BL_ptr->MA_ADC1_IN2_OutBfr[s] - Mean_2;
	  Variance_2 += Diff_2 * Diff_2;
  }

  Variance_2 /= ADC_DMA_SIXTEENTHBUFFERSIZE; // Average the squared differences

 return sqrt(Variance_2); //Square root of variance

}


float32_t  ADC2_IN3_SD_BL(ADC2_IN3_MA *ADC2_IN3_SD_BL_ptr, float32_t Mean_3)
{
  float32_t Variance_3 = 0.0f;
  for (uint32_t  v=0; v<ADC_DMA_SIXTEENTHBUFFERSIZE; v++)
  {
	  float32_t Diff_3 = ADC2_IN3_SD_BL_ptr->MA_ADC2_IN3_OutBfr[v] - Mean_3;
	  Variance_3 += Diff_3 * Diff_3;
  }

  Variance_3 /= ADC_DMA_SIXTEENTHBUFFERSIZE; // Average the squared differences

  return sqrt(Variance_3); //Square root of variance

}


float32_t  ADC2_IN4_SD_BL(ADC2_IN4_MA *ADC2_IN4_SD_BL_ptr, float32_t Mean_4)
{
  float32_t Variance_4 = 0.0f;
  for (uint32_t  w=0; w<ADC_DMA_SIXTEENTHBUFFERSIZE; w++)
  {
	  float32_t Diff_4 = ADC2_IN4_SD_BL_ptr->MA_ADC2_IN4_OutBfr[w] - Mean_4;
	  Variance_4 += Diff_4 * Diff_4;
  }

  Variance_4 /= ADC_DMA_SIXTEENTHBUFFERSIZE; // Average the squared differences

 return sqrt(Variance_4); //Square root of variance

}



float32_t  ADC3_IN1_SD_BL(ADC3_IN1_MA *ADC3_IN1_SD_BL_ptr, float32_t Mean_5)
{
  float32_t Variance_5 = 0.0f;
  for (uint32_t  d=0; d<ADC_DMA_SIXTEENTHBUFFERSIZE; d++)
  {
	  float32_t Diff_5 = ADC3_IN1_SD_BL_ptr->MA_ADC3_IN1_OutBfr[d] - Mean_5;
	  Variance_5 += Diff_5 * Diff_5;
  }

  Variance_5 /= ADC_DMA_SIXTEENTHBUFFERSIZE; // Average the squared differences

 return sqrt(Variance_5); //Square root of variance

}



float32_t  ADC3_IN2_SD_BL(ADC3_IN2_MA *ADC3_IN2_SD_BL_ptr, float32_t Mean_6)
{
  float32_t Variance_6 = 0.0f;
  for (uint32_t  c=0; c<ADC_DMA_SIXTEENTHBUFFERSIZE; c++)
  {
	  float32_t Diff_6 = ADC3_IN2_SD_BL_ptr->MA_ADC3_IN2_OutBfr[c] - Mean_6;
	  Variance_6 += Diff_6 * Diff_6;
  }

  Variance_6 /= ADC_DMA_SIXTEENTHBUFFERSIZE; // Average the squared differences

  return sqrt(Variance_6); //Square root of variance

}
