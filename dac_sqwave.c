	#include <lpc214x.h>
	void delay(int count )
{
	int i,j;
	for(i=0;i<count;i++)
		for(j = 0;j < 10000;j++);


}

	int main()
	{
	 while(1)
	 {
	 	DACR=1023;
		delay(10);
		DACR=0;
		delay(10);
	 }	


	}