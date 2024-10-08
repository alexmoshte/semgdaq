/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <_ADCn_INx_AR.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define NOOFITERATIONS_BL 20
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc2;
ADC_HandleTypeDef hadc3;
DMA_HandleTypeDef hdma_adc1;
DMA_HandleTypeDef hdma_adc2;
DMA_HandleTypeDef hdma_adc3;

FMAC_HandleTypeDef hfmac;

TIM_HandleTypeDef htim6;
TIM_HandleTypeDef htim7;
TIM_HandleTypeDef htim20;

/* USER CODE BEGIN PV */
ADC1_DMA_sort*ADC1_DMA_sort_ptr; // Declaring a pointer to the sorting structure at runtime
ADC2_DMA_sort*ADC2_DMA_sort_ptr;
ADC3_DMA_sort*ADC3_DMA_sort_ptr;


ADC1_IN1_MA MovingAverage_ADC1_IN1; // Declaring an instance of the moving average structure
ADC1_IN2_MA MovingAverage_ADC1_IN2;
ADC2_IN3_MA MovingAverage_ADC2_IN3;
ADC2_IN4_MA MovingAverage_ADC2_IN4;
ADC3_IN1_MA MovingAverage_ADC3_IN1;
ADC3_IN2_MA MovingAverage_ADC3_IN2;


ADC1_IN1_MA OffsetCalc_ADC1_IN1; // Declaring an instance of the Offset calculation
ADC1_IN2_MA OffsetCalc_ADC1_IN2;
ADC2_IN3_MA OffsetCalc_ADC2_IN3;
ADC2_IN4_MA OffsetCalc_ADC2_IN4;
ADC3_IN1_MA OffsetCalc_ADC3_IN1;
ADC3_IN2_MA OffsetCalc_ADC3_IN2;


ADC1_IN1_MA SD_BL_ADC1_IN1; // Declaring an instance of standard deviation calculation
ADC1_IN2_MA SD_BL_ADC1_IN2;
ADC2_IN3_MA SD_BL_ADC2_IN3;
ADC2_IN4_MA SD_BL_ADC2_IN4;
ADC3_IN1_MA SD_BL_ADC3_IN1;
ADC3_IN2_MA SD_BL_ADC3_IN2;


ADC1_IN1_MA TKEO_ADC1_IN1; // Declaring an instance of TKEO windowing
ADC1_IN2_MA TKEO_ADC1_IN2;
ADC2_IN3_MA TKEO_ADC2_IN3;
ADC2_IN4_MA TKEO_ADC2_IN4;
ADC3_IN1_MA TKEO_ADC3_IN1;
ADC3_IN2_MA TKEO_ADC3_IN2;


ADC1_IN1_MA SSC_ADC1_IN1; // Declaring an instance of slope sign change feature
ADC1_IN2_MA SSC_ADC1_IN2;
ADC2_IN3_MA SSC_ADC2_IN3;
ADC2_IN4_MA SSC_ADC2_IN4;
ADC3_IN1_MA SSC_ADC3_IN1;
ADC3_IN2_MA SSC_ADC3_IN2;


HAL_StatusTypeDef ADC_status;


float32_t Offset_1 = 0.0f; // Variable to store the calculated offset
float32_t Offset_2 = 0.0f;
float32_t Offset_3 = 0.0f;
float32_t Offset_4 = 0.0f;
float32_t Offset_5 = 0.0f;
float32_t Offset_6 = 0.0f;


uint8_t Offset_1_Calculated = 0; // Initialize the offset calculation flag to zero
uint8_t Offset_2_Calculated = 0;
uint8_t Offset_3_Calculated = 0;
uint8_t Offset_4_Calculated = 0;
uint8_t Offset_5_Calculated = 0;
uint8_t Offset_6_Calculated = 0;


float32_t SD_BL_1 = 0.0f;
float32_t SD_BL_2 = 0.0f;
float32_t SD_BL_3 = 0.0f;
float32_t SD_BL_4 = 0.0f;
float32_t SD_BL_5 = 0.0f;
float32_t SD_BL_6 = 0.0f;


uint8_t TKEO_1 = 0;
uint8_t TKEO_2 = 0;
uint8_t TKEO_3 = 0;
uint8_t TKEO_4 = 0;
uint8_t TKEO_5 = 0;
uint8_t TKEO_6 = 0;


float32_t SSC_1 = 0.0f;
float32_t SSC_2 = 0.0f;
float32_t SSC_3 = 0.0f;
float32_t SSC_4 = 0.0f;
float32_t SSC_5 = 0.0f;
float32_t SSC_6 = 0.0f;

float32_t* AR_1;
float32_t* AR_2;
float32_t* AR_3;
float32_t* AR_4;
float32_t* AR_5;
float32_t* AR_6;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
static void MX_ADC2_Init(void);
static void MX_ADC3_Init(void);
static void MX_FMAC_Init(void);
static void MX_TIM6_Init(void);
static void MX_TIM7_Init(void);
static void MX_TIM20_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  init_ADC1_IN1_struct(); // Pointer to the source buffer is initialized at runtime
  init_ADC1_IN1_FO_biquad_filter();  // Initializes the filter coefficients and variables
  MA_ADC1_IN1_Init(&MovingAverage_ADC1_IN1); // Initializes all the output and moving average buffers to zero and the index to zero

  init_ADC1_IN2_struct();
  init_ADC1_IN2_FO_biquad_filter();
  MA_ADC1_IN2_Init(&MovingAverage_ADC1_IN2);

  init_ADC2_IN3_struct();
  init_ADC2_IN3_FO_biquad_filter();
  MA_ADC2_IN3_Init(&MovingAverage_ADC2_IN3);

  init_ADC2_IN4_struct();
  init_ADC2_IN4_FO_biquad_filter();
  MA_ADC2_IN4_Init(&MovingAverage_ADC2_IN4);

  init_ADC3_IN1_struct();
  init_ADC3_IN1_FO_biquad_filter();
  MA_ADC3_IN1_Init(&MovingAverage_ADC3_IN1);

  init_ADC3_IN2_struct();
  init_ADC3_IN2_FO_biquad_filter();
  MA_ADC3_IN2_Init(&MovingAverage_ADC3_IN2);
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_ADC3_Init();
  MX_FMAC_Init();
  MX_TIM6_Init();
  MX_TIM7_Init();
  MX_TIM20_Init();
  /* USER CODE BEGIN 2 */
	
  /* ADC1 is started using timer 6 triggered conversions */
  HAL_StatusTypeDef HAL_TIM_Base_Start(TIM_HandleTypeDef *htim6);
    ADC_status=HAL_ADC_Start_DMA(&hadc1, ADC1_DMA_sort_ptr->ADC1_DMA_bfr, ADC_DMA_BUFFERSIZE);

  HAL_StatusTypeDef HAL_TIM_Base_Start(TIM_HandleTypeDef *htim7);
    ADC_status=HAL_ADC_Start_DMA(&hadc2, ADC2_DMA_sort_ptr->ADC2_DMA_bfr, ADC_DMA_BUFFERSIZE);

  HAL_StatusTypeDef HAL_TIM_Base_Start(TIM_HandleTypeDef *htim20);
    ADC_status=HAL_ADC_Start_DMA(&hadc3, ADC3_DMA_sort_ptr->ADC3_DMA_bfr, ADC_DMA_BUFFERSIZE);

/* Calculating the offset value and standard deviation for the base line signal for all the channels */
if(Offset_1_Calculated==0)
{
  float32_t OffsetSum_1 = 0.0f;
  for (uint8_t a=0; a< NOOFITERATIONS_BL; a++) // Calculates the mean and standard deviation for the baseline of the signal for the first n buffer fills where n= NOOFITERATIONS_BL
    {
		/* Collects samples to fill the buffer */
		update_ADC1_IN1_FO_biquad_filter();  // Filters channel 1 data
		MA_ADC1_IN1_Update(&MovingAverage_ADC1_IN1);  // Fill the buffer with ADC data

		/* Calculate the offset from the filled buffer */
		Offset_1 = ADC1_IN1_OffsetCalc(&OffsetCalc_ADC1_IN1);
		OffsetSum_1 += Offset_1;
    }

  Offset_1 = OffsetSum_1 / NOOFITERATIONS_BL;
  Offset_1_Calculated = 1; // Set the flag indicating offset has been calculated

  SD_BL_1 = ADC1_IN1_SD_BL(&SD_BL_ADC1_IN1, Offset_1); // Calculated the standard deviation for the last buffer fill
}


if(Offset_2_Calculated==0)
{
  float32_t OffsetSum_2;
  for (uint8_t a=0; a< NOOFITERATIONS_BL; a++)
    {

		update_ADC1_IN2_FO_biquad_filter();
		MA_ADC1_IN2_Update(&MovingAverage_ADC1_IN2);


		Offset_2 = ADC1_IN2_OffsetCalc(&OffsetCalc_ADC1_IN2);
		OffsetSum_2 += Offset_2;
    }

  Offset_2 = OffsetSum_2 / NOOFITERATIONS_BL;
  Offset_2_Calculated = 1;

  SD_BL_2 = ADC1_IN2_SD_BL(&SD_BL_ADC1_IN2, Offset_2);
}


if(Offset_3_Calculated==0)
{
  float32_t OffsetSum_3;
  for (uint8_t a=0; a< NOOFITERATIONS_BL; a++)
    {

		update_ADC2_IN3_FO_biquad_filter();
		MA_ADC2_IN3_Update(&MovingAverage_ADC2_IN3);


		Offset_3 = ADC2_IN3_OffsetCalc(&OffsetCalc_ADC2_IN3);
		OffsetSum_3 += Offset_3;
    }

  Offset_3 = OffsetSum_3 / NOOFITERATIONS_BL;
  Offset_3_Calculated = 1;

  SD_BL_3 = ADC2_IN3_SD_BL(&SD_BL_ADC2_IN3, Offset_3);
}


if(Offset_4_Calculated==0)
{
  float32_t OffsetSum_4;
  for (uint8_t a=0; a< NOOFITERATIONS_BL; a++)
    {

		update_ADC2_IN4_FO_biquad_filter();
		MA_ADC2_IN4_Update(&MovingAverage_ADC2_IN4);


		Offset_4 = ADC2_IN4_OffsetCalc(&OffsetCalc_ADC2_IN4);
		OffsetSum_4 += Offset_4;
    }

  Offset_4 = OffsetSum_4 / NOOFITERATIONS_BL;
  Offset_4_Calculated = 1;

  SD_BL_4 = ADC2_IN4_SD_BL(&SD_BL_ADC2_IN4, Offset_4);
}


if(Offset_5_Calculated==0)
{
  float32_t OffsetSum_5;
  for (uint8_t a=0; a< NOOFITERATIONS_BL; a++) // Calculates the mean and standard deviation for the baseline of the signal for the first n buffer fills where n= NOOFITERATIONS_BL
    {
		/* Collects samples to fill the buffer */
		update_ADC3_IN1_FO_biquad_filter();  // Notch filters channel 1 data
		MA_ADC3_IN1_Update(&MovingAverage_ADC3_IN1);  // Fill the buffer with ADC data

		/* Calculate the offset from the filled buffer */
		Offset_1 = ADC3_IN1_OffsetCalc(&OffsetCalc_ADC3_IN1);
		OffsetSum_5 += Offset_5;
    }

  Offset_5 = OffsetSum_5 / NOOFITERATIONS_BL;
  Offset_5_Calculated = 1; // Set the flag indicating offset has been calculated

  SD_BL_5 = ADC3_IN1_SD_BL(&SD_BL_ADC3_IN1, Offset_5);
}


if(Offset_6_Calculated==0)
{
  float32_t OffsetSum_6;
  for (uint8_t a=0; a< NOOFITERATIONS_BL; a++)
    {

		update_ADC3_IN2_FO_biquad_filter();
		MA_ADC3_IN2_Update(&MovingAverage_ADC3_IN2);


		Offset_6 = ADC3_IN2_OffsetCalc(&OffsetCalc_ADC3_IN2);
		OffsetSum_6 += Offset_6;
    }

  Offset_6 = OffsetSum_6 / NOOFITERATIONS_BL;
  Offset_6_Calculated = 1;

  SD_BL_6 = ADC3_IN2_SD_BL(&SD_BL_ADC3_IN2, Offset_6);
}
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  /* DSP SECTION */
	  update_ADC1_IN1_FO_biquad_filter();  // Filters channel 1 data
	  MA_ADC1_IN1_Update(&MovingAverage_ADC1_IN1); // Performs the moving average
	  for (uint32_t y = 0; y < ADC_DMA_SIXTEENTHBUFFERSIZE; y++)
	  {
		  MovingAverage_ADC1_IN1.MA_ADC1_IN1_OutBfr[y]  -= Offset_1; // Subtract the stored offset
	  }
	  /* FEATURE EXCTRACTION SECTION */
      TKEO_1 = ADC1_IN1_TKEO(&TKEO_ADC1_IN1, SD_BL_1); // Performs the windowing through the TKEO operator and returns binary data to indicate presence or absence of muscle activation

      if(TKEO_1 == 1) // Only runs when there is muscle activation.
      {
      /*Slope sign change*/
      SSC_1 = ADC1_IN1_SSC(&SSC_ADC1_IN1, 0.5 * Offset_1); // Calculates slope sign changes for active segments
      /*Computes the auto-correlation values and the auto-regression coefficients and returns the latter*/
      ADC1_IN1_autocorr_calc();
      AR_1 = ADC1_IN1_autoreg_coeffs();

      }


	  update_ADC1_IN2_FO_biquad_filter();
	  MA_ADC1_IN2_Update(&MovingAverage_ADC1_IN2);
	  for (uint32_t z = 0; z < ADC_DMA_SIXTEENTHBUFFERSIZE; z++)
	  {
		  MovingAverage_ADC1_IN2.MA_ADC1_IN2_OutBfr[z]  -= Offset_2;
	  }
	  TKEO_2 = ADC1_IN2_TKEO(&TKEO_ADC1_IN2, SD_BL_2);

	  if(TKEO_2 == 1)
	  {
	  SSC_2 = ADC1_IN2_SSC(&SSC_ADC1_IN2, 0.5 * Offset_2);
	  ADC1_IN2_autocorr_calc();
	  AR_2 = ADC1_IN2_autoreg_coeffs();
	  }


	  update_ADC2_IN3_FO_biquad_filter();
	  MA_ADC2_IN3_Update(&MovingAverage_ADC2_IN3);
	  for (uint32_t g = 0; g <ADC_DMA_SIXTEENTHBUFFERSIZE; g++)
	  {
		  MovingAverage_ADC2_IN3.MA_ADC2_IN3_OutBfr[g]  -= Offset_3;
	  }
	  TKEO_3 = ADC2_IN3_TKEO(&TKEO_ADC2_IN3, SD_BL_3);

	  if(TKEO_3 == 1)
	  {
	  SSC_3 = ADC2_IN3_SSC(&SSC_ADC2_IN3, 0.5 * Offset_3);
	  ADC2_IN3_autocorr_calc();
	  AR_3 = ADC2_IN3_autoreg_coeffs();
	  }


	  update_ADC2_IN4_FO_biquad_filter();
	  MA_ADC2_IN4_Update(&MovingAverage_ADC2_IN4);
	  for (uint32_t e = 0; e < ADC_DMA_SIXTEENTHBUFFERSIZE; e++)
	  {
		  MovingAverage_ADC2_IN4.MA_ADC2_IN4_OutBfr[e]  -= Offset_4;
	  }
	  TKEO_4 = ADC2_IN4_TKEO(&TKEO_ADC2_IN4, SD_BL_4);

	  if(TKEO_4 == 1)
	  {
	  SSC_4 = ADC2_IN4_SSC(&SSC_ADC2_IN4, 0.5 * Offset_4);
	  ADC2_IN4_autocorr_calc();
	  AR_4 = ADC2_IN4_autoreg_coeffs();
	  }


	  update_ADC3_IN1_FO_biquad_filter();
	  MA_ADC3_IN1_Update(&MovingAverage_ADC3_IN1);
	  for (uint32_t b = 0; b < ADC_DMA_SIXTEENTHBUFFERSIZE; b++)
	  {
		  MovingAverage_ADC3_IN1.MA_ADC3_IN1_OutBfr[b]  -= Offset_5;
	  }
	  TKEO_5 = ADC3_IN1_TKEO(&TKEO_ADC3_IN1, SD_BL_5);

	  if(TKEO_5 == 1)
	  {
	  SSC_5 = ADC3_IN1_SSC(&SSC_ADC3_IN1, 0.5 * Offset_5);
	  ADC3_IN1_autocorr_calc();
	  AR_5 = ADC3_IN1_autoreg_coeffs();
	  }


	  /* DSP SECTION */
	  update_ADC3_IN2_FO_biquad_filter(); // Notch filters channel 2 data
	  MA_ADC3_IN2_Update(&MovingAverage_ADC3_IN2); // Performs the moving average
	  for (uint32_t c = 0; c < ADC_DMA_SIXTEENTHBUFFERSIZE; c++)
	  {
		  MovingAverage_ADC3_IN2.MA_ADC3_IN2_OutBfr[c]  -= Offset_6;  // Subtract the stored offset
	  }
	  /* FEATURE EXCTRACTION SECTION */
	  TKEO_6 = ADC3_IN2_TKEO(&TKEO_ADC3_IN2, SD_BL_6); // Performs the windowing through the TKEO operator and returns binary data to indicate presence or absence of muscle activation

	  if(TKEO_6 == 1) // Only runs when there is muscle activation.
	  {
	  /*Slope sign change*/
	  SSC_6 = ADC3_IN2_SSC(&SSC_ADC3_IN2, 0.5 * Offset_6); // Calculates slope sign changes for active segments
	  /*Computes the auto-correlation values and the auto-regression coefficients and returns the latter*/
	  ADC3_IN2_autocorr_calc();
	  AR_6 = ADC3_IN2_autoreg_coeffs();
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 8;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.GainCompensation = 0;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 2;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_EXTERNALTRIG_T6_TRGO;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
  hadc1.Init.DMAContinuousRequests = ENABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc1.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_92CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief ADC2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC2_Init(void)
{

  /* USER CODE BEGIN ADC2_Init 0 */

  /* USER CODE END ADC2_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC2_Init 1 */

  /* USER CODE END ADC2_Init 1 */

  /** Common config
  */
  hadc2.Instance = ADC2;
  hadc2.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc2.Init.Resolution = ADC_RESOLUTION_12B;
  hadc2.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc2.Init.GainCompensation = 0;
  hadc2.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc2.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc2.Init.LowPowerAutoWait = DISABLE;
  hadc2.Init.ContinuousConvMode = DISABLE;
  hadc2.Init.NbrOfConversion = 2;
  hadc2.Init.DiscontinuousConvMode = DISABLE;
  hadc2.Init.ExternalTrigConv = ADC_EXTERNALTRIG_T7_TRGO;
  hadc2.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
  hadc2.Init.DMAContinuousRequests = ENABLE;
  hadc2.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc2.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_92CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC2_Init 2 */

  /* USER CODE END ADC2_Init 2 */

}

/**
  * @brief ADC3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC3_Init(void)
{

  /* USER CODE BEGIN ADC3_Init 0 */

  /* USER CODE END ADC3_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC3_Init 1 */

  /* USER CODE END ADC3_Init 1 */

  /** Common config
  */
  hadc3.Instance = ADC3;
  hadc3.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc3.Init.Resolution = ADC_RESOLUTION_12B;
  hadc3.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc3.Init.GainCompensation = 0;
  hadc3.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc3.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc3.Init.LowPowerAutoWait = DISABLE;
  hadc3.Init.ContinuousConvMode = DISABLE;
  hadc3.Init.NbrOfConversion = 2;
  hadc3.Init.DiscontinuousConvMode = DISABLE;
  hadc3.Init.ExternalTrigConv = ADC_EXTERNALTRIG_T20_TRGO;
  hadc3.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
  hadc3.Init.DMAContinuousRequests = ENABLE;
  hadc3.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc3.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc3) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_92CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC3_Init 2 */

  /* USER CODE END ADC3_Init 2 */

}

/**
  * @brief FMAC Initialization Function
  * @param None
  * @retval None
  */
static void MX_FMAC_Init(void)
{

  /* USER CODE BEGIN FMAC_Init 0 */

  /* USER CODE END FMAC_Init 0 */

  /* USER CODE BEGIN FMAC_Init 1 */

  /* USER CODE END FMAC_Init 1 */
  hfmac.Instance = FMAC;
  if (HAL_FMAC_Init(&hfmac) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN FMAC_Init 2 */

  /* USER CODE END FMAC_Init 2 */

}

/**
  * @brief TIM6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM6_Init(void)
{

  /* USER CODE BEGIN TIM6_Init 0 */

  /* USER CODE END TIM6_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM6_Init 1 */

  /* USER CODE END TIM6_Init 1 */
  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 8-1;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 7;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM6_Init 2 */

  /* USER CODE END TIM6_Init 2 */

}

/**
  * @brief TIM7 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM7_Init(void)
{

  /* USER CODE BEGIN TIM7_Init 0 */

  /* USER CODE END TIM7_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM7_Init 1 */

  /* USER CODE END TIM7_Init 1 */
  htim7.Instance = TIM7;
  htim7.Init.Prescaler = 8-1;
  htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim7.Init.Period = 7;
  htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM7_Init 2 */

  /* USER CODE END TIM7_Init 2 */

}

/**
  * @brief TIM20 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM20_Init(void)
{

  /* USER CODE BEGIN TIM20_Init 0 */

  /* USER CODE END TIM20_Init 0 */

  TIM_SlaveConfigTypeDef sSlaveConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM20_Init 1 */

  /* USER CODE END TIM20_Init 1 */
  htim20.Instance = TIM20;
  htim20.Init.Prescaler = 8-1;
  htim20.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim20.Init.Period = 7;
  htim20.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim20.Init.RepetitionCounter = 0;
  htim20.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim20) != HAL_OK)
  {
    Error_Handler();
  }
  sSlaveConfig.SlaveMode = TIM_SLAVEMODE_DISABLE;
  sSlaveConfig.InputTrigger = TIM_TS_ITR0;
  if (HAL_TIM_SlaveConfigSynchro(&htim20, &sSlaveConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim20, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM20_Init 2 */

  /* USER CODE END TIM20_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMAMUX1_CLK_ENABLE();
  __HAL_RCC_DMA1_CLK_ENABLE();
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
  /* DMA1_Channel6_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel6_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel6_IRQn);
  /* DMA2_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Channel1_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void                    HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc)   // Fires when the upper half of the DMA buffer is filled
{
	 if (hadc->Instance == ADC1)
	   {
	        ADC1_DMA_sort_uhb(); // Handles the upper half of the DMA buffer

	        ADC1_DMA_sort_ptr->ADC1_DMA_mon=ADC1_DMA_sort_ptr->ADC1_DMA_bfr[ADC_DMA_QUATERBUFFERSIZE];  // Monitors one of the DMA buffer registers in the upper half of the buffer
	        ADC1_DMA_sort_ptr->ADC1_IN1_mon=ADC1_DMA_sort_ptr->ADC1_IN1_bfr[ADC_DMA_EIGHTHBUFFERSIZE];  // Monitors one of the IN1 data buffer registers in the upper half of the buffer
	        ADC1_DMA_sort_ptr->ADC1_IN2_mon=ADC1_DMA_sort_ptr->ADC1_IN2_bfr[ADC_DMA_EIGHTHBUFFERSIZE];  // Monitors one of the IN2 data buffer registers in the upper half of the buffer
	   }


	 if (hadc->Instance == ADC2)

	   {
		    ADC2_DMA_sort_uhb(); 

		    ADC2_DMA_sort_ptr->ADC2_DMA_mon=ADC2_DMA_sort_ptr->ADC2_DMA_bfr[ADC_DMA_QUATERBUFFERSIZE];
		    ADC2_DMA_sort_ptr->ADC2_IN3_mon=ADC2_DMA_sort_ptr->ADC2_IN3_bfr[ADC_DMA_EIGHTHBUFFERSIZE];
		    ADC2_DMA_sort_ptr->ADC2_IN4_mon=ADC2_DMA_sort_ptr->ADC2_IN4_bfr[ADC_DMA_EIGHTHBUFFERSIZE];
	   }

	 if (hadc->Instance == ADC3)

	   {
		    ADC3_DMA_sort_uhb(); 

		    ADC3_DMA_sort_ptr->ADC3_DMA_mon=ADC3_DMA_sort_ptr->ADC3_DMA_bfr[ADC_DMA_QUATERBUFFERSIZE];
		    ADC3_DMA_sort_ptr->ADC3_IN1_mon=ADC3_DMA_sort_ptr->ADC3_IN1_bfr[ADC_DMA_EIGHTHBUFFERSIZE];
		    ADC3_DMA_sort_ptr->ADC3_IN2_mon=ADC3_DMA_sort_ptr->ADC3_IN2_bfr[ADC_DMA_EIGHTHBUFFERSIZE];
	   }
};

void                    HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)  // Fires when the lower half of the DMA buffer is filled
{
	  if (hadc->Instance == ADC1)
		{
			ADC1_DMA_sort_lhb(); // Handles the lower half of the DMA buffer

			ADC1_DMA_sort_ptr->ADC1_DMA_mon=ADC1_DMA_sort_ptr->ADC1_DMA_bfr[ADC_DMA_HALFBUFFERSIZE + ADC_DMA_QUATERBUFFERSIZE]; // Monitors one of the DMA buffer registers in the lower half of the buffer
			ADC1_DMA_sort_ptr->ADC1_IN1_mon=ADC1_DMA_sort_ptr->ADC1_IN1_bfr[ADC_DMA_QUATERBUFFERSIZE + ADC_DMA_EIGHTHBUFFERSIZE];  // Monitors one of the IN1 data buffer registers in the lower half of the buffer
			ADC1_DMA_sort_ptr->ADC1_IN2_mon=ADC1_DMA_sort_ptr->ADC1_IN2_bfr[ADC_DMA_QUATERBUFFERSIZE + ADC_DMA_EIGHTHBUFFERSIZE];  // Monitors one of the IN2 data buffer registers in the lower half of the buffer
		}


	  if (hadc->Instance == ADC2)

		{
		     ADC2_DMA_sort_lhb();

		     ADC2_DMA_sort_ptr->ADC2_DMA_mon=ADC2_DMA_sort_ptr->ADC2_DMA_bfr[ADC_DMA_HALFBUFFERSIZE + ADC_DMA_QUATERBUFFERSIZE];
		     ADC2_DMA_sort_ptr->ADC2_IN3_mon=ADC2_DMA_sort_ptr->ADC2_IN3_bfr[ADC_DMA_QUATERBUFFERSIZE + ADC_DMA_EIGHTHBUFFERSIZE];
			 ADC2_DMA_sort_ptr->ADC2_IN4_mon=ADC2_DMA_sort_ptr->ADC2_IN4_bfr[ADC_DMA_QUATERBUFFERSIZE + ADC_DMA_EIGHTHBUFFERSIZE];
		}

	   if (hadc->Instance == ADC3)

		{
		     ADC3_DMA_sort_lhb();

			 ADC3_DMA_sort_ptr->ADC3_DMA_mon=ADC3_DMA_sort_ptr->ADC3_DMA_bfr[ADC_DMA_HALFBUFFERSIZE + ADC_DMA_QUATERBUFFERSIZE];
			 ADC3_DMA_sort_ptr->ADC3_IN1_mon=ADC3_DMA_sort_ptr->ADC3_IN1_bfr[ADC_DMA_QUATERBUFFERSIZE + ADC_DMA_EIGHTHBUFFERSIZE];
			 ADC3_DMA_sort_ptr->ADC3_IN2_mon=ADC3_DMA_sort_ptr->ADC3_IN2_bfr[ADC_DMA_QUATERBUFFERSIZE + ADC_DMA_EIGHTHBUFFERSIZE];
		}

};

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
