#include<iostream>
#include<stdio.h>

long fuck(int x);

using namespace std;

int main()
{
	int x;
	cout << "Please enter number to check the program" << endl;
	
	while (cin >> x&&x>=0) {
		cout << "result is " << fuck(x) << endl;
	}

	cout << "Done.";
	cout << endl;

	system("pause");
	return 0;
}

long fuck(int x)
{
	long temp;
	if (x != 0)
		temp = x * fuck(x - 1);
	else
		temp = 1;


	return temp;
}