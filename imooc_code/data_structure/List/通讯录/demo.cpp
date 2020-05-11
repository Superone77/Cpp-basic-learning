#include"List.h"
#include"Node.h"
#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;


int main()
{
	Node node1;
	node1.data.name = "test1";
	node1.data.phone = "123456";
	Node node2;
	node2.data.name = "test2";
	node2.data.phone = "234567";

	List *pList = new List();
	pList->ListInsertTail(&node1);
	pList->ListInsertTail(&node2);

	pList->ListTraverse();

	delete pList;
	pList = NULL;

	system("pause");
	return 0;


}