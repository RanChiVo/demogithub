#include "Phanso.h"



istream & operator >> (istream & inDevice, Phanso & PS)
{
	PS = PS.reduce();

	inDevice >> PS.TuSo;

	while (!PS.MauSo)
	{
		cout << "\n Enter wrong";
		inDevice >> PS.MauSo;
	}

	return inDevice;
}

ostream & operator<<(ostream & outDevice, Phanso &PS)
{
	PS = PS.reduce();

	outDevice << PS.TuSo;

	if (PS.TuSo != 0 && PS.MauSo != 1)
	{
		outDevice << "/" << PS.MauSo;
	}

	return outDevice;
}

Phanso operator+(Phanso a, Phanso b)
{
	Phanso c;

	c.TuSo = a.TuSo*b.MauSo + a.MauSo*b.TuSo;
	c.MauSo = a.MauSo*b.MauSo;

	return c;
}

Phanso operator-(Phanso a, Phanso b)
{
	return a + -b;
}

Phanso operator*(Phanso a, Phanso b)
{
	Phanso c;

	c.TuSo = a.TuSo*b.TuSo;
	c.MauSo = a.MauSo*b.MauSo;

	return c;
}

Phanso operator/(Phanso a, Phanso b)
{
	Phanso c;

	c.TuSo = a.TuSo*b.MauSo;
	c.MauSo = a.MauSo*b.TuSo;

	return c;
}

bool operator>(Phanso a, Phanso b)
{
	if (a.TuSo*b.MauSo > a.MauSo*b.TuSo)

		return true;

	return false;
}

bool operator<(Phanso a, Phanso b)
{
	a = a.reduce();
	b = b.reduce();

	if (a.TuSo*b.MauSo < a.MauSo*b.TuSo)

		return true;

	return false;
}

bool operator>=(Phanso a, Phanso b)
{
	return (!(a < b));
}

bool operator<=(Phanso a, Phanso b)
{
	return (!(a > b));
}

bool operator==(Phanso a, Phanso b)
{

	return ((a.TuSo == b.TuSo) && (a.MauSo == b.MauSo));
}

bool operator!=(Phanso a, Phanso b)
{
	return (!(a == b));
}

long Phanso::UCLN(long a, long b)
{
	a = abs(a); b = abs(b);

	if (a == b) return a;

	if (a > b) return  UCLN(a - b, b);

	return UCLN(b - a, a);
}

Phanso::Phanso()
{
	TuSo = 2;
	MauSo = 3;
}

Phanso::Phanso(long t, long m)
{
	TuSo = t;
	MauSo = m;
}

Phanso Phanso::reduce()
{
	int m;

	m = UCLN(TuSo, MauSo);
	TuSo /= m;
	MauSo /= m;

	return *this;
}

Phanso & Phanso::operator+=(Phanso &a)
{
	(*this) = (*this) + a;

	return (*this);
}

Phanso & Phanso::operator-=(Phanso &a)
{
	(*this) = (*this) - a;

	return (*this);
}

Phanso & Phanso::operator*=(Phanso &a)
{
	(*this) = (*this) * a;

	return (*this);
}

Phanso & Phanso::operator/=(Phanso &a)
{
	(*this) = (*this) / a;

	return (*this);
}

Phanso& Phanso::operator++()
{
	TuSo = MauSo + TuSo;

	return(*this);
}

Phanso Phanso::operator++(int)
{
	Phanso t = *this;

	++(*this);

	return t;
}

Phanso& Phanso::operator--()
{
	TuSo = MauSo - TuSo;

	return (*this);
}

Phanso Phanso::operator--(int)
{
	Phanso t = *this;

	--(*this);

	return t;
}

Phanso::~Phanso()
{
}




