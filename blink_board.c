#include<lpc214x.h>

void delay(int);

void delay( int count)
{
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<count;j++);	
}

int main()
{
	IODIR0 = 1<<10;

	while(1)
	{
		IOSET0 = 1<<10;
		delay(5000);
		IOCLR0 = 1<<10;
		delay(5000);


	}

 }
