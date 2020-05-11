#include <iostream>
#include <limits>
#include "Sales.h"

namespace SALES
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	Sales::Sales (double arr[], int n)
	{
		unsigned	times = n < QUARTERS ? (unsigned)n : QUARTERS;
		for (unsigned i = 0; i < times; ++i) {
			sales[i] = arr[i];
		}
		for (unsigned i = times; i < QUARTERS; ++i) {
			sales[i] = 0;
		}

		size = times;
		average = calcAverage();
		max = calcMax();
		min = calcMin();
	}

	void
	Sales::setSales(void)
	{
		cout << "输入" << QUARTERS << "个销售记录：";
		size = QUARTERS;
		for (unsigned i = 0; i < QUARTERS; ++i) {
			cin >> sales[i];
			if (!cin) {
				size = i;
				break;
			}
		}
		for (unsigned i = (unsigned)size; i < QUARTERS; ++i) {
			sales[i] = 0;
		}

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		average = calcAverage();
		max = calcMax();
		min = calcMin();
	}

	double
	Sales::calcAverage (void) const
	{
		double	sum = 0;
		for (unsigned i = 0; i < size; ++i) {
			sum += sales[i];
		}

		return (sum / size);
	}

	double
	Sales::calcMax (void) const
	{
		unsigned	idxMax = 0;
		for (unsigned i = 0; i < size; ++i) {
			if (sales[i] > sales[idxMax]) {
				idxMax = i;
			}
		}

		return (sales[idxMax]);
	}

	double
	Sales::calcMin (void) const
	{
		unsigned	idxMin = 0;
		for (unsigned i = 0; i < size; ++i) {
			if (sales[i] < sales[idxMin]) {
				idxMin = i;
			}
		}

		return (sales[idxMin]);
	}

	void
	Sales::showSales (void) const
	{
		cout << "sales: ";
		for (const auto& e : sales) {
			cout << e << ' ';
		}
		cout << endl;
		cout << "average: " << average << endl;
		cout << "max: " << max << endl;
		cout << "min: " << min << endl;
	}
}

