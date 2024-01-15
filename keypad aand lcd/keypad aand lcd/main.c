
#include <avr/io.h>
#define F_CPU 1000000UL
#include "util/delay.h"
#include "utility.h"
#include "lcd.h"

int main(void)
{
	lcdInit();
	lcdPrint("press a key ");
	unsigned char butn;
	
	
	for (int i=4; i<8;i++) //output
	{
		DDRC |= (1 << i);
		PORTC &= ~(1 << i);
	}
	for (int j=0; j<4;j++) //input
	{
		DDRC &= ~(1 << j);
		PORTC |= (1 << j);
	}
	DDRA = 0xFF;
	while (1)
	{
		if(gpio_read_pin(PORTC_ID, 0) == 1 && gpio_read_pin(PORTC_ID, 1) ==1 &&
		gpio_read_pin(PORTC_ID, 2) == 1 && gpio_read_pin(PORTC_ID, 3) == 1){
			PORTA = 0x00;
		}
		else
		{
			for (int j=0; j<4;j++) // read status of colums pins
			{
				if ((PINC & (1 << j ))==0)
				{
					butn = j;
				}
			}
			PORTC &= ~(1 << 4);
			PORTC |= (1 << 5);
			PORTC |= (1 << 6);
			PORTC |= (1 << 7);
			if ((gpio_read_pin(PORTC_ID,butn))==1)
			{
				PORTC |= (1 << 4);
				PORTC &= ~(1 << 5);
				PORTC |= (1 << 6);
				PORTC |= (1 << 7);
				if ((gpio_read_pin(PORTC_ID,butn))==1)
				{
					PORTC |= (1 << 4);
					PORTC |= (1 << 5);
					PORTC &= ~(1 << 6);
					PORTC |= (1 << 7);
					if ((gpio_read_pin(PORTC_ID,butn))==1)
					{
						PORTC |= (1 << 4);
						PORTC |= (1 << 5);
						PORTC |= (1 << 6);
						PORTC &= ~(1 << 7);
						if ((gpio_read_pin(PORTC_ID,butn))==1)
						{
							PORTA = 0x00;
						}
						else {
							if (gpio_read_pin(PORTC_ID,3)==1){
								if (gpio_read_pin(PORTC_ID, 2)==1){
									if (gpio_read_pin(PORTC_ID, 1)==1){
										if (gpio_read_pin(PORTC_ID, 0)==1){
											lcdCmd(DISPLAY_ON_CURSOR_BLINKING);
											lcdCmd(FORCE_CURSOR_BEGINNING_FIRST_LINE);
										}
										else	{
											lcdData('A');
											_delay_ms(5000);
											lcdInit();
											lcdPrint("press again!! ");;
											for (int i =4; i<8;i++)
											{
												PORTC &= ~(1 << i);
											}
										}
									}
									else	{
										lcdData('3');
										_delay_ms(5000);
										lcdInit();
										lcdPrint("press again!! ");
										for (int i =4; i<8;i++)
										{
											PORTC &= ~(1 << i);
										}
									}
								}
								else	{
									lcdData('2');
									_delay_ms(5000);
									lcdInit();
									lcdPrint("press again!! ");
									for (int i =4; i<8;i++)
									{
										PORTC &= ~(1 << i);
									}
								}
							}
					else	{
						lcdData('1');
							_delay_ms(5000);
							lcdInit();
							lcdPrint("press again!! ");
							for (int i =4; i<8;i++)
							{
								PORTC &= ~(1 << i);
							}
						}
						}
					}
					else { 
						if (gpio_read_pin(PORTC_ID,3)==1){
						 if (gpio_read_pin(PORTC_ID, 2)==1){
							if (gpio_read_pin(PORTC_ID, 1)==1){
								if (gpio_read_pin(PORTC_ID, 0)==1){
									lcdCmd(DISPLAY_ON_CURSOR_BLINKING);
									lcdCmd(FORCE_CURSOR_BEGINNING_FIRST_LINE);
								
								}
								else	{
									lcdData('B');
									_delay_ms(5000);
									lcdInit();
									lcdPrint("press again!! ");
									for (int i =4; i<8;i++)
									{
										PORTC &= ~(1 << i);
									}
								}
							}
							else	{
								lcdData('6');
								_delay_ms(5000);
								lcdInit();
								lcdPrint("press again!! ");
								for (int i =4; i<8;i++)
								{
									PORTC &= ~(1 << i);
								}
							}
						}
						else	{
							lcdData('5');
							_delay_ms(5000);
							lcdInit();
							lcdPrint("press again!! ");
							for (int i =4; i<8;i++)
							{
								PORTC &= ~(1 << i);
							}
						}
					}
					else	{
						lcdData('4');
					_delay_ms(5000);
					lcdInit();
					lcdPrint("press again!! ");
						for (int i =4; i<8;i++)
						{
							PORTC &= ~(1 << i);
						}
					}
					}
				}
				else {
					if (gpio_read_pin(PORTC_ID,3)==1){
					 if (gpio_read_pin(PORTC_ID, 2)==1){
						if (gpio_read_pin(PORTC_ID, 1)==1){
							if (gpio_read_pin(PORTC_ID, 0)==1){
								lcdCmd(DISPLAY_ON_CURSOR_BLINKING);
								lcdCmd(FORCE_CURSOR_BEGINNING_FIRST_LINE);
							}
							else	{
								lcdData('C');
								_delay_ms(5000);
								lcdInit();
								lcdPrint("press again!! ");
								for (int i =4; i<8;i++)
								{
									PORTC &= ~(1 << i);
								}
							}
						}
						else	{
							lcdData('9');
						_delay_ms(5000);
						lcdInit();
						lcdPrint("press again!! ");
							for (int i =4; i<8;i++)
							{
								PORTC &= ~(1 << i);
							}
						}
					}
					else	{
						lcdData('8');
						_delay_ms(5000);
						lcdInit();
						lcdPrint("press again!! ");
						for (int i =4; i<8;i++)
						{
							PORTC &= ~(1 << i);
						}
					}
				}
				else	{
					lcdData('7');
					_delay_ms(5000);
					lcdInit();
					lcdPrint("press again!! ");
					for (int i =4; i<8;i++)
					{
						PORTC &= ~(1 << i);
					}
				}
				}
			}
			else	{
				if (gpio_read_pin(PORTC_ID,3)==1){
				 if (gpio_read_pin(PORTC_ID, 2)==1){
					if (gpio_read_pin(PORTC_ID, 1)==1){
						if (gpio_read_pin(PORTC_ID, 0)==1){
							lcdCmd(DISPLAY_ON_CURSOR_BLINKING);
							lcdCmd(FORCE_CURSOR_BEGINNING_FIRST_LINE);
						}
						else	{
							lcdData('D');
							_delay_ms(5000);
							lcdInit();
							lcdPrint("press again!! ");
							for (int i =4; i<8;i++)
							{
								PORTC &= ~(1 << i);
							}
						}
					}
					else	{
						lcdData('#');
						_delay_ms(5000);
						lcdInit();
						lcdPrint("press again!! ");
						for (int i =4; i<8;i++)
						{
							PORTC &= ~(1 << i);
						}
					}
				}
				else	{
					lcdData('0');
					_delay_ms(5000);
					lcdInit();
					lcdPrint("press again!! ");
					for (int i =4; i<8;i++)
					{
						PORTC &= ~(1 << i);
					}
				}
			}
			else	{
				lcdData('*');
				_delay_ms(5000);
				lcdInit();
				lcdPrint("press again!! ");
				for (int i =4; i<8;i++)
				{
					PORTC &= ~(1 << i);
				}
			}
			}
			}
		}
	
}

