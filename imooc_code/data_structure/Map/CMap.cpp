#include"CMap.h"
#include<iostream>
#include<vector>
using namespace std;

CMap::CMap(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];
	m_pMatrix = new int[m_iCapacity*m_iCapacity];
	memset(m_pMatrix, 0, m_iCapacity*m_iCapacity * sizeof(int));

	m_pEdge = new Edge[m_iCapacity - 1];
}

CMap::~CMap()
{
	delete[] m_pNodeArray;
	delete[] m_pMatrix;
}

bool
CMap::addNode(Node *pNode)
{
	m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;
	m_iNodeCount++;
	return true;
}

void 
CMap::resetNode()
{
	for (int i = 0; i < m_iNodeCount; i++)
	{
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

bool
CMap::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
	if (row >= 0 && row < m_iCapacity&&col >= 0 && col < m_iCapacity)
	{
		m_pMatrix[row * m_iCapacity + col] = val;
		return true;
	}
	return false;
}

bool 
CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	if (row >= 0 && row < m_iCapacity&&col >= 0 && col < m_iCapacity)
	{
		m_pMatrix[row*m_iCapacity + col] = val;
		m_pMatrix[col*m_iCapacity + row] = val;
		return true;
	}
	return false;
}

void 
CMap::printMatrix()
{
	for (int i = 0; i < m_iCapacity; i++)
	{
		for (int k = 0; k < m_iCapacity; k++)
		{
			cout << m_pMatrix[i*m_iCapacity + k] << " ";
		}
		cout << endl;
	}
}

bool 
CMap::getValueFromMatrix(int row, int col, int &val)
{
	
	if (row >= 0 && row < m_iCapacity&&col >= 0 && col < m_iCapacity)
	{
		val = m_pMatrix[row*m_iCapacity + col];
		return true;
	}
	return false;
} 

void 
CMap::depthFirstTraverse(int nodeIndex)
{
	int value = 0;
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	
	for (int i = 0; i < m_iCapacity; i++)
	{
		getValueFromMatrix(nodeIndex, i, value);
		if (value == 1)
		{
			if (m_pNodeArray[i].m_bIsVisited)
				continue;
			else
			{
				depthFirstTraverse(i);
			}
		}
		else
			continue;
	}
}
void 
CMap::breadthFirstTraverse(int nodeIndex)
{
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	vector<int> curVec;
	curVec.push_back(nodeIndex);

	breadthFirstTraverImpl(curVec);
}
void 
CMap::breadthFirstTraverImpl(vector<int>preVec)
{
	int value = 0;
	vector<int> curVec;

	for (int i = 0; i < (int)preVec.size(); i++)
	{
		for (int k = 0; k < m_iCapacity; k++)
		{
			getValueFromMatrix(preVec[i], k, value);
			if (value != 0)
			{
				if (m_pNodeArray[k].m_bIsVisited)
					continue;
				else
				{
					cout << m_pNodeArray[k].m_cData << " ";
					m_pNodeArray[k].m_bIsVisited = true;

					curVec.push_back(k);
				}
			}
		}
	}

	if (curVec.size() == 0)
		return;
	else
		breadthFirstTraverImpl(curVec);
}

void 
CMap::primTree(int nodeIndex)
{
	int value = 0;
	int edgeCount = 0;
	vector<int> nodeVec;
	vector<Edge> edgeVec;

	cout << m_pNodeArray[nodeIndex].m_cData << endl;

	nodeVec.push_back(nodeIndex);
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	while (edgeCount < m_iCapacity - 1)
	{
		int temp = nodeVec.back();

		for (int i = 0; i < m_iCapacity; i++)
		{
			getValueFromMatrix(temp, i, value);
			if (value != 0)
			{
				if (m_pNodeArray[i].m_bIsVisited)
					continue;
				else
				{
					Edge edge(temp, i, value);
					edgeVec.push_back(edge);
				}
			}
		}

		int edgeIndex = getMinEdge(edgeVec);
		edgeVec[edgeIndex].m_bSelected = true;

		cout << edgeVec[edgeIndex].m_iNodeIndexA << "----" << edgeVec[edgeIndex].m_iNodeIndexB;
		cout << "   " << edgeVec[edgeIndex].m_iWeightValue << endl;

		m_pEdge[edgeCount] = edgeVec[edgeIndex];
		edgeCount++;

		int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;

		nodeVec.push_back(nextNodeIndex);
		m_pNodeArray[nextNodeIndex].m_bIsVisited = true;
		cout << m_pNodeArray[nextNodeIndex].m_cData << endl;
	}

}

int
CMap::getMinEdge(vector<Edge> edgeVec)
{
	int temp = 0;
	int k = 0;
	for (; k < edgeVec.size(); k++)
	{
		if (!edgeVec[k].m_bSelected)
			break;
	}
	if (edgeVec[k].m_bSelected)
	{
		return -1;
	}
	temp = edgeVec[k].m_iWeightValue;
	int i = k;
	
	for(; i<edgeVec.size();i++)
	{
		if (temp > edgeVec[i].m_iWeightValue&&!edgeVec[i].m_bSelected)
		{
			temp = edgeVec[i].m_iWeightValue;
			k = i;
		}
	}
	return k;
}