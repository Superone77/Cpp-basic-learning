#pragma once

#include "cd.h"


class Classic : public Cd
{
private:
	static const unsigned mk_size = 64;

private:
	char m_songs[mk_size];

public:
	Classic(const char *songs_list = "", const char * s1="", const char * s2 = "", int n = 0, double x = 0.0);
	virtual void Report() const;
};

Classic::Classic(const char *songs_list, const char * s1, const char * s2, int n, double x) : Cd::Cd(s1,s2,n,x)
{
	copyChar(m_songs, songs_list, mk_size);
}

void
Classic::Report()const
{
	Cd::Report();
	cout << ", " << m_songs << endl;
}