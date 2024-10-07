/*
 * _DMA_Sort.h
 *
 *  Created on: Sep 14, 2024
 *  Author: Mwangi Alex. W
 *
 *  This header file holds all the variables and buffers within a struct that are neccessary to implement the sorting algorithm and all fucnction declarations
 *  for the same algorithm. The sorting algorithm is responsible for scanning the DMA buffer that stores data for all channels (IN1 and IN2 for ADC1 and ADC3,
 *  IN3 and IN4 for ADC2), loading each value from the buffer and storing it in buffers that now hold data for respective channels
 */

#ifndef INC__DMA_SORT_H_
#define INC__DMA_SORT_H_

// MACROS
enum
{
ADC_DMA_BUFFERSIZE= 2500,
ADC_DMA_HALFBUFFERSIZE= 1250,
ADC_DMA_QUATERBUFFERSIZE= 625,
ADC_DMA_EIGHTHBUFFERSIZE= 312,
ADC_DMA_SIXTEENTHBUFFERSIZE=160
};

//INCLUDES
#include "stm32g4xx_hal.h"

//STRUCTS, VARIABLES AND POINTERS
typedef struct //Struct for ADC1
{
	uint32_t ADC1_DMA_bfr[ADC_DMA_BUFFERSIZE]; // Buffer that stores the ADC conversions-source buffer
	uint32_t ADC1_DMA_mon; // Variable to monitor one value from the DMA buffer

	uint32_t ADC1_IN1_bfr[ADC_DMA_HALFBUFFERSIZE]; // Buffer that stores sorted IN1 data
	uint32_t ADC1_IN1_mon; // Variable to monitor one value from the IN1 data buffer

	uint32_t ADC1_IN2_bfr[ADC_DMA_HALFBUFFERSIZE];  // Buffer that stores sorted IN2 data
	uint32_t ADC1_IN2_mon; // Variable to monitor one value from the IN2 data buffer

} ADC1_DMA_sort;

extern ADC1_DMA_sort*ADC1_DMA_sort_ptr;  // Pointer to the struct


typedef struct //Struct for ADC2
{
	uint32_t ADC2_DMA_bfr[ADC_DMA_BUFFERSIZE];
	uint32_t ADC2_DMA_mon;

	uint32_t ADC2_IN3_bfr[ADC_DMA_HALFBUFFERSIZE];
	uint32_t ADC2_IN3_mon;

	uint32_t ADC2_IN4_bfr[ADC_DMA_HALFBUFFERSIZE];
	uint32_t ADC2_IN4_mon;

} ADC2_DMA_sort;

extern ADC2_DMA_sort*ADC2_DMA_sort_ptr;


typedef struct //Struct for ADC3
{
	uint32_t ADC3_DMA_bfr[ADC_DMA_BUFFERSIZE];
	uint32_t ADC3_DMA_mon;

	uint32_t ADC3_IN1_bfr[ADC_DMA_HALFBUFFERSIZE];
	uint32_t ADC3_IN1_mon;

	uint32_t ADC3_IN2_bfr[ADC_DMA_HALFBUFFERSIZE];
	uint32_t ADC3_IN2_mon;

} ADC3_DMA_sort;

extern ADC3_DMA_sort*ADC3_DMA_sort_ptr;


//FUNCTION DECLARATIONS
/* Loads data from the upper half of the DMA buffer for ADC1 (When a half complete call back is fired) and stores it in two buffers; one for channel one data and another for the channel 2 data such that they are stored independently */
void ADC1_DMA_sort_uhb (void);
/* Loads data from the lower half of the DMA buffer for ADC1 (When a complete call back is fired) and stores it in two buffers; one for channel one data and another for the channel 2 data such that they are stored independently */
void ADC1_DMA_sort_lhb (void);

void ADC2_DMA_sort_uhb (void);
void ADC2_DMA_sort_lhb (void);

void ADC3_DMA_sort_uhb (void);
void ADC3_DMA_sort_lhb (void);

#endif /* INC__DMA_SORT_H_ */
