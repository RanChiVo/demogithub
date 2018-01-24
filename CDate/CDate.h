#pragma once
#include <iostream>

using namespace std;

class CDate
{
private:

	int Day;
	int Month;
	int Year;

public:

	CDate();
	CDate(int, int, int);
	void SetDate(int D, int M, int Y) { Day = D; Month = M; Year = Y; }
	bool check();
	int MaxDay(int, int);

	friend istream& operator >> (istream & is, CDate&);
	friend ostream& operator << (ostream & os, CDate);

	CDate operator++();
	CDate operator--();
	CDate operator+(int);
	CDate operator-(int);

	~CDate();
};

