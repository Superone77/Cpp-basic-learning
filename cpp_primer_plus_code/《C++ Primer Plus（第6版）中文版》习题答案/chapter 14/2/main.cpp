#include <iostream>
#include "Wine.h"

int main ( void )
{
	using std::cin;
	using std::cout;
	using std::endl;
	using namespace n_wine;
	

	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	unsigned yrs;
	cin >> yrs;
	Wine holding(lab, yrs); // store label, years, give arrays yrs elements
	holding.getBottles();	// solicit input for year, bottle count
	holding.show();	// display object contents

	const unsigned YRS = 3;
	unsigned y[YRS] = {1993, 1995, 1998};
	unsigned b[YRS] = { 48, 60, 72};
	// create new object, initialize using data in arrays y and b
	Wine more("Gushing Grape Red",YRS, y, b);
	more.show();
	cout << "Total bottles for " << more.getLabel() // use Label() method
		<< ": " << more.sum() << endl;	// use sum() method
	cout << "Bye\n";

	return 0;
}
