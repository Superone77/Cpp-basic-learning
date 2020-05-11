//stonewt test

#include<stdio.h>
#include"stonewt.h"
#include<iostream>

using namespace std;
using namespace n_stonewt;

int main()
{
	Stonewt fuck1(2.0, Stonewt::GRAD);
	Stonewt fuck2(3.0);
	Stonewt fuck3(1, 2.0);

	cout << fuck1+fuck2 << endl << fuck2-fuck3 << endl << fuck3*3.0 << endl;
	system("pause");

	return 0;

}