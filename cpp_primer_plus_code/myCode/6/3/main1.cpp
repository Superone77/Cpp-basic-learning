#include <iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	cout << "Please enter one of the following choices:" << endl;
	cout << "c) carnivore          p) pianist" << endl;
	cout << "t) tree               g) game" << endl;
	
	char ch;
	
	cin >> ch;
	while (ch != 'c' && ch != 'p' && ch != 't' && ch != 'g') {
		cout << "Please enter a c,p,t or g:";
		cin >> ch;
	}
	switch (ch)
	{
	case 'c':cout << "~-~"; break;
	case 'p':cout << "~-~"; break;
	case 't':cout << "A maple is a tree."; break;
	case 'g':cout << "~-~";
	}

	cout << endl;

	system("pause");

	return 0;
}