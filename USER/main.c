/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * ����һ������pc���н�������������A�����յ�
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
 * ��������main
 * ����  : ������
 * ����  ����
 * ���  : ��
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


