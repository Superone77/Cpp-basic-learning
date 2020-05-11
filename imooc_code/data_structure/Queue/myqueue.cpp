#include<iostream>
#include"Myqueue.h"
using namespace std;

MyQueue::MyQueue(int queueCapacity)
{
	m_pQueue = new Customer[queueCapacity];
	m_iQueueCapacity = queueCapacity;
	ClearQueue();
}

MyQueue::~MyQueue()
{
	delete[] m_pQueue;
	m_pQueue = NULL;
}

void
MyQueue::ClearQueue()
{
	m_iQueueLen = 0;
	m_iHead = 0;
	m_iTail = 0;
}

bool
MyQueue::QueueEmpty() const
{
	if (m_iQueueLen == 0)
		return true;
	else
		return false;
}

bool
MyQueue::QueueFull() const
{
	if (m_iQueueLen == m_iQueueCapacity)
		return true;
	else
		return false;
}

int 
MyQueue::QueueLength() const
{
	return m_iQueueLen;
}

bool 
MyQueue::EnQueue(Customer element)
{
	if (m_iQueueLen == m_iQueueCapacity)
		return false;
	m_pQueue[m_iTail] = element;
	m_iTail++;
	m_iTail = m_iTail % m_iQueueCapacity;
	m_iQueueLen++;
	return true;
}

bool 
MyQueue::DeQueue(Customer &element)
{
	if (m_iQueueLen == 0)
		return false;
	element = m_pQueue[m_iHead];
	m_iHead++;
	m_iHead = m_iHead % m_iQueueCapacity;
	m_iQueueLen--;
	return true;
}

void 
MyQueue::QueueTraverse()
{
	for (int i = m_iHead; i < m_iQueueLen + m_iHead;i++)
	{
		m_pQueue[i].printinfo();
		
	}
}

