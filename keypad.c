#include <lpc214x.h>

#define row (1<<17|1<<18|1<<19|1<<20)
#define col (1<<21|1<<22|1<<23|1<<24)


#define EN (1<<10)  
#define RS	(1<<13)
#define RW	(1<<12)
#define DATA (0xff<<15)
#define DELAY_TIME 100

void cmd(int a);
void delay(int count);
void data(char ch);
void row1(void);
void row2(void);
void row3(void);
void row4(void);

int main()
{
	int a;
		IODIR0 = EN|RS|RW|DATA;

	cmd(0x38);
	cmd(0x0E);
	cmd(0x01);
	cmd(0x80);	
	
	


	while(1)
	{
	   		IODIR1 = row;
			IOCLR1 = row;
			a = (IOPIN1 & col);// a= 0x1e00000
		if(a!=0x1e00000)
		{
			
			if(a==0x1c00000)
			{
				row1();
						
			}
			if(a==0x1a00000)
			{
				row2();
				
			}
			if(a==0x1600000)
			{
				row3();
				
			}
			if(a==0x0e00000)
			{
				row4();
			
			}
		}
	}


}

void row1()
{
	int c;
	IODIR1 = col;
	IOCLR1 = col; 
	
	c=(IOPIN1 & row);
		if(c!=0x1e0000)
		{
		
		if(c==0x1c0000)
			{
				data('a');
				delay(DELAY_TIME);
				
			}
			if(c==0x1a0000)
			{
				data('b');
				delay(DELAY_TIME);
			
			}
			if(c==0x160000)
			{
				data('c');
				delay(DELAY_TIME);
			
			}
			if(c==0x0e0000)
			{
				data('d');
				delay(DELAY_TIME);
		
			}

		}	
}




void row2()
{	 
	int c;

	IODIR1 = col;
	IOCLR1 = col;  
	

		c=(IOPIN1 & row);
		if(c!=0x1e0000)
		{
			if(c==0x1c0000)
			{
				data('e');
				delay(DELAY_TIME);
					
			}
			if(c==0x1a0000)
			{
				data('f');
				delay(DELAY_TIME);
		
			}
			if(c==0x160000)
			{
				data('g');
				delay(DELAY_TIME);
		
			}
			if(c==0x0e0000)
			{
				data('h');
				delay(DELAY_TIME);
		
			} 


		}
}



void row3()
{
	int c;
	IODIR1 = col;
	IOCLR1 = col;	
	
	
		c=(IOPIN1 & row);	

		if(c!=0x1e0000)
		{
			if(c==0x1c0000)
			{
				data('i');
				delay(DELAY_TIME);
				
			}
			if(c==0x1a0000)
			{
				data('j');
				delay(DELAY_TIME);
			
			}
			if(c==0x160000)
			{
				data('k');
				delay(DELAY_TIME);
			
			}
			if(c==0x0e0000)
			{
				data('l');
				delay(DELAY_TIME);
			
			}  
		}
}



void row4()
{
	int c;
	IODIR1 = col;
	IOCLR1 = col;
	

	

		c=(IOPIN1 & row);
		if(c!=0x1e0000)
		{
		
			if(c==0x1c0000)
			{
				data('m');
				delay(DELAY_TIME);
				
			}
			if(c==0x1a0000)
			{
				data('n');
				delay(DELAY_TIME);
			
			}
			if(c==0x160000)
			{
				data('o');
				delay(DELAY_TIME);
		
			}
			if(c==0x0e0000)
			{
				data('p');
				delay(DELAY_TIME);
			
			}

		}
}





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