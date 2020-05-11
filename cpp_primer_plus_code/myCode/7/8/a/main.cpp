#include<iostream>
#include<stdio.h>

using namespace std;

const int Seasons = 4;

const char*fuck[] = { "Spring","Summer","Autumn","Winter"  };

void fill(double shabi[]);
void show(double ruozhi[]);

int main()
{
	double expense[Seasons];
	fill(expense);
	show(expense);
	system("pause");
	return 0;
}


void fill(double shabi[])
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter" << fuck[i] << " expenses: ";
		cin >> shabi[i];
	}
}

void show(double ruozhi[])
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << fuck[i] << " : $" << ruozhi[i] << endl;
		total += ruozhi[i];
	}
	cout << "Total Expenses: $" << total << endl;
	
}


