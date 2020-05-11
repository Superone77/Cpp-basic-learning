#include <iostream>
#include "TString.h"

using namespace std;
using namespace n_string;

int main()
{
	TString s1(" and I am a C++ student.");
	TString s2 = "Please enter your name: ";
	TString s3;
	cout << s2;
	// overloaded << operator
	cin >> s3;
	// overloaded >> operator
	s2 = "My name is " + s3;
	// overloaded =, + operators
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup();
	// converts string to uppercase
	cout	<< "The string\n" << s2 << "\ncontains " << s2.has('A')
			<< " 'A' characters in it.\n";
	s1 = "red";
	// tstring(const char *),
	// then tstring & operator=(const string&)
	TString rgb[3] = { TString(s1), TString("green"), TString("blue")};
	cout << "enter the name of a primary color for mixing light: ";
	TString ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow();
		// converts string to lowercase
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i]) // overloaded == operator
			{
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again!\n";
	}
	cout << "Bye\n";
	return 0;
}
