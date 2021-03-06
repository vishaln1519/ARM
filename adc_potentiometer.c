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
	 //	int sec;
 	// int sec; int min=0;
	int a;
	IODIR0 = EN|RS|RW|DATA1;
	PINSEL1=0<<27|1<<26; 

	cmd(0x38);
	cmd(0x0E);
	cmd(0x01);
	cmd(0x80);

	AD0CR=1<<2|4<<8|1<<16|1<<21;
	while(1)
	{
		cmd(0x01);
		while(!(AD0DR2 & 1<<31));

		a=((AD0DR2>>6)&(0X3FF));

		display(a);	
	}
// OR WE CAN READ FROM GLOBAL DATA REGISTER TO READ THE OUTPUT
//	while(1)
//	{
//		cmd(0x01);
//		while(!(AD0GDR & 1<<31));
//
//		a=((AD0GDR>>6)&(0X3FF));
//
//		display(a);// to get our code configured to room temperature	
//	}

}

void display(int n)
{

	if(n)
		display(n/10);

	data((n%10)+0x30);

 
}
	 