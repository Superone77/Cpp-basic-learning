#pragma once
#include <iostream>

using namespace std;
namespace n_stonewt
{
	
	class Stonewt
	{
	public:
		enum Mode { GRAD, KG, MIXING };
	public:
		const int kg_g = 1000;
		double m_g;
		double m_left;
		double m_kg;
		Mode m_mode;
	public:
		Stonewt(double g,Mode mode=KG);
		Stonewt(int kg=0, double g=0);
		~Stonewt();

		Stonewt operator+ (const Stonewt& stonewt) const;
		Stonewt operator- (const Stonewt& stonewt) const;
		Stonewt operator* (const double m) const;

		friend ostream &operator<<(ostream &os, const Stonewt stonewt);



	};
}
