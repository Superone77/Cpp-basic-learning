#include <iostream>
#include<stdio.h>
#include"sale.h"

using namespace std;

int main(void)
{
	using namespace SALES;

	Sales salesBook;
	salesBook.showSales();

	Sales salesPen;
	salesPen.showSales();

	cout << endl;
	system("pause");
	return 0;

}