#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int
main (void) 
{     
	cout << "输入行驶公里数（公里）和耗油量（升）：";
	double	distance, petrol;
	cin >> distance >> petrol;
	cout << "油耗为" << 100 * petrol / distance << "（升/100公里）";
	
	cout << endl;
	return (0);
} 
