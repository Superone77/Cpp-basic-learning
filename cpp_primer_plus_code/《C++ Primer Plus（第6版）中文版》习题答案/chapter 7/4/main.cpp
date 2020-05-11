#include <iostream>

using namespace std;

long double
calc_probability (unsigned numbers, unsigned picks) 
{
	long double	probability = 1.0;
	while (picks > 0) {
		probability *= 1.0 * numbers / picks;
		--numbers;
		--picks;
	}

	return (probability);
}

int
main (void) 
{     
	long double	probability = calc_probability(47, 5) * calc_probability(27, 1);
	cout << "你有" << fixed << probability << "分子一的几率中奖";

	cout << endl;
	return (0);
} 
