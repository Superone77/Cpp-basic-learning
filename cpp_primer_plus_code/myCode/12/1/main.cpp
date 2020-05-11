#include<iostream>
#include<stdio.h>
#include"cow.h"

using namespace std;

int main()
{
	char cowName[20];
	char *cowHobby = new char[20];
	double cowWeight;
	cout << "Enter the name: ";
	cin >> cowName;
	cout << "Enter the hobby: ";
	cin >> cowHobby;
	cout << "Enter the weight: ";
	cin >> cowWeight;
	Cow cow1;
	Cow cow2(cowName, cowHobby, cowWeight);
	Cow cow3 = cow2;
	cow1.ShowCow();
	cow2.ShowCow();
	cow3.ShowCow();

	system("pause");
	return 0;


}