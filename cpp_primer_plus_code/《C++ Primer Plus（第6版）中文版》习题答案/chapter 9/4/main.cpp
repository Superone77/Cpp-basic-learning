#include <iostream>
#include "Sales.h"

using namespace std;


int
main (void) 
{     
	using namespace SALES;

	Sales	salesBook;
	double	salesLst[] = {12.2, 11.16, 10.61, 16.24, 11.53};
	setSales(salesBook, salesLst, sizeof(salesLst)/sizeof(salesLst[0]));
	showSales(salesBook);

	Sales	salesPen;
	setSales(salesPen);
	showSales(salesPen);


	cout << endl;
	return	(0);
} 
