#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int
main (void) 
{     
	string	strName;
	cout << "Enter your name:\n";
	cin >> strName;

	string	strDessert;
	cout << "Enter your favorite dessert:\n";
	cin >> strDessert;

	cout << "I have some delicious " << strDessert;
	cout << " for you, " << strName << ".\n";

	
	cout << endl;
	return (0);
} 
