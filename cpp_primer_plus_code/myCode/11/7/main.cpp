#include <iostream>
#include "TComplex.h"

using namespace std;
using namespace n_complex;

int main()
{
	TComplex a(3.0, 4.0);	// initialize to (3,4i) Programming Exercises
	TComplex c;
	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c)
	{
		cout << "c is " << c << '\n';
		cout << "complex conjugate is " << ~c << '\n';
		cout << "a is " << a << "\n";
		cout << "a + c is " << a + c << '\n';
		cout << "a - c is " << a - c << '\n';
		cout << "a * c is " << a * c << '\n';
		cout << "2 * c is " << 2 * c << '\n';
		cout << "Enter a complex number (q to quit):\n";
	}
	cout << "Done!\n";

	return 0;
}
