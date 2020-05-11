#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void
show_time (int hour, int minute)
{
	cout << "Time: " << hour << ":" << minute << endl;
}

int
main (void) 
{     
	int	hour, minute;
	cout << "Enter the number of hours: ";
	cin >> hour;
	cout << "Enter the number of minutes: ";
	cin >> minute;
	show_time(hour, minute);
	
	cout << endl;
	return (0);
} 
