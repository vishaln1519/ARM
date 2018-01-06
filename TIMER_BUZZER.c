#include <lpc214x.h>

void delay(int count)
{
	int i,j;
	for(i=0;i<10000;i++)
	for(j=0;j<count;j++);	
}

int main()
{
 IODIR0=1<<25;
 T0CTCR=0x00;
 T0TCR=1<<1|1<<0;
 T0TCR=1<<0;
 
 T0PR=14;
 T0MR0=1000000;
 
 T0MCR=1<<0|1<<1;
	while(1)
	{
	 if(T0IR &1<<0)
 		{
  			IOSET0=1<<25;
			delay(1000);
			IOCLR0=1<<25;
		   	delay(1000);
			T0IR=1<<0;
 		}

	}

}


  
 	













