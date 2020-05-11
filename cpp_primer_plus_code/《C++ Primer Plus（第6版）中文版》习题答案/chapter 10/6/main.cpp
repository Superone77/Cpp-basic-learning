#include <iostream>
#include <cstring>

using namespace std;

class TMove
{
	private:
		double	m_x;
		double	m_y;

	public:
		TMove (double a = 0, double b = 0);
		void showMove (void) const;
		TMove add (const TMove& m) const;
		void reset (double a = 0, double b = 0);
};

TMove::TMove (double a, double b)
{
	m_x = a;
	m_y = b;
}

void
TMove::showMove (void) const
{
	cout << '(' << m_x << ", " << m_y << ')';
}
		
TMove
TMove::add (const TMove& m) const
{
	return (TMove(m.m_x + m_x, m.m_y + m_y));
}

void
TMove::reset (double a, double b)
{
	m_x = a;
	m_y = b;
}

int
main (void) 
{     
	TMove	one(12, 4);
	one.showMove();
	cout << endl;
	TMove	two(1, 1);
	one.add(two).showMove();
	cout << endl;
	one.reset();
	one.showMove();


	cout << endl;
	return (0);
} 
