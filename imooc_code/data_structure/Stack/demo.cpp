#include<iostream>
#include"MyStack.h"
#include<stdio.h>

using namespace std;

int main()
{
	MyStack<char> *pStack = new MyStack<char>(5);

	pStack->push('h'); //Õ»µ×
	pStack->push('e');
	pStack->push('l');
	pStack->push('l');
	pStack->push('o'); //Õ»¶¥

	pStack->stackTraverse(true);

	cout << endl;

	char elem = 0;
	pStack->pop(elem);

	cout << elem << endl;

	pStack->stackTraverse(false);

	cout << pStack->stackLength() << endl;

	pStack->clearStack();

	cout<<pStack->stackLength() << endl;

	if (pStack->stackEmpty())
	{
		cout << "Empty." << endl;
	}
	if (pStack->stackFull())
	{
		cout << "Full." << endl;
	}


	delete pStack;
	pStack = NULL;

	system("pause");
	return 0;
}