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
	IODIR0 = EN|RS|RW|DATA1|1<<25;
	PINSEL1=1<<28|0<<29; 

	cmd(0x38);
	cmd(0x0E);
	cmd(0x01);
	cmd(0x80);

	AD0CR=1<<3|4<<8|1<<16|1<<21;
	while(1)
	{
		cmd(0x01);
		while(!(AD0DR3 & 1<<31));

		a=((AD0DR3>>6)&(0X3FF));
		a=a/3;
		if(a>34){
			IOSET0=1<<25;
			delay(100);
			IOCLR0=1<<25;
			delay(100);}

		// to get our code configured to ROOM TEMPERATURE	
	}
 // OR WE CAN READ FROM GLOBAL DATA REGISTER TO READ THE OUTPUT
//	while(1)
//	{
//		cmd(0x01);
//		while(!(AD0GDR & 1<<31));
//
//		a=((AD0GDR>>6)&(0X3FF));
//
//		display(a/3);// to get our code configured to room temperature	
//	}


}

void display(int n)
{

	if(n)
		display(n/10);

	data((n%10)+0x30);

 
}
	 