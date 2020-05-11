#include <string>
#include<iostream>
#include"golf.h"
#include<stdio.h>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	const unsigned k_size = 4;
	golf golfers[k_size];
	unsigned numGolfers = 0;
	while (numGolfers < k_size&&golfers[numGolfers].setgolf())
	{
		++numGolfers;
	}
	for (unsigned i = 0; i < numGolfers; ++i)
	{
		golfers[i].showgolf();
		cout << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}