#include <lpc214x.h>

void delay(int count )
{
	int i,j;
	for(i=0;i<count;i++)
		for(j = 0;j < 10000;j++);


}

int main()
{
	PINSEL0=1<<15|0<<14;
	PWMMR0=4000000;
	PWMLER=1<<1;

	PWMMCR=1<<1;

	PWMPCR=1<<10;

	PWMPR=14;

	PWMTCR=1<<0|1<<3;

	while(1)
	{
		PWMMR2=2000000;
		PWMLER=1<<2;
		delay(100);

//		PWMMR2=1000;
//		PWMLER=1<<2;
//		delay(100);
	}
}








