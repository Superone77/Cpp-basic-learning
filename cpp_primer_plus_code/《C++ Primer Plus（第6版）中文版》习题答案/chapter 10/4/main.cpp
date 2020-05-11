#include <iostream>
#include "Sales.h"

using namespace std;

int
main (void) 
{     
	using namespace SALES;

	Sales	salesBook;
	salesBook.showSales();

	Sales	salesPen;
	salesPen.showSales();


	cout << endl;
	return	(0);
} 
