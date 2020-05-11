#include<iostream>
#include "stonewt.h"

namespace n_stonewt
{
	Stonewt::Stonewt(double g, Mode mode)
	{
		if (mode = GRAD)
		{
			m_mode = GRAD;
			m_g = g;
			m_kg = 0.0;
		}
		else {
			m_mode = KG;
			m_kg = g;
			m_g = 0.0;
		}
			
	}
	Stonewt::Stonewt(int kg, double g)
	{
		m_mode = MIXING;
		m_left = g / kg_g;
		m_kg = kg + m_left;
		m_g = (int)g % kg_g;
	}

	Stonewt::~Stonewt()
	{

	}

	Stonewt 
	Stonewt::operator+ (const Stonewt& stonewt) const
	{
		Stonewt result;
		result.m_kg = m_kg + stonewt.m_kg;
		result.m_g = m_g + stonewt.m_g;
		result.m_left = result.m_g / kg_g;
		result.m_kg += result.m_left;
		result.m_g = (int)result.m_g%kg_g;

		return result;
		
	}
	Stonewt 
	Stonewt::operator- (const Stonewt& stonewt) const
	{
		Stonewt result;
		double x1, x2;
		x1 = m_kg * kg_g + m_g;
		x2 = stonewt.m_kg*kg_g + stonewt.m_g;
		result.m_g = x1 - x2;
		result.m_kg = result.m_g / kg_g;
		result.m_g = (int)result.m_g%kg_g;
		return result;
	}
	Stonewt 
	Stonewt::operator* (const double m) const
	{
		Stonewt result;
		result.m_g = m_g * m;
		result.m_kg = result.m_g / kg_g + m_kg * m;
		result.m_g = (int)result.m_g%kg_g;
		return result;
	}

	ostream &operator<<(ostream &os, const Stonewt stonewt)
	{
		if (stonewt.m_mode == Stonewt::GRAD) {
			os << stonewt.m_g << " GRAD" ;
		}
		else if (stonewt.m_mode == Stonewt::KG) {
			os << stonewt.m_kg << " KG" ;
		}
		else {
			os << stonewt.m_kg << " KG " <<stonewt.m_g<<" GRAD";
		}
		return (os);
	}
}

