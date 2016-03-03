/*
*	工厂方法模式	源文件
*/

#include <iostream>
#include "工厂方法模式.h"
using namespace std;


namespace gcff		//工厂方法的命名空间
{
	class IProduct
	{
	public:
		IProduct() { cout << "IProduct()\n"; };
		virtual ~IProduct() { cout << "~IProduct()\n"; };
		virtual void Use() = 0;
	};

	class Shoe : public IProduct
	{
	public:
		Shoe() { cout << "Shoe()\n"; };
		virtual ~Shoe() { cout << "~Shoe()\n"; };
		virtual void Use() { cout << "i am shoe--------\n"; };
	};

	class Clothes : public IProduct
	{
	public:
		Clothes() { cout << "Clothes()\n"; };
		virtual ~Clothes() { cout << "~Clothes()\n"; };
		virtual void Use() { cout << "i am clothes--------\n"; };
	};

	class IFactory
	{
	public:
		IFactory() { cout << "IFactory()\n"; };
		virtual ~IFactory() = 0;	//让子类实现
		virtual IProduct* CreateProduct() = 0;
	};

	//避免编译器找不到该析构函数的定义
	IFactory::~IFactory() { cout << "~IFactory()\n"; };

	class ShoeFactory : public IFactory
	{
	public:
		ShoeFactory() { cout << "ShoeFactory()\n"; };
		virtual ~ShoeFactory() { cout << "~ShoeFactory()\n"; };
		virtual IProduct* CreateProduct() { return new Shoe(); };
	};

	class ClothesFactory : public IFactory
	{
	public:
		ClothesFactory() { cout << "ClothesFactory()\n"; };
		virtual ~ClothesFactory() { cout << "~ClothesFactory()\n"; };
		virtual IProduct* CreateProduct() { return new Clothes(); };
	};

	void test_gcff()
	{
		cout << "\n----工厂方法模式----\n";
		IFactory* shoeFactory = new ShoeFactory();
		IProduct* shoe = shoeFactory->CreateProduct();
		shoe->Use();

		IFactory* clothesFactory = new ClothesFactory();
		IProduct* clothes = clothesFactory->CreateProduct();
		clothes->Use();

		delete shoeFactory;
		delete shoe;
		delete clothesFactory;
		delete clothes;
	};

};