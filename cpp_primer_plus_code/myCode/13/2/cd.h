//base class
#pragma once
#include <cstring>
#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

class Cd {
private:
	char *performers;
	char *label;
	int selections;
	double playtime;

public:
	explicit Cd(const char * s1 = " ", const char * s2=" ", int n=0,  double x=0.0);
	Cd(const Cd &d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	Cd & operator =(const Cd & d);
};

static char*
copyChar(const char* p_src_txt)
{
	unsigned  str_len = strlen(p_src_txt);
	char * p_des_txt = new char[str_len + 1];
	strcpy(p_des_txt, p_src_txt);

	return (p_des_txt);
}

Cd::Cd(const char * s1, const char * s2, int n , double x)
	:selections(n), playtime(x)
{
	performers = copyChar(s1);
	label = copyChar(s2);
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}

Cd::Cd(const Cd &d)
	:selections(d.selections), playtime(d.playtime)
{
	performers = copyChar(d.performers);
	label = copyChar(d.performers);
}

Cd &
Cd::operator=(const Cd & d)
{
	if (&d == this) {
		return (*this);
	}

	delete[] performers;
	performers = copyChar(d.performers);
	
	delete[] label;
	label = copyChar(d.label);

	selections = d.selections;
	
	playtime = d.playtime;

	return (*this);
}

void
Cd::Report() const
{
	cout << performers << ", " << label << ", " << selections << flush;
}
