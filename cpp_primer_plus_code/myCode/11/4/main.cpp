#include<iostream>
#include"time.h"
#include<stdio.h>

int main()
{
	using std::cout;
	using std::endl;

	Time aida(3.35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca:\n";
	cout << aida << ": " << tosca << endl;
	temp = aida + tosca;
	cout << "Aida+Tosca: " << temp << endl;
	temp = aida * 1.17;
	cout << "Aida*1.17: " << temp << endl;
	cout << "10.0*Tosca: " << 10.0*tosca << endl;

	system("pause");
	return 0;
}