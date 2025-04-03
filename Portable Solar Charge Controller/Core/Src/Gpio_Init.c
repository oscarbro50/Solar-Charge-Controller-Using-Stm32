/*
 * Gpio_Init.c
 *
 *  Created on: Mar 27, 2025
 *      Author: adeel.akhtar
 */
#include "Gpio_Init.h"





void MX_GPIO_Init(void)
{
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
