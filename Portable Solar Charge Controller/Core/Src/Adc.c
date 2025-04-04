/*
 * Adc.c
 *
 *  Created on: Apr 3, 2025
 *      Author: adeel.akhtar
 */
#include "Adc.h"
#include"Solar_Operations.h"
ADC_HandleTypeDef hadc1;
volatile uint16_t ADC_VAL[3];

void HAL_ADC_ConvCpltCallback (ADC_HandleTypeDef * hadc){

//	scaled_SV=(ADC_VAL[0]/65535.0)*3.30;
//	scaled_BV=(ADC_VAL[1]/65535.0)*3.30;
//	scaled_BC=(ADC_VAL[2]/65535.0)*3.30;
//	printf("BV = %0.2f\t SV = %0.2f\n",scaled_BV,scaled_SV);

}

void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */
//////
  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */
//////
  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_16B;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SEQ_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 3;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ConversionDataManagement = ADC_CONVERSIONDATA_DMA_ONESHOT;
  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc1.Init.LeftBitShift = ADC_LEFTBITSHIFT_NONE;
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
  sConfig.Channel = ADC_CHANNEL_7;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  sConfig.OffsetSignedSaturation = DISABLE;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_8;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_9;
  sConfig.Rank = ADC_REGULAR_RANK_3;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */
//////
  /* USER CODE END ADC1_Init 2 */
}



 void get_calibrated_voltage(){
	 int adc_channel_count = sizeof(ADC_VAL)/sizeof(ADC_VAL[0]);
	 float calibrated_voltage[3]={0};
	 for(int i=0;i<100;i++){
	 HAL_ADCEx_Calibration_Start (&hadc1, ADC_CALIB_OFFSET_LINEARITY, ADC_SINGLE_ENDED);		// TO set zero offset at 0V
	 HAL_ADC_Start_DMA(&hadc1, (uint32_t*)ADC_VAL, adc_channel_count);
	 calibrated_voltage[0] += (float)(ADC_VAL[0]/65535.0)*3.30;
	 calibrated_voltage[1] += (float)(ADC_VAL[1]/65535.0)*3.30;
	 calibrated_voltage[2] += (float)(ADC_VAL[2]/65535.0)*3.30;
	 }
	 scaled_SV = (calibrated_voltage[0] / 100);
	 scaled_BV = (calibrated_voltage[1] / 100);
	 scaled_BC = (calibrated_voltage[2] / 100);
	 printf("BV = %0.2f\t SV = %0.2f\tBC = %0.2f\n",scaled_BV,scaled_SV,scaled_BC);
 }
