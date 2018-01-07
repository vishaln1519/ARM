#include<lpc214x.h>

void delay(int);

void delay(int count)
{
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<count;j++);	
}

void up()
{
	int i;
	for(i=0;i<16;i++)
		{
			IOSET0=i<<4;
			delay(1000);
			IOCLR0=i<<4;
			delay(1000);
		}
}

void down() 
{
		int i;
		for(i=15;i>=0;i--)
		{
			IOSET0=i<<4;
			delay(1000);
			IOCLR0=i<<4;
			delay(1000);
		}
	}
	
int main()
{
	IODIR0=1<<4|1<<5|1<<6|1<<7;
	while(1)
	{
		up();
		down();
	}
}

