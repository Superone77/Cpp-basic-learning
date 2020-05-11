#include <iostream>
#include<stdlib.h>
#include<string>

using namespace std;

struct goodman {
	string name;
	double money;
};
int main()
{
	int num_goodman = 0;
	cout << "Please enter the number of the goodman: ";
	cin >> num_goodman;

	goodman* const Wuhan= new goodman [num_goodman];
	for (int i = 0; i < num_goodman; i++) {
		cout << "Enter the name: ";
		cin >> Wuhan[i].name;
		cout << "How much has this guy give? " << endl;
		cin >> Wuhan[i].money;
	}
	
	cout << "Grand Patrons" << endl;
	for (int i = 0; i < num_goodman; i++) {
		if (Wuhan[i].money > 10000)
			cout << Wuhan[i].name << endl;
	}

	cout << endl;

	cout << "Patrons" << endl;
	for (int i = 0; i < num_goodman; i++) {
		if (Wuhan[i].money <= 10000)
			cout << Wuhan[i].name << endl;
	}


	system("pause");

	return 0;
}