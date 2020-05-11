//base class
#pragma once
#include <cstring>
#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

class Cd {
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;

public:
	explicit Cd(const char * s1 = " ", const char * s2=" ", int n=0,  double x=0.0);
	//Cd(const Cd &d);
	Cd();
	virtual ~Cd(){}
	virtual void Report() const;
	//Cd & operator =(const Cd & d);
};

static void
copyChar(char *p_recevier, const char * p_input, unsigned charSize)
{
	unsigned str_len = strlen(p_input) < charSize - 1 ? strlen(p_input) : charSize - 1;
	strncpy(p_recevier, p_input, str_len);
	p_recevier[str_len] = '\0';
}

Cd::Cd(const char * s1, const char * s2, int n , double x)
	:selections(n), playtime(x)
{
	copyChar(performers, s1, 50);
	copyChar(label, s2, 20);
}

void
Cd::Report() const
{
	cout << performers << ", " << label << ", " << selections << flush;
}
