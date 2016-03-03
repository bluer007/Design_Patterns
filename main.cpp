/***************************************
*	project name: Design Patterns
*	description: This is the practice about design mode.
*	author: Bluer
***************************************/
#include <iostream>
#include "简单工厂模式.h"
#include "抽象工厂模式.h"
#include "装饰器模式.h"
#include "工厂方法模式.h"

using namespace std;

using zsq::test_zsq;		//装饰器模式
using cxgc::test_cxgc;		//抽象工厂模式
using jdgc::test_jdgc;		//简单工厂模式
using gcff::test_gcff;		//工厂方法模式

enum
{
	ZSQ = 1,	//装饰器模式
	CXGC,		//抽象工厂模式
	JDGC,		//简单工厂模式
	GCFF		//工厂方法模式
};

int main()
{
	char choose[3] = "";
	while (true)
	{
		cout << "Choose a number to show a design pattern,\nPress 'q' to quit." << endl;
		cout << "[1] 装饰器模式\n";
		cout << "[2] 抽象工厂模式\n";
		cout << "[3] 简单工厂模式\n";
		cout << "[4] 工厂方法模式\n";

		cin.getline(choose, 3);
		if (choose[0] == 'q' || choose[0] == 'Q')
			return 0;
		switch (atoi(choose))
		{
		case ZSQ:
			test_zsq();	break;		//装饰器模式
		case CXGC:
			test_cxgc();	break;	//抽象工厂模式
		case JDGC:
			test_jdgc();	break;	//简单工厂模式
		case GCFF:
			test_gcff();	break;	//工厂方法模式
		default:
			cout << "\nPlease choose a valid number.\n";	break;
		}
		system("echo, & pause & cls");
	}


	return 0;
}

