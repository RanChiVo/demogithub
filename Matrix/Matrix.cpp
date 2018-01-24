#include "Matrix.h"

CMatrix::CMatrix(const CMatrix & x)
{
	m = x.m;
	n = x.n;
	Cm = new double*[m];
	for (int i = 0; i < m; i++)
	{
		Cm[i] = new double[n];
		for (int j = 0; j < m; j++)
		{
			Cm[i][j] = x.Cm[i][j];
		}
	}
}

CMatrix::~CMatrix()
{
	for (int i = 0; i < m; i++)
		delete[] Cm[i];

	delete[]Cm;
}

CMatrix::CMatrix()
{
}

CMatrix CMatrix::operator*(double k)
{
	CMatrix S;
	S.m = m;
	S.n = n;
	S.Cm = new double*[S.m];

	for (int i = 0; i < m; i++)
	{
		S.Cm[i] = new double[S.n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			S.Cm[i][j] = Cm[i][j] * k;
		}
	}
	return S;
}

istream & operator >> (istream & is, CMatrix & a)
{
	cout << "so hang ";
	is>> a.m;
	cout << "So cot: ";
	cin >>a.n;

	a.Cm = new double*[a.m];

	for (int i = 0; i < a.m; i++)
	{
		a.Cm[i] = new double[a.n];

		for (int j = 0; j < a.n; j++)
		{
			is >> a.Cm[i][j];
		}
	}

	return is;
}

ostream & operator<<(ostream & os, CMatrix & a)
{
	os << endl;

	for (int i = 0; i < a.m; i++)
	{
		os << "[";
		for (int j = 0; j < a.n; j++)
		{
			if (j == a.n - 1)
			{
				cout << a.Cm[i][j] << "]" << endl;
				break;
			}
			os << a.Cm[i][j] << ", ";
		}
	}

	return os;
}

CMatrix operator+(CMatrix A, CMatrix B)
{
	CMatrix S;
	S.m = A.m;
	S.n =A. n;
	S.Cm = new double*[S.m];

	for (int i = 0; i <A.m; i++)
	{
		S.Cm[i] = new double[S.n];
	}

	for (int i = 0; i < A.m; i++)
	{
		for (int j = 0; j < A.n; j++)
		{
			S.Cm[i][j] = A.Cm[i][j] + B.Cm[i][j];
		}
	}

	return S;
}

CMatrix operator-(CMatrix A, CMatrix B)
{
	for(int i=0;i<B.m;i++)
		for (int j = 0; j < B.n; j++)
		{
			B.Cm[i][j] *= -1;
		}
	CMatrix c;
	c.Cm =new double*[c.m];

	for (int i = 0; i < c.n; i++)
	{
		for (int j = 0; i < c.m; j++)
		{
			c.Cm[i][j] = 0;
		}
	}

	c = A + B;

	return c;
}

CMatrix operator*(CMatrix A, CMatrix B)
{

	CMatrix T;

	T.m = A.m;
	T.n = A.n;
	T.Cm = new double*[T.m];

	for (int i = 0; i < T.n; i++)
	{
		T.Cm[i] = new double[T.n];
	}

	for (int i = 0; i < A.n; i++)
	{
		for (int k = 0; k < A.n; k++)
		{
			T.Cm[i][k] = 0;
			for (int j = 0; j < A.n; j++)
			{
				T.Cm[i][k] = T.Cm[i][k] + B.Cm[i][j] * A.Cm[j][k];

			}
		}
	}
	return T;
}

