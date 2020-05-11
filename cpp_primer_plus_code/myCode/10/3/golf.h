#pragma once

class golf
{
public:
	golf(const char*name = "", int hc = 0);
	int setgolf(void);
	void sethandicap(int hc);
	void showgolf(void) const;
private:
	static const int Len = 40;
	char fullname[Len];
	int handicap;
};