/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CE_Pin GPIO_PIN_13
#define CE_GPIO_Port GPIOC
#define DC_Pin GPIO_PIN_14
#define DC_GPIO_Port GPIOC
#define RST_Pin GPIO_PIN_15
#define RST_GPIO_Port GPIOC
#define UP_Button_Pin GPIO_PIN_1
#define UP_Button_GPIO_Port GPIOA
#define UP_Button_EXTI_IRQn EXTI1_IRQn
#define SELECT_Button_Pin GPIO_PIN_2
#define SELECT_Button_GPIO_Port GPIOA
#define SELECT_Button_EXTI_IRQn EXTI2_IRQn
#define DOWN_Button_Pin GPIO_PIN_3
#define DOWN_Button_GPIO_Port GPIOA
#define DOWN_Button_EXTI_IRQn EXTI3_IRQn
#define Green_Diod_Pin GPIO_PIN_12
#define Green_Diod_GPIO_Port GPIOD
#define Orange_Diod_Pin GPIO_PIN_13
#define Orange_Diod_GPIO_Port GPIOD
#define Red_Diod_Pin GPIO_PIN_14
#define Red_Diod_GPIO_Port GPIOD
#define Blue_Diod_Pin GPIO_PIN_15
#define Blue_Diod_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
