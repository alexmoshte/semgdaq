/*
 * _ADCn_INx_MA.h
 *
 * Created on: Sep 25, 2024
 * Author: Mwangi Alex. W
 *
 * Declares the structs necessary to conduct moving average filtering from the output of the notch filters to eradicate
 * baseline drift and smoothen data. The moving average filter is a low roll-off low pass filter that ensures the data we accrue
 * from the board is minimized of disturbances that arise from arm movements that cause baseline drift and  don't entail sEMG signal collection and also ensures
 * that the data is smooth.
 *
 */

#ifndef INC__ADCN_INX_MA_H_
#define INC__ADCN_INX_MA_H_

//INCLUSIONS
#include "_ADCn_INx_NF.h"

//MACROS
#define MA_FILTER_LENGTH 8

//STRUCTS, BUFFERS AND VARIABLES
typedef struct
{
	uint32_t MA_ADC1_IN1_bfr_indx;

	float32_t MA_ADC1_IN1_bfr[MA_FILTER_LENGTH]; // Buffer where present and past samples are stores for convolution

	float32_t MA_ADC1_IN1_OutBfr[ADC_DMA_SIXTEENTHBUFFERSIZE]; // Output Buffer

	float32_t MA_ADC1_IN1_Level_OutBfr[ADC_DMA_SIXTEENTHBUFFERSIZE]; // Output Buffer that stores the data converted from voltage values (0-3.3V) to levels (0-4096). The levels are fed to the DAC for monitoring

} ADC1_IN1_MA;


typedef struct
{
	uint32_t MA_ADC1_IN2_bfr_indx;

	float32_t MA_ADC1_IN2_bfr[MA_FILTER_LENGTH];

	float32_t MA_ADC1_IN2_OutBfr[ADC_DMA_SIXTEENTHBUFFERSIZE];

	float32_t MA_ADC1_IN2_Level_OutBfr[ADC_DMA_SIXTEENTHBUFFERSIZE];

} ADC1_IN2_MA;


typedef struct
{
	uint32_t MA_ADC2_IN3_bfr_indx;

	float32_t MA_ADC2_IN3_bfr[MA_FILTER_LENGTH];

	float32_t MA_ADC2_IN3_OutBfr[ADC_DMA_SIXTEENTHBUFFERSIZE];

	float32_t MA_ADC2_IN3_Level_OutBfr[ADC_DMA_SIXTEENTHBUFFERSIZE];

} ADC2_IN3_MA;


typedef struct
{
	uint32_t MA_ADC2_IN4_bfr_indx;

	float32_t MA_ADC2_IN4_bfr[MA_FILTER_LENGTH];

	float32_t MA_ADC2_IN4_OutBfr[ADC_DMA_SIXTEENTHBUFFERSIZE];

	float32_t MA_ADC2_IN4_Level_OutBfr[ADC_DMA_SIXTEENTHBUFFERSIZE];

} ADC2_IN4_MA;


typedef struct
{
	uint32_t MA_ADC3_IN1_bfr_indx;

	float32_t MA_ADC3_IN1_bfr[MA_FILTER_LENGTH]; // Buffer where present and past samples are stores for convolution

	float32_t MA_ADC3_IN1_OutBfr[ADC_DMA_SIXTEENTHBUFFERSIZE]; // Output Buffer

	float32_t MA_ADC3_IN1_Level_OutBfr[ADC_DMA_SIXTEENTHBUFFERSIZE]; // Output Buffer that stores the data converted from voltage values (0-3.3V) to levels (0-4096). The levels are fed to the DAC for monitoring

} ADC3_IN1_MA;


typedef struct
{
	uint32_t MA_ADC3_IN2_bfr_indx;

	float32_t MA_ADC3_IN2_bfr[MA_FILTER_LENGTH];

	float32_t MA_ADC3_IN2_OutBfr[ADC_DMA_SIXTEENTHBUFFERSIZE];

	float32_t MA_ADC3_IN2_Level_OutBfr[ADC_DMA_SIXTEENTHBUFFERSIZE];

} ADC3_IN2_MA;


//FUNCTION DECLARATIONS
void MA_ADC1_IN1_Init (ADC1_IN1_MA *ADC1_IN1_MA_ptr);
void MA_ADC1_IN1_Update(ADC1_IN1_MA *ADC1_IN1_MA_ptr);

void MA_ADC1_IN2_Init (ADC1_IN2_MA *ADC1_IN2_MA_ptr);
void MA_ADC1_IN2_Update (ADC1_IN2_MA *ADC1_IN2_MA_ptr);

void MA_ADC2_IN3_Init (ADC2_IN3_MA *ADC2_IN3_MA_ptr);
void MA_ADC2_IN3_Update (ADC2_IN3_MA *ADC2_IN3_MA_ptr);

void MA_ADC2_IN4_Init (ADC2_IN4_MA *ADC2_IN4_MA_ptr);
void MA_ADC2_IN4_Update (ADC2_IN4_MA *ADC2_IN4_MA_ptr);

void MA_ADC3_IN1_Init (ADC3_IN1_MA *ADC3_IN1_MA_ptr);
void MA_ADC3_IN1_Update (ADC3_IN1_MA *ADC3_IN1_MA_ptr);

void MA_ADC3_IN2_Init (ADC3_IN2_MA *ADC3_IN2_MA_ptr);
void MA_ADC3_IN2_Update (ADC3_IN2_MA *ADC3_IN2_MA_ptr);

#endif /* INC__ADCN_INX_MA_H_ */
