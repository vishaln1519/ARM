#include <lpc214x.h>

void EXT_ISR(void)__irq;
void delay(int count);

void delay(int count)
{
 
 int i,j;
 for(i=0;i<1000
 
 ;i++)
 for(j=0;j<count;j++);

}



void EXT_ISR()__irq//irq is to function qualifier for the arm to detect that its an ISR
{ 
	IOSET0=1<<25;
	delay(10000);
	IOCLR0=1<<25;
	delay(10000);

	EXTINT=1<<1;
	VICVectAddr=0;


}


int main()
{

	IODIR0=1<<25;
	PINSEL0=1<<29|0<<28;
	VICIntEnable=1<<15;
	VICIntSelect=0<<15;//IRQ

/********* NON VECTORED ****************/
	VICDefVectAddr=(long)EXT_ISR;  // NO PRIORITY ALL THE ISR's ARE RUN SEQUENTIALLY

/********************************************************/

/*	VECTORED INTERUPPT*/
	//VICVectAddr0=(long)EXT_ISR;  //THIS HAS PRIORITY

	//VICVectCntl0=1<<5|15;
/**********************************************************/
	EXTINT=1<<1;

	EXTMODE=1<<1;//edge trigerring 
	EXTPOLAR=1<<1;//active high

//	 EXTMODE=1<<1;//edge trigerring 
//	EXTPOLAR=0<<1;//active low

	//EXTMODE=0<<1;//level trigerring 
	//EXTPOLAR=1<<1;//active high

	//EXTMODE=0<<1;//level trigerring 
	//EXTPOLAR=0<<1;//active low
		while(1);


}
