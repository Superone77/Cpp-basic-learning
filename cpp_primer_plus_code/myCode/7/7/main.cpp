#include<iostream>
#include<stdio.h>

const int Max = 5;

int fill_array(double*pBeg, const double*pEnd)
{
	using namespace std;
	double temp;
	int i = 0;
	while (pBeg < pEnd)
	{
		cout << "Enter value #" << i++ << ":";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input;input process terminated.\n";
			break;
		}
		else if (temp < 0)
			break;
		*pBeg = temp;
		++pBeg;

	}
	return i;
}

void show_array(const double* pBeg, const double*pEnd)
{
	using namespace std;
	for (int i = 0; pBeg < pEnd; ++pBeg)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << *pBeg << endl;
	}
}

void revalue(double r, double*pBeg, const double*pEnd)
{
	while (pBeg < pEnd)
	{
		*pBeg *= r;
		++pBeg;
	}
}

int main()
{
	using namespace std;
	double properties[Max];
	int size = fill_array(properties, properties + Max);
	show_array(properties, properties + size);
	if (size > 0)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input;Please enter a number: ";
		}
		revalue(factor, properties, properties + size);
		show_array(properties, properties + size);
	}

	cout << "Done\n";
	system("pause");
	return 0;
}
