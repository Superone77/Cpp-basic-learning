#include<iostream>
#include<stdio.h>

int Fill_array(double ar[], int limit);
void Show_array(double ar[], int size);
void Reverse_array(double ar[], int size);
const int k = 10;

using namespace std;

int main()
{
	double fuck[k];
	int n = Fill_array(fuck, k);
	Show_array(fuck, n);
	Reverse_array(fuck, n);

	for (int i = 0; i < n; i++)
	{
		cout << fuck[i] << " ";
	}

	cout << endl;
	double temp;
	temp = fuck[0];
	fuck[0] = fuck[n - 1];
	fuck[n - 1] = temp;

	for (int i = 0; i < n; i++)
	{
		cout << fuck[i] << " ";
	}
	cout << endl;

	cout << "Done.";
	cout << endl;

	system("pause");
	return 0;
}


int Fill_array(double ar[], int limit)
{
	double temp;
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << "Enter the numbers: " << endl;
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "End.\n";
			break;
		}
		else
			ar[i] = temp;
	}

		
		return i;
	

	
}
void Show_array(double ar[], int size)
{
	for (int i = 0; i < size; i++)
		cout << ar[i] << ' ';
	cout << endl;
}
void Reverse_array(double ar[], int size)
{
	double temp;
	for (int i = 0; i < size / 2; i++) {
		temp = ar[i];
		ar[i] = ar[size - i-1];
		ar[size - i-1] = temp;
	}
}
