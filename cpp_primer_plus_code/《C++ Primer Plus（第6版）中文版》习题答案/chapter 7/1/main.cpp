#include <iostream>

using namespace std;

double
calc_harmonic_mean (unsigned x, unsigned y)
{
	return (2.0 * x * y / (x + y));
}

int
main (void) 
{     
	while (true) {
		unsigned	x, y;
		cout << "输入一对正整数，计算其调和平均数（0退出）：";
		cin >> x >> y;
		if (0 == x || 0 == y) {
			cout << "再会" << endl;
			break;
		}
		cout << "--> " << calc_harmonic_mean(x, y) << endl;
	}

	cout << endl;
	return (0);
} 
