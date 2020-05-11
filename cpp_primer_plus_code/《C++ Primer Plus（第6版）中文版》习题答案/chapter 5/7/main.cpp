#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

struct TCar 
{
	string		strMaker;
	unsigned	uBulitYear;
};

int
main (void) 
{     
	cout << "How many cars do you wish to catalog? ";
	unsigned	uCatalogNum;
	cin >> uCatalogNum;
	cin.get();

	TCar*	pCarsLst = new TCar [uCatalogNum];

	for (unsigned i = 0; i < uCatalogNum; ++i) {
		cout << "Car #" << i+1 << ": " << endl;

		cout << "Please enter the make: ";
		getline(cin, pCarsLst[i].strMaker);

		cout << "Please enter the year made: ";
		cin >> pCarsLst[i].uBulitYear;
		cin.get();
	}

	cout << "Here is your collection: " << endl;
	for (unsigned i = 0; i < uCatalogNum; ++i) {
		cout << pCarsLst[i].uBulitYear << " " << pCarsLst[i].strMaker << endl;
	}
	
	delete [] pCarsLst;
	pCarsLst = NULL;


	
	cout << endl;
	return (0);
} 
