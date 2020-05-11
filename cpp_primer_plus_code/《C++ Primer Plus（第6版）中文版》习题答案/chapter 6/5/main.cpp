#include <iostream>

int
main (void) 
{     
	using namespace std;

	// |-----|----------|--------------------|-----...
	//   0% (5K)  10% (1.5W)      15%      (3.5W)  20%

	double	tvarp;
	while (cin >> tvarp && tvarp >= 0) {
		double	arrFourSection[4] = {5000, 10000, 20000};

		if (tvarp <= 5000) {
			arrFourSection[0] = tvarp;
			arrFourSection[1] = arrFourSection[2] = arrFourSection[3] = 0;
		} else if ((tvarp -= 5000) <= 10000) {
			arrFourSection[1] = tvarp;
			arrFourSection[2] = arrFourSection[3] = 0;
		} else if ((tvarp -= 10000) <= 20000) {
			arrFourSection[2] = tvarp;
			arrFourSection[3] = 0;
		} else {
			arrFourSection[3] = tvarp - 20000;
		}

		cout << "税收明细如下：" 
			 << arrFourSection[0] << " * 0% + " << arrFourSection[1] << " * 10% + "
			 << arrFourSection[2] << " * 15% + " << arrFourSection[3] << " * 20% "
			 << " = " << arrFourSection[0] * 0 + arrFourSection[1] * 0.1 + arrFourSection[2] * 0.15 + arrFourSection[3] * 0.2
			 << endl;
	}



	cout << endl;
	return (0);
} 
