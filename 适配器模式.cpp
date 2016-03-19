/*
*	原型模式	源文件
*/

#include <iostream>
#include "适配器模式.h"

using namespace std;

namespace spq
{
	class XiaoMi
	{
	public:
		virtual ~XiaoMi() {};	//将要作为基类, 最好虚析构函数
		virtual void use()		//被外部所依赖的类和接口
		{
			cout << "i am xiao mi" << endl;
		};
	};

	class XiaoMi2s
	{
	public:
		void useXiaoMi2s()	//实际想调用的接口
		{
			cout << "i am xiao mi 2s" << endl;
		};
	};

	class Adapter : public XiaoMi, public XiaoMi2s		//类适配器, 即两个类都继承
	{
	public:
		//Adapter() {};
		virtual void use()	//适配器接口, 跟外部所依赖接口名一样
		{
			XiaoMi2s::useXiaoMi2s();	//或__super::useXiaoMi2s();
		};
	};

	class Adapter2 : public XiaoMi		//对象适配器, 即继承一个类,并使用类成员变量来使用另一个类
	{
	public:
		//Adapter2() {};
		virtual void use()
		{
			m_xiaomi2s.useXiaoMi2s();
		};

	private:
		XiaoMi2s m_xiaomi2s;	//当然指针也行
	};

	void test_spq()
	{
		cout << "\n----适配器模式----" << endl;
		//外部看来, 所依赖的接口是XiaoMi类的use()接口
		XiaoMi* xiaomi = new Adapter();		//类适配器
		xiaomi->use();		//实际调用了小米2s的接口
		delete xiaomi;
		xiaomi = nullptr;
		
		xiaomi = new Adapter2();	//对象适配器
		xiaomi->use();		//实际调用了小米2s的接口
		delete xiaomi;
		xiaomi = nullptr;
	};
};