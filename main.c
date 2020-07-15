#include "reg52.h"

sfr P4 = 0xE8;
sbit led32 = P3^7;

void LightInit(void)
{
	led32 = 1;
	P0 = 0xFF;
	P1 = 0xFF;
	P2 = 0xFF;
	P4 = 0x7F;
}

void SetLight(unsigned long dat)
{
	unsigned char *light = &dat;
	P0 = ~light[3];
	P1 = ~light[2];
	P2 = ~light[1];
	P4 = ~(light[0]&0x7F);
	led32 = (light[0]&0x80)==0?1:0; // µÕµÁ∆Ωµ„¡¡
}

void delay(int t)
{
	int i,j;
	for(i = 0; i < t; i++)
		for(j = 0; j < 2000; j++);
}

void main(void)
{
	int cnt = 0;
	LightInit();
	while(1)
	{
//		for(cnt = 0; cnt < 32; cnt++)
//		{
//			SetLight(0x01lu<<cnt);
//			delay(10);
//		}
		SetLight(0b11);
	}
}