#pragma once
#include"Node.h"
#include<vector>
#include"Edge.h"

using namespace std;

class CMap
{
public:
	CMap(int capacity);
	~CMap();
	bool addNode(Node *pNode);//向图中加入顶点
	void resetNode();//重置顶点
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);//为有向图设置邻接矩阵
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);//为无向图设置邻接矩阵

	void printMatrix(); //打印邻接矩阵

	void depthFirstTraverse(int nodeIndex);//深度优先遍历
	void breadthFirstTraverse(int nodeIndex);//广度优先遍历

	void primTree(int nodeIndex); // prim生成树

private:
	bool getValueFromMatrix(int row, int col, int &val); // 从矩阵中获取权值
	void breadthFirstTraverImpl(vector<int>preVec);
	int getMinEdge(vector<Edge> edgevec);

private:
	int m_iCapacity; //图中最多可以容纳的顶点数
	int m_iNodeCount; //已经添加的顶点个数
	Node *m_pNodeArray; //用来存放顶点数组
	int *m_pMatrix; //用来存放邻接矩阵

	Edge *m_pEdge; //边的指针
};