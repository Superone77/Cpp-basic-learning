#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<string>

using namespace std;

struct goodman {
	string name;
	double money;
};

int main()
{
	ifstream inFile;
	int num_goodman = 0;
	inFile.open("C:\\Users\\Superone77\\Desktop\\6\\9\\donation.txt");
	inFile >> num_goodman;

	goodman* const Wuhan = new goodman[num_goodman];

	for (int i = 0; i < num_goodman; i++) {
		inFile.get();
		getline(inFile, Wuhan[i].name);
		ifs >> Wuhan[i].amount;
	}
	inFile.close();

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


	

	return 0;
}