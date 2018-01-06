#include <lpc214x.h>

void delay(int count)
{
	int i,j;
	for(i=0;i<10000;i++)
	for(j=0;j<count;j++);	
}

int main()
{
 IODIR0=1<<25;
 IODIR0|=1<<4;// ORING FOR IODIR0 MUST

 // OR THIS WAY ( IODIR0=1<<25|1<<4;  )
 T0CTCR=0x00;
 T0TCR=1<<1|1<<0;//RESET AND SET
 T0TCR=1<<0;					//ENABLE
 
 T0PR=14;
 T0MR0=1000000;
 T0MR1=2000000;
 T0MR2=3000000;
 T0MR3=4000000;

 
 T0MCR=1<<0|1<<3|1<<6|1<<9|1<<10;
 

	while(1)
	{
	 if(T0IR&1<<0)	 // mr0
 		{
  			IOSET0=1<<25;
			delay(1000);
		
			T0IR=1<<0;
 		}
	  if( T0IR&1<<1)   //mr1
	  {
	  		IOCLR0=1<<25;
		   	delay(1000);
			T0IR=1<<1;//CLEAR  MR1 	
	  }

	  if(T0IR&1<<2)		  //mr2
 		{
  			IOSET0=1<<4;
			delay(100);
			T0IR=1<<2;
 		}

	   if(T0IR&1<<3)// mr3
 		{
  			IOCLR0=1<<4;
			delay(1000);   		
			T0IR=1<<3;
 		}
	  
	  	

	}

}


  
 	













