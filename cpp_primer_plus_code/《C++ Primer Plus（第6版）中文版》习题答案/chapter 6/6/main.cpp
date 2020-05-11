#include <iostream>
#include <string>

using namespace std;

struct TDonor {
	string	name;
	double	amount;
};

int
main (void) 
{     
	cout << "输入捐赠人数：";
	unsigned	num_donor;
	cin >> num_donor;
	TDonor* const	p_donor = new TDonor [num_donor];	

	for (unsigned i = 0; i < num_donor; ++i) {
		cout << "输入捐赠人姓名：";
		cin >> p_donor[i].name;
		cout << "输入捐赠金额：";
		cin >> p_donor[i].amount;
	}

	cout << "荣誉捐赠者：" << endl;
	for (unsigned i = 0; i < num_donor; ++i) {
		if (p_donor[i].amount >= 10000) {
			cout << p_donor[i].name << endl;
		}
	}

	cout << "普通捐赠者：" << endl;
	for (unsigned i = 0; i < num_donor; ++i) {
		if (p_donor[i].amount < 10000) {
			cout << p_donor[i].name << endl;
		}
	}

	delete [] p_donor;


	cout << endl;
	return (0);
} 
