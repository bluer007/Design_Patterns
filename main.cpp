/***************************************
*	project name: Design Patterns
*	description: This is the practice about design mode.
*	author: Bluer
***************************************/
#include <iostream>
using namespace std;

extern void test();



int main()
{
	char choose[2] = "";
	while (true)
	{
		cout << "choose a number to show a design pattern, press 'q' to quit." << endl;
		cout << "[1] ×°ÊÎÆ÷Ä£Ê½" << endl << endl;
		cin.getline(choose, 2);
		if (choose[0] == 'q' || choose[0] == 'Q')
			return 0;

		switch (choose[0])
		{
		case '1':
			test(); break;
		
		}
		system("echo, & pause & cls");
	}

	
	return 0;
}

