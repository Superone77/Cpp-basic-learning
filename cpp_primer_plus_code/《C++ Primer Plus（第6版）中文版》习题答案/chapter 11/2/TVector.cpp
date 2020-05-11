#include <iostream>
#include <cmath>
#include "TVector.h"

namespace n_vector	
{
	using std::ostream;
	using std::sqrt;
	using std::atan2;
	using std::cos;
	using std::sin;

	// ====================================
	// 非成员辅助函数
	// ====================================

	static const double	k_rad_to_deg = 57.2958;

	static double
	convertRadToDeg (double rad)
	{
		return (rad * k_rad_to_deg);
	}
	
	static double
	convertDegToRad (double deg)
	{
		return (deg / k_rad_to_deg);
	}
	

	// ====================================
	// 公有成员函数
	// ====================================

	TVector::TVector (double a, double b, Mode mode)
		: m_mode(mode)
	{
		if (RECT == mode) {
			m_x = a;
			m_y = b;
		} else if (POL == mode) {
			m_convertPolarToRect(a, convertDegToRad(b));
		} else {
			;
		}
	}

	void
	TVector::reset (double a, double b, Mode mode)
	{
		*this = TVector(a, b, mode);
	}
	
	void
	TVector::setMode (Mode mode)
	{
		m_mode = mode;
	}

	TVector::Mode
	TVector::getMode (void) const
	{
		return (m_mode);
	}

	double
	TVector::getX (void) const
	{
		return (m_x);
	}

	double
	TVector::getY (void) const
	{
		return (m_y);
	}

	double
	TVector::getAngle (void) const
	{
		double	length, angle;
		m_converRectToPolar(length, angle);
		return (convertRadToDeg(angle));
	}

	double
	TVector::getLength (void) const
	{
		double	length, angle;
		m_converRectToPolar(length, angle);
		return (length);
	}

	TVector
	TVector::operator+ (const TVector& rvalue) const
	{
		TVector	tmp(m_x + rvalue.m_x, m_y + rvalue.m_y);
		tmp.m_mode = this->m_mode;
		return (tmp);
	}
			
	TVector&
	TVector::operator+= (const TVector& rvalue)
	{
		*this = *this + rvalue;
		return (*this);
	}

	TVector
	TVector::operator- (void) const
	{
		TVector	tmp(-m_x, -m_y);
		tmp.m_mode = this->m_mode;
		return (tmp);
	}
			

	// ====================================
	// 私有成员函数
	// ====================================

	void
	TVector::m_convertPolarToRect (double length, double angle)
	{
		m_x = length * cos(angle);
		m_y = length * sin(angle);
	}

	void
	TVector::m_converRectToPolar (double& length, double& angle) const
	{
		length = sqrt(m_x * m_x + m_y * m_y);
		angle = (0 == m_x && 0 == m_y) ? 0 : atan2(m_y, m_x);
	}


	// ====================================
	// 重载运算符
	// ====================================

	ostream& operator<< (ostream& os, const TVector& vec)
	{
		if (TVector::RECT == vec.getMode()) {
			os << '(' << vec.getX() << ',' << vec.getY() << ')';
		} else {
			os << '(' << vec.getLength() << ',' << vec.getAngle() << "°)";
		}

		return (os);
	}
}
