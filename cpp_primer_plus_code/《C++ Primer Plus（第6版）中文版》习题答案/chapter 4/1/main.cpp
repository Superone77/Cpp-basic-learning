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
	cout << "What is your first name? ";
	getline(cin, strFirstname);
	
	string	strLastname;
	cout << "What is your last name? ";
	cin >> strLastname;

	char	chGrade;
	cout << "What letter grade do you deserve? ";
	cin >> chGrade;

	unsigned	unAge;
	cout << "What is your age? ";
	cin >> unAge;

	cout << "Name: " << strLastname << ", " << strFirstname << endl;
	cout << "Grade: " << char(chGrade + 1) << endl;
	cout << "Age: " << unAge << endl;

	
	cout << endl;
	return (0);
} 
