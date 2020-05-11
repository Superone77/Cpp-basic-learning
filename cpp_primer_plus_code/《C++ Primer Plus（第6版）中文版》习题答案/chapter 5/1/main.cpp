#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int
main (void) 
{     
	int	nLowerBound, nUpperBound;
	cout << "输入区间：";
	cin >> nLowerBound >> nUpperBound;

	int	nSum = 0;
	for (int i = nLowerBound; i <= nUpperBound; ++i) {
		nSum += i;
	}

	cout << "[" << nLowerBound << ", " << nUpperBound << "]区间总和为" << nSum;
	
	cout << endl;
	return (0);
} 
