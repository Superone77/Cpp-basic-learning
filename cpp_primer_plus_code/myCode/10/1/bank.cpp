#include<iostream>
#include<string>
#include"bank.h"

using namespace std;

bank::bank(string name, string number, unsigned money)
{
	cout << "bank()" << endl;
	m_name = name;
	m_number = number;
	m_money = money;
}

bank::~bank()
{
	cout << "~bank()" << endl;
}

void bank::showName()
{
	cout << m_name << endl;
}

void bank::showNumber()
{
	cout << m_number << endl;
}

void bank::showMoney()
{
	cout << m_money << endl;
}

void bank::increaseMoney(unsigned amount)
{
	m_money = m_money + amount;
}

void bank::decreaseMoney(unsigned amount)
{
	m_money = m_money - amount;
}