#pragma once
#include"port.h"


class VintagePort : public Port // style necessarily = "vintage"
{
private:
	char * nickname; // i.e., "The Noble" or "Old Velvet", etc.
	int year; // vintage year
public:
	explicit VintagePort(const char * br = "", int b = 0, const char * nn = "", int y = 0);
	VintagePort(const VintagePort & vp);
	virtual ~VintagePort() { delete[] nickname; }
	VintagePort & operator=(const VintagePort & vp);
	virtual void Show() const;
	friend ostream & operator<<(ostream & os, const VintagePort & vp);
};