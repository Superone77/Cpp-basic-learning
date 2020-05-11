#include<iostream>
#include<stdio.h>

#include"Tree.h"

using namespace std;

int main()
{
	int root = 3;
	Tree *pTree = new Tree(10, &root);

	int node1 = 5;
	int node2 = 8;
	pTree->AddNode(0, 0, &node1);
	pTree->AddNode(0, 1, &node2);

	int node3 = 2;
	int node4 = 6;

	pTree->AddNode(1, 0, &node3);
	pTree->AddNode(1, 1, &node4);

	int node5 = 9;
	int node6 = 7;

	pTree->AddNode(2, 0, &node5);
	pTree->AddNode(2, 1, &node6);

	int node = 0;
	pTree->DeleteNode(6, &node);
	cout << endl << node << endl;

	pTree->TreeTraverse();

	int *p=pTree->SearchNode(2);

	cout << endl<<*p << endl;

	delete pTree;
	pTree = NULL;

	system("pause");
	return 0;
}

