#include "time.h"

Time::Time()
{
	hours = minutes == 0;
}
Time::Time(int h, int m )
{
	hours = h;
	minutes = m;
}
void 
Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void 
Time::AddNr(int h)
{
	hours += h;
}
void 
Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}
Time 
operator+(const Time &a, const Time &b)
{
	Time sum;
	sum.minutes = a.minutes + b.minutes;
	sum.hours = a.hours + b.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
Time
operator-(const Time &a, const Time &b)
{
	Time diff;
	int tot1, tot2;
	tot1 = a.minutes + 60 * a.hours;
	tot2 = b.minutes + 60 * b.hours;
	diff.minutes = (tot1 - tot2) % 60;
	diff.minutes = (tot1 - tot2) / 60;
	return diff;
}

Time 
operator*(double m, const Time &t)
{
	Time result;
	long totalminutes = t.hours * m * 60 + t.minutes * m;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

Time
operator*(const Time &t, double m)
{
	Time result;
	long totalminutes = t.hours * m * 60 + t.minutes * m;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}


std::ostream & operator<<(std::ostream &os, const Time &t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}