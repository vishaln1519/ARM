#include <lpc214x.h>

int main()
{
	PINSEL0=1<<8|1<<12;
	IODIR0=1<<7;

	S0SPCR=1<<2|1<<5;
	S0SPCCR=8;

	IOCLR0=1<<7;
	S0SPDR=0X0C01;
	while(!(S0SPSR & 1<<7));
	IOSET0=1<<7;

	IOCLR0=1<<7;
	S0SPDR=0X090F;
	while(!(S0SPSR & 1<<7));
	IOSET0=1<<7;

	

	IOCLR0=1<<7;
	S0SPDR=0X0B03;
	while(!(S0SPSR & 1<<7));
	IOSET0=1<<7;

	IOCLR0=1<<7;
	S0SPDR=0X0A0F;
	while(!(S0SPSR & 1<<7));
	IOSET0=1<<7;

	

	IOCLR0=1<<7;
	S0SPDR=0X0100;
	while(!(S0SPSR & 1<<7));
	IOSET0=1<<7;

	IOCLR0=1<<7;
	S0SPDR=0X020C;
	while(!(S0SPSR & 1<<7));
	IOSET0=1<<7;

	IOCLR0=1<<7;
	S0SPDR=0X0301;
	while(!(S0SPSR & 1<<7));
	IOSET0=1<<7;

	IOCLR0=1<<7;
	S0SPDR=0X0402;
	while(!(S0SPSR & 1<<7));
	IOSET0=1<<7;



}