#include<iostream>
#include<stdio.h>
int fill_array(int grade[], int limit);
void show_array(const int grade[], int n);
float average(const int grade[], int n);
const int Size = 10;

using namespace std;

int main()
{
	int grade[Size];
	int i = fill_array(grade, Size);
	show_array(grade, i);
	
	if (i != 0) {
		float a = average(grade, i);

		cout << "the average of the grade is " << a<<endl;
	}
	

	cout << "Done!";
	cout << endl;

	system("pause");
	return 0;
}

int fill_array(int grade[], int limit)
{
	cout << "Please enter the golf grade,and end with no number" << endl;

	int temp;

	int i;

	for ( i = 0; i < limit; i++) {
		cout << i + 1 << " :";
		cin >> temp;
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Enter is finished. \n";
			break;
		}
		else if (temp < 0)
			break;
		grade[i] = temp;
	}
	return i;
}
void show_array(const int grade[], int n)
{
	cout << "The golfgrade are: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << grade[i] << ", ";
	}

	cout << endl;
}
float average(const int grade[], int n)
{
	float temp;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + grade[i];
	}
	temp = 1.0*sum / n;

	return temp;
}