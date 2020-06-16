#include "lpc17xx_gpio.h"
#include "lpc17xx_pinsel.h"
#include "KBD.h"

const uint8_t segmentTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


void Delay()
{
   for(uint16_t count=0;count<UINT16_MAX-100;count++);
	    
}
uint8_t read_key(void);
int main(void)
{
	GPIO_SetDir(0,0x3F8000,1);
	GPIO_SetDir(1,(1<<16 | 1<<17 | 1<<18 | 1<<19 ),1);
	
	while(1){
		GPIO_ClearValue(1,1<<19);
		GPIO_SetValue(1,1<<16);
		GPIO_SetValue(0,~segmentTable[read_key()]<<15);
		GPIO_ClearValue(0,segmentTable[read_key()]<<15);
		Delay();
	}
 }

 uint8_t read_key(void){
	 uint8_t read;
// uint8_t man=0;
	 uint8_t row=3;
	 uint8_t column=3;
	 uint8_t true_kry=0;
	 uint8_t shift=0;
	 FIO_ByteSetDir(KBD_Port ,KBD_PIN_Part,0x0f,1);
	 FIO_ByteSetDir(KBD_Port ,KBD_PIN_Part,0xf0,0);
	 FIO_ByteSetValue(KBD_Port ,KBD_PIN_Part,0xf0);
	 FIO_ByteClearValue(KBD_Port ,KBD_PIN_Part,0x0f);
	 read=FIO_ByteReadValue(KBD_Port ,KBD_PIN_Part);
	 
	 if((read & 0x0f) !=0x0f){
		 for(uint8_t count=0;count<10;count++)    // check if key pressed true
		 {
			 if((FIO_ByteReadValue(KBD_Port ,KBD_PIN_Part) & 0xf0) !=0xf0)
				 true_kry++;
			 Delay();
		 }
		 
		 if(true_kry==10)  // key is preesed truely
		 {
			 read=FIO_ByteReadValue(KBD_Port ,KBD_PIN_Part);
			 for(uint8_t count_row=0;count_row<4;count_row++)
			 {
	
				if(((read>>4) & 0x01)==0) 
					 break;
				read>>=1;
				row--;
			 }
			 read=FIO_ByteReadValue(KBD_Port ,KBD_PIN_Part);
			  for(uint8_t count_colm=0;count_colm<4;count_colm++)
			 {
				 FIO_ByteSetValue(KBD_Port ,KBD_PIN_Part,(0x01<<shift));
			
				 if((FIO_ByteReadValue(KBD_Port ,KBD_PIN_Part) & 0xf0) ==0xf0)
					 break;
				shift++;
				column--;
			 }
			 
		 }
		 
		 return (3*row)+(column)+1;
		 
	 }
	 
	 return 0;
	 
	 
 }
