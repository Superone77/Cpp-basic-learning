//图的基本操作
#include<iostream>
#include<stdlib.h>
#include"CMap.h"

using namespace std;

int main()
{
	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');


	CMap *pMap = new CMap(6);

	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);


	pMap->setValueToMatrixForUndirectedGraph(0, 1,6);
	pMap->setValueToMatrixForUndirectedGraph(0, 4,5);
	pMap->setValueToMatrixForUndirectedGraph(0, 5, 1);
	pMap->setValueToMatrixForUndirectedGraph(1, 2,3);
	pMap->setValueToMatrixForUndirectedGraph(1, 5,2);
	pMap->setValueToMatrixForUndirectedGraph(2, 5,8);
	pMap->setValueToMatrixForUndirectedGraph(2, 3,7);
	pMap->setValueToMatrixForUndirectedGraph(3, 5,4);
	pMap->setValueToMatrixForUndirectedGraph(3, 4, 2);
	pMap->setValueToMatrixForUndirectedGraph(4, 5, 9);

	pMap->primTree(0);

	
	/*pMap->printMatrix();

	cout << endl;

	pMap->depthFirstTraverse(0);

	cout << endl;

	pMap->resetNode();
	pMap->breadthFirstTraverse(0);*/

	system("pause");
	return 0;
}