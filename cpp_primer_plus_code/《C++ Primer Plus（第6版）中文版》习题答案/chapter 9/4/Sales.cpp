#include <iostream>
#include "Sales.h"

namespace SALES
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	static double
	calcAverage (double arr[], unsigned arrSize)
	{
		double	sum = 0;
		for (unsigned i = 0; i < arrSize; ++i) {
			sum += arr[i];
		}

		return (sum / arrSize);
	}

	static double
	calcMax (double arr[], unsigned arrSize)
	{
		unsigned	idxMax = 0;
		for (unsigned i = 0; i < arrSize; ++i) {
			if (arr[i] > arr[idxMax]) {
				idxMax = i;
			}
		}

		return (arr[idxMax]);
	}

	static double
	calcMin (double arr[], unsigned arrSize)
	{
		unsigned	idxMin = 0;
		for (unsigned i = 0; i < arrSize; ++i) {
			if (arr[i] < arr[idxMin]) {
				idxMin = i;
			}
		}

		return (arr[idxMin]);
	}

	void
	setSales (Sales & s, const double ar[], int n)
	{
		unsigned	times = n < QUARTERS ? (unsigned)n : QUARTERS;
		for (unsigned i = 0; i < times; ++i) {
			s.sales[i] = ar[i];
		}
		for (unsigned i = times; i < QUARTERS; ++i) {
			s.sales[i] = 0;
		}

		s.average = calcAverage(s.sales, times);
		s.max = calcMax(s.sales, times);
		s.min = calcMin(s.sales, times);
	}

	void
	setSales(Sales & s)
	{
		cout << "输入" << QUARTERS << "个销售记录：";
		unsigned	times = QUARTERS;
		double	arr[QUARTERS] = {0};
		for (unsigned i = 0; i < QUARTERS; ++i) {
			cin >> arr[i];
			if (!cin) {
				times = i;
				break;
			}
		}

		setSales(s, arr, QUARTERS);

		s.average = calcAverage(s.sales, times);
		s.max = calcMax(s.sales, times);
		s.min = calcMin(s.sales, times);
	}

	void
	showSales (const Sales & s)
	{
		cout << "sales: ";
		for (const auto& e : s.sales) {
			cout << e << ' ';
		}
		cout << endl;
		cout << "average: " << s.average << endl;
		cout << "max: " << s.max << endl;
		cout << "min: " << s.min << endl;
	}
}

