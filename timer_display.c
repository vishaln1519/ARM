#include <lpc214x.h>
#define EN (1<<10)  
#define RS	(1<<13)
#define RW	(1<<12)
#define DATA1 (0xff<<15)
	 
void cmd(int a);
void delay(int count);
void data(char ch);
void display(int n);

	int sec,min,hr;

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
	IODIR0 = EN|RS|RW|DATA1;

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
	while(1)
	{
	   
	 	if(T0IR &1<<0)

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
		}				
 	}	

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
