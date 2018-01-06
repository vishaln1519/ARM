#include <lpc214x.h>

void delay(int count)
{
	int i,j;
	for(i=0;i<10000;i++)
	for(j=0;j<count;j++);	
}

void timer_isr(void)__irq;
int main()
{
 IODIR0=1<<25;
 T0CTCR=0x00;
 T0TCR=1<<1|1<<0;
 T0TCR=1<<0;
 
 T0PR=14;
 T0MR0=1000000;
 
 T0MCR=1<<0|1<<1;

 VICIntEnable=1<<4;
 VICIntSelect=0<<4;
 VICVectAddr0=(long)timer_isr;
 VICVectCntl0=1<<5|4;

 while(1); 

}
void timer_isr(void)__irq
{
	IOSET0=1<<25;
	delay(10);
	IOCLR0=1<<25;
	delay(10);
	
	T0IR=1<<0;
	VICVectAddr=0; 
	

}
