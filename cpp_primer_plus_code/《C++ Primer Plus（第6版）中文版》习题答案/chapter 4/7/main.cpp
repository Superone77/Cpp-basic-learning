#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct	TPizza
{
	string	company_name;
	double	diameter;
	double	weight;
};

int
main (void) 
{     
	TPizza	pizza;

	cout << "输入披萨名：";
	getline(cin, pizza.company_name);

	cout << "输入披萨直径（厘米）：";
	cin >> pizza.diameter;

	cout << "输入披萨重量（克）：";
	cin >> pizza.weight;

	cout << pizza.company_name << "公司出品直径为" << pizza.diameter << "厘米重量为" << pizza.weight << "克的披萨" << endl;
	
	cout << endl;
	return (0);
} 
