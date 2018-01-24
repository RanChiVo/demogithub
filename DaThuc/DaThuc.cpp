#include "DaThuc.h"



DaThuc::DaThuc()
{
}

DaThuc::DaThuc(int sz)
{
	if (sz <= 0)
	{
		n = 0;
		delete[]a;
		a = nullptr;
	}

	n = sz;

	a = new float[sz];

	for (int i = 0; i < sz; i++)
	{
		a[i] = 0;
	}
}

DaThuc & DaThuc::operator=(const DaThuc &b)
{
	if (this != &b)
	{
		delete[]a;

		a = new float[b.n];

		for (int i = 0; i < b.n; i++)
		{
			a[i] = b.a[i];
		}
	}

	return *this;
}


DaThuc::~DaThuc()
{
}

istream & operator >> (istream & is, DaThuc & b)
{
	cout << "\nNhap so bac cao nhat cua da thuc:";
	is >> b.n;

	b.a = new float[b.n + 1];

	cout << "\nNhap cac he so cua da thuc: " << endl;

	for (int i = 0; i <= b.n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> b.a[i];
	}
	cout << endl;

	return is;
}

ostream & operator<<(ostream & os, DaThuc & b)
{
	for (int i = 0; i <= b.n; i++)
	{

		if (b.a[i] != 0)
		{
			if (i == 0 && b.a[0] == 0 || i == 0 || b.a[i] < 0)
				cout << b.a[i] << "x^" << i;
			else
				cout << " + " << b.a[i] << "x^" << i;
		}
	}
	cout << endl;

	return os;
}

DaThuc operator+(DaThuc A, DaThuc B)
{
	int M;
	M = ((A.n > B.n) ? A.n : B.n);
	DaThuc c(M);

	for (int i = 0; i <= M; i++)
	{
		if (A.n >= i && B.n >= i)
		{
			c.a[i] = A.a[i] + B.a[i];
		}

		else if (B.n < i)
		{
			c.a[i] = A.a[i];
		}

		else if (A.n < i)
		{
			c.a[i] = B.a[i];
		}
	}

	return c;
}

DaThuc operator-(DaThuc A, DaThuc B)
{
	for (int i = 0; i < A.n; i++)
	{
		A.a[i] *= -1;
	}

	DaThuc c = A + B;

	return c;
}

DaThuc operator*(DaThuc A, DaThuc B)
{
	int M;
	M = A.n + B.n;

	DaThuc c(M);

	for (int i = 0; i <= M; i++)
	{
		c.a[i] = 0;
	}

	for (int i = 0; i <= A.n; i++)
	{
		for (int j = 0; j <= B.n; j++)
		{
			c.a[i + j] = c.a[i + j] + A.a[i] * B.a[j];
		}
	}
	return c;
}

DaThuc operator/(DaThuc, DaThuc)
{
	return DaThuc();
}
