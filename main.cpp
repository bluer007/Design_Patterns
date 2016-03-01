/***************************************
*	project name: Design Patterns
*	description: This is the practice about design mode.
*	author: Bluer
***************************************/
#include <iostream>
using namespace std;

extern void test_ZhuangShiQi();		//装饰器模式
extern void test_ChouXiangGongChang();		//抽象工厂模式

enum
{
	ZhuangShiQi = '1',		//装饰器模式
	ChouXiangGongChang		//抽象工厂模式
};

int main()
{
	char choose[2] = "";
	while (true)
	{
		cout << "choose a number to show a design pattern,\npress 'q' to quit." << endl;
		cout << "[1] 装饰器模式" << endl;
		cout << "[2] 抽象工厂模式" << endl << endl;

		cin.getline(choose, 2);
		if (choose[0] == 'q' || choose[0] == 'Q')
			return 0;
		switch (choose[0])
		{
		case ZhuangShiQi:
			test_ZhuangShiQi();	break;		//装饰器模式
		case ChouXiangGongChang:
			test_ChouXiangGongChang();	break;	//抽象工厂模式
		
		}
		system("echo, & pause & cls");
	}

	
	return 0;
}

