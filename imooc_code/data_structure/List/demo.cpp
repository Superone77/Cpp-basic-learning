//线性表-顺序表

#include"List.h"
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	Coordinate e1(1, 2);
	Coordinate e2(2, 2);
	Coordinate e3(3, 2);
	Coordinate temp(0, 0);
	
	List *list1 = new List(10);

	list1->ListInsert(0, &e1);
	list1->ListInsert(1, &e2);
	list1->ListInsert(2, &e3);

	list1->ListTraverse();   

	list1->PriorElem(&e2, &temp);
	cout << temp << endl;
	list1->NextElem(&e2, &temp);
	cout << temp << endl;



	 

	delete list1;
	list1 = NULL;

	system("pause");
	return 0; 
}