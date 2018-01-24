#include "SoPhuc.h"



SoPhuc::SoPhuc()
{
}

SoPhuc::SoPhuc(float T, float A)
{
	PThuc = T;
	PAo = A;
}


SoPhuc SoPhuc::operator+(SoPhuc SP)
{
	SoPhuc c;

	c.PThuc = PThuc + SP.PThuc;
	c.PAo = PAo + SP.PAo;

	return c;
}

SoPhuc SoPhuc::operator-(SoPhuc SP)
{
	SoPhuc c;

	c.PThuc = PThuc - SP.PThuc;
	c.PAo = PAo + SP.PAo;

	return c;
}

SoPhuc SoPhuc::operator*(SoPhuc SP)
{
	SoPhuc c;

	c.PThuc = PThuc*SP.PThuc - PAo*SP.PAo;
	c.PAo = PThuc * SP.PAo + PAo*SP.PThuc;

	return c;
}

SoPhuc SoPhuc::operator/(SoPhuc SP)
{
	SoPhuc c;

	c.PThuc = (PThuc*SP.PThuc + PAo*SP.PAo) / (SP.PThuc*SP.PThuc + SP.PAo*SP.PAo);
	c.PAo = (PAo*SP.PThuc - PThuc*SP.PAo) / (SP.PThuc*SP.PThuc + SP.PAo*SP.PAo);;

	return c;
}

SoPhuc::~SoPhuc()
{
}

istream & operator >> (istream & is, SoPhuc &SP)
{
	is >> SP.PThuc >> SP.PAo;

	return is;
}

ostream & operator<<(ostream & os, SoPhuc SP)
{
	os << SP.PThuc;

	if (SP.PAo > 0)
	{
		os << "+";
	}

	os << SP.PAo << "i" << endl;

	return os;
}
