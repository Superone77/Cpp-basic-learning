#include <iostream>
#include <cctype>

using namespace std;

string&
str_to_upper (string& str)
{
	for (auto& e : str) {
		e = (char)toupper(e);
	}

	return (str);
}

int
main (void) 
{     
	while (true) {
		cout << "Enter a string (q to quit): ";

		string	strInput;
		getline(cin, strInput);
		if (!cin || "q" == strInput || "Q" == strInput) {
			break;
		}

		cout << str_to_upper(strInput) << endl;
	}


	cout << endl;
	return (0);
} 
