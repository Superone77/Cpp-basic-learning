#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename T>
int
reduce (T ar[], int n)
{
	sort(ar, ar+n);
	const auto	iter_end = unique(ar, ar+n);
	return (distance(ar, iter_end));
}

int
main (void)
{
	long	ar[] = {13, 22, 1, 43, 1, 13, 22, 13};
	copy(ar, ar + sizeof(ar)/sizeof(ar[0]), ostream_iterator<int>(cout, " "));
	cout << endl;
	int		ar_size = reduce(ar, sizeof(ar)/sizeof(ar[0]));
	cout << "剔重后剩下" << ar_size << "个元素：";
	copy(ar, ar + ar_size, ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	string	ar_str[] = {"hello", "the", "who", "hello", "who"};
	copy(ar_str, ar_str + sizeof(ar_str)/sizeof(ar_str[0]), ostream_iterator<string>(cout, " "));
	cout << endl;
	int		ar_str_size = reduce(ar_str, sizeof(ar_str)/sizeof(ar_str[0]));
	cout << "剔重后剩下" << ar_str_size << "个元素：";
	copy(ar_str, ar_str + ar_str_size, ostream_iterator<string>(cout, " "));
	cout << endl;

	return (EXIT_SUCCESS);
}
