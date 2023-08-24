
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *1
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
#include "main.h"
#include "stm32f0xx_hal.h"

/* USER CODE BEGIN Includes */
#include "math.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc;

DAC_HandleTypeDef hdac1;

SPI_HandleTypeDef hspi2;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
int i;
int iii = 99999999;
extern int dbresult;
volatile int btnCurrent[12] = {1,1,1,1,1,1,1,1,1,1,1,1};
volatile int btnPrev[12] = {1,1,1,1,1,1,1,1,1,1,1,1};
uint8_t prefix = 0xFE;
uint8_t clear = 0x51;
int br[6] = {0,0,0,0,0,0};
int brDisp [6] = {0,0,0,0,0,0};
int a[6] = {1,0,0,0,0,0};
int b[6] = {1,0,1,0,0,0};
int c[6] = {1,1,0,0,0,0};
int d[6] = {1,1,0,1,0,0};
int e[6] = {1,0,0,1,0,0};
int f[6] = {1,1,1,0,0,0};
int g[6] = {1,1,1,1,0,0};
int h[6] = {1,0,1,1,0,0};
int ii[6] = {0,1,1,0,0,0};
int j[6] = {0,1,1,1,0,0};
int k[6] = {1,0,0,0,1,0};
int l[6] = {1,0,1,0,1,0};
int m[6] = {1,1,0,0,1,0};
int n[6] = {1,1,0,1,1,0};
int o[6] = {1,0,0,1,1,0};
int p[6] = {1,1,1,0,1,0};
int q[6] = {1,1,1,1,1,0};
int rr[6] = {1,0,1,1,1,0};
int s[6] = {0,1,1,0,1,0};
int t[6] = {0,1,1,1,1,0};
int u[6] = {1,0,0,0,1,1};
int v[6] = {1,0,1,0,1,1};
int w[6] = {0,1,1,1,0,1};
int xx[6] = {1,1,0,0,1,1};
int y[6] = {1,1,0,1,1,1};
int z[6] = {1,0,0,1,1,1};
int yi[6] = {1,0,0,0,0,0};
int er[6] = {1,0,1,0,0,0};
int san[6] = {1,1,0,0,0,0};
int si[6] = {1,1,0,1,0,0};
int wu[6] = {1,0,0,1,0,0};
int lv[6] = {1,1,1,0,0,0};
int qi[6] = {1,1,1,1,0,0};
int ba[6] = {1,0,1,1,0,0};
int jv[6] = {0,1,1,0,0,0};
int ling[6] = {0,1,1,1,0,0};
int space[6] = {0,0,0,0,0,0};
char allChar[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
char allNum[] = "1234567890";
char test[1];
char line[]="READY TO GO!";
char output;
int inputflag = 0;
int resetflag = 0;
int x = 0;
int arrayIndex;
int compare[6];
int memc = 9999999;
int counter = 0;
int dispIndex = 0;
char output1;
char output2;
char output3;
char output4;
char output5;
char output6;
char output7;
char output8;
char output9;
char output10;
char null[] = "a";
extern int continueFlag;
extern int charFlag;
extern int numFlag;
extern int clearFlag;



void led1(int state,int brigthness)
{
if (state == 0)
{
    TIM2->CCR1=brigthness;
    TIM2->CCR2=0;
    TIM2->CCR3=0;
    TIM2->CCR4=0;
    TIM3->CCR1=0;
    TIM3->CCR2=0;
    TIM3->CCR3=0;
}
else if(state == 1)
{
    TIM2->CCR1=brigthness;
}

}
void led2(int state,int brigthness)
{
    if (state == 0)
    {
        TIM2->CCR1=0;
        TIM2->CCR2=brigthness;
        TIM2->CCR3=0;
        TIM2->CCR4=0;
        TIM3->CCR1=0;
        TIM3->CCR2=0;
        TIM3->CCR3=0;
    }
    else if(state == 1)
    {
        TIM2->CCR2=brigthness;
    }
TIM3->CCR3=0;
}
void led3(int state,int brigthness)
{
if (state == 0)
{
    TIM2->CCR1=0;
    TIM2->CCR2=0;
    TIM2->CCR3=brigthness;
    TIM2->CCR4=0;
    TIM3->CCR1=0;
    TIM3->CCR2=0;
    TIM3->CCR3=0;
}
else if(state == 1)
{
    TIM2->CCR3=brigthness;
}

}
void led4(int state,int brigthness)
{
if (state == 0)
{
    TIM2->CCR1=0;
    TIM2->CCR2=0;
    TIM2->CCR3=0;
    TIM2->CCR4=brigthness;
    TIM3->CCR1=0;
    TIM3->CCR2=0;
    TIM3->CCR3=0;
}
else if(state == 1)
{
    TIM2->CCR4=brigthness;
}

}
void led5(int state,int brigthness)
{
if (state == 0)
{
    TIM2->CCR1=0;
    TIM2->CCR2=0;
    TIM2->CCR3=0;
    TIM2->CCR4=0;
    TIM3->CCR1=brigthness;
    TIM3->CCR2=0;
    TIM3->CCR3=0;
}
else if(state == 1)
{
    TIM3->CCR1=brigthness;
}

}
void led6(int state,int brigthness)
{
if (state == 0)
{
    TIM2->CCR1=0;
    TIM2->CCR2=0;
    TIM2->CCR3=0;
    TIM2->CCR4=0;
    TIM3->CCR1=0;
    TIM3->CCR2=brigthness;
    TIM3->CCR3=0;
}
else if(state == 1)
{
    TIM3->CCR2=brigthness;
}

}
void led7(int state,int brigthness)
{
if (state == 0)
{
    TIM2->CCR1=0;
    TIM2->CCR2=0;
    TIM2->CCR3=0;
    TIM2->CCR4=0;
    TIM3->CCR1=0;
    TIM3->CCR2=0;
    TIM3->CCR3=brigthness;
}
else if(state == 1)
{
    TIM3->CCR3=brigthness;
}

}

void ledAllOn(int brightness)
{
    TIM2->CCR1=brightness;
    TIM2->CCR2=brightness;
    TIM2->CCR3=brightness;
    TIM2->CCR4=brightness;
    TIM3->CCR1=brightness;
    TIM3->CCR2=brightness;
    TIM3->CCR3=brightness;
 }

void ledAllOff()
{
    TIM2->CCR1=0;
    TIM2->CCR2=0;
    TIM2->CCR3=0;
    TIM2->CCR4=0;
    TIM3->CCR1=0;
    TIM3->CCR2=0;
    TIM3->CCR3=0;
}
void matrixDebounce()
{
    static int scan = 0;
    if (scan == 0)
    {
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_SET);

        btnCurrent[0] = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7);
        btnCurrent[3] = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6);
        btnCurrent[6] = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5);
        btnCurrent[9] = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4);
    }
    else if(scan == 1)
    {
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_SET);

        btnCurrent[1] = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7);
        btnCurrent[4] = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6);
        btnCurrent[7] = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5);
        btnCurrent[10] = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4);
    }
    else if(scan == 2)
    {
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_RESET);

        btnCurrent[2] = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7);
        btnCurrent[5] = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6);
        btnCurrent[8] = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5);
        btnCurrent[11] = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4);
    }
    scan++;
    if (scan ==3)
        {
            scan = 0;
        }
}

int btnDebounce(int i)
{
    if ((btnPrev[i] == 1) && (btnCurrent[i] == 0))
        {
            btnPrev[i] = btnCurrent[i];
            return 1;
        }
        else{
            btnPrev[i] = btnCurrent[i];
            return 0;
        }
}

void display(char *ddd,int length)
{
    for (int j = 0;j<length;j++)
    {
        HAL_SPI_Transmit(&hspi2,&ddd[j], sizeof(ddd[j]), 10000);
        int x = 30000;
        while (x!=0)
        {
            x--;
        }
    }
}
void waitB()
{
    dbresult = btnDebounce(x);
    if (dbresult == 1)
    {
        switch(x)
        {
        case 0: br[0] = 1;break;
        case 1: br[1] = 1;break;
        case 2: inputflag = 0;break;
        case 3: br[2] = 1;break;
        case 4: br[3] = 1;break;
        case 5: resetflag = 1;break;
        case 6: br[4] = 1;break;
        case 7: br[5] = 1;break;
        }
    }
    if((inputflag==1)&&(x<7))
    {
        x++;
    }
    else
    {
        x = 0;
    }

}
void coolEffect2()
{

static int ledShift = 20;

static int state = 0;

ledShift--;

if (ledShift == 0)

{

    ledShift = 20;

    switch (state)

    {

    case 0:led1(0,4096);break;

    case 1:led2(0,4096);break;

    case 2:led3(0,4096);break;

    case 3:led4(0,4096);break;

    case 4:led5(0,4096);break;

    case 5:led6(0,4096);break;

    case 6:led7(0,4096);break;

    }

    state++;

    if (state == 8)

    {

        state = 0;

    }

}
}

int compareArrays(int ax[], int bx[], int n) {
  int iix;
  for(iix = 0; iix <= n; iix++) {
    if (ax[iix] != bx[iix]) return 0;
  }
  return 1;
}
int charArrayIndex(int top1,int top2,int mid1,int mid2,int bot1,int bot2)
{
    int r = 989899;
    compare[0]=top1;
    compare[1]=top2;
    compare[2]=mid1;
    compare[3]=mid2;
    compare[4]=bot1;
    compare[5]=bot2;
    if (compareArrays(compare,a,5)==1)
            r = 0;
    else if (compareArrays(compare,b,5)==1)
                r = 1;
    else if (compareArrays(compare,c,5)==1)
                r = 2;
    else if (compareArrays(compare,d,5)==1)
                    r = 3;
    else if (compareArrays(compare,e,5)==1)
                    r = 4;
    else if (compareArrays(compare,f,5)==1)
                    r = 5;
    else if (compareArrays(compare,g,5)==1)
                    r = 6;
    else if (compareArrays(compare,h,5)==1)
                    r = 7;
    else if (compareArrays(compare,ii,5)==1)
                    r = 8;
    else if (compareArrays(compare,j,5)==1)
                    r = 9;
    else if (compareArrays(compare,k,5)==1)
                    r = 10;
    else if (compareArrays(compare,l,5)==1)
                    r = 11;
    else if (compareArrays(compare,m,5)==1)
                    r = 12;
    else if (compareArrays(compare,n,5)==1)
                    r = 13;
    else if (compareArrays(compare,o,5)==1)
                    r = 14;
    else if (compareArrays(compare,p,5)==1)
                    r = 15;
    else if (compareArrays(compare,q,5)==1)
                    r = 16;
    else if (compareArrays(compare,rr,5)==1)
                    r = 17;
    else if (compareArrays(compare,s,5)==1)
                    r = 18;
    else if (compareArrays(compare,t,5)==1)
                    r = 19;
    else if (compareArrays(compare,u,5)==1)
                    r = 20;
    else if (compareArrays(compare,v,5)==1)
                    r = 21;
    else if (compareArrays(compare,w,5)==1)
                    r = 22;
    else if (compareArrays(compare,xx,5)==1)
                    r = 23;
    else if (compareArrays(compare,y,5)==1)
                    r = 24;
    else if (compareArrays(compare,z,5)==1)
                    r = 25;
    else if (compareArrays(compare,space,5)==1)
                    r = 26;
    compare[0]=0;
    compare[1]=0;
    compare[2]=0;
    compare[3]=0;
    compare[4]=0;
    compare[5]=0;
    return r;
}

int numArrayIndex(int compare[6])
{
    int r;
    if (compareArrays(compare,yi,5)==1)
                r = 0;
    else if (compareArrays(compare,er,5)==1)
                r = 1;
    else if (compareArrays(compare,san,5)==1)
                r = 2;
    else if (compareArrays(compare,si,5)==1)
                    r = 3;
    else if (compareArrays(compare,wu,5)==1)
                    r = 4;
    else if (compareArrays(compare,lv,5)==1)
                    r = 5;
    else if (compareArrays(compare,qi,5)==1)
                    r = 6;
    else if (compareArrays(compare,ba,5)==1)
                    r = 7;
    else if (compareArrays(compare,jv,5)==1)
                    r = 8;
    else if (compareArrays(compare,ling,5)==1)
                    r = 9;
    return r;
}

void delay(int xxx)
{
    while(xxx!=0)
    {
        xxx--;
    }
    xxx = 1000000;
}

void charDisp(char *chr, int brightness)
{
    int xxx;
    if (chr == 'A')
        {
            xxx = 3000;
            led1(0,brightness);
            led2(1,brightness);
            led3(1,brightness);
            led4(1,brightness);
            led5(1,brightness);
            led6(1,brightness);

            while(xxx!=0)
               {
                   xxx--;
                   if (continueFlag == 1)
                       break;
               }
            xxx = 17000;
            led7(0,brightness);
            led3(1,brightness);
            while(xxx!=0)
                       {
                           xxx--;
                           if (continueFlag == 1)
                           break;
                       }
            xxx = 3000;
                   led1(0,brightness);
                   led2(1,brightness);
                   led3(1,brightness);
                   led4(1,brightness);
                   led5(1,brightness);
                   led6(1,brightness);

                   while(xxx!=0)
                      {
                          xxx--;
                          if (continueFlag == 1)
                              break;
                      }
            xxx = 7000;
            ledAllOff(brightness);
            while(xxx!=0)
                       {
                           xxx--;
                           if (continueFlag == 1)
                           break;
                       }

        }
    else if (chr == 'E')
        {
            xxx = 3000;
            ledAllOn(brightness);
            while(xxx!=0)
               {
                   xxx--;
                   if (continueFlag == 1)
                       break;
               }
            xxx = 20000;
            led4(0,brightness);
            led1(1,brightness);
            led7(1,brightness);
            while(xxx!=0)
                       {
                           xxx--;
                           if (continueFlag == 1)
                           break;
                       }
            xxx = 7000;
            ledAllOff(brightness);
            while(xxx!=0)
                       {
                           xxx--;
                           if (continueFlag == 1)
                           break;
                       }

        }
    else if (chr == 'B')
        {
            xxx = 3000;
            ledAllOn(brightness);
            while(xxx!=0)
               {
                   xxx--;
                   if (continueFlag == 1)
                       break;
               }
            xxx = 17000;
            led4(0,brightness);
            led1(1,brightness);
            led7(1,brightness);
            while(xxx!=0)
                       {
                           xxx--;
                           if (continueFlag == 1)
                           break;
                       }
            xxx = 3000;
            led6(0,brightness);
            led5(1,brightness);
            led3(1,brightness);
            led2(1,brightness);
            while(xxx!=0)
               {
                   xxx--;
                   if (continueFlag == 1)
                       break;
               }
            xxx = 7000;
            ledAllOff(brightness);
            while(xxx!=0)
                       {
                           xxx--;
                           if (continueFlag == 1)
                           break;
                       }

        }
    else if (chr == 'C')
            {
                xxx = 3000;
                led6(0,brightness);
                led5(1,brightness);
                led4(1,brightness);
                led3(1,brightness);
                led2(1,brightness);
                while(xxx!=0)
                   {
                       xxx--;
                       if (continueFlag == 1)
                           break;
                   }
                xxx = 17000;
                led1(0,brightness);
                led7(1,brightness);
                while(xxx!=0)
                           {
                               xxx--;
                               if (continueFlag == 1)
                               break;
                           }
                xxx = 3000;
                led6(0,brightness);
                led2(1,brightness);
                while(xxx!=0)
                   {
                       xxx--;
                       if (continueFlag == 1)
                           break;
                   }
                xxx = 7000;
                ledAllOff(brightness);
                while(xxx!=0)
                           {
                               xxx--;
                               if (continueFlag == 1)
                               break;
                           }

            }
    else if (chr == 'D')
                {
                    xxx = 3000;
                    ledAllOn(brightness);
                    while(xxx!=0)
                       {
                           xxx--;
                           if (continueFlag == 1)
                               break;
                       }
                    xxx = 17000;
                            led1(0,brightness);
                            led7(1,brightness);
                    while(xxx!=0)
                               {
                                   xxx--;
                                   if (continueFlag == 1)
                                   break;
                               }
                    xxx = 3000;
                    led6(0,brightness);
                    led5(1,brightness);
                    led4(1,brightness);
                    led3(1,brightness);
                    led2(1,brightness);
                    while(xxx!=0)
                       {
                           xxx--;
                           if (continueFlag == 1)
                               break;
                       }
                    xxx = 7000;
                    ledAllOff(brightness);
                    while(xxx!=0)
                               {
                                   xxx--;
                                   if (continueFlag == 1)
                                   break;
                               }

                }
 else if (chr == 'E')
    {
        xxx = 3000;
        ledAllOn(brightness);
        while(xxx!=0)
           {
               xxx--;
               if (continueFlag == 1)
                   break;
           }
        xxx = 20000;
        led4(0,brightness);
        led1(1,brightness);
        led7(1,brightness);
        while(xxx!=0)
                   {
                       xxx--;
                       if (continueFlag == 1)
                       break;
                   }
        xxx = 7000;
        ledAllOff(brightness);
        while(xxx!=0)
                   {
                       xxx--;
                       if (continueFlag == 1)
                       break;
                   }

    }
 else if (chr == 'F')
     {
         xxx = 3000;
         ledAllOn(brightness);
         while(xxx!=0)
            {
                xxx--;
                if (continueFlag == 1)
                    break;
            }
         xxx = 17000;
         led4(0,brightness);
         led7(1,brightness);
         while(xxx!=0)
                    {
                        xxx--;
                        if (continueFlag == 1)
                        break;
                    }
         xxx = 3000;
                  led7(0,brightness);
                  while(xxx!=0)
                             {
                                 xxx--;
                                 if (continueFlag == 1)
                                 break;
                             }
         xxx = 7000;
         ledAllOff(brightness);
         while(xxx!=0)
                    {
                        xxx--;
                        if (continueFlag == 1)
                        break;
                    }

     }
 else if (chr == 'G')
            {
                xxx = 3000;
                led6(0,brightness);
                led5(1,brightness);
                led4(1,brightness);
                led3(1,brightness);
                led2(1,brightness);
                while(xxx!=0)
                   {
                       xxx--;
                       if (continueFlag == 1)
                           break;
                   }
                xxx = 14000;
                led1(0,brightness);
                led7(1,brightness);
                while(xxx!=0)
                           {
                               xxx--;
                               if (continueFlag == 1)
                               break;
                           }
                xxx = 3000;
                led1(0,brightness);
                led7(1,brightness);
                led3(1,brightness);
                while(xxx!=0)
                   {
                       xxx--;
                       if (continueFlag == 1)
                           break;
                   }
                xxx = 3000;
                led1(0,brightness);
                led2(1,brightness);
                led6(1,brightness);
                led3(1,brightness);
                while(xxx!=0)
                   {
                       xxx--;
                       if (continueFlag == 1)
                           break;
                   }
                xxx = 7000;
                ledAllOff(brightness);
                while(xxx!=0)
                           {
                               xxx--;
                               if (continueFlag == 1)
                               break;
                           }

            }
 else if (chr == 'H')
     {
         xxx = 3000;
         ledAllOn(brightness);
         while(xxx!=0)
            {
                xxx--;
                if (continueFlag == 1)
                    break;
            }
         xxx = 17000;
         led4(0,brightness);
         while(xxx!=0)
                    {
                        xxx--;
                        if (continueFlag == 1)
                        break;
                    }
         xxx = 3000;
          ledAllOn(brightness);
          while(xxx!=0)
                     {
                         xxx--;
                         if (continueFlag == 1)
                         break;
                     }
         xxx = 7000;
         ledAllOff(brightness);
         while(xxx!=0)
                    {
                        xxx--;
                        if (continueFlag == 1)
                        break;
                    }

     }
 else if (chr == 'I')
     {
         xxx = 10000;
         led7(0,brightness);
         led1(1,brightness);
         while(xxx!=0)
            {
                xxx--;
                if (continueFlag == 1)
                    break;
            }
         xxx = 3000;
         ledAllOn(brightness);
         while(xxx!=0)
                    {
                        xxx--;
                        if (continueFlag == 1)
                        break;
                    }
         xxx = 10000;
         led7(0,brightness);
         led1(1,brightness);
         while(xxx!=0)
            {
                xxx--;
                if (continueFlag == 1)
                    break;
            }
         xxx = 7000;
         ledAllOff(brightness);
         while(xxx!=0)
                    {
                        xxx--;
                        if (continueFlag == 1)
                        break;
                    }

     }
 else if (chr == 'J')
     {
         xxx = 4600;
         led7(0,brightness);
         led2(1,brightness);
         while(xxx!=0)
            {
                xxx--;
                if (continueFlag == 1)
                    break;
            }
         xxx = 9200;
         led7(0,brightness);
	     led1(1,brightness);
         while(xxx!=0)
                    {
                        xxx--;
                        if (continueFlag == 1)
                        break;
                    }
         xxx = 4600;
         led7(0,brightness);
         led6(1,brightness);
         led5(1,brightness);
         led4(1,brightness);
         led3(1,brightness);
         led2(1,brightness);
         while(xxx!=0)
            {
                xxx--;
                if (continueFlag == 1)
                    break;
            }
         xxx = 4600;
		  led7(0,brightness);
		  while(xxx!=0)
			 {
				 xxx--;
				 if (continueFlag == 1)
					 break;
			 }
         xxx = 7000;
         ledAllOff(brightness);
         while(xxx!=0)
                    {
                        xxx--;
                        if (continueFlag == 1)
                        break;
                    }

     }
 else if (chr == 'K')
     {
         xxx = 5000;
         ledAllOn(brightness);
         while(xxx!=0)
            {
                xxx--;
                if (continueFlag == 1)
                    break;
            }
         xxx = 4500;
         led4(0,brightness);
         while(xxx!=0)
                    {
                        xxx--;
                        if (continueFlag == 1)
                        break;
                    }
         xxx = 4500;
         led5(0,brightness);
         led3(1,brightness);
         while(xxx!=0)
            {
                xxx--;
                if (continueFlag == 1)
                    break;
            }
         xxx = 4500;
		led6(0,brightness);
		led2(1,brightness);
		while(xxx!=0)
		 {
			 xxx--;
			 if (continueFlag == 1)
				 break;
		 }

		  xxx = 4500;
	   led7(0,brightness);
	   led1(1,brightness);
	   while(xxx!=0)
		  {
			  xxx--;
			  if (continueFlag == 1)
				  break;
		  }

         xxx = 7000;
         ledAllOff(brightness);
         while(xxx!=0)
                    {
                        xxx--;
                        if (continueFlag == 1)
                        break;
                    }

     }
 else if (chr == 'L')
      {
          xxx = 3000;
          ledAllOn(brightness);
          while(xxx!=0)
             {
                 xxx--;
                 if (continueFlag == 1)
                     break;
             }
          xxx = 20000;
          led1(0,brightness);
          while(xxx!=0)
                     {
                         xxx--;
                         if (continueFlag == 1)
                         break;
                     }
          xxx = 7000;
          ledAllOff(brightness);
          while(xxx!=0)
                     {
                         xxx--;
                         if (continueFlag == 1)
                         break;
                     }
      }
 else if (chr == 'M')
       {
           xxx = 4600;
           ledAllOn(brightness);
           while(xxx!=0)
              {
                  xxx--;
                  if (continueFlag == 1)
                      break;
              }
           xxx = 4600;
           led6(0,brightness);
           led5(1,brightness);
           while(xxx!=0)
                      {
                          xxx--;
                          if (continueFlag == 1)
                          break;
                      }
           xxx = 4600;
		  led5(0,brightness);
		  led4(1,brightness);
		  while(xxx!=0)
					 {
						 xxx--;
						 if (continueFlag == 1)
						 break;
					 }
		  xxx = 4600;
			 led6(0,brightness);
			 led5(1,brightness);
			 while(xxx!=0)
						{
							xxx--;
							if (continueFlag == 1)
							break;
						}
			 xxx = 4600;
			ledAllOn(brightness);
			while(xxx!=0)
					   {
						   xxx--;
						   if (continueFlag == 1)
						   break;
					   }

           xxx = 7000;
           ledAllOff(brightness);
           while(xxx!=0)
                      {
                          xxx--;
                          if (continueFlag == 1)
                          break;
                      }
       }
 else if (chr == 'N')
        {
            xxx = 4600;
            ledAllOn(brightness);
            while(xxx!=0)
               {
                   xxx--;
                   if (continueFlag == 1)
                       break;
               }
            xxx = 4600;
            led6(0,brightness);
            led5(1,brightness);
            while(xxx!=0)
                       {
                           xxx--;
                           if (continueFlag == 1)
                           break;
                       }
            xxx = 4600;
 		  led5(0,brightness);
 		  led4(1,brightness);
 		  while(xxx!=0)
 					 {
 						 xxx--;
 						 if (continueFlag == 1)
 						 break;
 					 }
 		  xxx = 4600;
 			 led4(0,brightness);
 			 led3(1,brightness);
 			 while(xxx!=0)
 						{
 							xxx--;
 							if (continueFlag == 1)
 							break;
 						}
 			 xxx = 4600;
 			ledAllOn(brightness);
 			while(xxx!=0)
 					   {
 						   xxx--;
 						   if (continueFlag == 1)
 						   break;
 					   }

            xxx = 7000;
            ledAllOff(brightness);
            while(xxx!=0)
                       {
                           xxx--;
                           if (continueFlag == 1)
                           break;
                       }
        }
 else if (chr == 'O')
         {
             xxx = 4600;
             led6(0,brightness);
             led5(1,brightness);
             led4(1,brightness);
             led3(1,brightness);
             led2(1,brightness);
             while(xxx!=0)
                {
                    xxx--;
                    if (continueFlag == 1)
                        break;
                }
             xxx = 13800;
             led7(0,brightness);
             led1(1,brightness);
             while(xxx!=0)
                        {
                            xxx--;
                            if (continueFlag == 1)
                            break;
                        }
  			 xxx = 4600;
  			led6(0,brightness);
			 led5(1,brightness);
			 led4(1,brightness);
			 led3(1,brightness);
			 led2(1,brightness);
  			while(xxx!=0)
  					   {
  						   xxx--;
  						   if (continueFlag == 1)
  						   break;
  					   }

             xxx = 7000;
             ledAllOff(brightness);
             while(xxx!=0)
                        {
                            xxx--;
                            if (continueFlag == 1)
                            break;
                        }
         }
 else if (chr == 'P')
         {
             xxx = 4600;
             ledAllOn(brightness);
             while(xxx!=0)
                {
                    xxx--;
                    if (continueFlag == 1)
                        break;
                }
             xxx = 13800;
             led7(0,brightness);
             led4(1,brightness);
             while(xxx!=0)
                        {
                            xxx--;
                            if (continueFlag == 1)
                            break;
                        }
  			 xxx = 4600;
  			led6(0,brightness);
			 led5(1,brightness);
  			while(xxx!=0)
  					   {
  						   xxx--;
  						   if (continueFlag == 1)
  						   break;
  					   }

             xxx = 7000;
             ledAllOff(brightness);
             while(xxx!=0)
                        {
                            xxx--;
                            if (continueFlag == 1)
                            break;
                        }
         }
 else if (chr == 'Q')
          {
              xxx = 4600;
              led6(0,brightness);
			 led5(1,brightness);
			 led4(1,brightness);
			 led3(1,brightness);
			 led2(1,brightness);
              while(xxx!=0)
                 {
                     xxx--;
                     if (continueFlag == 1)
                         break;
                 }
              xxx = 4600;
              led7(0,brightness);
              led1(1,brightness);
              while(xxx!=0)
                         {
                             xxx--;
                             if (continueFlag == 1)
                             break;
                         }
   			 xxx = 4600;
   			led7(0,brightness);
   			led3(1,brightness);
			  led1(1,brightness);
   			while(xxx!=0)
   					   {
   						   xxx--;
   						   if (continueFlag == 1)
   						   break;
   					   }
   			xxx = 4600;
			led7(0,brightness);
			led2(1,brightness);
			while(xxx!=0)
					   {
						   xxx--;
						   if (continueFlag == 1)
						   break;
					   }
			xxx = 4600;
			led6(0,brightness);
			led5(1,brightness);
			  led4(1,brightness);
			  led3(1,brightness);
			  led1(1,brightness);
			while(xxx!=0)
					   {
						   xxx--;
						   if (continueFlag == 1)
						   break;
					   }
              xxx = 7000;
              ledAllOff(brightness);
              while(xxx!=0)
                         {
                             xxx--;
                             if (continueFlag == 1)
                             break;
                         }
          }
 else if (chr == 'R')
         {
             xxx = 4600;
             ledAllOn(brightness);
             while(xxx!=0)
                {
                    xxx--;
                    if (continueFlag == 1)
                        break;
                }
             xxx = 9200;
             led7(0,brightness);
             led4(1,brightness);
             while(xxx!=0)
                        {
                            xxx--;
                            if (continueFlag == 1)
                            break;
                        }
  			 xxx = 4600;
  			led7(0,brightness);
			 led4(1,brightness);
			 led3(1,brightness);
  			while(xxx!=0)
  					   {
  						   xxx--;
  						   if (continueFlag == 1)
  						   break;
  					   }
  			 xxx = 4600;
			led6(0,brightness);
			 led5(1,brightness);
			 led2(1,brightness);
			 led1(1,brightness);
			while(xxx!=0)
					   {
						   xxx--;
						   if (continueFlag == 1)
						   break;
					   }

             xxx = 7000;
             ledAllOff(brightness);
             while(xxx!=0)
                        {
                            xxx--;
                            if (continueFlag == 1)
                            break;
                        }
         }
 else if (chr == 'S')
         {
             xxx = 4600;
             led6(0,brightness);
             led5(1,brightness);
             led2(1,brightness);
             while(xxx!=0)
                {
                    xxx--;
                    if (continueFlag == 1)
                        break;
                }
             xxx = 13800;
             led7(0,brightness);
             led4(1,brightness);
             led1(1,brightness);
             while(xxx!=0)
                        {
                            xxx--;
                            if (continueFlag == 1)
                            break;
                        }
  			 xxx = 4600;
  			led6(0,brightness);
			 led3(1,brightness);
			 led2(1,brightness);
  			while(xxx!=0)
  					   {
  						   xxx--;
  						   if (continueFlag == 1)
  						   break;
  					   }
             xxx = 7000;
             ledAllOff(brightness);
             while(xxx!=0)
                        {
                            xxx--;
                            if (continueFlag == 1)
                            break;
                        }
         }
 else if (chr == 'T')
         {
             xxx = 9200;
             led7(0,brightness);
             while(xxx!=0)
                {
                    xxx--;
                    if (continueFlag == 1)
                        break;
                }
             xxx = 4600;
             ledAllOn(brightness);
             while(xxx!=0)
                        {
                            xxx--;
                            if (continueFlag == 1)
                            break;
                        }
  			 xxx = 9200;
  			led7(0,brightness);
  			while(xxx!=0)
  					   {
  						   xxx--;
  						   if (continueFlag == 1)
  						   break;
  					   }
             xxx = 7000;
             ledAllOff(brightness);
             while(xxx!=0)
                        {
                            xxx--;
                            if (continueFlag == 1)
                            break;
                        }
         }
 else if (chr == 'U')
          {
              xxx = 4600;
              led7(0,brightness);
			 led6(1,brightness);
			 led5(1,brightness);
			 led4(1,brightness);
			 led3(1,brightness);
			 led2(1,brightness);
              while(xxx!=0)
                 {
                     xxx--;
                     if (continueFlag == 1)
                         break;
                 }
              xxx = 13800;
              led1(0,brightness);
              while(xxx!=0)
                         {
                             xxx--;
                             if (continueFlag == 1)
                             break;
                         }
   			 xxx = 4600;
   			led7(0,brightness);
		   led6(1,brightness);
		   led5(1,brightness);
		   led4(1,brightness);
		   led3(1,brightness);
		   led2(1,brightness);
   			while(xxx!=0)
   					   {
   						   xxx--;
   						   if (continueFlag == 1)
   						   break;
   					   }
              xxx = 7000;
              ledAllOff(brightness);
              while(xxx!=0)
                         {
                             xxx--;
                             if (continueFlag == 1)
                             break;
                         }
          }
 else if (chr == 'U')
           {
               xxx = 4600;
               led7(0,brightness);
               led6(1,brightness);
               led5(1,brightness);
               led4(1,brightness);
               led3(1,brightness);

               while(xxx!=0)
                  {
                      xxx--;
                      if (continueFlag == 1)
                          break;
                  }
               xxx = 4600;
               led2(0,brightness);
               while(xxx!=0)
                          {
                              xxx--;
                              if (continueFlag == 1)
                              break;
                          }
    			 xxx = 4600;
    			 led1(0,brightness);
    			while(xxx!=0)
    					   {
    						   xxx--;
    						   if (continueFlag == 1)
    						   break;
    					   }
    			xxx = 4600;
				   led2(0,brightness);
				   while(xxx!=0)
							  {
								  xxx--;
								  if (continueFlag == 1)
								  break;
							  }
				   xxx = 4600;
					 led7(0,brightness);
					 led6(1,brightness);
					 led5(1,brightness);
					 led4(1,brightness);
					 led3(1,brightness);

					 while(xxx!=0)
						{
							xxx--;
							if (continueFlag == 1)
								break;
						}
               xxx = 7000;
               ledAllOff(brightness);
               while(xxx!=0)
                          {
                              xxx--;
                              if (continueFlag == 1)
                              break;
                          }
           }
 else if (chr == 'W')
           {
               xxx = 4600;
               led7(0,brightness);
               led6(1,brightness);
               led5(1,brightness);
               led4(1,brightness);
               led3(1,brightness);
               led2(1,brightness);
               while(xxx!=0)
                  {
                      xxx--;
                      if (continueFlag == 1)
                          break;
                  }
               xxx = 4600;
               led1(0,brightness);
               while(xxx!=0)
                          {
                              xxx--;
                              if (continueFlag == 1)
                              break;
                          }
    			 xxx = 4600;
    			 led4(0,brightness);
				led3(1,brightness);
				led2(1,brightness);
    			while(xxx!=0)
    					   {
    						   xxx--;
    						   if (continueFlag == 1)
    						   break;
    					   }
    			 xxx = 4600;
			   led1(0,brightness);
			   while(xxx!=0)
						  {
							  xxx--;
							  if (continueFlag == 1)
							  break;
						  }
    			xxx = 4600;
				   led2(0,brightness);
				   while(xxx!=0)
							  {
								  xxx--;
								  if (continueFlag == 1)
								  break;
							  }
				   xxx = 4600;
					 led7(0,brightness);
					 led6(1,brightness);
					 led5(1,brightness);
					 led4(1,brightness);
					 led3(1,brightness);
					 led2(1,brightness);
					 while(xxx!=0)
						{
							xxx--;
							if (continueFlag == 1)
								break;
						}
               xxx = 7000;
               ledAllOff(brightness);
               while(xxx!=0)
                          {
                              xxx--;
                              if (continueFlag == 1)
                              break;
                          }
           }
 else if (chr == 'X')
            {
                xxx = 4600;
                led7(0,brightness);
                led6(1,brightness);
                led2(1,brightness);
                led1(1,brightness);
                while(xxx!=0)
                   {
                       xxx--;
                       if (continueFlag == 1)
                           break;
                   }
                xxx = 4600;
                led5(0,brightness);
				led3(1,brightness);
                while(xxx!=0)
                           {
                               xxx--;
                               if (continueFlag == 1)
                               break;
                           }
     			 xxx = 4600;
     			 led4(0,brightness);
     			while(xxx!=0)
     					   {
     						   xxx--;
     						   if (continueFlag == 1)
     						   break;
     					   }
     			 xxx = 4600;
     			led5(0,brightness);
				led3(1,brightness);
 			   while(xxx!=0)
 						  {
 							  xxx--;
 							  if (continueFlag == 1)
 							  break;
 						  }
     			xxx = 4600;
     			led7(0,brightness);
     			                led6(1,brightness);
     			                led2(1,brightness);
     			                led1(1,brightness);
 				   while(xxx!=0)
 							  {
 								  xxx--;
 								  if (continueFlag == 1)
 								  break;
 							  }
                xxx = 7000;
                ledAllOff(brightness);
                while(xxx!=0)
                           {
                               xxx--;
                               if (continueFlag == 1)
                               break;
                           }
            }
 else if (chr == 'Y')
             {
                 xxx = 4600;
                 led7(0,brightness);
                 led6(1,brightness);
                 led5(1,brightness);
                 while(xxx!=0)
                    {
                        xxx--;
                        if (continueFlag == 1)
                            break;
                    }
                 xxx = 4600;
                 led4(0,brightness);
                 while(xxx!=0)
                            {
                                xxx--;
                                if (continueFlag == 1)
                                break;
                            }
      			 xxx = 4600;
      			led3(0,brightness);
      			                 led2(1,brightness);
      			                 led1(1,brightness);
      			while(xxx!=0)
      					   {
      						   xxx--;
      						   if (continueFlag == 1)
      						   break;
      					   }
      			 xxx = 4600;
      			led4(0,brightness);
  			   while(xxx!=0)
  						  {
  							  xxx--;
  							  if (continueFlag == 1)
  							  break;
  						  }
      			xxx = 4600;
      			led7(0,brightness);
      			                 led6(1,brightness);
      			                 led5(1,brightness);
  				   while(xxx!=0)
  							  {
  								  xxx--;
  								  if (continueFlag == 1)
  								  break;
  							  }
                 xxx = 7000;
                 ledAllOff(brightness);
                 while(xxx!=0)
                            {
                                xxx--;
                                if (continueFlag == 1)
                                break;
                            }
             }
 else if (chr == 'Z')
            {
                xxx = 4600;
                led5(0,brightness);
                led2(1,brightness);
                led1(1,brightness);
                while(xxx!=0)
                   {
                       xxx--;
                       if (continueFlag == 1)
                           break;
                   }
                xxx = 4600;
                led7(0,brightness);
                                led3(1,brightness);
                                led1(1,brightness);
                while(xxx!=0)
                           {
                               xxx--;
                               if (continueFlag == 1)
                               break;
                           }
     			 xxx = 4600;
     			led7(0,brightness);
     			                led4(1,brightness);
     			                led1(1,brightness);
     			while(xxx!=0)
     					   {
     						   xxx--;
     						   if (continueFlag == 1)
     						   break;
     					   }
     			 xxx = 4600;
     			led7(0,brightness);
     			                led5(1,brightness);
     			                led1(1,brightness);
 			   while(xxx!=0)
 						  {
 							  xxx--;
 							  if (continueFlag == 1)
 							  break;
 						  }
     			xxx = 4600;
     			led7(0,brightness);
     			                led6(1,brightness);
     			                led1(1,brightness);
 				   while(xxx!=0)
 							  {
 								  xxx--;
 								  if (continueFlag == 1)
 								  break;
 							  }
                xxx = 7000;
                ledAllOff(brightness);
                while(xxx!=0)
                           {
                               xxx--;
                               if (continueFlag == 1)
                               break;
                           }
            }
 else if (chr == '1')
 {
     xxx = 4600;
                     led5(0,brightness);
                     led1(1,brightness);
                     while(xxx!=0)
                        {
                            xxx--;
                            if (continueFlag == 1)
                                break;
                        }
                     xxx = 4600;
                     led6(0,brightness);
                                     led1(1,brightness);
                     while(xxx!=0)
                                {
                                    xxx--;
                                    if (continueFlag == 1)
                                    break;
                                }
                      xxx = 4600;
                     ledAllOn(brightness);
                     while(xxx!=0)
                                {
                                    xxx--;
                                    if (continueFlag == 1)
                                    break;
                                }
                      xxx = 4600;
                                     led1(0,brightness);
                    while(xxx!=0)
                               {
                                   xxx--;
                                   if (continueFlag == 1)
                                   break;
                               }
                     xxx = 4600;
                                     led1(0,brightness);
                        while(xxx!=0)
                                   {
                                       xxx--;
                                       if (continueFlag == 1)
                                       break;
                                   }
                     xxx = 7000;
                     ledAllOff(brightness);
                     while(xxx!=0)
                                {
                                    xxx--;
                                    if (continueFlag == 1)
                                    break;
                                }
 }
 else if (chr == '2')
 {
     xxx = 4600;
                     led6(0,brightness);
                     led2(1,brightness);
                     led1(1,brightness);
                     while(xxx!=0)
                        {
                            xxx--;
                            if (continueFlag == 1)
                                break;
                        }
                     xxx = 4600;
                     led7(0,brightness);
                     led3(1,brightness);
                     led1(1,brightness);
                     while(xxx!=0)
                                {
                                    xxx--;
                                    if (continueFlag == 1)
                                    break;
                                }
                      xxx = 4600;
                      led7(0,brightness);
                      led4(1,brightness);
                      led1(1,brightness);
                     while(xxx!=0)
                                {
                                    xxx--;
                                    if (continueFlag == 1)
                                    break;
                                }
                      xxx = 4600;
                      led7(0,brightness);
                    led4(1,brightness);
                    led1(1,brightness);
                    while(xxx!=0)
                               {
                                   xxx--;
                                   if (continueFlag == 1)
                                   break;
                               }
                     xxx = 4600;
                     led6(0,brightness);
                     led5(1,brightness);
                     led1(1,brightness);
                        while(xxx!=0)
                                   {
                                       xxx--;
                                       if (continueFlag == 1)
                                       break;
                                   }
                     xxx = 7000;
                     ledAllOff(brightness);
                     while(xxx!=0)
                                {
                                    xxx--;
                                    if (continueFlag == 1)
                                    break;
                                }
 }
 else if (chr == '3')
  {
      xxx = 4600;
                      led6(0,brightness);
                      led2(1,brightness);
                      while(xxx!=0)
                         {
                             xxx--;
                             if (continueFlag == 1)
                                 break;
                         }
                      xxx = 4600;
                      led7(0,brightness);
                      led1(1,brightness);
                      while(xxx!=0)
                                 {
                                     xxx--;
                                     if (continueFlag == 1)
                                     break;
                                 }
                       xxx = 4600;
                       led7(0,brightness);
                       led4(1,brightness);
                       led1(1,brightness);
                      while(xxx!=0)
                                 {
                                     xxx--;
                                     if (continueFlag == 1)
                                     break;
                                 }
                       xxx = 4600;
                       led7(0,brightness);
                     led4(1,brightness);
                     led1(1,brightness);
                     while(xxx!=0)
                                {
                                    xxx--;
                                    if (continueFlag == 1)
                                    break;
                                }
                      xxx = 4600;
                      led6(0,brightness);
                      led5(1,brightness);
                      led3(1,brightness);
                      led2(1,brightness);
                         while(xxx!=0)
                                    {
                                        xxx--;
                                        if (continueFlag == 1)
                                        break;
                                    }
                      xxx = 7000;
                      ledAllOff(brightness);
                      while(xxx!=0)
                                 {
                                     xxx--;
                                     if (continueFlag == 1)
                                     break;
                                 }
  }
 else if (chr == '4')
  {
      xxx = 4600;
                      led3(0,brightness);
                      led4(1,brightness);
                      while(xxx!=0)
                         {
                             xxx--;
                             if (continueFlag == 1)
                                 break;
                         }
                      xxx = 4600;
                      led5(0,brightness);
                      led3(1,brightness);
                      while(xxx!=0)
                                 {
                                     xxx--;
                                     if (continueFlag == 1)
                                     break;
                                 }
                       xxx = 4600;
                       led6(0,brightness);
                       led3(1,brightness);
                      while(xxx!=0)
                                 {
                                     xxx--;
                                     if (continueFlag == 1)
                                     break;
                                 }
                       xxx = 4600;
                       ledAllOn(brightness);
                     while(xxx!=0)
                                {
                                    xxx--;
                                    if (continueFlag == 1)
                                    break;
                                }
                      xxx = 4600;
                      led3(0,brightness);
                         while(xxx!=0)
                                    {
                                        xxx--;
                                        if (continueFlag == 1)
                                        break;
                                    }
                      xxx = 7000;
                      ledAllOff(brightness);
                      while(xxx!=0)
                                 {
                                     xxx--;
                                     if (continueFlag == 1)
                                     break;
                                 }
  }
 else if (chr == '5')
   {
       xxx = 4600;
                       led7(0,brightness);
                       led6(1,brightness);
                       led5(1,brightness);
                       led2(1,brightness);
                       while(xxx!=0)
                          {
                              xxx--;
                              if (continueFlag == 1)
                                  break;
                          }
                       xxx = 4600;
                       led7(0,brightness);
                       led5(1,brightness);
                       led1(1,brightness);
                       while(xxx!=0)
                                  {
                                      xxx--;
                                      if (continueFlag == 1)
                                      break;
                                  }
                        xxx = 4600;
                        led7(0,brightness);
                                               led5(1,brightness);
                                               led1(1,brightness);
                       while(xxx!=0)
                                  {
                                      xxx--;
                                      if (continueFlag == 1)
                                      break;
                                  }
                        xxx = 4600;
                        led7(0,brightness);
                                               led5(1,brightness);
                                               led1(1,brightness);
                      while(xxx!=0)
                                 {
                                     xxx--;
                                     if (continueFlag == 1)
                                     break;
                                 }
                       xxx = 4600;
                       led7(0,brightness);
                       led4(1,brightness);
                                              led3(1,brightness);
                                              led2(1,brightness);
                          while(xxx!=0)
                                     {
                                         xxx--;
                                         if (continueFlag == 1)
                                         break;
                                     }
                       xxx = 7000;
                       ledAllOff(brightness);
                       while(xxx!=0)
                                  {
                                      xxx--;
                                      if (continueFlag == 1)
                                      break;
                                  }
   }
 else if (chr == '6')
   {
       xxx = 4600;
                       led6(0,brightness);
                       led5(1,brightness);
                       led4(1,brightness);
                       led3(1,brightness);
                       led2(1,brightness);
                       while(xxx!=0)
                          {
                              xxx--;
                              if (continueFlag == 1)
                                  break;
                          }
                       xxx = 4600;
                       led7(0,brightness);
                       led4(1,brightness);
                       led1(1,brightness);
                       while(xxx!=0)
                                  {
                                      xxx--;
                                      if (continueFlag == 1)
                                      break;
                                  }
                        xxx = 4600;
                        led7(0,brightness);
                                               led4(1,brightness);
                                               led1(1,brightness);
                       while(xxx!=0)
                                  {
                                      xxx--;
                                      if (continueFlag == 1)
                                      break;
                                  }
                        xxx = 4600;
                        led7(0,brightness);
                                               led4(1,brightness);
                                               led1(1,brightness);
                      while(xxx!=0)
                                 {
                                     xxx--;
                                     if (continueFlag == 1)
                                     break;
                                 }
                       xxx = 4600;
                       led6(0,brightness);

                                              led3(1,brightness);
                                              led2(1,brightness);
                          while(xxx!=0)
                                     {
                                         xxx--;
                                         if (continueFlag == 1)
                                         break;
                                     }
                       xxx = 7000;
                       ledAllOff(brightness);
                       while(xxx!=0)
                                  {
                                      xxx--;
                                      if (continueFlag == 1)
                                      break;
                                  }
   }
 else if (chr == '7')
   {
       xxx = 4600;
                       led7(0,brightness);
                       while(xxx!=0)
                          {
                              xxx--;
                              if (continueFlag == 1)
                                  break;
                          }
                       xxx = 4600;
                       led7(0,brightness);
                       while(xxx!=0)
                                  {
                                      xxx--;
                                      if (continueFlag == 1)
                                      break;
                                  }
                        xxx = 4600;
                        led7(0,brightness);
                                               led4(1,brightness);
                                               led3(1,brightness);
                                               led2(1,brightness);
                                               led1(1,brightness);
                       while(xxx!=0)
                                  {
                                      xxx--;
                                      if (continueFlag == 1)
                                      break;
                                  }
                        xxx = 4600;
                        led7(0,brightness);
                                               led5(1,brightness);
                      while(xxx!=0)
                                 {
                                     xxx--;
                                     if (continueFlag == 1)
                                     break;
                                 }
                       xxx = 4600;
                       led7(0,brightness);
                                              led6(1,brightness);
                          while(xxx!=0)
                                     {
                                         xxx--;
                                         if (continueFlag == 1)
                                         break;
                                     }
                       xxx = 7000;
                       ledAllOff(brightness);
                       while(xxx!=0)
                                  {
                                      xxx--;
                                      if (continueFlag == 1)
                                      break;
                                  }
   }
 else if (chr == '8')
    {
        xxx = 4600;
                        led6(0,brightness);
                        led5(1,brightness);
                        led3(1,brightness);
                        led2(1,brightness);
                        while(xxx!=0)
                           {
                               xxx--;
                               if (continueFlag == 1)
                                   break;
                           }
                        xxx = 4600;
                        led7(0,brightness);
                        led4(1,brightness);
                        led1(1,brightness);
                        while(xxx!=0)
                                   {
                                       xxx--;
                                       if (continueFlag == 1)
                                       break;
                                   }
                         xxx = 4600;
                         led7(0,brightness);
                                                 led4(1,brightness);
                                                 led1(1,brightness);
                        while(xxx!=0)
                                   {
                                       xxx--;
                                       if (continueFlag == 1)
                                       break;
                                   }
                         xxx = 4600;
                         led7(0,brightness);
                                                 led4(1,brightness);
                                                 led1(1,brightness);
                       while(xxx!=0)
                                  {
                                      xxx--;
                                      if (continueFlag == 1)
                                      break;
                                  }
                        xxx = 4600;
                        led6(0,brightness);
                                               led5(1,brightness);
                                               led3(1,brightness);
                                               led2(1,brightness);
                           while(xxx!=0)
                                      {
                                          xxx--;
                                          if (continueFlag == 1)
                                          break;
                                      }
                        xxx = 7000;
                        ledAllOff(brightness);
                        while(xxx!=0)
                                   {
                                       xxx--;
                                       if (continueFlag == 1)
                                       break;
                                   }
    }
 else if (chr == '9')
     {
         xxx = 4600;
                         led6(0,brightness);
                         led5(1,brightness);
                         led2(1,brightness);
                         while(xxx!=0)
                            {
                                xxx--;
                                if (continueFlag == 1)
                                    break;
                            }
                         xxx = 4600;
                         led7(0,brightness);
                         led4(1,brightness);
                         led1(1,brightness);
                         while(xxx!=0)
                                    {
                                        xxx--;
                                        if (continueFlag == 1)
                                        break;
                                    }
                          xxx = 4600;
                          led7(0,brightness);
                                                  led4(1,brightness);
                                                  led1(1,brightness);
                         while(xxx!=0)
                                    {
                                        xxx--;
                                        if (continueFlag == 1)
                                        break;
                                    }
                          xxx = 4600;
                          led7(0,brightness);
                                                  led4(1,brightness);
                                                  led1(1,brightness);
                        while(xxx!=0)
                                   {
                                       xxx--;
                                       if (continueFlag == 1)
                                       break;
                                   }
                         xxx = 4600;
                         led6(0,brightness);
                                                led5(1,brightness);
                                                led4(1,brightness);
                                                led3(1,brightness);
                                                led2(1,brightness);
                            while(xxx!=0)
                                       {
                                           xxx--;
                                           if (continueFlag == 1)
                                           break;
                                       }
                         xxx = 7000;
                         ledAllOff(brightness);
                         while(xxx!=0)
                                    {
                                        xxx--;
                                        if (continueFlag == 1)
                                        break;
                                    }
     }
 else if (chr == '0')
     {
         xxx = 4600;
         led6(0,brightness);
                                                        led5(1,brightness);
                                                        led4(1,brightness);
                                                        led3(1,brightness);
                                                        led2(1,brightness);
                         while(xxx!=0)
                            {
                                xxx--;
                                if (continueFlag == 1)
                                    break;
                            }
                         xxx = 4600;
                         led7(0,brightness);
                         led3(1,brightness);
                         led1(1,brightness);
                         while(xxx!=0)
                                    {
                                        xxx--;
                                        if (continueFlag == 1)
                                        break;
                                    }
                          xxx = 4600;
                          led7(0,brightness);
                                                  led4(1,brightness);
                                                  led1(1,brightness);
                         while(xxx!=0)
                                    {
                                        xxx--;
                                        if (continueFlag == 1)
                                        break;
                                    }
                          xxx = 4600;
                          led7(0,brightness);
                                                  led5(1,brightness);
                                                  led1(1,brightness);
                        while(xxx!=0)
                                   {
                                       xxx--;
                                       if (continueFlag == 1)
                                       break;
                                   }
                         xxx = 4600;
                         led6(0,brightness);
                                                                        led5(1,brightness);
                                                                        led4(1,brightness);
                                                                        led3(1,brightness);
                                                                        led2(1,brightness);
                            while(xxx!=0)
                                       {
                                           xxx--;
                                           if (continueFlag == 1)
                                           break;
                                       }
                         xxx = 7000;
                         ledAllOff(brightness);
                         while(xxx!=0)
                                    {
                                        xxx--;
                                        if (continueFlag == 1)
                                        break;
                                    }
     }
 else  if(*chr == 'a')
    {
        xxx = 76000;
        ledAllOff();
        while(xxx!=0)
       {
           xxx--;
           if (continueFlag == 1)
                              continue;
       }
    }
}


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
static void MX_DAC1_Init(void);
static void MX_SPI2_Init(void);
static void MX_ADC_Init(void);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
                                
                                

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
 {
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_DAC1_Init();
  MX_SPI2_Init();
  MX_ADC_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim1);
  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);
  HAL_DAC_Start(&hdac1,DAC_CHANNEL_1);
  HAL_ADC_Start(&hadc);
  SPI2->CR1 |= SPI_CR1_BIDIOE;
  SPI2->CR2 |= SPI_CR2_SSOE;
  display(line,12);

//  DAC->DHR8R1 = 200;
//  DAC->SWTRIGR |= 0x00000001;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  static int effect = 1;
		  coolEffect2();

          if(charFlag == 1)
          {
        	  effect = 0;
        	  continueFlag = 0;
              if(counter == 0)
               {
                  HAL_SPI_Transmit(&hspi2, &prefix, 1, 100);
                  HAL_SPI_Transmit(&hspi2, &clear, 1, 100);
                  counter = 1;
               }
              inputflag = 1;
              while(inputflag == 1)
              {
                  waitB();
              }
                iii = charArrayIndex(br[0],br[1],br[2],br[3],br[4],br[5]);
                HAL_SPI_Transmit(&hspi2,&allChar[iii],1, 100);
                output = allChar[iii];
                dispIndex++;
                delay(1000000);
                inputflag = 0;
                br[0] = 0;
                br[1] = 0;
                br[2] = 0;
                br[3] = 0;
                br[4] = 0;
                br[5] = 0;
                charFlag = 0;
          }
          else if(numFlag == 1)
          {
        	  effect = 0;
              continueFlag = 0;
              if(counter == 0)
                 {
                    HAL_SPI_Transmit(&hspi2, &prefix, 1, 100);
                    HAL_SPI_Transmit(&hspi2, &clear, 1, 100);
                    counter = 1;
                 }
                inputflag = 1;
                while(inputflag == 1)
                {
                    waitB();
                }
                  iii = numArrayIndex(br);
                  HAL_SPI_Transmit(&hspi2,&allNum[iii],1, 100);
                  output = allNum[iii];
                  dispIndex++;
                  delay(1000000);
                  inputflag = 0;
                  br[0] = 0;
                  br[1] = 0;
                  br[2] = 0;
                  br[3] = 0;
                  br[4] = 0;
                  br[5] = 0;
                  numFlag = 0;
          }
          else if(clearFlag == 1)
          {
        	  effect = 0;
              continueFlag = 0;
              HAL_SPI_Transmit(&hspi2, &prefix, 1, 100);
              HAL_SPI_Transmit(&hspi2, &clear, 1, 100);
              delay(1000000);
              inputflag = 0;
              counter = 0;
              dispIndex = 0;
              br[0] = 0;
              br[1] = 0;
              br[2] = 0;
              br[3] = 0;
              br[4] = 0;
              br[5] = 0;
              display(" RESET COMPLETE!",16);
              int xxx = 10000000;
              while(xxx!=0)
                 {
                     xxx--;
                 }
              HAL_SPI_Transmit(&hspi2, &prefix, 1, 100);
              HAL_SPI_Transmit(&hspi2, &clear, 1, 100);
              delay(1000000);
              display(" READY TO GO! ",14);
              clearFlag= 0;
          }
          if ((dispIndex >=0)&&(dispIndex<=10))
                  {
                  switch(dispIndex)
                  {
                  case 1:output1 = output;break;
                  case 2:output2 = output;break;
                  case 3:output3 = output;break;
                  case 4:output4 = output;break;
                  case 5:output5 = output;break;
                  case 6:output6 = output;break;
                  case 7:output7 = output;break;
                  case 8:output8 = output;break;
                  case 9:output9 = output;break;
                  case 10:output10 = output;break;
                  }
                      if(dispIndex >=1)
                      {
                      charDisp(output1,4096);
                          if(dispIndex >=2)
                          {
                              charDisp(output2,4096);
                              if(dispIndex >=3)
                                 {
                                     charDisp(output3,4096);
                                     if(dispIndex >=4)
                                        {
                                            charDisp(output4,4096);
                                            if(dispIndex >=5)
                                               {
                                                   charDisp(output5,4096);
                                                   if(dispIndex >=6)
                                                      {
                                                          charDisp(output6,4096);
                                                          if(dispIndex >=7)
                                                             {
                                                                 charDisp(output7,4096);
                                                                 if(dispIndex >=8)
                                                                    {
                                                                        charDisp(output8,4096);
                                                                        if(dispIndex >=9)
                                                                           {
                                                                               charDisp(output9,4096);
                                                                               if(dispIndex == 10)
                                                                                  {
                                                                                      charDisp(output10,4096);

                                                                                  }
                                                                           }
                                                                    }
                                                             }
                                                      }
                                               }
                                        }
                                 }
                          }
                      }

                  }
          if(dispIndex <= 10)
                                 {
                                 charDisp(null,4096);
                                     if(dispIndex <=9)
                                     {
                                         charDisp(null,4096);
                                         if(dispIndex <=8)
                                            {
                                             charDisp(null,4096);
                                                if(dispIndex <=7)
                                                   {
                                                    charDisp(null,4096);
                                                       if(dispIndex <=6)
                                                          {
                                                           charDisp(null,4096);
                                                              if(dispIndex <=5)
                                                                 {
                                                                  charDisp(null,4096);
                                                                     if(dispIndex <=4)
                                                                        {
                                                                         charDisp(null,4096);
                                                                            if(dispIndex <=3)
                                                                               {
                                                                                charDisp(null,4096);
                                                                                   if(dispIndex <=2)
                                                                                      {
                                                                                       charDisp(null,4096);
                                                                                          if(dispIndex <=1)
                                                                                             {
                                                                                              charDisp(null,4096);
                                                                                             }
                                                                                      }
                                                                               }
                                                                        }
                                                                 }
                                                          }
                                                   }
                                            }
                                     }
                                 }

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */

}
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI14;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* ADC init function */
static void MX_ADC_Init(void)
{

  ADC_ChannelConfTypeDef sConfig;

    /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
    */
  hadc.Instance = ADC1;
  hadc.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc.Init.Resolution = ADC_RESOLUTION_12B;
  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
  hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc.Init.LowPowerAutoWait = DISABLE;
  hadc.Init.LowPowerAutoPowerOff = DISABLE;
  hadc.Init.ContinuousConvMode = ENABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.DMAContinuousRequests = DISABLE;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure for the selected ADC regular channel to be converted. 
    */
  sConfig.Channel = ADC_CHANNEL_7;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* DAC1 init function */
static void MX_DAC1_Init(void)
{

  DAC_ChannelConfTypeDef sConfig;

    /**DAC Initialization 
    */
  hdac1.Instance = DAC;
  if (HAL_DAC_Init(&hdac1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**DAC channel OUT1 config 
    */
  sConfig.DAC_Trigger = DAC_TRIGGER_SOFTWARE;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_DISABLE;
  if (HAL_DAC_ConfigChannel(&hdac1, &sConfig, DAC_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* SPI2 init function */
static void MX_SPI2_Init(void)
{

  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 7;
  hspi2.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi2.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM1 init function */
static void MX_TIM1_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 47999;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 1;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM2 init function */
static void MX_TIM2_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_CENTERALIGNED1;
  htim2.Init.Period = 4096;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  HAL_TIM_MspPostInit(&htim2);

}

/* TIM3 init function */
static void MX_TIM3_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_CENTERALIGNED1;
  htim3.Init.Period = 4096;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  HAL_TIM_MspPostInit(&htim3);

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |LD4_Pin|LD3_Pin|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pins : PF0 PF1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PC0 PC1 PC2 PC3 
                           LD4_Pin LD3_Pin PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |LD4_Pin|LD3_Pin|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PD2 */
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PB3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB4 PB5 PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
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
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
