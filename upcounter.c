#include<lpc214x.h>

void delay(int);

void delay(int count)
{
	int i,j;
	for(i=0;i<9000000*900000;i++)
	for(j=0;j<count;j++);	
}

int main()
{
	int i;
	IODIR0=1<<4|1<<5|1<<6|1<<7;
	while(1)
	{
		for(i=0;i<16;i++)
		{
			IOSET0=i<<4;
			delay(100000000);
			IOCLR0=i<<4;
			delay(100000000);
		}
		for(i=15;i>=0;i--)
		{
			IOSET0=i<<4;
			delay(10000000);
			IOCLR0=i<<4;
			delay(10000000);
		}
	}
}
