#include <iostream>
#include <cstring>

using namespace std;

class Port
{
	private:
		char * brand;
		char style[20]; // i.e., tawny, ruby, vintage
		int bottles;
	public:
		explicit Port(const char * br = "none", const char * st = "none", int b = 0);
		Port(const Port & p); // copy constructor
		virtual ~Port() { delete [] brand; }
		Port & operator=(const Port & p);
		virtual void Show() const;
		Port & operator+=(int b); // adds b to bottles
		Port & operator-=(int b); // subtracts b from bottles, if available
		int BottleCount() const { return bottles; }
		friend ostream & operator<<(ostream & os, const Port & p);
};

static char*
cpNewStr (const char* p_src_txt)
{
	unsigned	str_len = strlen(p_src_txt);
	char*	p_des_txt = new char [str_len + 1];
	strcpy(p_des_txt, p_src_txt);

	return (p_des_txt);
}

static void
cpStr (char* p_des_txt, const char* p_src_txt, unsigned des_arr_size)
{
	unsigned	str_len = strlen(p_src_txt) < des_arr_size-1 ? strlen(p_src_txt) : des_arr_size-1;
	strncpy(p_des_txt, p_src_txt, str_len);
	p_des_txt[str_len] = '\0';
}

Port::Port (const char * br, const char * st, int b)
	: brand(cpNewStr(br)), bottles(b)
{
	cpStr(style, st, 20);
}

Port::Port(const Port & p)
	: brand(cpNewStr(p.brand)), bottles(p.bottles)
{
	cpStr(style, p.style, 20);
}

void
Port::Show() const
{
	cout 	<< "Brand: " << brand << endl
			<< "Style: " << style << endl
			<< "Bottles: " << bottles << flush;
}

Port &
Port::operator=(const Port & p)
{
	if (&p == this) {
		return (*this);
	}

	delete [] brand;
	brand = cpNewStr(p.brand);

	cpStr(style, p.style, 20);

	bottles = p.bottles;

	return (*this);
}

Port &
Port::operator+=(int b)
{
	bottles += b;
	return (*this);
}

Port &
Port::operator-=(int b)
{
	bottles -= b;
	return (*this);
}

ostream &
operator<< (ostream & os, const Port & p)
{
	cout << p.brand << ", " << p.style << ", " << p.bottles << flush;
	return (os);
}

class VintagePort : public Port // style necessarily = "vintage"
{
	private:
		char * nickname; // i.e., "The Noble" or "Old Velvet", etc.
		int year; // vintage year
	public:
		explicit VintagePort(const char * br = "", int b = 0, const char * nn = "", int y = 0);
		VintagePort(const VintagePort & vp);
		virtual ~VintagePort() { delete [] nickname; }
		VintagePort & operator=(const VintagePort & vp);
		virtual void Show() const;
		friend ostream & operator<<(ostream & os, const VintagePort & vp);
};

VintagePort::VintagePort (const char * br, int b, const char * nn, int y)
	: Port(br, "vintage", b), nickname(cpNewStr(nn)), year(y)
{
	;
}

VintagePort::VintagePort (const VintagePort & vp)
	: Port(vp), nickname(cpNewStr(vp.nickname)), year(vp.year)
{
	;
}

void
VintagePort::Show () const
{
	Port::Show();
	cout << endl;
	cout << "Nickname: " << nickname << endl;
	cout << "Year: " << year << flush;
}

VintagePort &
VintagePort::operator= (const VintagePort & vp)
{
	if (&vp == this) {
		return (*this);
	}

	Port::operator=(vp);

	delete [] nickname;
	nickname = cpNewStr(vp.nickname);

	year = vp.year;

	return (*this);
}

ostream &
operator<< (ostream & os, const VintagePort & vp)
{
	os << Port(vp);
	cout << ", " << vp.nickname << ", " << vp.year << flush;
	return (os);
}

int
main()
{
	Port	port1("gallo", "tawny", 20);
	cout << port1 << endl << endl;

	VintagePort	vp("gallo", 24, "nice", 16);
	VintagePort	vp2(vp);
	cout << vp2 << endl << endl;

	VintagePort	vp3;
	vp3 = vp;
	cout << vp3 << endl << endl;

	Port*	p_port;
	p_port = &port1;
	p_port->Show();
	cout << endl;
	p_port = &vp;
	p_port->Show();
	cout << endl;


	return 0;
}
