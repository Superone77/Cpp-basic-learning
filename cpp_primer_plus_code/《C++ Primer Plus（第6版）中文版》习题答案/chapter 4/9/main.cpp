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
	const unsigned	k_candybar_num = 3;
	TCandyBar*	candybar_list = new TCandyBar [k_candybar_num];

	candybar_list[0].name = "Mocha Munch";
	candybar_list[0].weight = 2.3;
	candybar_list[0].calories = 350;

	candybar_list[1].name = "阿尔卑斯";
	candybar_list[1].weight = 6.3;
	candybar_list[1].calories = 310;
	
	candybar_list[2].name = "优の良品";
	candybar_list[2].weight = 2.1;
	candybar_list[2].calories = 291;

	cout << candybar_list[0].name << "\t" << candybar_list[0].weight << "\t" << candybar_list[0].calories << endl; 
	cout << candybar_list[1].name << "\t" << candybar_list[1].weight << "\t" << candybar_list[1].calories << endl; 
	cout << candybar_list[2].name << "\t" << candybar_list[2].weight << "\t" << candybar_list[2].calories << endl; 

	delete [] candybar_list;
	candybar_list = NULL;
	
	cout << endl;
	return (0);
} 
