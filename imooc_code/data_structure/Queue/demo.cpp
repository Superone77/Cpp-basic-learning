#include"Myqueue.h"
#include<iostream>
#include<stdio.h>
#include"customer.h"

using namespace std;

int main()
{
	MyQueue *p = new MyQueue(4);
	Customer c1("zhang", 20);
	Customer c2("Li", 30);
	Customer c3("wang", 20);

	p->EnQueue(c1);
	p->EnQueue(c2);
	p->EnQueue(c3);

	p->QueueTraverse();

	Customer c4("", 0);
	p->DeQueue(c4);
	c4.printinfo();

	p->QueueTraverse();

	system("pause");
	return 0;
}