#include<iostream>
#include<stdio.h>
#include"move.h"

using namespace std;

int main(void)
{


	Move fuck2(1,1);
	fuck2.showmove();

	Move fuck3(1, 1);
	fuck3.add(fuck2).showmove();
	fuck3.showmove();
	fuck3.reset();
	fuck3.showmove();

	cout << endl;
	system("pause");
	return 0;
}