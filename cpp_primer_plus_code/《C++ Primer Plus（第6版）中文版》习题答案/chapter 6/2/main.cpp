#include <iostream>

int
main (void) 
{     
	using namespace std;

	const unsigned	k_size = 10;
	double	arrDonation[k_size];
	double	dSum = 0;
	unsigned	cntDonation = 0;
	while (cntDonation < k_size && cin >> arrDonation[cntDonation]) {
		dSum += arrDonation[cntDonation++];
	}

	double	dAverage = dSum / cntDonation;
	unsigned	cntLargerAverage = 0;
	for (unsigned i = 0; i < k_size; ++i) {
		if (arrDonation[i] > dAverage) {
			++cntLargerAverage;
		}
	}

	cout << "平均值为" << dAverage << "，超过平均值的有" << cntLargerAverage << "个。" << endl;


	cout << endl;
	return (0);
} 
