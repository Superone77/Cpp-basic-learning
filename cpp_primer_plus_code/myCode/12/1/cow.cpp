
#pragma warning (disable: 4996)
#include <iostream>
#include<string>
#include "cow.h"
using namespace std;

Cow::Cow()
{
	strcpy(name, "/0");
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0.0;
}
Cow::Cow(const char * nm, const char * ho, double wt)
{
	strcpy(name, nm);
	int len = strlen(ho);
	hobby = new char[len + 1];
	strcpy(hobby, ho);
	weight = wt;
}
Cow::Cow(const Cow &c)
{
	strcpy(name,c.name);
	int len = strlen(c.hobby);
	hobby = new char[len + 1];
	weight = c.weight;
	strcpy(hobby, c.hobby);
}
Cow::~Cow()
{
	delete[] hobby;
}
Cow & Cow::operator = (const Cow &c)
{
	if (this == &c)
		return *this;
	delete[] hobby;
	int len = strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy(hobby, c.hobby);
	strcpy(name, c.name);
	weight = c.weight;
	return *this;
}
void Cow::ShowCow() const
{
	cout <<"name: "<< name << endl;
	cout << "hobby: " << hobby << endl;
	cout << "weight: " << weight << endl;

}