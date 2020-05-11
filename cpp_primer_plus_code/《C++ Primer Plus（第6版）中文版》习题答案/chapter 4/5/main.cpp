#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

struct TCandyBar
{
	string	name;
	double	weight;
	double	calories;
};

int
main (void) 
{     
	TCandyBar	snack = {"Mocha Munch", 2.3, 350};
	cout << snack.name << "\n" << snack.weight << "\n" << snack.calories << endl; 
	
	cout << endl;
	return (0);
} 
