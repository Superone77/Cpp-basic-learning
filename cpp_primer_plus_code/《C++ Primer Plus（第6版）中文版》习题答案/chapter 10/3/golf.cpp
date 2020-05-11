#include <iostream>
#include <cstring>
#include "golf.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

golf::golf (const char * name, int hc)
{
	strcpy(fullname, name);
	handicap = hc;
}

int
golf::setgolf (void)
{
	cout << "输入姓名：";
	string	strTmp;
	getline(cin, strTmp);
	if ("" == strTmp) {
		return (0);
	}

	cout << "输入差点：";
	int	n;
	cin >> n;
	cin.get();
	if (!n) {
		return (0);
	}

	*this = golf(strTmp.c_str(), n);

	return (1);
}

void
golf::sethandicap(int hc)
{
	handicap = hc;
}

void
golf::showgolf(void) const
{
	cout << fullname << '\t' << handicap;
}
