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
	TCandyBar	snack[] =	{	{"Mocha Munch", 2.3, 350},
								{"阿尔卑斯", 6.3, 310},
								{"优の良品", 2.1, 291}	};
	cout << snack[0].name << "\t" << snack[0].weight << "\t" << snack[0].calories << endl; 
	cout << snack[1].name << "\t" << snack[1].weight << "\t" << snack[1].calories << endl; 
	cout << snack[2].name << "\t" << snack[2].weight << "\t" << snack[2].calories << endl; 
	
	cout << endl;
	return (0);
} 
