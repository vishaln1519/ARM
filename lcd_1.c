#include<LPC214X.H>


	#define EN (1 << 10)
	#define RW  (1 << 12)
	#define RS  (1 << 13)
	#define BUZZ (1 << 25)
	#define DATA  (0Xff << 15)
	#define led (1<<4)
	#define port  EN | RW | RS | DATA | BUZZ |led

   	void cmd(int c);
	void delay(int count);
	void data(char d);


	void cmd(int c)
	{
	IOPIN0 = c << 15;
	IOCLR0 = RW;
	IOCLR0 = RS;
	IOSET0 = EN;
	delay(25);
	IOCLR0 = EN;
	
	}
	void data(char d)
	{
	  IOPIN0 = d << 15;
	IOCLR0 = RW;
	IOSET0 = RS;
	IOSET0 = EN;
	delay(25); 
	IOCLR0 = EN;
	} 
	void delay(int count)
	{
	int i,j;
	for(i = 0;i < count;i++)
	for(j = 0;j < 5000;j++);
	} 
	
	int main()
	{
	 IODIR0 |= port;
	 IOSET0= BUZZ|led;
	 
	 delay(5);
	// IOCLR0|=BUZZ;
	// delay(5);
	
	

	cmd(0x38);
	cmd(0x0E);
	cmd(0x01);
	cmd(0x83);
		data ('N');
		data (0x43);
	data (67);

	
	}


