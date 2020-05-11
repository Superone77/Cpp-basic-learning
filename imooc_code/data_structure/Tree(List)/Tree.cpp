#include"Tree.h"
#include<iostream>

using namespace std;

Tree::Tree()
{
	m_pRoot = new Node();
}

Tree::~Tree()
{
	DeleteNode(0, NULL);
	//m_pRoot->DeleteNode();
}

Node*
Tree::SearchNode(int nodeIndex)
{
	return m_pRoot->SearchNode(nodeIndex);
}


bool 
Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL)
	{
		return false;
	}

	Node *node = new Node();
	node->index = pNode->index;
	node->data = pNode->data;
	node->pParent = temp;

	if (direction == 0)
	{
		temp->pLChild = node;
	}
	if (direction == 1)
	{
		temp->pRChild = node;
	}

	return true;
	
}

bool 
Tree::DeleteNode(int nodeIndex, Node *pNode)
{
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL)
	{
		return false;
	}

	if (pNode != NULL)
	{
		pNode->data = temp->data;
	}

	temp->DeleteNode();

	return true;

}

void
Tree::PreorderTraversal()
{
	m_pRoot->PreorderTraversal();
}

void
Tree::InorderTraversal()
{
     m_pRoot->InorderTraversal();
}

void
Tree::PostorderTraversal()
{
	m_pRoot->PostorderTraversal();
}