#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int
main (void) 
{     
	const long	k_factorMinuteToSecond = 60;
	const long	k_factorHourToMinute = 60;
	const long	k_factorDayToHour = 24;

	cout << "Enter the number of seconds: ";

	long	secondsTotal;
	cin >> secondsTotal;
	long	seconds = secondsTotal % k_factorMinuteToSecond;

	long	minutesTotal = secondsTotal / k_factorMinuteToSecond;
	long	minutes = minutesTotal % k_factorHourToMinute;

	long	hoursTotal = minutesTotal / k_factorHourToMinute;
	long	hours = hoursTotal % k_factorDayToHour;

	long	days = hoursTotal / k_factorDayToHour;

	cout << secondsTotal <<  " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";
	
	cout << endl;
	return (0);
} 
