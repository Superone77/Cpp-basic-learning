#pragma once

class golf
{
public:
	golf (const char * name = "", int hc = 0);

	// interactive version:
	// function solicits name and handicap from user
	// and sets the members of g to the values entered
	// returns 1 if name is entered, 0 if name is empty string
	int setgolf(void);

	// function resets handicap to new value
	void sethandicap(int hc);

	// function displays contents of golf structure
	void showgolf(void) const;
	
private:
	static const int Len = 40;
	char fullname[Len];
	int handicap;
};

