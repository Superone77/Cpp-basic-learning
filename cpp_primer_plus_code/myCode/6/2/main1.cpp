#include <iostream>
#include<cctype>
#include<stdlib.h>

using namespace std;

int main()
{

	const int ArSize = 10;
	double donation[ArSize];

	cout << "enter maximal 10 number:" << endl;
	
	int i = 0;
	int average = 0;
	int sum = 0;
	while (i<ArSize && cin >> donation[i]) {
		sum = sum + donation[i];
		i++;
	}
	
	average = sum / i;

	int number = 0;
	
	for (int j = 0; j < i; j++) {
		if (donation[j] > average) {
			number++;
		}
	}
	
	cout << "average of these numbers is " << average << endl;
	cout << number << " number are bigger than the average.";
	cout << endl;

	system("pause");

	return 0;
}