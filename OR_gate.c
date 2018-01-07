#include<lpc214x.h>

#define SW1 0<<17
#define SW2 0<<18

#define LED1 1<<4
#define LED2 1<<5

int main()
{
 	IODIR1 = SW1;
	IODIR1 = SW2;

	IODIR0 = LED1;
	IODIR0 = LED2;

	if ((IOPIN1 & 1<<17)   || (IOPIN1 & 1<<18))
	{
		if(IOPIN1 & 1<<17)
		IOSET0 = LED1;
		else
		IOSET0 = LED2;
	 }
	 else if(((IOPIN1 & 1<<17 )==0) && ((IOPIN1 & 1<<18 )==0))
	 {
	 	IOCLR0 = LED1;
		IOCLR0 =  LED2;	
	 }
	 else
	 {
	 	IOSET0 = LED1;
		IOSET0  = LED2;
		 
	  }


}

