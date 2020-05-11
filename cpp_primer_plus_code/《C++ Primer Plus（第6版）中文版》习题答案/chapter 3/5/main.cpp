#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int
main (void) 
{     
	long long	worldPopulation, usaPopulation;
	cout << "Enter the world's population: ";
	cin >> worldPopulation;
	cout << "Enter the population of the US: ";
	cin >> usaPopulation;
	cout << "The population of the US is " << 100.0 * usaPopulation / worldPopulation << "% of the world population.";
	
	cout << endl;
	return (0);
} 
