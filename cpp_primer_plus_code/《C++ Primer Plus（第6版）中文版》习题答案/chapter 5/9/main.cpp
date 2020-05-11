#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int
main (void) 
{     
	cout << "Enter words (to stop, type the word done): ";
	const string	k_strDone = "done";
	int	cntWord = -1;
	string	strWord;
	do {
		++cntWord;
		cin >> strWord;
	} while (k_strDone != strWord);
	cout << "You entered a total of " << cntWord << " words." << endl;
		
	cout << endl;
	return (0);
} 
