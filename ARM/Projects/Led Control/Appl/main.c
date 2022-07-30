#include "IntCtrl.h"
#include "Port.h"
#include "DIO.h"
#include "GPT.h"


#define HIGH_TIME 	(2U)
#define LOW_TIME 	(1U)


void Blink_LED(void);


int main() {
  
  IntCrtl_Init();
	Port_Init();
	GPT_Init();
  GPT_EnableNotification(GPT_TIMER1_WIDE);
  Blink_LED();

  while (1) {
    
  }
}


void Blink_LED(void)
{
		static uint8 LED_status = 1;
	
		if(1 == LED_status ){
				LED_status = 0;
				Dio_WriteChannel(DIO_CHANNEL_F2,DIO_HIGH);
				GPT_StartTimer(GPT_TIMER1_WIDE, HIGH_TIME * 1000000);
		}
		else{
			LED_status = 0;
			Dio_WriteChannel(DIO_CHANNEL_F2,DIO_LOW);
			GPT_StartTimer(GPT_TIMER1_WIDE, LOW_TIME * 1000000);
		}
		
}

void notify(void)
{
		Blink_LED();
}
