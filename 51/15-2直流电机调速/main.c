#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"

sbit Motor=P1^0;

unsigned char Counter,Compare;
unsigned char KeyNum,Speed;

void main()
{
	Timer0Init();
	Compare=5;
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			Speed++;
			if(Speed>=4) Speed=0;
			if(Speed==0) Compare=0;
			if(Speed==1) Compare=50;
			if(Speed==2) Compare=75;
			if(Speed==3) Compare=100;
		}
		Nixie(1,Speed);
	}
}

void Timer0_Rountine() interrupt 1
{
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	Counter++;
	if(Counter>=100) Counter=0;
	if(Counter<Compare)
	{
		Motor=1;
	}
	else
	{
		Motor=0;
	}
}