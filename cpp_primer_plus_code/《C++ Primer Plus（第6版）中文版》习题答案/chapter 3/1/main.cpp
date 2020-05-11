#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int
main (void) 
{     
	const int	k_factorFeetToInch = 12;	// 1英尺 = 12英寸
	int	inches;
	cout << "输入身高，__英寸：";
	cin >> inches;
	cout << "也就" << inches / k_factorFeetToInch << "英尺又" << inches % k_factorFeetToInch << "英寸";
	
	cout << endl;
	return (0);
} 
