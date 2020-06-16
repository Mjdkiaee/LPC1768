#include "lpc17xx_gpio.h"

const uint8_t segmentTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


void Delay()
{
   for(uint16_t count=0;count<UINT16_MAX-100;count++);
	    
}

void DelayLow()
{
   for(uint16_t count=0;count<UINT16_MAX-100;count++);
	    
}


int main(){
	uint8_t pushCount=0;
	
	uint8_t read_key=0;
	GPIO_SetDir(0,0x3F8000,1);
	GPIO_SetDir(1,(1<<16 | 1<<17 | 1<<18 | 1<<19 ),1);
	GPIO_SetValue(1,1<<16);
	GPIO_SetDir(2,1<<11,0);
	
	
	while(1){
		
		
		read_key=GPIO_ReadValue(2);
		if(((read_key>>11) & 0x01) ==0){
			uint8_t countTrue=0;
			for(uint8_t count=0;count<10;count++){
					if(((GPIO_ReadValue(2)>>11)&0x01)==0){
						countTrue++;
						DelayLow();
					}
			}
		
			if(countTrue==10)
			{
				 pushCount++;
			
				 if(pushCount==10)
						pushCount=0;
			
				GPIO_SetValue(0, ~segmentTable[pushCount]<<15);
				GPIO_ClearValue(0,segmentTable[pushCount]<<15);
				
				while(((GPIO_ReadValue(2)>>11)&0x01)==0);
			}
		
	   }
	}
	
}
