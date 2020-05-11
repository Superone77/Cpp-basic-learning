#include<iostream>
#include<stdio.h>
#include"List.h"
#include"node.h"

using namespace std;

int main()
{
	Node node1;
	node1.data = 3;
	Node node2;
	node2.data = 4;
	Node node3;
	node3.data = 5;
	Node node4;
	node4.data = 6;
	Node node5;
	node5.data = 7;
	List *pList = new List();

	Node temp;

	/*pList->ListInsertHead(&node1);
	pList->ListInsertHead(&node2);
	pList->ListInsertHead(&node3);
	pList->ListInsertHead(&node4);*/

	pList->ListInsertTail(&node1);//0ºÅÎ»ÖÃ
	pList->ListInsertTail(&node2);
	pList->ListInsertTail(&node3);
	pList->ListInsertTail(&node4);

	pList->ListInsert(1, &node5);

	//pList->ListDelete(1, &temp);

	//pList->GetElem(1, &temp);
	pList->PriorElem(&node5, &temp);

	pList->ListTraverse();

	temp.printNode();


	delete pList;
	pList = NULL;

	system("pause");
	return 0;
}