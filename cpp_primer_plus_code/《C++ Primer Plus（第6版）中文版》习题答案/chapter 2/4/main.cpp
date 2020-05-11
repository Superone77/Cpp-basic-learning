#include <iostream>

int
main (void) 
{     

	using std::cout;
	using std::cin;
	using std::endl;

	int	age;
	cout << "Enter your age: ";
	cin >> age;
	cout << "Your age in months is " << age * 12 << endl;
	
	cout << endl;
	return (0);
} 
