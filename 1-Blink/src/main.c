#include "lpc17xx_gpio.h"

void Delay()
{
   for(uint16_t count=0;count<UINT16_MAX;count++)
	    for(uint8_t count2=0;count2<150;count2++);
	     
				 
			 
}

int main()
{	
	
	// test p1.22 on camera Header (header number:19)
	// and tested with port1 header (header number:36) 
	
	GPIO_SetDir(1,(1<<22),1);  
  

while(1)
{	
	GPIO_SetValue(1,(1<<22));  //p1.22 led is  blinking
	Delay();
	GPIO_ClearValue(1,(1<<22));  
	Delay();
}
	
}

	

