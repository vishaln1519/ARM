#include <lpc214x.h>
#define EN (1<<10)  
#define RS	(1<<13)
#define RW	(1<<12)
#define DATA1 (0xff<<15)
int sec,min,hr;
	 
void cmd(int a);
void delay(int count);
void data(char ch);
void display(int n);
void ext_isr(void)__irq;
void temp_dis();




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
 	IODIR0 = EN|RS|RW|DATA1|1<<25;
	PINSEL0=1<<29|0<<28;
	PINSEL1=1<<28|0<<29;
	 // to change the functionality of isp pin	 (FOR EXTERNAL INTERUPT)
	cmd(0x38);
	cmd(0x0E);
	cmd(0x01);
	cmd(0x80);

	  	

	

	VICIntEnable=1<<15;
	VICIntSelect=0<<15;
	VICVectAddr0=(long)ext_isr;
	 VICVectCntl0=1<<5|15;	//1<<5 to enable the slot(slotenable)

	 EXTINT=1<<1;
  EXTMODE=1<<1;//edge trigerring 
  EXTPOLAR=1<<1;//active high
	 while(1);
}
void ext_isr(void)__irq
{
	IOSET0=1<<25;
	delay(100);
	IOCLR0=1<<25;
	delay(100);
		temp_dis();
	 
	EXTINT=1<<1;
	VICVectAddr=0;
 

}
void display(int n)
{

		if(n)
		display(n/10);
	data((n%10)+0x30);

}

void temp_dis()
{
	int a;
	
	AD0CR=1<<3|4<<8|1<<16|1<<21;
	cmd(0x01);
		while(!(AD0DR3 & 1<<31));

		a=((AD0DR3>>6)&(0X3FF));

		display(a/3);// to get our code configured to ROOM TEMPERATURE	
		return;	
}