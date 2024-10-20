/*
 * _ADCn_INx_DAC1_Cond.c
 *
 *  Created on: Oct 15, 2024
 *  Author: Mwangi Alex. W
 *
 *  The functions defined here within port data from the moving average output buffer for all channels to DAC1.
 *  The functions run under conditional compilation such that only one channel on the right and another on the left of the semgdaq
 *  are ported to channel one and two of the DAC1 respectively. That way, we can only monitor two channels at the same time using and oscilloscope but can
 *  monitor other channel combinations simply by changing the definitions
 */

//INCLUDES
#include "_ADCn_INx_DAC1_Cond.h"

//FUNCTION DEFINITIONS
#ifdef MONITOR_CHANNEL_1_LEFT
void ADC1_IN1_DAC_Update(ADC1_IN1_MA *ADC1_IN1_DAC_ptr)
{
	for (uint32_t n = 0; n < ADC_DMA_SIXTEENTHBUFFERSIZE; n++)
	{
	    float Filt_Volt_1 = ADC1_IN1_DAC_ptr->MA_ADC1_IN1_OutBfr[n];
	    uint32_t DAC_Level_1 = (Filt_Volt_1 / LEVEL_VALUE_SCALAR); // Converting the voltages (0-3.3V) to levels (0-4096) for the DAC

	    /* Ensure the DAC level is within bounds */
	    if (DAC_Level_1 > 4095)
	    {
	        DAC_Level_1 = 4095;
	    }
	    else if (DAC_Level_1 < 0)
	    {
	        DAC_Level_1 = 0;
	    }

	    ADC1_IN1_DAC_ptr->MA_ADC1_IN1_Level_OutBfr[n] = DAC_Level_1;
	}

   HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_1, (uint32_t* )ADC1_IN1_DAC_ptr->MA_ADC1_IN1_Level_OutBfr, ADC_DMA_SIXTEENTHBUFFERSIZE, DAC_ALIGN_12B_R);
}
#endif

#ifdef MONITOR_CHANNEL_2_LEFT
void ADC2_IN3_DAC_Update(ADC2_IN3_MA *ADC2_IN3_DAC_ptr)
{
	for (uint32_t n = 0; n < ADC_DMA_SIXTEENTHBUFFERSIZE; n++)
	{
		float Filt_Volt_2 = ADC2_IN3_DAC_ptr->MA_ADC2_IN3_OutBfr[n];
		uint32_t DAC_Level_2 = (Filt_Volt_2 / LEVEL_VALUE_SCALAR);

		if (DAC_Level_2 > 4095)
		{
			DAC_Level_2 = 4095;
		}
		else if (DAC_Level_2 < 0)
		{
			DAC_Level_2 = 0;
		}

		ADC2_IN3_DAC_ptr->MA_ADC2_IN3_Level_OutBfr[n] = DAC_Level_2;
	}

   HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_1, (uint32_t* )ADC2_IN3_DAC_ptr->MA_ADC2_IN3_Level_OutBfr, ADC_DMA_SIXTEENTHBUFFERSIZE, DAC_ALIGN_12B_R);
}
#endif

#ifdef MONITOR_CHANNEL_3_LEFT
void ADC3_IN1_DAC_Update(ADC3_IN1_MA *ADC3_IN1_DAC_ptr)
{
	for (uint32_t n = 0; n < ADC_DMA_SIXTEENTHBUFFERSIZE; n++)
	{
		float Filt_Volt_3 = ADC3_IN1_DAC_ptr->MA_ADC3_IN1_OutBfr[n];
		uint32_t DAC_Level_3 = (Filt_Volt_3 / LEVEL_VALUE_SCALAR);

		if (DAC_Level_3 > 4095)
		{
			DAC_Level_3 = 4095;
		}
		else if (DAC_Level_3 < 0)
		{
			DAC_Level_3 = 0;
		}

		ADC3_IN1_DAC_ptr->MA_ADC3_IN1_Level_OutBfr[n] = DAC_Level_3;
	}

   HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_1, (uint32_t* )ADC3_IN1_DAC_ptr->MA_ADC3_IN1_Level_OutBfr, ADC_DMA_SIXTEENTHBUFFERSIZE, DAC_ALIGN_12B_R);
}
#endif


#ifdef MONITOR_CHANNEL_4_RIGHT
void ADC1_IN2_DAC_Update(ADC1_IN2_MA *ADC1_IN2_DAC_ptr)
{
	for (uint32_t n = 0; n < ADC_DMA_SIXTEENTHBUFFERSIZE; n++)
	{
		float Filt_Volt_4 = ADC1_IN2_DAC_ptr->MA_ADC1_IN2_OutBfr[n];
		uint32_t DAC_Level_4 = (Filt_Volt_4 / LEVEL_VALUE_SCALAR);

		if (DAC_Level_4 > 4095)
		{
			DAC_Level_4 = 4095;
		}
		else if (DAC_Level_4 < 0)
		{
			DAC_Level_4 = 0;
		}

		ADC1_IN2_DAC_ptr->MA_ADC1_IN2_Level_OutBfr[n] = DAC_Level_4;
	}

   HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_2, (uint32_t* )ADC1_IN2_DAC_ptr->MA_ADC1_IN2_Level_OutBfr, ADC_DMA_SIXTEENTHBUFFERSIZE, DAC_ALIGN_12B_R);
}
#endif

#ifdef MONITOR_CHANNEL_5_RIGHT
void ADC2_IN4_DAC_Update(ADC2_IN4_MA *ADC2_IN4_DAC_ptr)
{
	for (uint32_t n = 0; n < ADC_DMA_SIXTEENTHBUFFERSIZE; n++)
	{
		float Filt_Volt_5 = ADC2_IN4_DAC_ptr->MA_ADC2_IN4_OutBfr[n];
		uint32_t DAC_Level_5 = (Filt_Volt_5 / LEVEL_VALUE_SCALAR);

		if (DAC_Level_5 > 4095)
		{
			DAC_Level_5 = 4095;
		}
		else if (DAC_Level_5 < 0)
		{
			DAC_Level_5 = 0;
		}

		ADC2_IN4_DAC_ptr->MA_ADC2_IN4_Level_OutBfr[n] = DAC_Level_5;
	}

   HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_2, (uint32_t* )ADC2_IN4_DAC_ptr->MA_ADC2_IN4_Level_OutBfr, ADC_DMA_SIXTEENTHBUFFERSIZE, DAC_ALIGN_12B_R);
}
#endif

#ifdef MONITOR_CHANNEL_6_RIGHT
void ADC3_IN2_DAC_Update(ADC3_IN2_MA *ADC3_IN2_DAC_ptr)
{
	for (uint32_t n = 0; n < ADC_DMA_SIXTEENTHBUFFERSIZE; n++)
	{
		float Filt_Volt_6 = ADC3_IN2_DAC_ptr->MA_ADC3_IN2_OutBfr[n];
		uint32_t DAC_Level_6 = (Filt_Volt_6 / LEVEL_VALUE_SCALAR); // Converting the voltages (0-3.3V) to levels (0-4096) for the DAC

		/*  Ensure the DAC level is within bounds */
		if (DAC_Level_6 > 4095)
		{
			DAC_Level_6 = 4095;
		}
		else if (DAC_Level_6 < 0)
		{
			DAC_Level_6 = 0;
		}

		ADC3_IN2_DAC_ptr->MA_ADC3_IN2_Level_OutBfr[n] = DAC_Level_6;
	}

   HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_2, (uint32_t* )ADC3_IN2_DAC_ptr->MA_ADC3_IN2_Level_OutBfr, ADC_DMA_SIXTEENTHBUFFERSIZE, DAC_ALIGN_12B_R);
}
#endif

