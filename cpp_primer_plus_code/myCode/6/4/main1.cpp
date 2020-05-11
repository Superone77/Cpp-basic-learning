#include <iostream>
#include<stdlib.h>

using namespace std;

const unsigned strsize = 64;

struct bop {
	char fullname[strsize];//real name
	char title[strsize];//job title;
	char bopname[strsize];//secret BOP name
	int preference;//0=fullname,1=title,2=bopname
};

int main()
{

	const int BSize = 4;
	bop	everybodyletsgo[BSize] = { {"Yang Yang", "chinamobile", "yangyang.gnu", 1},
							{"xiao wang", "microsoft", "xiaowang", 2},
							{"xiao liu", "IBM", "xiaoliu", 0},
							{"xiao zhang", "Huawei", "xiaozhang",1} };

	cout << "Benevolent Order of Programmers Report" << endl;
	cout << "a. display by name    b. display by title" << endl;
	cout << "c. display by bopname d. display by preference" << endl;
	cout << "q. quit" << endl;
	cout << "enter your choice: ";
	
	char ch;
	
	while (cin >> ch && ch != 'q') {
		switch (ch)
		{
		case 'a': 
		{
			for (int i = 0; i < BSize; i++) {
				cout << everybodyletsgo[i].fullname << endl;
			}
			cout << "Next choice: ";
			break;
		}
		case 'b':
		{
			for (int i = 0; i < BSize; i++) {
				cout << everybodyletsgo[i].title << endl;
			}
			cout << "Next choice: ";
			break;
		}
		case 'c':
		{
			for (int i = 0; i < BSize; i++) {
				cout << everybodyletsgo[i].bopname << endl;
			}
			cout << "Next choice: ";
			break;
		}
		case 'd':
		{
			for (int i = 0; i < BSize; i++) {

				if(everybodyletsgo[i].preference=0)
				    cout << everybodyletsgo[i].fullname << endl;

				else if(everybodyletsgo[i].preference = 1)
					cout << everybodyletsgo[i].title << endl;
				else cout << everybodyletsgo[i].bopname << endl;
					
			}
			cout << "Next choice: ";
			break;
		}
	     
		default:
			break;
		}
	}
	
	cout << "Bye!" << endl;


	system("pause");

	return 0;
}