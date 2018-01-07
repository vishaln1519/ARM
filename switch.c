#include <lpc214x.h>

void delay(int count)
{
 
 int i,j;
 for(i=0;i<1000;i++)
 for(j=0;j<count;j++);

}

int main()
{
		IODIR0= 1<<25;// to make p.25 output;
		IODIR1= 0<<16;

		while(1)
		{
			if(IOPIN1 & 1<<16)
			{
				IOSET0 = 0X02000000;
				//delay(1000);
				
			}
			else
			{
			    IOCLR0 = 0x02000000;
				//delay(1000);
			} 




		}

		



}