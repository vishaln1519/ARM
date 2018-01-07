#include <lpc214x.h>
void delay(int count )
{
	int i,j;
	for(i=0;i<count;i++)
		for(j = 0;j < 10000;j++);


}
int main()
{
	IODIR0=1<<25;
	IOCLR0=1<<25;
	delay(100);

	WDMOD=0x03;
	WDTC=0xffff;
	WDFEED=0xAA;
	WDFEED=0X55;
	while(1)  //GOES TO INFINTE LOOP AND WATCHDOG RESETS IT AND MAKES BUZZER OFF
	{
		IOSET0=1<<25;
//		if(WDTV==0X7FF)
//		{
//		WDTC=0xfffF;// CHANGING VALUE BEFORE IT CAN REACH NULL SO UR WATCHDOG WILL NEVER RESET
//		WDFEED=0xAA;
//		WDFEED=0X55;
//		// TO AVOID UR WATCHDOG TIMMER OT TO REACH ZERO AT ALL	
//		}
	}

}
