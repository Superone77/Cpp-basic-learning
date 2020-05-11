#include<iostream>
#include"customer.h"

using namespace std;

Customer::Customer(string name, int age)
{
	m_name = name;
	m_age = age;
}

void
Customer::printinfo() const
{
	cout << endl << "ÐÕÃû£º " << m_name << endl;
	cout << "ÄêÁä£º" << m_age << endl;
} 