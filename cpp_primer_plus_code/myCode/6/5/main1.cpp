#include <iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	const float taxPercent1 = 0.1;
	const float taxPercent2 = 0.15;
	const float taxPercent3 = 0.2;
	long income;
	long tax;

	cout << "Enter your income: ";

	while (cin >> income && income > 0) {
		if (income < 5000) {
			tax = 0;
		}
		else if (income < 15000 && income>5000) {
			tax = (income - 5000)*taxPercent1;
		}
		else if (income < 35000 && income>15000) {
			tax = (income - 1500)*taxPercent2 + 10000 * taxPercent1;
		}
		else tax = (income - 35000)*taxPercent3 + 20000 * taxPercent2 + 10000 * taxPercent1;
		cout << "your tax is " << tax << " tvarps" << endl;
	}

	cout << "Bye!" << endl;
	
	


	system("pause");

	return 0;
}