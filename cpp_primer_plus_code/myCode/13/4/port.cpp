#pragma warning (disable: 4996)
#include"port.h"
#include<iostream>
#include<string>

using namespace std;

static char*
cpNewStr(const char* p_src_txt)
{
	unsigned	str_len = strlen(p_src_txt);
	char*	p_des_txt = new char[str_len + 1];
	strcpy(p_des_txt, p_src_txt);

	return (p_des_txt);
}
static void
cpStr(char* p_des_txt, const char* p_src_txt, unsigned des_arr_size)
{
	unsigned	str_len = strlen(p_src_txt) < des_arr_size - 1 ? strlen(p_src_txt) : des_arr_size - 1;
	strncpy(p_des_txt, p_src_txt, str_len);
	p_des_txt[str_len] = '\0';
}

Port::Port(const char *br, const char*st, int b )
	: brand(cpNewStr(br)), bottles(b)
{
	
	for (int i = 0; i < 20; i++)
		style[i] = st[i];
}

Port::Port(const Port & p)
	: brand(cpNewStr(p.brand)), bottles(p.bottles)
{

	for (int i = 0; i < 20; i++)
		style[i] = p.style[i];
}

Port &
Port::operator=(const Port &p) 
{
	brand = cpNewStr(p.brand);
	for (int i = 0; i < 20; i++)
		style[i] = p.style[i];
	bottles = p.bottles;
	return *this;
}

Port &
Port::operator+=(int b)
{
	bottles += b;
	return *this;
}

Port &
Port::operator-=(int b)
{
	bottles -= b;
	return *this;
}

void
Port::Show() const
{
	cout << endl;
	cout << "Brand: " << brand << endl;
	cout << "Kind: " << style << endl;
	cout << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles << endl;
	return os;
}

