/**
  ******************************************************************************
  * @file    stm32f0xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"
#include "stm32f0xx.h"
#include "stm32f0xx_it.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern int i;
extern ADC_HandleTypeDef hadc;
extern SPI_HandleTypeDef hspi2;
extern TIM_HandleTypeDef htim1;
int led = 10;

int shiftLed = 100;

int dbresult;

void led1(int state,int brigthness);

void led2(int state,int brigthness);

void led3(int state,int brigthness);

void led4(int state,int brigthness);

void led5(int state,int brigthness);

void led6(int state,int brigthness);

void led7(int state,int brigthness);

void matrixDebounce();

int btnDebounce(int i);

int charFlag;

int numFlag;

int clearFlag;

int continueFlag;



void coolEffect1()

{

    static int state = 0;

    shiftLed--;

    if (shiftLed ==0)

    {

        shiftLed = 100;

        switch(state)

        {

        case 0:TIM2->CCR1 = 4096;break;

        case 1:TIM2->CCR2 = 4096;break;

        case 2:TIM2->CCR3 = 4096;break;

        case 3:TIM2->CCR4 = 4096;break;

        case 4:TIM3->CCR1 = 4096;break;

        case 5:TIM3->CCR2 = 4096;break;

        case 6:TIM3->CCR3 = 4096;break;



        }

        state++;

        if(state == 8)

        {

            state = 0;

            TIM2->CCR1=0;

            TIM2->CCR2=0;

            TIM2->CCR3=0;

            TIM2->CCR4=0;

            TIM3->CCR1=0;

            TIM3->CCR2=0;

            TIM3->CCR3=0;

        }

    }

}




/******************************************************************************/
/*            Cortex-M0 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f0xx.s).                    */
/******************************************************************************/

/**
* @brief This function handles ADC and COMP interrupts (COMP interrupts through EXTI lines 21 and 22).
*/
void ADC1_COMP_IRQHandler(void)
{
  /* USER CODE BEGIN ADC1_COMP_IRQn 0 */

  /* USER CODE END ADC1_COMP_IRQn 0 */
  HAL_ADC_IRQHandler(&hadc);
  /* USER CODE BEGIN ADC1_COMP_IRQn 1 */

  /* USER CODE END ADC1_COMP_IRQn 1 */
}

/**
* @brief This function handles TIM1 break, update, trigger and commutation interrupts.
*/
void TIM1_BRK_UP_TRG_COM_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_BRK_UP_TRG_COM_IRQn 0 */
      TIM1->SR &= ~TIM_SR_UIF;
  /* USER CODE END TIM1_BRK_UP_TRG_COM_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_BRK_UP_TRG_COM_IRQn 1 */
      i++;
      if(i == 12)
      {
          i = 0;
      }
        matrixDebounce();
        led--;
        if (led==0)
        {
            ADC1->CR |= ADC_CR_ADSTART;
            TIM3->CCR4 = ADC1->DR;
            led = 10;
        }

        dbresult = btnDebounce(i);
        if(dbresult==1 && i==9)
        {
            charFlag =1;
            numFlag = 0;
            clearFlag = 0;
            continueFlag = 1;
        }
        else if(dbresult==1 && i==11)
        {
            charFlag =0;
            numFlag = 1;
            clearFlag = 0;
            continueFlag = 1;
        }
        else if(dbresult==1 && i==10)
        {
            charFlag =0;
            numFlag = 0;
            clearFlag = 1;
            continueFlag = 1;
        }

        //coolEffect2();

}


  /* USER CODE END TIM1_BRK_UP_TRG_COM_IRQn 1 */


/**
* @brief This function handles TIM1 capture compare interrupt.
*/
void TIM1_CC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_CC_IRQn 0 */

  /* USER CODE END TIM1_CC_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_CC_IRQn 1 */

  /* USER CODE END TIM1_CC_IRQn 1 */
}

/**
* @brief This function handles SPI2 global interrupt.
*/
void SPI2_IRQHandler(void)
{
  /* USER CODE BEGIN SPI2_IRQn 0 */

  /* USER CODE END SPI2_IRQn 0 */
  HAL_SPI_IRQHandler(&hspi2);
  /* USER CODE BEGIN SPI2_IRQn 1 */

  /* USER CODE END SPI2_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
