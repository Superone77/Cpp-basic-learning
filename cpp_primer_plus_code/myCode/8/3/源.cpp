#include<iostream>
#include<stdio.h>
#include<cctype>
#include<string>

using namespace std;

string& str_upper(string & sentence);

string& str_upper(string &sentence)
{
	for (auto&e : sentence)//auto& xxx: xxx 遍历字符串
		e = (char)toupper(e);
	return sentence;
}

int main()
{
	while (true) {
		cout << "Enter a string(q to quit): ";
		string fuck;
		getline(cin, fuck);
		if (!cin || "q" == fuck || "Q" == fuck) {
			cout << "Bye!" << endl;
			break;
		}
		fuck=str_upper(fuck);
		cout << fuck << endl;
	}
	system("pause");
	return 0;
}