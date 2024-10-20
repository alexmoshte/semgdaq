/*
 * _ADCn_INx_TKEO.c
 *
 * Created on: Oct 2, 2024
 * Author: Mwangi Alex. W
 *
 * The Teager-Kaiser Energy Operator (TKEO) is a windowing tool used to track the instantaneous energy of the moving average output buffer (segment)
 * so as the evaluate muscle activation. It captures both amplitude and frequency variations to inform us whenever there has been any muscle activation using
 * a thresholding technique that compares the standard deviation of the TKEO data calculated with the standard deviation of the baseline signal
 */

//INCLUDES
#include "_ADCn_INx_TKEO.h"

//VARIABLES
float32_t ADC1_IN1_Tkeo_bfr[ADC_DMA_SIXTEENTHBUFFERSIZE]; // Buffer that stores the TKEO data
float32_t ADC1_IN2_Tkeo_bfr[ADC_DMA_SIXTEENTHBUFFERSIZE];
float32_t ADC2_IN3_Tkeo_bfr[ADC_DMA_SIXTEENTHBUFFERSIZE];
float32_t ADC2_IN4_Tkeo_bfr[ADC_DMA_SIXTEENTHBUFFERSIZE];
float32_t ADC3_IN1_Tkeo_bfr[ADC_DMA_SIXTEENTHBUFFERSIZE];
float32_t ADC3_IN2_Tkeo_bfr[ADC_DMA_SIXTEENTHBUFFERSIZE];


//FUNCTION DEFINITIONS
uint8_t ADC1_IN1_TKEO(ADC1_IN1_MA *ADC1_IN1_TKEO_ptr, float32_t StnDev_BL_1)
{
  for(uint32_t n=1; n<ADC_DMA_SIXTEENTHBUFFERSIZE-1 ; n++)
  {
	  ADC1_IN1_Tkeo_bfr[n]= (ADC1_IN1_TKEO_ptr->MA_ADC1_IN1_OutBfr[n] * ADC1_IN1_TKEO_ptr->MA_ADC1_IN1_OutBfr[n]) - (ADC1_IN1_TKEO_ptr->MA_ADC1_IN1_OutBfr[n-1] * ADC1_IN1_TKEO_ptr->MA_ADC1_IN1_OutBfr[n+1]);
  }

  /* Handling boundary conditions */
  ADC1_IN1_Tkeo_bfr[0] = 0.0f;
  ADC1_IN1_Tkeo_bfr[ADC_DMA_SIXTEENTHBUFFERSIZE-1] = 0.0f;


  float32_t Tkeo_Sum_1 = 0.0f; // Initialize the sum to zero
  float32_t Tkeo_mean_1 =0.0f; // Initialize the mean to zero
  float32_t Tkeo_Variance_1 = 0.0f; // Initialize variance to zero
  float32_t Tkeo_SD_1 = 0.0f; //Initialize standard deviation to zero

  uint8_t Tkeo_flag_1 = 0;

  for (uint32_t h=0; h<ADC_DMA_SIXTEENTHBUFFERSIZE; h++)
  {
	Tkeo_Sum_1 += ADC1_IN1_Tkeo_bfr[h];  // Accumulate the sum of all values in the buffer
  }

  Tkeo_mean_1 = Tkeo_Sum_1 / ADC_DMA_SIXTEENTHBUFFERSIZE;


  for (uint32_t  q=0; q<ADC_DMA_SIXTEENTHBUFFERSIZE; q++)
  {
  	float32_t Tkeo_Diff_1 = ADC1_IN1_Tkeo_bfr[q] - Tkeo_mean_1;
  	Tkeo_Variance_1 += Tkeo_Diff_1 * Tkeo_Diff_1;
  }

  Tkeo_Variance_1 /= ADC_DMA_SIXTEENTHBUFFERSIZE; // Average the squared differences

  Tkeo_SD_1 = sqrt(Tkeo_Variance_1);

  if (Tkeo_SD_1 > 3 * StnDev_BL_1)
  {
	  Tkeo_flag_1 = 1;

	  return  Tkeo_flag_1;
  }

  else
  {
	  return 0;
  }


}


uint8_t ADC1_IN2_TKEO(ADC1_IN2_MA *ADC1_IN2_TKEO_ptr, float32_t StnDev_BL_2)
{
  for(uint32_t n=1; n<ADC_DMA_SIXTEENTHBUFFERSIZE-1 ; n++)
  {
	  ADC1_IN2_Tkeo_bfr[n]= (ADC1_IN2_TKEO_ptr->MA_ADC1_IN2_OutBfr[n] * ADC1_IN2_TKEO_ptr->MA_ADC1_IN2_OutBfr[n]) - (ADC1_IN2_TKEO_ptr->MA_ADC1_IN2_OutBfr[n-1] * ADC1_IN2_TKEO_ptr->MA_ADC1_IN2_OutBfr[n+1]);
  }


  ADC1_IN2_Tkeo_bfr[0] = 0.0f;
  ADC1_IN2_Tkeo_bfr[ADC_DMA_SIXTEENTHBUFFERSIZE-1] = 0.0f;


  float32_t Tkeo_Sum_2 = 0.0f;
  float32_t Tkeo_mean_2 =0.0f;
  float32_t Tkeo_Variance_2 = 0.0f;
  float32_t Tkeo_SD_2 = 0.0f;

  uint8_t Tkeo_flag_2 = 0;

  for (uint32_t h=0; h<ADC_DMA_SIXTEENTHBUFFERSIZE; h++)
  {
	Tkeo_Sum_2 += ADC1_IN2_Tkeo_bfr[h];
  }

  Tkeo_mean_2 = Tkeo_Sum_2 / ADC_DMA_SIXTEENTHBUFFERSIZE;


  for (uint32_t  q=0; q<ADC_DMA_SIXTEENTHBUFFERSIZE; q++)
  {
  	float32_t Tkeo_Diff_2 = ADC1_IN2_Tkeo_bfr[q] - Tkeo_mean_2;
  	Tkeo_Variance_2 += Tkeo_Diff_2 * Tkeo_Diff_2;
  }

  Tkeo_Variance_2 /= ADC_DMA_SIXTEENTHBUFFERSIZE;

  Tkeo_SD_2 = sqrt(Tkeo_Variance_2);

  if (Tkeo_SD_2 > 3 * StnDev_BL_2)
  {
	  Tkeo_flag_2 = 1;

	  return  Tkeo_flag_2;
  }

  else
  {
	  return 0;
  }


}



uint8_t ADC2_IN3_TKEO(ADC2_IN3_MA *ADC2_IN3_TKEO_ptr, float32_t StnDev_BL_3)
{
  for(uint32_t n=1; n<ADC_DMA_SIXTEENTHBUFFERSIZE-1 ; n++)
  {
	  ADC2_IN3_Tkeo_bfr[n]= (ADC2_IN3_TKEO_ptr->MA_ADC2_IN3_OutBfr[n] * ADC2_IN3_TKEO_ptr->MA_ADC2_IN3_OutBfr[n]) - (ADC2_IN3_TKEO_ptr->MA_ADC2_IN3_OutBfr[n-1] * ADC2_IN3_TKEO_ptr->MA_ADC2_IN3_OutBfr[n+1]);
  }


  ADC2_IN3_Tkeo_bfr[0] = 0.0f;
  ADC2_IN3_Tkeo_bfr[ADC_DMA_SIXTEENTHBUFFERSIZE-1] = 0.0f;


  float32_t Tkeo_Sum_3 = 0.0f;
  float32_t Tkeo_mean_3 =0.0f;
  float32_t Tkeo_Variance_3 = 0.0f;
  float32_t Tkeo_SD_3 = 0.0f;

  uint8_t Tkeo_flag_3 = 0;

  for (uint32_t h=0; h<ADC_DMA_SIXTEENTHBUFFERSIZE; h++)
  {
	Tkeo_Sum_3 += ADC2_IN3_Tkeo_bfr[h];
  }

  Tkeo_mean_3 = Tkeo_Sum_3 / ADC_DMA_SIXTEENTHBUFFERSIZE;


  for (uint32_t  q=0; q<ADC_DMA_SIXTEENTHBUFFERSIZE; q++)
  {
  	float32_t Tkeo_Diff_3 = ADC2_IN3_Tkeo_bfr[q] - Tkeo_mean_3;
  	Tkeo_Variance_3 += Tkeo_Diff_3 * Tkeo_Diff_3;
  }

  Tkeo_Variance_3 /= ADC_DMA_SIXTEENTHBUFFERSIZE;

  Tkeo_SD_3 = sqrt(Tkeo_Variance_3);

  if (Tkeo_SD_3 > 3 * StnDev_BL_3)
  {
	  Tkeo_flag_3 = 1;

	  return  Tkeo_flag_3;
  }

  else
  {
	  return 0;
  }


}


uint8_t ADC2_IN4_TKEO(ADC2_IN4_MA *ADC2_IN4_TKEO_ptr, float32_t StnDev_BL_4)
{
  for(uint32_t n=1; n<ADC_DMA_SIXTEENTHBUFFERSIZE-1 ; n++)
  {
	  ADC2_IN4_Tkeo_bfr[n]= (ADC2_IN4_TKEO_ptr->MA_ADC2_IN4_OutBfr[n] * ADC2_IN4_TKEO_ptr->MA_ADC2_IN4_OutBfr[n]) - (ADC2_IN4_TKEO_ptr->MA_ADC2_IN4_OutBfr[n-1] * ADC2_IN4_TKEO_ptr->MA_ADC2_IN4_OutBfr[n+1]);
  }


  ADC2_IN4_Tkeo_bfr[0] = 0.0f;
  ADC2_IN4_Tkeo_bfr[ADC_DMA_SIXTEENTHBUFFERSIZE-1] = 0.0f;


  float32_t Tkeo_Sum_4 = 0.0f;
  float32_t Tkeo_mean_4 =0.0f;
  float32_t Tkeo_Variance_4 = 0.0f;
  float32_t Tkeo_SD_4 = 0.0f;

  uint8_t Tkeo_flag_4 = 0;

  for (uint32_t h=0; h<ADC_DMA_SIXTEENTHBUFFERSIZE; h++)
  {
	Tkeo_Sum_4 += ADC2_IN4_Tkeo_bfr[h];
  }

  Tkeo_mean_4 = Tkeo_Sum_4 / ADC_DMA_SIXTEENTHBUFFERSIZE;


  for (uint32_t  q=0; q<ADC_DMA_SIXTEENTHBUFFERSIZE; q++)
  {
  	float32_t Tkeo_Diff_4 = ADC2_IN4_Tkeo_bfr[q] - Tkeo_mean_4;
  	Tkeo_Variance_4 += Tkeo_Diff_4 * Tkeo_Diff_4;
  }

  Tkeo_Variance_4 /= ADC_DMA_SIXTEENTHBUFFERSIZE;

  Tkeo_SD_4 = sqrt(Tkeo_Variance_4);

  if (Tkeo_SD_4 > 3 * StnDev_BL_4)
  {
	  Tkeo_flag_4 = 1;

	  return  Tkeo_flag_4;
  }

  else
  {
	  return 0;
  }


}



uint8_t ADC3_IN1_TKEO(ADC3_IN1_MA *ADC3_IN1_TKEO_ptr, float32_t StnDev_BL_5)
{
  for(uint32_t n=1; n<ADC_DMA_SIXTEENTHBUFFERSIZE-1 ; n++)
  {
	  ADC3_IN1_Tkeo_bfr[n]= (ADC3_IN1_TKEO_ptr->MA_ADC3_IN1_OutBfr[n] * ADC3_IN1_TKEO_ptr->MA_ADC3_IN1_OutBfr[n]) - (ADC3_IN1_TKEO_ptr->MA_ADC3_IN1_OutBfr[n-1] * ADC3_IN1_TKEO_ptr->MA_ADC3_IN1_OutBfr[n+1]);
  }

  /* Handling boundary conditions */
  ADC3_IN1_Tkeo_bfr[0] = 0.0f;
  ADC3_IN1_Tkeo_bfr[ADC_DMA_SIXTEENTHBUFFERSIZE-1] = 0.0f;


  float32_t Tkeo_Sum_5 = 0.0f; // Initialize the sum to zero
  float32_t Tkeo_mean_5 =0.0f; // Initialize the mean to zero
  float32_t Tkeo_Variance_5 = 0.0f; // Initialize variance to zero
  float32_t Tkeo_SD_5 = 0.0f; //Initialize standard deviation to zero

  uint8_t Tkeo_flag_5 = 0;

  for (uint32_t h=0; h<ADC_DMA_SIXTEENTHBUFFERSIZE; h++)
  {
	Tkeo_Sum_5 += ADC3_IN1_Tkeo_bfr[h];  // Accumulate the sum of all values in the buffer
  }

  Tkeo_mean_5 = Tkeo_Sum_5 / ADC_DMA_SIXTEENTHBUFFERSIZE;


  for (uint32_t  q=0; q<ADC_DMA_SIXTEENTHBUFFERSIZE; q++)
  {
  	float32_t Tkeo_Diff_5 = ADC3_IN1_Tkeo_bfr[q] - Tkeo_mean_5;
  	Tkeo_Variance_5 += Tkeo_Diff_5 * Tkeo_Diff_5;
  }

  Tkeo_Variance_5 /= ADC_DMA_SIXTEENTHBUFFERSIZE; // Average the squared differences

  Tkeo_SD_5 = sqrt(Tkeo_Variance_5);

  if (Tkeo_SD_5 > 3 * StnDev_BL_5)
  {
	  Tkeo_flag_5 = 1;

	  return  Tkeo_flag_5;
  }

  else
  {
	  return 0;
  }


}



uint8_t ADC3_IN2_TKEO(ADC3_IN2_MA *ADC3_IN2_TKEO_ptr, float32_t StnDev_BL_6)
{
  for(uint32_t n=1; n<ADC_DMA_SIXTEENTHBUFFERSIZE-1 ; n++)
  {
	  ADC3_IN2_Tkeo_bfr[n]= (ADC3_IN2_TKEO_ptr->MA_ADC3_IN2_OutBfr[n] * ADC3_IN2_TKEO_ptr->MA_ADC3_IN2_OutBfr[n]) - (ADC3_IN2_TKEO_ptr->MA_ADC3_IN2_OutBfr[n-1] * ADC3_IN2_TKEO_ptr->MA_ADC3_IN2_OutBfr[n+1]);
  }


  ADC3_IN2_Tkeo_bfr[0] = 0.0f;
  ADC3_IN2_Tkeo_bfr[ADC_DMA_SIXTEENTHBUFFERSIZE-1] = 0.0f;


  float32_t Tkeo_Sum_6 = 0.0f;
  float32_t Tkeo_mean_6 =0.0f;
  float32_t Tkeo_Variance_6 = 0.0f;
  float32_t Tkeo_SD_6 = 0.0f;

  uint8_t Tkeo_flag_6 = 0;

  for (uint32_t h=0; h<ADC_DMA_SIXTEENTHBUFFERSIZE; h++)
  {
	Tkeo_Sum_6 += ADC3_IN2_Tkeo_bfr[h];
  }

  Tkeo_mean_6 = Tkeo_Sum_6 / ADC_DMA_SIXTEENTHBUFFERSIZE;


  for (uint32_t  q=0; q<ADC_DMA_SIXTEENTHBUFFERSIZE; q++)
  {
  	float32_t Tkeo_Diff_6 = ADC3_IN2_Tkeo_bfr[q] - Tkeo_mean_6;
  	Tkeo_Variance_6 += Tkeo_Diff_6 * Tkeo_Diff_6;
  }

  Tkeo_Variance_6 /= ADC_DMA_SIXTEENTHBUFFERSIZE;

  Tkeo_SD_6 = sqrt(Tkeo_Variance_6);

  if (Tkeo_SD_6 > 3 * StnDev_BL_6)
  {
	  Tkeo_flag_6 = 1;

	  return  Tkeo_flag_6;
  }

  else
  {
	  return 0;
  }


}



