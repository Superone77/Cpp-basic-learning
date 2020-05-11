#pragma once
//单链表
#include"node.h"
#include"Person.h"

class List
{
public:
	List();
	~List();
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, Node *pNode);
	int LocateElem(Node *pNode);
	bool PriorElem(Node *pCurrentNode, Node *pPreNode);
	bool NextElem(Node *pCurrentNode, Node *pNextNode);
	void ListTraverse();
	bool ListInsert(int i, Node *pNode);//i从0开始
	bool ListDelete(int i, Node *pNode);
	bool ListInsertHead(Node *pNode);
	bool ListInsertTail(Node *pNode);

private:
	Node *m_pList;//头结点
	int m_iLength;
	//链表不需要定义Size
};