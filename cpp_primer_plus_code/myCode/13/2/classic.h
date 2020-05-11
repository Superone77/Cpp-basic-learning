#pragma once

#include "cd.h"


class Classic : public Cd
{

private:
	char * songs;

public:
	explicit Classic(const char *songs_list = "", const char * s1="", const char * s2 = "", int n = 0, double x = 0.0);
	virtual void Report() const;
	virtual ~Classic();
	Classic(const Classic & classic);
	Classic &  operator=(const Classic& classic);
};

Classic::Classic(const char *songs_list, const char * s1, const char * s2, int n, double x) : Cd::Cd(s1,s2,n,x)
{
	songs = copyChar(songs_list);
}

Classic::Classic(const Classic& classic):Cd(classic)
{
	songs = copyChar(classic.songs);
}

Classic&
Classic::operator=(const Classic& classic)
{
	if (&classic == this)
	{
		return(*this);
	}
	Cd::operator=(classic);

	delete[]songs;
	songs = copyChar(classic.songs);
}

void
Classic::Report()const
{
	Cd::Report();
	cout << ", " << songs << endl;
}

Classic::~Classic()
{
	delete[] songs;
}