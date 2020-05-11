#pragma once
#include<string>
#include<cstring>

using namespace std;

class plorg
{
public:
	plorg(string name = "Plorga", int ci = 50);
	void setname(string name);
	void setci(int ci);
	void getplorg();
private:
	string m_name;
	int m_ci;
};