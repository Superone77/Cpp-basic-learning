#pragma once

#include <iostream>

namespace n_complex
{
	using std::ostream;
	using std::istream;

	class TComplex
	{
		public:
			explicit TComplex (double real = 0, double imaginary = 0);

			friend ostream& operator<< (ostream& os, const TComplex& coplx);
			friend istream& operator>> (istream& is, TComplex& coplx);
			friend TComplex operator~ (const TComplex& coplx);
			friend TComplex operator+ (const TComplex& lvalue, const TComplex& rvalue);
			friend TComplex operator- (const TComplex& lvalue, const TComplex& rvalue);
			friend TComplex operator* (const TComplex& lvalue, const TComplex& rvalue);
			friend TComplex operator* (double n, const TComplex& coplx);
		
		private:
			double m_real;
			double m_imaginary;
	};
}
