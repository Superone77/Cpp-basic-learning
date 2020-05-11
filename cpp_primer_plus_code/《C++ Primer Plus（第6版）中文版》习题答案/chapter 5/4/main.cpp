#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int
main (void) 
{     
	const double	k_dSimpleInterest = 0.1;
	const double	k_dCompoundInterest = 0.05;
	const double	k_dDaphneBase = 100;
	const double	k_dCleoBase = 100;

	unsigned	uYears = 0;
	double		dDaphneTotal = k_dDaphneBase, dCleoTotal = k_dCleoBase;
	do {
		dDaphneTotal += k_dDaphneBase * k_dSimpleInterest;
		dCleoTotal += dCleoTotal * k_dCompoundInterest;

		++uYears;

		cout << uYears << ": " << dDaphneTotal << "\t" << dCleoTotal << endl;
	} while (dDaphneTotal >= dCleoTotal);

	cout << endl;
	cout << uYears << "年后，" << "Cleo的财富将超过Daphne，前者将达到$" << dCleoTotal << "、后者$" << dDaphneTotal << endl;
	
	cout << endl;
	return (0);
} 
