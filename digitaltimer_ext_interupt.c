// RESETTING THE DIGITAL TIMER FOR EXTERNAL INTERUPT
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
void timer_isr(void)__irq ;



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


void timer_isr(void)__irq;
int main()
{
 	IODIR0 = EN|RS|RW|DATA1;
	PINSEL0=1<<29|0<<28; // to change the functionality of isp pin	 (FOR EXTERNAL INTERUPT)
	cmd(0x38);
	cmd(0x0E);
	cmd(0x01);
	cmd(0x80);

 T0CTCR=0x00;
 T0TCR=1<<1|1<<0;
 T0TCR=1<<0;
 
 T0PR=14;
 T0MR0=1000000;
 
 T0MCR=1<<0|1<<1;

 VICIntEnable=1<<4|1<<15;  //enabling for ext(15) anf timer(4)
 VICIntSelect=0<<4|0<<15;  // MAKING BOTH ID OF EXT AND TIMER AS IRQ

 VICVectAddr0=(long)ext_isr;//GIVING FIRST PRIORITY FOR EXTERNAL INTERUPT
 VICVectCntl0=1<<5|15;
  // WHENEVER THE ISP IS PRESSED THE CONTROL GOES THERE

  EXTINT=1<<1;
  EXTMODE=1<<1;//edge trigerring 
  EXTPOLAR=1<<1;//active high

 VICVectAddr1=(long)timer_isr;// GIVING  SECOND PRIORITY FOR TIMER
 VICVectCntl1=1<<5|4;
  // WHENEVER MATCHING OCCURS THE CONTROL WILL GO TO timer_isr	it checks internally for TOIR


 while(1); 

}
void timer_isr(void)__irq
{
			sec++;
			display(sec);
		
		 
			if(sec>59)
			{
				min++;
				sec=0;
				display(min);
			}
			if(min>59)
			{
				min=0 ;
				hr++;
				sec=0;
				display(hr);
			}
	
	T0IR=1<<0;
	VICVectAddr=0; 
	

}

void ext_isr(void)__irq
{
	sec=0;
	hr=0;
	min=0;
	EXTINT=1<<1;
	VICVectAddr=0;

}

void display(int n)
{

 int s1,s2,m1,m2,h1,h2;
 
 s1=sec/10;
 s2=sec%10;
 cmd(0x80);
 data(s1+0x30);
 data(s2+0x30);

 data(':');
 cmd(0x83);
 m1=min/10;
 m2=min%10;
 data(m1+0x30);
 data(m2+0x30);

 data(':');
 cmd(0x86);
 h1=hr/10;
 h2=hr%10;
 data(h1+0x30);
 data(h2+0x30);



}