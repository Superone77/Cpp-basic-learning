#include <iostream>
#include <limits>
#include "TComplex.h"


namespace n_complex
{
	using std::cout;
	using std::ostream;
	using std::numeric_limits;
	using std::streamsize;

	// ====================================
	// 辅助函数
	// ====================================

	// ====================================
	// 成员函数
	// ====================================

	TComplex::TComplex (double real, double imaginary)
	{
		m_real = real;
		m_imaginary = imaginary;
	}

	// ====================================
	// 重载运算符
	// ====================================
	
	ostream&
	operator<< (ostream& os, const TComplex& coplx)
	{
		os << '(' << coplx.m_real << ", " << coplx.m_imaginary << "i)";
		return (os);
	}

	istream&
	operator>> (istream& is, TComplex& coplx)
	{
		cout << "real: ";
		is >> coplx.m_real;
		if (!is) {
			is.ignore(numeric_limits<streamsize>::max(), '\n');	// 清空输入缓冲区内容
			return (is);
		}

		cout << "imaginary: ";
		is >> coplx.m_imaginary;
		is.ignore(numeric_limits<streamsize>::max(), '\n');	// 清空输入缓冲区内容
		return (is);
	}

	TComplex
	operator~ (const TComplex& coplx)
	{
		return (TComplex(coplx.m_real, -coplx.m_imaginary));
	}

	TComplex
	operator+ (const TComplex& lvalue, const TComplex& rvalue)
	{
		return (TComplex(lvalue.m_real + rvalue.m_real, lvalue.m_imaginary + rvalue.m_imaginary));
	}

	TComplex
	operator- (const TComplex& lvalue, const TComplex& rvalue)
	{
		return (TComplex(lvalue.m_real - rvalue.m_real, lvalue.m_imaginary - rvalue.m_imaginary));
	}

	TComplex
	operator* (const TComplex& lvalue, const TComplex& rvalue)
	{
		return (TComplex(	lvalue.m_real * rvalue.m_real - lvalue.m_imaginary * rvalue.m_imaginary,
				   			lvalue.m_real * rvalue.m_imaginary + lvalue.m_imaginary * rvalue.m_real	));
	}

	TComplex
	operator* (double n, const TComplex& coplx)
	{
		return (TComplex(n*coplx.m_real, n*coplx.m_imaginary));
	}
}
