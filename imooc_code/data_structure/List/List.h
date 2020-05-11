#pragma on
#include"Coordinate.h"


class List
{
public:
	List(int size); //创建
	~List();        //销毁
	void ClearList();//清空
	bool ListEmpty(); //判断是否为空
	int ListLength();//获取长度
	bool GetElem(int i, Coordinate *e);//获取指定元素
	int LocateElem(Coordinate *e);//寻找满足的元素的位序
	bool PriorElem(Coordinate *currentElem, Coordinate *preElem);//获取指定元素的前驱
	bool NextElem(Coordinate *currentElem, Coordinate *nextElem); //获取指定元素的后继
	void ListTraverse();//遍历
	bool ListInsert(int i, Coordinate *e);//插入
	bool ListDelete(int i, Coordinate *e);//删除

private:
	Coordinate * m_pList;
	int m_iLength;
	int m_iSize;
};