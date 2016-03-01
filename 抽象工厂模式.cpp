/*  
*   鎶借薄宸ュ巶妯″紡
*/

#include <iostream>
using namespace std;

class IProduct
{
public:
	virtual ~IProduct() = 0;	//声明为纯虚函数
	virtual void UseProduct() = 0;
};
IProduct::~IProduct() { cout << "~IProduct()\n"; };		//必须写函数体才能编译

class IFactory
{
public:
    virtual IProduct* CreateProduct() = 0;
	virtual ~IFactory(){ cout << "~IFactory()\n"; };
};

class Shoe : public IProduct
{
public:
	Shoe() { cout << "Shoe()" << endl; };
	virtual ~Shoe() { cout << "~Shoe()" << endl; };
	virtual void UseProduct()
	{
		cout << "i am shoe -- product." << endl;
	};

};

class ShoeFactory : public IFactory
{
public:
	ShoeFactory() { cout << "ShoeFactory()" << endl; };
	virtual ~ShoeFactory() { cout << "~ShoeFactory()" << endl; };
    virtual IProduct* CreateProduct()
    {
		return new Shoe();
    };
};


void test_ChouXiangGongChang()
{
	std::cout << "\n----抽象工厂模式----\n";
	IFactory* pFactory = new ShoeFactory();
	IProduct* pProduct = pFactory->CreateProduct();
	pProduct->UseProduct();
	delete pProduct;
	delete pFactory;
}

