#include <iostream>
#include <array>

using std::cout;
using std::endl;
using std::cin;
using std::array;

int
main (void) 
{     
	const unsigned	k_times = 3;
	array<unsigned, k_times>	dash_array;
	cout << "输入三次40米短跑成绩：";
	cin  >> dash_array[0] >> dash_array[1] >> dash_array[2];

	cout << "共计输入" << k_times << "笔短跑成绩，平均分为" << (dash_array[0] + dash_array[1] + dash_array[2]) / 3 << endl;
	
	cout << endl;
	return (0);
} 
