#include<iostream>
#include"move.h"

using namespace std;

Move::Move(double a , double b)
{
	x = a;
	y = b;
}
void
Move::showmove(void) const
{
	cout << x << endl;
	cout << y << endl;
}

Move Move::add(const Move&m) const
{
	return (Move(m.x + x, m.y + y));
}
void
Move::reset(double a , double b)
{
	x = a;
	y = b;
}

