#pragma once
#include <iostream>
using namespace std;

class CMatrix
{
private:

	int m;
	int n;
	double **Cm;

public:

	CMatrix(const CMatrix &);
	~CMatrix();
	CMatrix();

	friend istream & operator >> (istream & is, CMatrix & a);
	friend ostream & operator << (ostream & os, CMatrix & a);

	friend CMatrix operator +(CMatrix, CMatrix);
	friend CMatrix operator -(CMatrix, CMatrix);
	CMatrix operator *(double k);
	friend CMatrix operator *(CMatrix, CMatrix);
};

