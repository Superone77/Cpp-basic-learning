#include <iostream>
#include <cctype>

int
main (void) 
{     
	using namespace std;

	const char	k_flagEnd = '@';
	char	ch;
	while (cin >> ch && k_flagEnd != ch) {
		if (isdigit(ch)) {
			continue;
		}

		if (islower(ch)) {
			ch = (char)toupper(ch);
		} else if (isupper(ch)) {
			ch = (char)tolower(ch);
		} else {
			;	// nop!
		}

		cout << ch;
	}
		
	cout << endl;
	return (0);
} 
