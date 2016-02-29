/*
*	装饰器模式
*/

#include <iostream>
#include <string>
using namespace std;

class Component		//基本物件, 可被其他东西装饰
{
public:
	virtual void use() = 0;
};

class Zhuji : public Component		//主机类, 要被装饰上其他配件
{
private:
	string str;
public:
	Zhuji() : str("主机") {};
	 void use() 
	{
		cout << "我是" << str << "--基本物件" << endl;		
	}
};

class Decorator : public Component		
{
public:
	Decorator(Component* com) : component(com){};
	 void use()
	{
		if (component)
			component->use();
	};

private:
	Component* component;
};

class Xianshiqi : public Decorator	//显示器类, 装饰器
{
public:
	Xianshiqi(Component* com) : Decorator(com), str("显示器") {};

	 void use()
	{
		Decorator::use();
		cout << "装上--" << str << endl;
	};

private:
	string str;
};

class Jianpan : public Decorator	//键盘类, 装饰器
{
public:
	Jianpan(Component* com) : Decorator(com), str("键盘") {};
	 void use()
	{
		Decorator::use();
		cout << "装上--" << str << endl;
	};

private:
	string str;
};


void test()
{
	cout << "----装饰器模式----" << endl;
	Component* component = new Zhuji();
	component->use();

	cout << "\n即将装备---\n";
	Decorator* decorator = new Xianshiqi(component);
	decorator->use();			//装上显示器

	cout << "\n即将装备---\n";
	Decorator* decorator1 = new Jianpan(decorator);		//装上键盘
	decorator1->use();
	delete decorator1;
	delete decorator;
	delete component;
}





