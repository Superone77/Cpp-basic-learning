#include <iostream>
#include<cctype>

using namespace std;

int main()
{

	char ch;

	cout << "Please enter something with keyboard and end with @" << endl;


	ch = cin.get();
	while (ch != '@')
	{
		if (isdigit(ch))
			ch = cin.get();
		else if (islower(ch)) {
			ch=toupper(ch);
			cout << ch;
			ch = cin.get();
		}
		else if (isupper(ch)) {
			ch=tolower(ch);
			cout << ch;
			ch = cin.get();
		}
		else {
			cout << ch;
			ch = cin.get();
		}


	}

	cout << endl;


	return 0;
}