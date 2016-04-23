/*
*	组合模式	源文件
*/

#include <iostream>
#include <vector>
#include <string>
#include "组合模式.h"

using namespace std;

namespace zh
{
	class Component
	{
	public:
		virtual void DoSomething() = 0;
		virtual void Add(Component* component) = 0;
		virtual void Delete(Component* component) = 0;
		virtual Component* GetChild(int num) = 0;
		virtual string GetName() { return m_name; };
		virtual ~Component() {};
		Component(string name) : m_name(name) {};

	private:
		Component();		//故意不实现
		string m_name;
	};

	class Leaf : public Component
	{
	public:
		Leaf(string name) : Component(name) {};

		virtual void DoSomething()
		{
			cout << "i am leaf, my name is " << this->GetName() << endl;
		};

		virtual void Add(Component* component)
		{
			return;
		}

		virtual Component* GetChild(int num)
		{
			return nullptr;
		}

		virtual void Delete(Component* component)
		{
			return;
		}

	};

	class Composite : public Component
	{
	public:
		virtual void DoSomething()
		{
			cout << "i am composite, my name is " << this->GetName() << endl;	

			std::vector<Component*>::iterator ite;
			for (ite = m_child.begin(); ite != m_child.end(); ite++)
			{
				(*ite)->DoSomething();
			}
		};

		virtual void Add(Component* component)
		{
			this->m_child.push_back(component);
		};

		virtual void Delete(Component* component)
		{
			std::vector<Component*>::iterator ite;
			for (ite = m_child.begin(); ite != m_child.end(); ite++)
			{
				if ((*ite)->GetName() == component->GetName())
				{
					m_child.erase(ite);
					break;
				}
			}
		}

		virtual Component* GetChild(int num)
		{
			Component* component = this->m_child.at(num - 1);
			return component;
				
		}

		Composite(string name) : Component(name) {};
		
	private:
		vector<Component*> m_child;
	};

	void test_zh()
	{
		cout << "\n----组合模式----" << endl;
		
		Component* compositeA = new Composite("compositeA");
		Component* leafA = new Leaf("leafA"); 
		Component* leafB = new Leaf("leafB"); 
		
		compositeA->DoSomething();
		leafA->DoSomething();
		leafB->DoSomething();

		cout << endl;
		compositeA->Add(leafA);
		compositeA->Add(leafB);
		compositeA->DoSomething();

		cout << endl;
		compositeA->Delete(compositeA->GetChild(2));
		compositeA->DoSomething();

		delete leafB;
		delete leafA;
		delete compositeA;
	}
	

};