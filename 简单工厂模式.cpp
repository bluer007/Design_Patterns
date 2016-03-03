/*
*	简单工厂模式	源文件
*/

#include <iostream>
#include <string>
#include "简单工厂模式.h"

using namespace std;

namespace jdgc	//简单工厂模式命名空间
{
	class IProduct
	{
	public:
		IProduct() { cout << "IProduct()" << endl; };
		virtual ~IProduct() { cout << "~IProduct()" << endl; };
		virtual void Use() = 0;
	};

	class IFactory
	{
	public:
		IFactory() { cout << "IFactory()" << endl; };
		virtual ~IFactory() { cout << "~IFactory()" << endl; };
		virtual IProduct* CreateProduct(string) = 0;
	};

	class RedMi : public IProduct
	{
	public:
		RedMi() { cout << "RedMi()" << endl; };
		~RedMi() { cout << "~RedMi()" << endl; };
		virtual void Use()
		{
			cout << "i am RedMi-----------" << endl;
		};

	};

	class XiaoMi : public IProduct
	{
	public:
		XiaoMi() { cout << "XiaoMi()" << endl; };
		~XiaoMi() { cout << "~XiaoMi()" << endl; };
		virtual void Use()
		{
			cout << "i am XiaoMi----------" << endl;
		};
	};

	class XiaoMiFactory : public IFactory
	{
	public:
		XiaoMiFactory() { cout << "XiaoMiFactory()" << endl; };
		virtual ~XiaoMiFactory() { cout << "~XiaoMiFactory()" << endl; };
		virtual IProduct* CreateProduct(string type)
		{
			if (type == "xiaomi")
				return new XiaoMi();
			if (type == "redmi")
				return new RedMi();

			return NULL;
		};
	};

	void test_jdgc()	//简单工厂的测试用例
	{
		cout << "\n----简单工厂模式----" << endl;

		IFactory* factory = new XiaoMiFactory();
		IProduct* xiaomi = factory->CreateProduct("xiaomi");
		xiaomi->Use();
		IProduct* redmi = factory->CreateProduct("redmi");
		redmi->Use();
		delete factory;
		delete xiaomi;
		delete redmi;
	};






};
