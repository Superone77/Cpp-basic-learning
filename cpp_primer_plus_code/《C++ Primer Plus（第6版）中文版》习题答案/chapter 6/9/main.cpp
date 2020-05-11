#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct TDonor {
	string	name;
	double	amount;
};

int
main (void) 
{     
	ifstream	ifs("C:\\Users\\Superone77\\Desktop\\6\\9\\donation.txt");
	
	unsigned	num_donor;
	ifs >> num_donor;
	TDonor* const	p_donor = new TDonor [num_donor];	

	for (unsigned i = 0; i < num_donor; ++i) {
		ifs.get();
		getline(ifs, p_donor[i].name);
		ifs >> p_donor[i].amount;
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
