#include <REGX52.H>

/**
  * @brief 定时器1初始化，100us@11.0592MHz
  * @param  无
  * @retval 无
  */

void Timer1_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = 0xA4;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	TF1 = 0;		//清除TF0标志
	TR1 = 1;		//定时器0开始计时
	ET1 = 1;
	EA = 1;
	PT1 = 0;
}

/*
定时器中断函数模版
void Timer1_Rountine() interrupt 3
{
	static unsigned int T0Count = 0;
	TL1 = 0xA4;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	T0Count++;
	if(T0Count >= 1000)
	{
		T0Count = 0;
		
	}
}
*/