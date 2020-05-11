#include <iostream>

using namespace std;

unsigned long long
calc_factorial_less_equ_to_20 (unsigned long long n)
{
	return ((0 == n) ? 1 : n * calc_factorial_less_equ_to_20(n-1));
}

int
main (void) 
{     
	while (true) {
		cout << "输入一个不超过20的非负整数：";
		unsigned long long n;
		cin >> n;
		if (!cin || n > 20) {	// 采用递归实现的阶乘算法最多只能计算20以内的阶乘，否则将导致溢出
			break;
		}
		cout << n << "的阶乘为：" << calc_factorial_less_equ_to_20(n) << endl;
	}

	cout << endl;
	return (0);
} 
