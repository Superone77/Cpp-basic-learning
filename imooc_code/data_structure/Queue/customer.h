#pragma once
#include<string>
using namespace std;

class Customer
{
public:
	Customer(string name ="", int age=0);
	void printinfo() const;

private:
	string m_name;
	int m_age;
};