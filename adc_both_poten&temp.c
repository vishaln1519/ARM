#include <lpc214x.h>
#define EN (1<<10)  
#define RS	(1<<13)
#define RW	(1<<12)
#define DATA1 (0xff<<15)

void cmd(int a);
void delay(int count);
void data(char ch);
void display(int n);

void cmd(int a)
{
	IOPIN0 = a<<15;
	IOCLR0 = RS;
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(10);
	IOCLR0 = EN;

}
void data(char ch)
{
	IOPIN0 = ch<<15;
	IOSET0 = RS;
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(10);
	IOCLR0 = EN;

}

void delay(int count )
{
	int i,j;
	for(i=0;i<count;i++)
		for(j = 0;j < 10000;j++);


}
int main()
{
	
	int a; int ch;
	IODIR0 = EN|RS|RW|DATA1;
	PINSEL1=0<<27|1<<26|1<<28|0<<29;

	cmd(0x38);
	cmd(0x0E);
	cmd(0x01);
	cmd(0x80);

	AD0CR=1<<2|1<<3|4<<8|1<<16|1<<21;
	while(1)
	{
	
		ch = (AD0GDR>>24 & 0X07);
		if(ch == 2)
		{
			cmd(0x01);
		while(!(AD0DR2 & 1<<31));

		a=((AD0DR2>>6)&(0X3FF));

		display(a);
		delay(500);
		}

		if(ch == 3)
		{
			cmd(0x01);
		while(!(AD0DR3 & 1<<31));

		a=((AD0DR3>>6)&(0X3FF));

		display(a/3);
		delay(500);

		}
		
			
	}

}

void display(int n)
{

	if(n)
		display(n/10);

	data((n%10)+0x30);

 
}
	 