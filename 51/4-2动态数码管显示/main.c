#include <REGX52.H>
#include <INTRINS.H>

unsigned char NixieTable[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x00};

void Delay(xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms--)
	{
		_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
	}
	
}


void Nixie(unsigned char location,number)
{
	switch(location)
	{
		case 1:P2_4 = 0;P2_3 = 0;P2_2 = 0;break;
		case 2:P2_4 = 0;P2_3 = 0;P2_2 = 1;break;
		case 3:P2_4 = 0;P2_3 = 1;P2_2 = 0;break;
		case 4:P2_4 = 0;P2_3 = 1;P2_2 = 1;break;
		case 5:P2_4 = 1;P2_3 = 0;P2_2 = 0;break;
		case 6:P2_4 = 1;P2_3 = 0;P2_2 = 1;break;
		case 7:P2_4 = 1;P2_3 = 1;P2_2 = 0;break;
		case 8:P2_4 = 1;P2_3 = 1;P2_2 = 1;break;		
	}
	P0 = NixieTable[number];
	Delay(1);
	P0 = 0x00;

}


void main()
{
	
	while(1)
	{
		Nixie(8,6);
		//Delay(20);
		Nixie(7,6);
		//Delay(20);
		Nixie(6,6);
		//Delay(20);
	}
}
 