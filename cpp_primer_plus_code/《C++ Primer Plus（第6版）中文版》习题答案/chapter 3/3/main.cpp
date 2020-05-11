#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int
main (void) 
{     
	int	degrees, minutes, seconds;
	cout << "Enter a latitude in degrees, minutes, and seconds.";
	cout << "First, enter the degrees: ";
	cin >> degrees;
	cout << "Next, enter the minutes of arc: ";
	cin >> minutes;
	cout << "Finally, enter the seconds of arc: ";
	cin >> seconds;

	const int	k_factor = 60;
	cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = "
		 << degrees + 1.0*minutes/k_factor + 1.0*seconds/k_factor/k_factor;
	
	cout << endl;
	return (0);
} 
