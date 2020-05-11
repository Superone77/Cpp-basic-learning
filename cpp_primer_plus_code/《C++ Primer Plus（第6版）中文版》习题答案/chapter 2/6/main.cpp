#include <iostream>

double
to_astronomical (double lightYear)
{
	return (lightYear * 63240);
}

int
main (void) 
{     

	using std::cout;
	using std::cin;
	using std::endl;

	double	lightYear;
	cout << "Enter the number of light years: ";
	cin >> lightYear;
	cout << lightYear << " light years = " << to_astronomical(lightYear) << " astronomical units." << endl;
	
	cout << endl;
	return (0);
} 
