#include<pic.h>
#include"LCD 4 BIT.h"
#include<htc.h>

unsigned char SPI_Receive_Data()
{
	while(!SSPIF);
	return SSPBUF;
}

void main()
{
	TRISD=0X00;
	PORTD=0X00;
	TRISC=0X18;//	TRISC3=1;	TRISC4=1;	TRISC5=0;
	PORTC=0X00;

	Lcd_Intialization();
	
	SSPSTAT=0X00;
	SSPCON=0X25;

	Lcd_Command(0x80);
	Lcd_String("LYCA SOFT");

	Lcd_Command(0xC0);
	while(1)
	{
		char Ch = SPI_Receive_Data();
		Lcd_Data(Ch);
		__delay_ms(5);
	}
}