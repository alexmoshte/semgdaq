/*
 * _ADCn_INx_Trans.h
 *
 *  Created on: Oct 20, 2024
 *  Author: Mwangi Alex. W
 */

#ifndef INC__ADCN_INX_TRANS_H_
#define INC__ADCN_INX_TRANS_H_

//INCLUDES
#include "_ADCn_INx_DAC1_Cond.h"

//DEFINES
#define FV_ORDER (2 + AR_ORDER + (ADC_DMA_SIXTEENTHBUFFERSIZE / 2))

//VARIABLES
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

uint8_t Feature_Vector_1[FV_ORDER + 1];
uint8_t Feature_Vector_2[FV_ORDER + 1];
uint8_t Feature_Vector_3[FV_ORDER + 1];
uint8_t Feature_Vector_4[FV_ORDER + 1];
uint8_t Feature_Vector_5[FV_ORDER + 1];
uint8_t Feature_Vector_6[FV_ORDER + 1];

//FUNCTION DECLARATION
void USART1_ADC1_IN1_TXFV_DMA(float32_t tkeo_1, float32_t ssc_1, float32_t* ar_1, uint32_t AR_order_1, float32_t* stft_1, uint32_t stft_order_1);
void USART2_ADC2_IN3_TXFV_DMA(float32_t tkeo_3, float32_t ssc_3, float32_t* ar_3, uint32_t AR_order_3, float32_t* stft_3, uint32_t stft_order_3);
void USART3_ADC3_IN1_TXFV_DMA(float32_t tkeo_5, float32_t ssc_5, float32_t* ar_5, uint32_t AR_order_5, float32_t* stft_5, uint32_t stft_order_5);
void I2C1_ADC1_IN2_TXFV_DMA(float32_t tkeo_2, float32_t ssc_2, float32_t* ar_2, uint32_t AR_order_2, float32_t* stft_2, uint32_t stft_order_2);
void I2C2_ADC2_IN4_TXFV_DMA(float32_t tkeo_4, float32_t ssc_4, float32_t* ar_4, uint32_t AR_order_4, float32_t* stft_4, uint32_t stft_order_4);
void I2C3_ADC3_IN2_TXFV_DMA(float32_t tkeo_5, float32_t ssc_5, float32_t* ar_5, uint32_t AR_order_5, float32_t* stft_5, uint32_t stft_order_5);



#endif /* INC__ADCN_INX_TRANS_H_ */
