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
	
	GPIO_SetDir(1,(1<<22),1);  // 23 for p1.23 works and led is blinking , 21 for p1.21 works and led is blinking ,BUT for 22 led is just on and ISNOT blinking
  

while(1)
{	
	GPIO_SetValue(1,(1<<22));  // 23 for p1.23 works and led is blinking , 21 for p1.21 works and led is blinking ,BUT for 22 led is just on and ISNOT blinking
	Delay();
	GPIO_ClearValue(1,(1<<22));	  // 23 for p1.23 works and led is blinking , 21 for p1.21 works and led is blinking ,BUT for 22 led is just on and ISNOT blinking
	Delay();
}
	
}

	

