/*
*	原型模式	源文件
*/

#include <iostream>
#include "原型模式.h"

using namespace std;

namespace yx
{
	class CProduct
	{
	public:
		virtual ~CProduct() {};
		virtual CProduct* clone() = 0;
		virtual void use() = 0;		//使用产品
		virtual	void set(int num) = 0;	//设置产品
	};

	class CProductA : public CProduct
	{
	public:
		CProductA(int num) : m_num(num) {};

		virtual ~CProductA() {};

		CProductA(CProductA& product)	//拷贝构造函数,注意深浅拷贝问题
		{
			this->m_num = product.m_num;
		};

		virtual	void set(int num)
		{
			cout << "change number to " << num << endl;
			this->m_num = num;
		};

		virtual CProduct* clone()
		{
			return new CProductA(*this);
		};

		virtual void use()
		{
			cout << "i am product A, my number is " << this->m_num << endl;
		};

	private:
		int m_num;
	};

	void test_yx()
	{
		/*
		原型模式相比使用拷贝函数的优点:
		1, 假如一个封闭系统中传出一个基类指针,现需要对此类进行拷贝,
		原型模式则需clone一下即可拷贝了正确的派生类,拷贝函数则需要知道该封闭系统中
		该基类指针真正指向的派生类,才可以调用该派生类的拷贝函数
		2, 原型模式可以在类对象使用过程中,动态的改变一些参数后,正确的克隆出派生对象(保持着参数的变动),原来的对象则可删除等操作.具有动态删减增加的好处.
		3, 原型模式中,只需继承含有clone()的抽象类后,则可随时clone,使用过程中,可统一的使用基类指针,即可完成一些派生类的操作
		*/

		cout << "\n----原型模式----\n";
		CProduct* product1 = new CProductA(1);
		product1->use();	//使用产品
		product1->set(2);	//更改产品参数
		CProduct* product2 = product1->clone();		//克隆产品,保持更改的参数信息
		delete product1;	//已经克隆,所以随时delete都没有问题
		
		product2->use();
		
		delete product2;
	};
};