#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int
main (void) 
{     
	const int	k_nEndFlag = 0;
	int			nSum = 0;
	int			nTmp;
	cout << "输入数字：";
	do {
		cin >> nTmp;
		nSum += nTmp;
	} while (k_nEndFlag != nTmp);

	cout << "总和为：" << nSum;
	
	
	cout << endl;
	return (0);
} 
