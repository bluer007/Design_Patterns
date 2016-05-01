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
#include "建造者模式.h"
#include "原型模式.h"
#include "单例模式.h"
#include "适配器模式.h"
#include "桥接模式.h"
#include "组合模式.h"
#include "外观模式.h"

using namespace std;

using zsq::test_zsq;		//装饰器模式
using cxgc::test_cxgc;		//抽象工厂模式
using jdgc::test_jdgc;		//简单工厂模式
using gcff::test_gcff;		//工厂方法模式
using jzz::test_jzz;		//建造者模式
using yx::test_yx;			//原型模式
using dl::test_dl;			//单例模式
using spq::test_spq;		//适配器模式
using qj::test_qj;			//桥接模式
using zh::test_zh;			//组合模式
using wg::test_wg;			//外观模式

enum
{
	ZSQ = 1,	//装饰器模式
	CXGC,		//抽象工厂模式
	JDGC,		//简单工厂模式
	GCFF,		//工厂方法模式
	JZZ,		//建造者模式
	YX,			//原型模式
	DL,			//单例模式
	SPQ,		//适配器模式
	QJ,			//桥接模式
	ZH,			//组合模式
	WG			//外观模式
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
		cout << "[5] 建造者模式\n";
		cout << "[6] 原型模式\n";
		cout << "[7] 单例模式\n";
		cout << "[8] 适配器模式\n";
		cout << "[9] 桥接模式\n";
		cout << "[10] 组合模式\n";
		cout << "[11] 外观模式\n";

		cin.getline(choose, 3);
		if (choose[0] == 'q' || choose[0] == 'Q')
			return 0;
		switch (atoi(choose))
		{
		case ZSQ:
			test_zsq();		break;	//装饰器模式
		case CXGC:
			test_cxgc();	break;	//抽象工厂模式
		case JDGC:
			test_jdgc();	break;	//简单工厂模式
		case GCFF:
			test_gcff();	break;	//工厂方法模式
		case JZZ:
			test_jzz();		break;	//建造者模式
		case YX:
			test_yx();		break;	//原型模式
		case DL:
			test_dl();		break;	//单例模式
		case SPQ:
			test_spq();		break;	//适配器模式
		case QJ:
			test_qj();		break;	//桥接模式
		case ZH:
			test_zh();		break;	//组合模式
		case WG:
			test_wg();		break;	//外观模式
		default:
			cout << "\nPlease choose a valid number.\n";	break;
		}
		system("echo, & pause & cls");
	}


	return 0;
}

