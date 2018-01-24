#pragma once
#include <iostream>

using namespace std;

class DaThuc
{
private:
	
	float *a;
	int n;//so mu cao nhat

public:


	DaThuc();
	DaThuc(int);
	DaThuc & operator=(const DaThuc &);

	friend istream & operator >> (istream & is, DaThuc &);
	friend ostream & operator <<(ostream & os, DaThuc &);

	friend DaThuc operator+(DaThuc, DaThuc);
	friend DaThuc operator-(DaThuc, DaThuc);
	friend DaThuc operator*(DaThuc, DaThuc);
	friend DaThuc operator/(DaThuc, DaThuc);

	~DaThuc();
};

