#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
const T&
maxn (const T arr[], unsigned n)
{
	unsigned	idxMax = 0;
	for (unsigned i = 0; i < n; ++i) {
		if (arr[i] > arr[idxMax]) {
			idxMax = i;
		}
	}

	return (arr[idxMax]);
}

const char*
maxn (const char* arr[], unsigned n)
{
	unsigned	idxMax = 0;
	for (unsigned i = 0; i < n; ++i) {
		if (strlen(arr[i]) > strlen(arr[idxMax])) {
			idxMax = i;
		}
	}

	return (arr[idxMax]);
}

int
main (void)
{
	int	iArray[] = {32, -1, 99, 0, 256, 9};
	for (const auto& e : iArray) {
		cout << e << ' ';
	}
	cout << " ----max: " << maxn(iArray, sizeof(iArray)/sizeof(iArray[0])) << endl;

	double	dArray[] = {-3.2, 221.22, 9.9, 0, 1};
	for (const auto& e : dArray) {
		cout << e << ' ';
	}
	cout << " ----max: " << maxn(dArray, sizeof(dArray)/sizeof(dArray[0])) << endl;

	const char*	szArray[] = {	"aa aa",
								"dddddddddddd",
								"",
								"fffffff ffff",
								"kk kk",
	};
	for (const auto& e : szArray) {
		cout << '\"' << e << '\"' << ' ';
	}
	cout << " ----max: " << '\"' << maxn(szArray, sizeof(szArray)/sizeof(szArray[0])) << '\"' << endl;


	cout << endl;
	return 0;
}
