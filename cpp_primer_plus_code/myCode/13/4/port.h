#pragma once

#include <iostream>
using namespace std;

class Port
{
private:
	char * brand;
	char style[20]; // i.e., tawny, ruby, vintage
	int bottles;
public:
	explicit Port(const char * br = "none", const char * st = "none", int b = 0);
	Port(const Port & p); // copy constructor
	virtual ~Port() { delete[] brand; brand = NULL; }
	Port & operator=(const Port & p);
	virtual void Show() const;
	Port & operator+=(int b); // adds b to bottles
	Port & operator-=(int b); // subtracts b from bottles, if available
	int BottleCount() const { return bottles; }
	friend ostream & operator<<(ostream & os, const Port & p);
};