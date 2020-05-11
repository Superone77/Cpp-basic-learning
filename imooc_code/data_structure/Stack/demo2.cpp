#include<iostream>
#include<stdio.h>
#include"MyStack.h"
#include<math.h>

using namespace std;

unsigned ten_to_n(unsigned x, unsigned n_class);

int main()
{
	unsigned x_ten;
	cout << "请输入： ";
	cin >> x_ten;
	cout << "二进制： "<<ten_to_n(x_ten, 2) << endl;
	cout << "八进制： " << ten_to_n(x_ten, 8) << endl;
	cout << "十六进制： " << ten_to_n(x_ten, 16) << endl;

	system("pause");
	return 0;
	
}

unsigned 
ten_to_n(unsigned x,unsigned n_class)
{
	MyStack<unsigned> *pClass = new MyStack<unsigned>(20);
	unsigned n;
	while (x != 0)
	{
		
		n = x % n_class;
		pClass->push(n);
		x = x / n_class;
		
	}
	int count = pClass->stackLength()-1;
	unsigned k=(unsigned)pow(10,count);
	unsigned rec;
	unsigned sum=0;
	while(!pClass->stackEmpty())
	{
		pClass->pop(rec);
		rec *= k;
		sum += rec;
		k /= 10;
	}
	delete pClass;
	pClass = NULL;
	return sum;
	
}