#include<lpc214x.h>

void delay(int);
void down(int);
void delay(int count)
{
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<count;j++);	
}

void up(int store)
{

	int i;
	for(i=store;i<16;i++)
		{
			if(!(IOPIN0 & 1<<16))
			down(i);
			IOSET0=i<<4;
			delay(1000);
			IOCLR0=i<<4;
			//delay(1000);
						 	
		}
}

void down(int store) 
{
		int i;
		for(i=store;i>=0;i--)
		{
			IOSET0=i<<4;
			delay(1000);
			IOCLR0=i<<4;
			if(IOPIN0 & 1<<16)
			up(i);
			//delay(1000);
		}
	}
	
int main()
{
	int store=0;
	
	IODIR0=1<<4|1<<5|1<<6|1<<7;
	
	while(1)
	{
		if(IOPIN0 & 1<<16)
		{
			
	
			up(store);
		
		}
		else
		{
			
			down(store);
			
		}
	}
}


