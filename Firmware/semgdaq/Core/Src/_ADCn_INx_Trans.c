/*
 * _ADCn_INx_Trans.c
 *
 *  Created on: Oct 20, 2024
 *  Author: Mwangi Alex. W
 *
 *
 *  This .c file caters for the transmission of extracted feature data in form of feature vectors using the UART and I2C communication
 *  protocols. The features are first of all serialized and stored in the feature vector buffer before being transmitted. Additionally,
 *  the files caters for transmission in both binary and CSV format optionally such that one can chose either by changing the definition
 *  in the header file as instructed
 *
 */
//INCLUDES
#include "_ADCn_INx_Trans.h"

//FUNCTION DEFINITIONS
void USART1_ADC1_IN1_TXFV_DMA(float32_t tkeo_1, float32_t ssc_1, float32_t* ar_1, uint32_t AR_order_1, float32_t* stft_1, uint32_t stft_order_1)
{
	#ifdef TRANSMIT_BINARY

		uint32_t FV_Indx = 0; // Initialize the feature vector index to zero

		memcpy(&Feature_Vector_1[FV_Indx], &tkeo_1, sizeof(float32_t)); // Copy TKEO_1 as bytes
		FV_Indx += sizeof(float32_t);

		memcpy(&Feature_Vector_1[FV_Indx], &ssc_1, sizeof(float32_t)); // Copy SSC_1 as bytes
		FV_Indx += sizeof(float32_t);

		/* Copy AR_1 coefficients as bytes */
		for(uint32_t n = 0; n < AR_order_1; n++)
		{
			memcpy(&Feature_Vector_1[FV_Indx], &ar_1[n], sizeof(float32_t));
			FV_Indx += sizeof(float32_t);
		}

		/* Copy STFT_1 values as bytes */
		for(uint32_t n = 0; n < stft_order_1; n++)
		{
			memcpy(&Feature_Vector_1[FV_Indx], &stft_1[n], sizeof(float32_t));
			FV_Indx += sizeof(float32_t);
		}

		/* Transmit the feature vector in binary format and with DMA */
		HAL_UART_Transmit_DMA(&huart1, (uint8_t* )Feature_Vector_1, FV_ORDER);

	#endif

	#ifdef TRANSMIT_CSV
		uint32_t FV_Indx = 0;

		 /* Convert the features into a CSV string */
		 FV_Indx += snprintf((char*)(Feature_Vector_1 + FV_Indx), (sizeof(Feature_Vector_1) - FV_Indx), "%.2f,%.2f,", tkeo_1, ssc_1);

		/* Append AR coefficients */
		for (uint32_t i = 0; i < AR_order_1; i++)
		{
			FV_Indx += snprintf((char*)(Feature_Vector_1 + FV_Indx), (sizeof(Feature_Vector_1) - FV_Indx), "%.2f,", ar_1[i]);
		}

		/* Append STFT data */
		for (uint16_t i = 0; i < stft_order_1; i++)
		{
			FV_Indx += snprintf((char*)(Feature_Vector_1 + FV_Indx), (sizeof(Feature_Vector_1) - FV_Indx), "%.2f,", stft_1[i]);
		}

		/* Add a newline character to signify the end of the frame */
		FV_Indx += snprintf((char*)(Feature_Vector_1 + FV_Indx), (sizeof(Feature_Vector_1) - FV_Indx), "\n");

		/* Transmit the feature vector in CSV format and with DMA */
		HAL_UART_Transmit_DMA(&huart1, (uint8_t* )Feature_Vector_1, FV_ORDER);

	#endif
}

void USART2_ADC2_IN3_TXFV_DMA(float32_t tkeo_3, float32_t ssc_3, float32_t* ar_3, uint32_t AR_order_3, float32_t* stft_3, uint32_t stft_order_3)
{
	#ifdef TRANSMIT_BINARY

		uint32_t FV_Indx = 0;

		memcpy(&Feature_Vector_3[FV_Indx], &tkeo_3, sizeof(float32_t));
		FV_Indx += sizeof(float32_t);

		memcpy(&Feature_Vector_3[FV_Indx], &ssc_3, sizeof(float32_t));
		FV_Indx += sizeof(float32_t);

		for(uint32_t n = 0; n < AR_order_3; n++)
		{
			memcpy(&Feature_Vector_3[FV_Indx], &ar_3[n], sizeof(float32_t));
			FV_Indx += sizeof(float32_t);
		}

		for(uint32_t n = 0; n < stft_order_3; n++)
		{
			memcpy(&Feature_Vector_3[FV_Indx], &stft_3[n], sizeof(float32_t));
			FV_Indx += sizeof(float32_t);
		}

		HAL_UART_Transmit_DMA(&huart2, (uint8_t* )Feature_Vector_3, FV_ORDER);

	#endif

	#ifdef TRANSMIT_CSV
		uint32_t FV_Indx = 0;

		 FV_Indx += snprintf((char*)(Feature_Vector_3 + FV_Indx), (sizeof(Feature_Vector_3) - FV_Indx), "%.2f,%.2f,", tkeo_3, ssc_3);

		for (uint32_t i = 0; i < AR_order_3; i++)
		{
			FV_Indx += snprintf((char*)(Feature_Vector_3 + FV_Indx), (sizeof(Feature_Vector_3) - FV_Indx), "%.2f,", ar_3[i]);
		}

		for (uint32_t i = 0; i < stft_order_3; i++)
		{
			FV_Indx += snprintf((char*)(Feature_Vector_3 + FV_Indx), (sizeof(Feature_Vector_3) - FV_Indx), "%.2f,", stft_3[i]);
		}

		FV_Indx += snprintf((char*)(Feature_Vector_3 + FV_Indx), (sizeof(Feature_Vector_3) - FV_Indx), "\n");

		HAL_UART_Transmit_DMA(&huart2, (uint8_t* )Feature_Vector_3, FV_ORDER);

	#endif
}

void USART3_ADC3_IN1_TXFV_DMA(float32_t tkeo_5, float32_t ssc_5, float32_t* ar_5, uint32_t AR_order_5, float32_t* stft_5, uint32_t stft_order_5)
{
	#ifdef TRANSMIT_BINARY

		uint32_t FV_Indx = 0;

		memcpy(&Feature_Vector_5[FV_Indx], &tkeo_5, sizeof(float32_t));
		FV_Indx += sizeof(float32_t);

		memcpy(&Feature_Vector_5[FV_Indx], &ssc_5, sizeof(float32_t));
		FV_Indx += sizeof(float32_t);

		for(uint32_t n = 0; n < AR_order_5; n++)
		{
			memcpy(&Feature_Vector_5[FV_Indx], &ar_5[n], sizeof(float32_t));
			FV_Indx += sizeof(float32_t);
		}

		for(uint32_t n = 0; n < stft_order_5; n++)
		{
			memcpy(&Feature_Vector_5[FV_Indx], &stft_5[n], sizeof(float32_t));
			FV_Indx += sizeof(float32_t);
		}

		HAL_UART_Transmit_DMA(&huart3, (uint8_t* )Feature_Vector_5, FV_ORDER);

	#endif

	#ifdef TRANSMIT_CSV
		uint32_t FV_Indx = 0;

		 FV_Indx += snprintf((char*)(Feature_Vector_5 + FV_Indx), (sizeof(Feature_Vector_5) - FV_Indx), "%.2f,%.2f,", tkeo_5, ssc_5);

		for (uint32_t i = 0; i < AR_order_5; i++)
		{
			FV_Indx += snprintf((char*)(Feature_Vector_5 + FV_Indx), (sizeof(Feature_Vector_5) - FV_Indx), "%.2f,", ar_5[i]);
		}

		for (uint32_t i = 0; i < stft_order_5; i++)
		{
			FV_Indx += snprintf((char*)(Feature_Vector_5 + FV_Indx), (sizeof(Feature_Vector_5) - FV_Indx), "%.2f,", stft_5[i]);
		}

		FV_Indx += snprintf((char*)(Feature_Vector_5 + FV_Indx), (sizeof(Feature_Vector_5) - FV_Indx), "\n");

		HAL_UART_Transmit_DMA(&huart3, (uint8_t* )Feature_Vector_5, FV_ORDER);

	#endif
}
