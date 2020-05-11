#pragma once

#include<string>
#include<ostream>
using namespace std;


class Person
{
	friend ostream &operator<<(ostream &out, Person &person);
public:
	string name;
	string phone;
	Person &operator=(Person &person);
	bool operator==(Person &person);
	
};

