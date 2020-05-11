#pragma warning (disable: 4996)
#include "vintageport.h"
#include"port.h"

using namespace std;

static char*
cpNewStr(const char* p_src_txt)
{
	unsigned	str_len = strlen(p_src_txt);
	char*	p_des_txt = new char[str_len + 1];
	strcpy(p_des_txt, p_src_txt);

	return (p_des_txt);
}


VintagePort::VintagePort(const char * br, int b, const char * nn, int y)
	:Port(br,"Vintage",b), nickname(cpNewStr(nn)), year(y)
{
	;
}

VintagePort::VintagePort(const VintagePort &vp)
	: Port(vp), nickname(cpNewStr(vp.nickname)), year(vp.year)
{
	;
}

void 
VintagePort::Show() const
{
	Port::Show();
	cout << endl;
	cout << "Nickname: " << nickname << endl;
	cout << "Year: " << year << flush;
}

VintagePort &
VintagePort::operator=(const VintagePort & vp)
{
	if (&vp == this)
		return *this;
	Port::operator=(vp);
	delete[] nickname;
	nickname = cpNewStr(vp.nickname);

	year = vp.year;
	return (*this);
}

ostream &
operator<<(ostream &os, const VintagePort & vp)
{
	os << Port(vp);
	cout << ", " << vp.nickname << ", " << vp.year << flush;
	return (os);
}