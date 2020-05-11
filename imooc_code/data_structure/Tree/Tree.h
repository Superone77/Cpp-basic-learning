#pragma once
//数组 - 二叉树
class Tree
{
public:
	Tree(int size, int *pRoot);
	~Tree();
	int *SearchNode(int nodeIndex); //根据索引寻找节点
	bool AddNode(int nodeIndex, int direction, int *pNode); //添加节点
	bool DeleteNode(int nodeIndex, int *pNode);//删除节点
	void TreeTraverse(); //遍历节点
private:
	int *m_pTree;
	int m_iSize;
};