#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int
main (void) 
{     
	unsigned	lstMonthlySales[3][12];
	const string	k_months[] = {"1月", "2月", "3月", "4月", "5月", "6月", "7月", "8月", "9月", "10月", "11月", "12月"};
	for (int i = 0; i < 3; ++i) {
		cout << "输入第" << i + 1 << "年每月销售量。"<< endl;
		for (int j = 0; j < 12; ++j) {
			cout << k_months[j] << "：";
			cin >> lstMonthlySales[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < 3; ++i) {
		unsigned	uSum = 0;
		for (int j = 0; j < 12; ++j) {
			uSum += lstMonthlySales[i][j];
		}
		cout << "第" << i + 1 << "年销售总量" << uSum << endl;
	}

	
	cout << endl;
	return (0);
} 
