#include <iostream>
#include <cstring>
#include <cctype>
#include "TString.h"


namespace n_string
{
	using std::ostream;
	using std::istream;


	// ====================================
	// 文件内辅助函数
	// ====================================

	// ====================================
	// 共有成员函数
	// ====================================

	TString::TString (const char* text)
	{
		m_assignMember(text);
	}

	TString::TString (const TString& str)
	{
		m_assignMember(str.toCstr());
	}

	TString::~TString ()
	{
		delete [] mp_text;
	}

	unsigned
	TString::getLength (void) const
	{
		return (m_text_length);
	}

	const char*
	TString::toCstr (void) const
	{
		return (mp_text);
	}
	
	void
	TString::stringup (void)
	{
		for (unsigned i = 0; i < m_text_length; ++i) {
			mp_text[i] = (char)toupper((int)mp_text[i]);
		}
	}
	
	void
	TString::stringlow (void)
	{
		for (unsigned i = 0; i < m_text_length; ++i) {
			mp_text[i] = (char)tolower((int)mp_text[i]);
		}
	}

	unsigned
	TString::has (char ch) const
	{
		unsigned	ch_cnt = 0;
		for (unsigned i = 0; i < m_text_length; ++i) {
			if (ch == mp_text[i]) {
				++ch_cnt;
			}
		}

		return (ch_cnt);
	}
	
	// ====================================
	// 私有成员函数
	// ====================================

	void
	TString::m_assignMember (const char* text)
	{
		m_text_length = strlen(text);
		mp_text = new char [m_text_length + 1];
		strcpy(mp_text, text);
	}



	// ====================================
	// 重载运算符
	// ====================================
	
	TString&
	TString::operator= (const TString& str)
	{
		if (&str == this) {
			return (*this);
		}

		delete [] mp_text;
		m_assignMember(str.toCstr());
		return (*this);
	}

	TString&
	TString::operator+= (const TString& str)
	{
		return (*this = *this + str);
	}

	char&
	TString::operator[] (unsigned idx)
	{
		return (mp_text[idx]);
	}

 	const char&
	TString::operator[] (unsigned idx) const
	{
		return (mp_text[idx]);
	}

	ostream&
	operator<< (ostream& os, const TString& str)
	{
		os << str.toCstr();
		return (os);
	}

	istream&
	operator>> (istream& is, TString& str)
	{
		char	txt[TString::k_buffer_max_size];

		if (is >> txt) {
			str = txt;
		}
		is.ignore(TString::k_buffer_max_size, '\n');

		return (is);
	}

	bool
	operator< (const TString& lvalue, const TString& rvalue)
	{
		return (strcmp(lvalue.toCstr(), rvalue.toCstr()) < 0);
	}

	bool
	operator> (const TString& lvalue, const TString& rvalue)
	{
		return (rvalue < lvalue);
	}

	bool
	operator== (const TString& lvalue, const TString& rvalue)
	{
		return (!(lvalue < rvalue) && !(lvalue > rvalue));
	}

	bool
	operator<= (const TString& lvalue, const TString& rvalue)
	{
		return (!(lvalue > rvalue));
	}

	bool
	operator>= (const TString& lvalue, const TString& rvalue)
	{
		return (!(lvalue < rvalue));
	}

	TString
	operator+ (const TString& lvalue, const TString& rvalue)
	{
		char*	p_txt = new char [lvalue.getLength() + rvalue.getLength() + 1];
		strcpy(p_txt, lvalue.toCstr());
		strcat(p_txt, rvalue.toCstr());
		TString	tmp(p_txt);
		delete [] p_txt;

		return (tmp);
	}
}
