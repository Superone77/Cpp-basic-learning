#include<iostream>
#include<stdio.h>

long double probability(unsigned numbers, unsigned picks);

using namespace std;

int main()
{
	int x1 = 47, x2 = 27;
	int y1 = 5, y2 = 1;
	long double n1, n2;
	n1 = probability(x1, y1);
	n2 = probability(x2, y2);
	
	cout << "You have one chance in " << n1 * n2 << " of winning" << endl;

	cout << "Done.";
	cout << endl;

	system("pause");
	return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
	long double fuck = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		fuck = fuck * n / p;
	return fuck;
}