/*
*	单例模式	源文件
*/

#include <iostream>
#include "单例模式.h"

using namespace std;

namespace dl
{
	//本方法的实例申请和销毁(实例或文件资源等)都必须手动调用类接口实现
	class Singleton
	{
	public:
		static Singleton* getInstance()		//用于实例化类的唯一途径,故能被外部访问,设为static
		{
			//if (m_singleton == NULL)	并发时这样的判断可减少Lock()带来的性能负担
			{
				//Lock();		并发时考虑上锁问题
				//没有this指针,只能访问类的static成员
				if (m_singleton == NULL)	//并发时再一次判断可保证线程安全
				{
					m_singleton = new Singleton();
				}
				//Unlock();
			}
			return m_singleton;
		};
		
		void destryInstance()	//由开发者手动调用,当然也可以开发者手动delete
		{
			if (this->m_singleton)
			{
				delete this->m_singleton;
				this->m_singleton = NULL;
			}
		};

		void use()
		{
			cout << "use class Singleton" << endl;
		};

	private:
		static Singleton* m_singleton;		//通过static方法类来保证唯一实例(可以是其他类)
		Singleton() { cout << "Singleton()\n"; };		//私有化唯一的构造函数,故不能实例化类,只能通过getInstance()获得类实例. 且并且写出构造函数的函数体,因为new操作符会调用构造函数

		~Singleton() { cout << "~Singleton()\n"; };		//因为本类中m_singleton是分配到堆上,由delete销毁,即对象不会自动析构,所以析构函数可以私有化(但类外部将不能调用,包括外部delete,只能调用类接口destryInstance()销毁实例)
	};

	Singleton* Singleton::m_singleton = NULL;	//初始化类的static成员


	//本方法虽然不必开发者手动销毁实例,但是不能处理自动销毁其他句柄资源问题
	class Singleton2
	{
	public:
		static Singleton2& getInstance()
		{
			static Singleton2 single;	//调用本接口时,才创建该实例,程序结束时,系统自动销毁该静态变量.也可以写为类成员变量,则外部声明Singleton2变量时会自动创建该实例
			return single;
		};

		Singleton2(Singleton2& tmp)
		{
			cout << "Singleton2拷贝构造函数" << endl;
		};

		void use()
		{
			cout << "use class Singleton2" << endl;
		};

		//因为本类中static Singleton2 single;是分配到栈上,即对象会自动析构,所以析构函数不能私有化,只能public
		~Singleton2() {
			cout << "单例模式中清理实例对象 ~Singleton2()\n"; 
			system("pause");
		};
	private:
		Singleton2() { cout << "Singleton2()\n"; };

	};

	//本方法实现了自动销毁实例和其他句柄资源的功能
	class Singleton3
	{
	public:
		static Singleton3& getInstance()
		{
			if (m_instance == NULL)
			{
				m_instance = new Singleton3();
			}
			return *m_instance;
		};

		void use()
		{
			cout << "use class Singleton3" << endl;
		};

	private:
		//FILE* m_file;		//假设有文件对象
		static Singleton3* m_instance;
		Singleton3() { cout << "Singleton3()\n"; };
		~Singleton3() { cout << "~Singleton3()\n"; };
		
		//通过GC类自动销毁实例和其他对象资源
		class GC
		{
		public:
			GC() 
			{ 
				//cout << "GC()\n"; 
			};

			~GC() 
			{ 
				cout << "单例模式中清理实例和其他对象 ~GC() -- Began to clean up\n"; 
				//delete m_file;	销毁除实例外的其他对象资源
				if (m_instance)
				{
					delete m_instance;	//通过GC类的析构函数销毁实例
					m_instance = nullptr;
				}
				system("pause");
			};
		};

		static GC m_gc;		//程序退出时,自动调用该静态成员的析构函数来清理各种资源
	};
	
	Singleton3* Singleton3::m_instance = nullptr;
	Singleton3::GC Singleton3::m_gc;	//程序运行时,自动调用Singleton3::GC类的构造函数

	void test_dl()
	{
		cout << "\n----单例模式----\n";
		Singleton* single = Singleton::getInstance();
		single->use();
		//delete single;	不能,因Singleton类的析构函数是私有函数,只能由类的接口来销毁
		single->destryInstance();		//使用完后需手动清理.
		cout << endl;

		Singleton2& single2 = Singleton2::getInstance();	//若声明为Singleton2 single2;则会调用Singleton2类的拷贝构造函数
		single2.use();		//Singleton2使用完后,系统会自动清理实例
		cout << endl;

		Singleton3& single3 = Singleton3::getInstance();
		single3.use();		//Singleton2使用完后,系统会自动清理实例和其他资源
		cout << endl;
	};

};