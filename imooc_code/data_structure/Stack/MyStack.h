#pragma once

#include<iostream>

using namespace std;
template <typename T>
class MyStack
{
public:
	MyStack(int size); //分配内存初始化栈空间
	~MyStack(); //回收栈空间内存
	bool stackEmpty(); //判定栈是否为空
	bool stackFull(); //判定栈是否为满
	void clearStack(); //清空栈
	int stackLength(); //已有元素的个数
	void push(T  elem); //元素入栈
	bool pop(T &elem); //元素出栈
	void stackTraverse(bool isFromButtom); //遍历
	
private:
	T* m_pBuffer;
	int m_iSize;
	int m_iTop;
};

template <typename T>
MyStack<T>::MyStack(int size)
	:m_iSize(size)
{
	m_pBuffer = new T[m_iSize];
	m_iTop = 0;
}

template <typename T>
MyStack<T>::~MyStack()
{
	delete[] m_pBuffer;
	m_pBuffer = NULL;
}

template <typename T>
bool
MyStack<T>::stackEmpty()
{
	if (0 == m_iTop)
		return true;
	return false;
}

template <typename T>
bool
MyStack<T>::stackFull()
{
	if (m_iTop == m_iSize)
		return true;
	return false;
}

template <typename T>
void
MyStack<T>::clearStack()
{
	m_iTop = 0;
}

template <typename T>
int
MyStack<T>::stackLength()
{
	return m_iTop;
}

template <typename T>
void
MyStack<T>::push(T elem)
{
	if (!stackFull())
	{
		m_pBuffer[m_iTop] = elem;
		m_iTop++;
	}
}

template <typename T>
bool
MyStack<T>::pop(T &elem)
{
	if (stackEmpty())
		return false;
	m_iTop--;
	elem = m_pBuffer[m_iTop];
	return true;
}

//char 
//MyStack::pop()
//{
//	if (stackEmpty())
//		throw "Stack is empty.";
//	m_iTop--;
//	return m_pBuffer[m_iTop];
//}

template <typename T>
void
MyStack<T>::stackTraverse(bool isFromButtom)
{
	if (isFromButtom)
	{
		for (int i = 0; i < m_iTop; i++)
		{
			cout << m_pBuffer[i] << " ";
		}
	}
	else
	{
		for (int i = m_iTop - 1; i >= 0; i--)
		{
			cout << m_pBuffer[i] << " ";
		}
	}


}