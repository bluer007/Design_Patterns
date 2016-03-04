/*
*	建造者模式	源文件
*/


#include <iostream>
#include "建造者模式.h"

using namespace std;

namespace jzz
{
	class IPerson		//产品类,最终要被生产(建造)出来
	{
	public:
		void setType(string str) { this->type = str; };
		void setBody(int body) { this->param_body = body; };
		void setHead(int head) { this->param_head = head; };
		void setHand(int hand) { this->param_hand = hand; };
		void setFoot(int foot) { this->param_foot = foot; };
		void Use()		//产品的使用接口
		{
			cout << "\ni am "<<type.c_str()<<".\n";
			cout << "body length: " << param_body << endl;
			cout << "head length: " << param_head << endl;
			cout << "hand length: " << param_hand << endl;
			cout << "foot length: " << param_foot << endl;
		};
	private:
		string type;
		int param_body;
		int param_head;
		int param_hand;
		int param_foot;
	};

	class IPersonBuilder	//制造者抽象类,可制造各个零件(部分),留有接口
	{
	public:
		virtual ~IPersonBuilder() {};	//若写成纯虚析构函数,则需写函数定义.故直接用空实现代替
		virtual void CreateBody(int param) = 0;
		virtual void CreateHead(int param) = 0;
		virtual void CreateHand(int param) = 0;
		virtual void CreateFoot(int param) = 0;

		virtual IPerson* GetPerson() = 0;
	};

	class FatPersonBuilder : public IPersonBuilder	//制造者,可制造有自己特色的各个零件(部分)
	{
	public:
		virtual ~FatPersonBuilder() { cout << "~FatPersonBuilder()\n"; };
		FatPersonBuilder() 
		{ 
			this->m_person = new IPerson(); 
			this->m_person->setType("fat person");
		};

		virtual void CreateBody(int param) 
		{ 
			this->m_person->setBody(param);
			cout << "create fat body-----" << param << endl;
		};

		virtual void CreateHead(int param) 
		{
			this->m_person->setHead(param);
			cout << "create fat head-----" << param << endl;
		};

		virtual void CreateHand(int param)
		{
			this->m_person->setHand(param);
			cout << "create fat hand-----" << param << endl;
		};

		virtual void CreateFoot(int param)
		{
			this->m_person->setFoot(param);
			cout << "create fat foot-----" << param << endl;
		};
		
		virtual IPerson* GetPerson()
		{
			return this->m_person;
		};

	private:
		IPerson* m_person;
	};

	class PersonDirector	//制造的指挥者,指导把各个零件(部分) 按需求 组装起来
	{
	public:
		PersonDirector(IPersonBuilder* per) : m_per(per) {};
		
		void CreatePerson(int body,int head, int hand, int foot)
		{
			cout << "start to create person\n";
			this->m_per->CreateBody(body);
			this->m_per->CreateHead(head);
			this->m_per->CreateHand(hand);
			this->m_per->CreateFoot(foot);
			cout << "create person complete\n";
		};

	private:
		IPersonBuilder* m_per;
	};

	void test_jzz()
	{
		cout << "\n----建造者模式----\n";
		//builder可制造产品的每一个部分(零件)
		IPersonBuilder* builder = new FatPersonBuilder();

		PersonDirector director(builder);
		
		//可传不同参数,表示可按需制造(组装)不同的产品(person)
		director.CreatePerson(1,2,3,4);

		//获取组装完毕的产品,返回给person
		IPerson* person = builder->GetPerson();
		//使用产品
		person->Use();

		delete person;
		delete builder;
	};
};