/*
*	外观模式	源文件
*/

#include <iostream>
#include <string>
#include "外观模式.h"

using namespace std;

namespace wg
{
	class RedMi
	{
	public:
		RedMi(string name) : m_name(name) {};

		void DoSomething1()
		{
			cout << "i am RedMi , my name is " << m_name << endl;
		};

	private:
		string m_name;
	};

	class XiaoMi
	{
	public:
		XiaoMi(string name) : m_name(name) {};

		void DoSomething2()
		{
			cout << "i am XiaoMi , my name is " << m_name << endl;
		};

	private:
		string m_name;
	};

	class Facade
	{
	public:
		void DoSomething()
		{
			//外观模式中, 外部只能看到Facade类, 且只能通过Facede类接口完成内部系统的逻辑
			string name_redmi = "红米2";
			string name_xiaomi = "小米note3";
			RedMi redmi(name_redmi);
			XiaoMi xiaomi(name_xiaomi);
			redmi.DoSomething1();
			xiaomi.DoSomething2();
		};

	};


	void test_wg()
	{
		cout << "\n----外观模式----\n";
		//外观模式中, 外部只能看到Facade类, 且只能通过Facede类接口完成内部系统的逻辑
		Facade facade;
		facade.DoSomething();

	}
};