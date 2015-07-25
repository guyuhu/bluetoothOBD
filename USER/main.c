/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 串口一用来和pc进行交流，当发送是A，则收到
 *
**********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"
#include "usart2.h"
#include "usart3.h"
#include "timer2.h"

int time;
int timeFlag;

#define START_TIME  time=0;RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);TIM_Cmd(TIM2, ENABLE)

/* 
 * 函数名：main
 * 描述  : 主函数
 * 输入  ：无
 * 输出  : 无
 */
int main(void)
{
  // u16 receiveData ;
   
   TIM2_NVIC_Configuration();
   TIM2_Configuration(); 
   
   USART1_Config();
   NVIC_Configuration();
   USART2_Config();
   USART3_Config();
  
   START_TIME;
   
   while(1)
   {
      if(timeFlag==1)
      {
         USART1_printf(USART1, "AirBagState\n");      
      }
//       else
//       { 
//          receiveData= USART_ReceiveData(USART1);
//           if(receiveData==0x31)
//          {
//             USART2_printf(USART2,"1");
//          }
//          else
//          {
//             USART2_printf(USART2,"0");
//          }
//       }    
   }
}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/


