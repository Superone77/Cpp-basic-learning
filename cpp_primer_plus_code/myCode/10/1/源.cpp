#include"bank.h"
#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

int main()
{
	bank fuck("superman", "DE12345", 200);
	fuck.showName();
	fuck.showNumber();
	fuck.showMoney();

	fuck.increaseMoney(2);
	fuck.showMoney();
	fuck.decreaseMoney(8);
	fuck.showMoney();

	system("pause");
	return 0;
	
}