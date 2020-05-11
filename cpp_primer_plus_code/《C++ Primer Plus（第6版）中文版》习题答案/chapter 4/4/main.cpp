#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int
main (void) 
{     
	string	strFirstname;
	cout << "Enter your first name: ";
	cin >> strFirstname;

	string	strLastname;
	cout << "Enter your last name: ";
	cin >> strLastname;

	string	strInfo = strLastname + ", " + strFirstname;
	cout << "Here’s the information in a single string: " << strInfo;

	
	cout << endl;
	return (0);
} 
