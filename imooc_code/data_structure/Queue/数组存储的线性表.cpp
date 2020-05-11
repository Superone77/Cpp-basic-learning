//线性表的顺序存储实现
#include <stdio.h>
#include<iostream>
#include <malloc.h>
#define MAXSIZE 100;

using namespace std;

typedef int ElementType; //Elementtype  可定义为任何类型

class List
{
public:
	ElementType Date[MAXSIZE];
	int Last; 
public:
	List();
	~List();
	friend ElementType FindKth(int K, List &L);//查找第K个元素
	friend int Find(ElementType X, List &L); //查找X在哪个位置
	friend void Insert(ElementType X, int i, List &L); //在位序i前插入一个新元素X
	friend void Delete(int i, List &L); //删除指定位序i的元素
	friend int Length(List &L); //返回线性表L的长度
};





//初始化
List::List()
{
	
	Last = -1;
	
}

//查找X在哪个位置第一次出现
int Find(ElementType X, List &L)
{
	int i = 0;
	while (i <= L.Last&&L.Date[i] != X)
		i++;
	if (i > L.Last) return -1; //没找到返回-1
	else return i;
}

//插入
void Insert(ElementType X, int i, List &L)
{
	int j;
	if (L.Last == (MAXSIZE - 1)) //表空间已满
	{
		cout << "表满" << endl;
		
	}

	if (i<1 || i >L.Last + 2) //插入位置合法性检测
	{
		cout << "位置不合法" << endl;
		
	}
	
	for (j = L.Last; j >= i - 1; j--)
	{
		L.Date[j + 1] = L.Date[j]; //i后面的每个向后移动一位
	}

	L.Date[i - 1] = X;
	L.Last++; //末尾标识修改
}

//删除
void Delete(int i, List &L)
{
	int j;
	if (i<1 || i> L.Last + 1)
	{
		cout << "不存在第" << i << "个元素" << endl;
		return;
	}
	for (j = i; j <= L.Last; j++)//删完还要进行移动
		L.Date[j - 1] = L.Date[j];
	L.Last--;
}

//按序查找
ElementType FindKth(int K, List &L)
{
	if (K < 0 || L.Last < K)//不存在
	{
		cout << "不存在该元素" << endl;
		return 0;
	}
	
	return L.Date[K];
	
}

//表长
int Length(List &L)
{
	return L.Last + 1;
}


//测试程序
int main() {
	int i = 0;
	List L;
	Insert(11, 0, L);
	cout << "在线性表L-Data[0]插入11\n";
	Insert(25, 0, L);
	cout << "在线性表L-Data[0]插入25\n";
	Insert(33, 0, L);
	cout << "在线性表L-Data[0]插入33\n";
	Insert(77, 0, L);
	cout << "在线性表L-Data[0]插入77\n";
	cout << "此时的线性表为：";
	for (i = 0; i < Length(L); i++)
		cout << L.Date[i];
	cout << endl;
	cout << "查找值为12的下标是：" << Find(12, L) << endl;
	cout << "下标为3的线性表的值是：" << FindKth(3, L) << endl;;
	Delete(2, L);
	cout << "删除线性表中下标为2的元素\n";
	Delete(2, L);
	cout << "删除线性表中下标为2的元素\n";
	cout << "此时的线性表为：";
	for (i = 0; i < Length(L); i++)
		cout << L.Date[i];

	cout << endl;

	system("pause");
	return 0;
}

