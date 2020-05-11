#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;

int
main (void) 
{     
	cout << "Enter words (to stop, type the word done): ";
	const char* const	k_szDone = "done";
	const unsigned	k_uSize = 64;
	int	cntWord = -1;
	char	word[k_uSize];
	do {
		++cntWord;
		cin >> word;
	} while (strcmp(k_szDone, word));
	cout << "You entered a total of " << cntWord << " words." << endl;
		
	cout << endl;
	return (0);
} 
