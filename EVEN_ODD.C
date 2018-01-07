#include<lpc214x.h>

void delay(int count)
{
 
 int i,j;
 for(i=0;i<1000;i++)
 for(j=0;j<count;j++);

}

int main()
{
int i;	for(i=0;i<32;i++)
	{
		IODIR0|= 1<<i;

	}		

	while(1)
	{
		
		
	 IOSET0 = 0XAAAAAAAA;
	 delay(1000);
	 IOCLR0 = 0XAAAAAAAA;
	 delay(100);
	 IOSET0 = 0x55555555;
	 delay(1000);		
	 IOCLR0 = 0x55555555;
	 delay(100);

			


	 }
	//}	
//	while(1)
// 	if(
}


