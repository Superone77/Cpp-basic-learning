#include <iostream>
#include <array>

using namespace std;

template<typename T>
const T&
max5 (const array<T, 5>& arr)
{
	unsigned	idxMax = 0;
	for (unsigned i = 0; i < 5; ++i) {
		if (arr[i] > arr[idxMax]) {
			idxMax = i;
		}
	}

	return (arr[idxMax]);
}

int
main (void)
{
	array<int, 5>	iArray = {{32, -1, 99, 256, 9}};
	for (const auto& e : iArray) {
		cout << e << ' ';
	}
	cout << " ----max: " << max5(iArray) << endl;

	array<double, 5>	dArray = {{-3.2, 221.22, 9.9, 0, 1}};
	for (const auto& e : dArray) {
		cout << e << ' ';
	}
	cout << " ----max: " << max5(dArray);


	cout << endl;
	return 0;
}
