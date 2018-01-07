#include <lpc214x.h>
#define EN (1<<10)  
#define RS	(1<<13)
#define RW	(1<<12)
#define DATA (0xff<<15)
	 
void cmd(int a);
void delay(int count);
void data(char ch);

int main()
{	char str[]="vishal hii hello namaskara  pavan,shivagaru blah blah blah"; int i;

	IODIR0 = EN|RS|RW|DATA;

		cmd(0x38);
	cmd(0x0E);
	cmd(0x01);
	cmd(0x80);

	
	
	for(i=0;str[i]!='\0';i++)
	{
		
		data(str[i]);
		
		if(i>15)
			cmd(0x18);
	}
	



}

void cmd(int a)
{
	IOPIN0 = a<<15;
	IOCLR0 = RS;
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(100);
	IOCLR0 = EN;

}
void data(char ch)
{
	IOPIN0 = ch<<15;
	IOSET0 = RS;
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(100);
	IOCLR0 = EN;

}

void delay(int count )
{
	int i,j;
	for(i=0;i<count;i++)
		for(j = 0;j < 10000;j++);


}
