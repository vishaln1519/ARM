	#include <lpc214x.h>
	#include <math.h>
	#define pi 3.141
	void delay(int count )
{
	int i,j;
	for(i=0;i<count;i++)
		for(j = 0;j < 10000;j++);


}

	int main()
	{ int i;float res;float out;
	 while(1)
	 {
	 	for(i=0;i<360;i+=1)
		{
			res=sin(i*(pi/180));
			out=(5+(5*res))*102.3;
			DACR = out;
		}
	 }	


	}