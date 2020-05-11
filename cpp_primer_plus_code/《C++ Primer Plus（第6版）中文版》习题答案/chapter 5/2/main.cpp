#include <iostream>
#include <array>

using std::cout;
using std::endl;
using std::cin;
using std::array;

int
main (void) 
{     
	const unsigned	k_uSize = 101;
	array<long double, k_uSize>	factorials;
	factorials[1] = factorials[0] = 1.0L;

	for (unsigned i = 2; i < k_uSize; ++i) {
		factorials[i] = i * factorials[i-1];
	}

	for (unsigned i = 0; i < k_uSize; ++i) {
		cout << i << "! = "<< factorials[i] << endl;
	}
	
	cout << endl;
	return (0);
} 
