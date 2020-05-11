#include <iostream>

double
to_fahrenheit (double celsius)
{
	return (1.8 * celsius + 32.0);
}

int
main (void) 
{     
	using std::cout;
	using std::cin;
	using std::endl;

	double	celsius;
	cout << "Please enter a Celsius value: ";
	cin >> celsius;
	cout << celsius << " degrees Celsius is " << to_fahrenheit(celsius) << " degrees Fahrenheit.";
	
	cout << endl;
	return (0);
} 
