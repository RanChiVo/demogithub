#pragma once
#include <iostream>

using namespace std;

class SoPhuc
{
private:
	 
	float PThuc;
	float PAo;

public:
	SoPhuc();
	SoPhuc(float, float);
	
	void SetSophuc(float T, float A) { PThuc = T; PAo = A; }
	float GetThuc() { return PThuc; }
	float GetAO() { return PAo; }

	friend istream & operator >> (istream & is, SoPhuc &);
	friend ostream & operator <<(ostream& os, SoPhuc);

	SoPhuc operator +(SoPhuc);
	SoPhuc operator-(SoPhuc);
	SoPhuc operator*(SoPhuc);
	SoPhuc operator/(SoPhuc);

	~SoPhuc();
};

