#include <iostream>
#include "TTime.h"

using namespace std;
using namespace n_time;


int
main (void) 
{     
	TTime	time1(1, 65, 60);
	cout << time1 << endl;
	TTime	time2(8, 25);
	cout << time2 << endl;
	cout << time1 + time2 << endl;
	cout << time1 - time2 << endl;

	cout << "=========" << endl;
	time1.add(1, 55, 30);
	cout << time1 << endl;

	cout << "=========" << endl;
	time1.reset(32, 64, 128);
	cout << time1 << endl;

	cout << "=========" << endl;
	cout << time1 * 1.5  << endl;
	cout << 1.5 * time1 << endl;


	cout << endl;
	return (0);
} 
