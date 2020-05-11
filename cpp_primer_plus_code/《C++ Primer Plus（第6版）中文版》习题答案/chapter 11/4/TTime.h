#pragma once

#include <iostream>

namespace n_time
{
	class TTime 
	{
		public:
			explicit TTime (unsigned hour = 0, unsigned minute = 0, unsigned second = 0);

		public:
			void add (unsigned hour = 0, unsigned minute = 0, unsigned second = 0);
			void reset (unsigned hour = 0, unsigned minute = 0, unsigned second = 0);
			unsigned getSecond (void) const;
			unsigned getMinute (void) const;
			unsigned getHour (void) const;

			friend TTime operator+ (const TTime& lvalue, const TTime& rvalue);
			friend TTime operator- (const TTime& lvalue, const TTime& rvalue);
			friend TTime operator* (const TTime& lvalue, double n);
			friend TTime operator* (double n, const TTime& rvalue);
			friend std::ostream& operator<< (std::ostream& os, const TTime& time);
		
		private:
			unsigned	m_second;
			unsigned	m_minute;
			unsigned	m_hour;
	};
}
