#include<iostream>
#include<stdio.h>

using namespace std;

const int Seasons = 4;

const char*fuck[] = { "Spring","Summer","Autumn","Winter"  };

struct jiba
{
	double arr[Seasons];
};

void fill(jiba* shabi);
void show(jiba ruozhi);

int main()
{
	jiba expense;
	fill(&expense);
	show(expense);
	system("pause");
	return 0;
}


void fill(jiba* shabi)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter" << fuck[i] << " expenses: ";
		cin >> shabi->arr[i];
	}
}

void show(jiba ruozhi)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << fuck[i] << " : $" << ruozhi.arr[i] << endl;
		total += ruozhi.arr[i];
	}
	cout << "Total Expenses: $" << total << endl;
	
}


