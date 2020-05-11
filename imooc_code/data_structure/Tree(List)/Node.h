#pragma once

class Node
{
public:
	Node();
	Node *SearchNode(int nodeIndex);
	void DeleteNode();
	void PreorderTraversal();//前序遍历
	void InorderTraversal();//中序遍历
	void PostorderTraversal();//后序遍历
	int index;
	int data;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;
};