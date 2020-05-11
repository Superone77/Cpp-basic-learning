#include<iostream>
#include<string>
#include"plorg.h"

using namespace std;

plorg::plorg(string name, int ci)
{
	int limit = 19;
	if (name.size() > limit) {
		m_name=name.substr(0, limit);
	}
	else 
		m_name = name;

	m_ci = ci;
}

void plorg::setname(string name)
{
	int limit = 19;
		if (name.size() > limit) {
			m_name = name.substr(0, limit);
		}
		else
			m_name = name;
}
void plorg::setci(int ci)
{
	m_ci = ci;
}
void plorg::getplorg()
{
	cout << "name is " << m_name << endl;
	cout << "CI is " << m_ci << endl;
}