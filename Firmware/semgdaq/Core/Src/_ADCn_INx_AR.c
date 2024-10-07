/*
 * _ADCn_INx_AR.c
 *
 * Created on: Oct 7, 2024
 * Author: Mwangi Alex. W
 */

//INCLUDES
#include "_ADCn_INx_AR.h"

//VARIABLES
float32_t AutoCorr_1[AR_ORDER];
float32_t AutoCorr_2[AR_ORDER];
float32_t AutoCorr_3[AR_ORDER];
float32_t AutoCorr_4[AR_ORDER];
float32_t AutoCorr_5[AR_ORDER];
float32_t AutoCorr_6[AR_ORDER];

ADC1_IN1_MA AR_ADC1_IN1; // Declaring an instance of Auto-regression feature
ADC1_IN2_MA AR_ADC1_IN2;
ADC2_IN3_MA AR_ADC2_IN3;
ADC2_IN4_MA AR_ADC2_IN4;
ADC3_IN1_MA AR_ADC3_IN1;
ADC3_IN2_MA AR_ADC3_IN2;

//FUNCTION DEFINITIONS
void ADC1_IN1_autocorr_calc(void)
{
	/* Iterate through each lag*/
	for(uint32_t n=0; n<AR_ORDER; n++)
	{
		float32_t result_1 = 0.0f; // Initializing it to zero before calculation

		/* Number of valid points for the dot product at this lag */
		uint32_t Blocksize_1 = ADC_DMA_SIXTEENTHBUFFERSIZE - AR_ORDER;

		arm_dot_prod_f32(&(AR_ADC1_IN1.MA_ADC1_IN1_OutBfr[n]), AR_ADC1_IN1.MA_ADC1_IN1_OutBfr, Blocksize_1, &result_1);

		AutoCorr_1[n] = result_1 / ADC_DMA_SIXTEENTHBUFFERSIZE;
	}
}


void ADC1_IN2_autocorr_calc(void)
{
	/* Iterate through each lag*/
	for(uint32_t n=0; n<AR_ORDER; n++)
	{
		float32_t result_2 = 0.0f; // Initializing it to zero before calculation

		/* Number of valid points for the dot product at this lag */
		uint32_t Blocksize_2 = ADC_DMA_SIXTEENTHBUFFERSIZE - AR_ORDER;

		arm_dot_prod_f32(&(AR_ADC1_IN2.MA_ADC1_IN2_OutBfr[n]), AR_ADC1_IN2.MA_ADC1_IN2_OutBfr, Blocksize_2, &result_2);

		AutoCorr_2[n] = result_2 / ADC_DMA_SIXTEENTHBUFFERSIZE;
	}
}


void ADC2_IN3_autocorr_calc(void)
{
	/* Iterate through each lag*/
	for(uint32_t n=0; n<AR_ORDER; n++)
	{
		float32_t result_3 = 0.0f; // Initializing it to zero before calculation

		/* Number of valid points for the dot product at this lag */
		uint32_t Blocksize_3 = ADC_DMA_SIXTEENTHBUFFERSIZE - AR_ORDER;

		arm_dot_prod_f32(&(AR_ADC2_IN3.MA_ADC2_IN3_OutBfr[n]), AR_ADC2_IN3.MA_ADC2_IN3_OutBfr, Blocksize_3, &result_3);

		AutoCorr_3[n] = result_3 / ADC_DMA_SIXTEENTHBUFFERSIZE;
	}
}


void ADC2_IN4_autocorr_calc(void)
{
	/* Iterate through each lag*/
	for(uint32_t n=0; n<AR_ORDER; n++)
	{
		float32_t result_4 = 0.0f; // Initializing it to zero before calculation

		/* Number of valid points for the dot product at this lag */
		uint32_t Blocksize_4 = ADC_DMA_SIXTEENTHBUFFERSIZE - AR_ORDER;

		arm_dot_prod_f32(&(AR_ADC2_IN4.MA_ADC2_IN4_OutBfr[n]), AR_ADC2_IN4.MA_ADC2_IN4_OutBfr, Blocksize_4, &result_4);

		AutoCorr_4[n] = result_4 / ADC_DMA_SIXTEENTHBUFFERSIZE;
	}
}


void ADC3_IN1_autocorr_calc(void)
{
	/* Iterate through each lag*/
	for(uint32_t n=0; n<AR_ORDER; n++)
	{
		float32_t result_5 = 0.0f; // Initializing it to zero before calculation

		/* Number of valid points for the dot product at this lag */
		uint32_t Blocksize_5 = ADC_DMA_SIXTEENTHBUFFERSIZE - AR_ORDER;

		arm_dot_prod_f32(&(AR_ADC3_IN1.MA_ADC3_IN1_OutBfr[n]), AR_ADC3_IN1.MA_ADC3_IN1_OutBfr, Blocksize_5, &result_5);

		AutoCorr_5[n] = result_5 / ADC_DMA_SIXTEENTHBUFFERSIZE;
	}
}


void ADC3_IN2_autocorr_calc(void)
{
	/* Iterate through each lag*/
	for(uint32_t n=0; n<AR_ORDER; n++)
	{
		float32_t result_6 = 0.0f; // Initializing it to zero before calculation

		/* Number of valid points for the dot product at this lag */
		uint32_t Blocksize_6 = ADC_DMA_SIXTEENTHBUFFERSIZE - AR_ORDER;

		arm_dot_prod_f32(&(AR_ADC3_IN2.MA_ADC3_IN2_OutBfr[n]), AR_ADC3_IN2.MA_ADC3_IN2_OutBfr, Blocksize_6, &result_6);

		AutoCorr_6[n] = result_6 / ADC_DMA_SIXTEENTHBUFFERSIZE;
	}
}
