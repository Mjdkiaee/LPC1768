#include "lpc17xx_gpio.h"
#include "lpc17xx_pinsel.h"

const uint8_t segmentTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


void Delay()
{
   for(uint16_t count=0;count<UINT16_MAX-100;count++);
	    
}

int main(void)
{
	GPIO_SetDir(0,0x3F8000,1);
	GPIO_SetDir(1,(1<<16 | 1<<17 | 1<<18 | 1<<19 ),1);
	while(1){
		GPIO_ClearValue(1,1<<19);
		GPIO_SetValue(1,1<<16);
		GPIO_SetValue(0,~segmentTable[1]<<15);
		GPIO_ClearValue(0,segmentTable[1]<<15);
		Delay();
		GPIO_ClearValue(1,1<<16);
		GPIO_SetValue(1,1<<17);
		GPIO_SetValue(0,~segmentTable[3]<<15);
		GPIO_ClearValue(0,segmentTable[3]<<15);
		Delay();
		GPIO_ClearValue(1,1<<17);
		GPIO_SetValue(1,1<<18);
		GPIO_SetValue(0,~segmentTable[9]<<15);
		GPIO_ClearValue(0,segmentTable[9]<<15);
		Delay();
		GPIO_ClearValue(1,1<<18);
		GPIO_SetValue(1,1<<19);
		GPIO_SetValue(0,~segmentTable[9]<<15);
		GPIO_ClearValue(0,segmentTable[9]<<15);
		Delay();
	}
 }
