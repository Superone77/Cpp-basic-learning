#include <iostream>
#include "TTime.h"


namespace n_time 
{
	using std::ostream;

	// ====================================
	// 辅助函数
	// ====================================
	static void
	format (	unsigned in_hour, unsigned in_minute, unsigned in_second, 
				unsigned& out_hour, unsigned& out_minute, unsigned& out_second	)
	{
		unsigned	total_second = in_hour * 3600 + in_minute * 60 + in_second;
		out_hour = total_second / 3600;
		out_minute = total_second % 3600 / 60;
		out_second = total_second % 3600 % 60;
	}

	// ====================================
	// 成员函数
	// ====================================

	TTime::TTime (unsigned hour, unsigned minute, unsigned second)
	{
		format (hour, minute, second, m_hour, m_minute, m_second);
	}

	void
	TTime::add (unsigned hour, unsigned minute, unsigned second)
	{
		format (m_hour + hour, m_minute + minute, m_second + second, m_hour, m_minute, m_second);
	}
	
	void 
	TTime::reset (unsigned hour, unsigned minute, unsigned second)
	{
		format (hour, minute, second, m_hour, m_minute, m_second);
	}

	unsigned
	TTime::getSecond (void) const 
	{
		return (m_second);
	}

	unsigned
	TTime::getMinute (void) const 
	{
		return (m_minute);
	}

	unsigned
	TTime::getHour (void) const 
	{
		return (m_hour);
	}

	// ====================================
	// 重载运算符
	// ====================================
	
	TTime 
	operator+ (const TTime& lvalue, const TTime& rvalue)
	{
		return (TTime(	lvalue.m_hour + rvalue.m_hour, 
						lvalue.m_minute + rvalue.m_minute,
						lvalue.m_second + rvalue.m_second	));
	}
	
	TTime 
	operator- (const TTime& lvalue, const TTime& rvalue)
	{
		return (TTime(	(unsigned)abs((int)lvalue.m_hour - (int)rvalue.m_hour), 
						(unsigned)abs((int)lvalue.m_minute - (int)rvalue.m_minute),
						(unsigned)abs((int)lvalue.m_second - (int)rvalue.m_second)	));
	}

	TTime 
	operator* (const TTime& lvalue, double n)
	{
		return (TTime(unsigned(lvalue.m_hour * n), unsigned(lvalue.m_minute * n), unsigned(lvalue.m_second * n)));
	}

	TTime 
	operator* (double n, const TTime& rvalue)
	{
		return (rvalue * n);
	}

	ostream&
	operator<< (ostream& os, const TTime& time)
	{
		os << time.m_hour << ':' << time.m_minute << ':' << time.m_second;
		return (os);
	}
}
