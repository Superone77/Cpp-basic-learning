#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int
main (void) 
{     
	unsigned	lstMonthlySales[12];
	const string	k_months[] = {"1月", "2月", "3月", "4月", "5月", "6月", "7月", "8月", "9月", "10月", "11月", "12月"};
	cout << "输入每月销售量。" << endl;
	for (int i = 0; i < 12; ++i) {
		cout << k_months[i] << "：";
		cin >> lstMonthlySales[i];
	}

	unsigned	uSum = 0;
	for (int i = 0; i < 12; ++i) {
		uSum += lstMonthlySales[i];
	}
	cout << "全年销售总量" << uSum << endl;

	
	cout << endl;
	return (0);
} 
