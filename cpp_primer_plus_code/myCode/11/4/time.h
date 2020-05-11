#pragma once

#include<iostream>

using namespace std;

class Time
{
private:
	int hours;
	int minutes;

public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddNr(int h);
	void Reset(int h = 0, int m = 0);
	friend Time operator+(const Time &a, const Time &b);
	friend Time operator-(const Time &a, const Time &b);
	friend Time operator*(double m, const Time &t);
	friend Time operator*(const Time &t,double m);
	friend std::ostream & operator<<(std::ostream &os, const Time &t);
};