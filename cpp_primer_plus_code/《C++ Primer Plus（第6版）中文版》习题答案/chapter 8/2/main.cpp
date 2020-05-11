#include <iostream>

using namespace std;

struct TCandyBar
{
	string	strBrand;
	double	weight;
	int		calories;
};

void
set_candybar (TCandyBar& candbar, const char* strBrand = "Millennium Munch", double weight = 2.85, int calories = 350)
{
	candbar.strBrand = strBrand;
	candbar.weight = weight;
	candbar.calories = calories;
}

void
show_candybar (const TCandyBar& candbar)
{
	cout << candbar.strBrand << '\t' << candbar.weight << '\t' << candbar.calories << endl;
}

int
main (void) 
{     
	TCandyBar	candbar1, candbar2;
	set_candybar(candbar1);
	show_candybar(candbar1);
	set_candybar(candbar2, "yang yang", 3.11, 256);
	show_candybar(candbar2);

	cout << endl;
	return (0);
} 
