/*
*	桥接模式	源文件
*/

#include <iostream>
#include "桥接模式.h"

using namespace std;

namespace qj
{
	class Product
	{
	public:
		virtual ~Product() {};
		virtual void UseProduct() = 0;
	};

	class Clothes : public Product
	{
	public:
		virtual ~Clothes() {};
		virtual void UseProduct()
		{
			cout << "use clothes" << endl;
		};
	};

	class Person
	{
	public:
		virtual ~Person() {};
		virtual void DoSomething() = 0;
	};

	class Bluer : public Person
	{
	public:
		Bluer(Product* product) : m_product(product) {};
		virtual ~Bluer() {};
		virtual void DoSomething()
		{
			this->m_product->UseProduct();
		};

	private:
		Product* m_product;
	};

	void test_qj()
	{
		Product* product = new Clothes();
		Person* person = new Bluer(product);
		person->DoSomething();

		delete product;
		delete person;
	};
};