#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int
main (void) 
{     
	const char	k_ch1 = '.';
	const char	k_ch2 = '*';

	cout << "Enter number of rows: ";
	unsigned	uRows;
	cin >> uRows;

	char*	pCharLst = new char [uRows * uRows];

	for (unsigned i = 0; i < uRows; ++i) {
		for (unsigned j = 0; j < uRows-i-1; ++j) {
			pCharLst[i*uRows + j] = k_ch1;
		}
		for (unsigned j = uRows-i-1; j < uRows; ++j) {
			pCharLst[i*uRows + j] = k_ch2;
		}
	}

	for (unsigned i = 0; i < uRows*uRows; ++i) {
		cout << pCharLst[i];

		if (0 == (i+1) % uRows) {
			cout << endl;
		}
	}

	delete [] pCharLst;
	pCharLst = NULL;
		
	cout << endl;
	return (0);
} 
