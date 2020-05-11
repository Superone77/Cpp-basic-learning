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
	TPizza*	p_pizza = new TPizza;

	cout << "输入披萨直径（厘米）：";
	cin >> p_pizza->diameter;	// cin忽略输入流中的空白符（回车符、空格符、制表符），回车符仍保留在输入流中

	cout << "输入披萨名：";
	cin.get(); 	// 提取先前留在输入流中的回车符，否则下面的getline()不会等待输入，而直接读取输入流中已有的回车符
	getline(cin, p_pizza->company_name);

	cout << "输入披萨重量（克）：";
	cin >> p_pizza->weight;

	cout << p_pizza->company_name << "公司出品直径为" << p_pizza->diameter << "厘米重量为" << p_pizza->weight << "克的披萨" << endl;

	delete p_pizza;
	p_pizza = NULL;
	
	cout << endl;
	return (0);
} 
