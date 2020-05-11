#include <iostream>

int
main (void) 
{     

	using std::cout;
	using std::cin;
	using std::endl;

	double	furlongs;
	cout << "输入一段距离（单位弗隆）：" << endl;
	cin >> furlongs;
	cout << furlongs << "(弗隆) 等于 " << furlongs * 220 << "(码)" << endl;
	
	cout << endl;
	return (0);
} 
