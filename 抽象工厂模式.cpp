/*
*   抽象工厂模式	源文件
*/

#include <iostream>
#include "抽象工厂模式.h"
using namespace std;

namespace cxgc
{
	class IProductA
	{
	public:
		virtual ~IProductA() = 0;	//声明为纯虚函数
		virtual void UseProduct() = 0;
	};
	IProductA::~IProductA() { cout << "~IProductA()\n"; };		//必须写函数体才能编译

	class IProductB
	{
	public:
		virtual ~IProductB() = 0;	//声明为纯虚函数
		virtual void UseProduct() = 0;
	};
	IProductB::~IProductB() { cout << "~IProductB()\n"; };		//必须写函数体才能编译

	class IFactory
	{
	public:
		virtual IProductA* CreateProductA() = 0;
		virtual IProductB* CreateProductB() = 0;
		virtual ~IFactory() { cout << "~IFactory()\n"; };
	};

	class ShoeA : public IProductA
	{
	public:
		ShoeA() { cout << "ShoeA()" << endl; };
		virtual ~ShoeA() { cout << "~ShoeA()" << endl; };
		virtual void UseProduct()
		{
			cout << "i am shoe A ----- product." << endl;
		};

	};

	class ShoeB : public IProductB
	{
	public:
		ShoeB() { cout << "ShoeB()" << endl; };
		virtual ~ShoeB() { cout << "~ShoeB()" << endl; };
		virtual void UseProduct()
		{
			cout << "i am shoe B ----- product." << endl;
		};
	};

	class ShoeFactory : public IFactory
	{
	public:
		ShoeFactory() { cout << "ShoeFactory()" << endl; };
		virtual ~ShoeFactory() { cout << "~ShoeFactory()" << endl; };
		virtual IProductA* CreateProductA(){ return new ShoeA();};
		virtual IProductB* CreateProductB() { return new ShoeB(); };
	};

	void test_cxgc()
	{
		std::cout << "\n----抽象工厂模式----\n";
		IFactory* pFactory = new ShoeFactory();
		IProductA* pProductA = pFactory->CreateProductA();
		pProductA->UseProduct();
		
		IProductB* pProductB = pFactory->CreateProductB();
		pProductB->UseProduct();
		
		delete pProductA;
		delete pProductB;
		delete pFactory;
	}

};
