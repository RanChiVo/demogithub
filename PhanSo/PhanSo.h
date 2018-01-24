#pragma once
#include  <iostream>

using namespace std;

class Phanso
{
private:

	long TuSo;
	long MauSo;
	long UCLN(long a, long b);
	Phanso reduce();

public:

	Phanso();
	Phanso(long, long);
	Phanso(long t) { SetPS(t, 1); }
	void SetPS(long t, long m) { TuSo = t; MauSo = m; }
	long GetTu() { return TuSo; }
	long GetMau() { return MauSo; }

	friend istream& operator >> (istream& inDevice, Phanso &PS);
	friend ostream& operator <<(ostream& outDevice, Phanso &PS);
	
	friend	Phanso operator +(Phanso, Phanso);
	friend Phanso operator-(Phanso, Phanso);
	friend Phanso operator*(Phanso, Phanso);
	friend Phanso operator / (Phanso, Phanso);

	friend bool operator>(Phanso, Phanso);
	friend bool operator<(Phanso, Phanso);
	friend bool operator>=(Phanso, Phanso);
	friend bool operator<=(Phanso, Phanso);
	friend bool operator==(Phanso, Phanso);
	friend bool operator!=(Phanso, Phanso);

	Phanso& operator +=(Phanso&);
	Phanso& operator -=(Phanso&);
	Phanso& operator *=(Phanso&);
	Phanso& operator /=(Phanso&);

	Phanso& operator++();
	Phanso operator++(int);
	Phanso& operator--();
	Phanso operator--(int);
	Phanso operator -()const { return Phanso(-TuSo, MauSo); }

	~Phanso();

};

