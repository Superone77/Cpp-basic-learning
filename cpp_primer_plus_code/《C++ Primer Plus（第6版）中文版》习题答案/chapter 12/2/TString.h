#pragma once

#include <iostream>

namespace n_string
{
	class TString
	{
		public:
			static const unsigned	k_buffer_max_size = 256;

		public:
			TString (const char* text = "");	// ！非explicit
			TString (const TString& str);
			~TString ();

			unsigned getLength (void) const;

			const char* toCstr (void) const;

			void stringup (void);
			void stringlow (void);

			unsigned has (char ch) const;

			TString& operator= (const TString& str);
			TString& operator+= (const TString& str);

			char& operator[] (unsigned idx);
			const char& operator[] (unsigned idx) const;

			friend std::istream& operator>> (std::istream& is, TString& str);

		
		private:
			void m_assignMember (const char* text);

		private:
			char*		mp_text;
			unsigned	m_text_length;
	};

	std::ostream& operator<< (std::ostream& os, const TString& str);

	bool operator< (const TString& lvalue, const TString& rvalue);
	bool operator> (const TString& lvalue, const TString& rvalue);
	bool operator== (const TString& lvalue, const TString& rvalue);
	bool operator<= (const TString& lvalue, const TString& rvalue);
	bool operator>= (const TString& lvalue, const TString& rvalue);

	TString operator+ (const TString& lvalue, const TString& rvalue);
}
