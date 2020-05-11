#include<iostream>
#include<stdio.h>

float tAverage(float x, float y);

int main()
{
	using namespace std;

	float x = 1.0;
	float y = 1.0;
	float z;

	while (x != 0 && y != 0) {
		cout << "Enter first number:";
		cin >> x;
		cout << "Enter second number: ";
		cin >> y;
		z = tAverage(x, y);
		cout << z << " is their tiaohepingjunshu!" << endl;

	}
	cout << "Done!";
	cout << endl;

	system("pause");
	return 0;
}

float tAverage(float x, float y)
{
	using namespace std;
	float temp;
	temp = 2.0*x*y / (x + y);
	
	return temp;
}