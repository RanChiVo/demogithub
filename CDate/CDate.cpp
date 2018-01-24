#include "CDate.h"



CDate::CDate()
{
}

CDate::CDate(int D, int M, int Y)
{
	Day = D;
	Month = M;
	Year = Y;
}

CDate CDate::operator++()
{
	Day++;

	if (Day > MaxDay(Month, Year))
	{
		Day = 1;
		Month++;

		if (Month > 12)
		{
			Month = 1;
			Year++;
		}
	}
	
	return (*this);
}

CDate CDate::operator--()
{
	Day -= 1;

	if (Day == 0)
	{
		if (Month - 1 == 0)
		{
			Day = 31;
			Month = 12;
			Year--;
		}
		else
		{
			Day = MaxDay(Month - 1, Year);
			Month--;
		}
	}

	return (*this);
}

CDate CDate::operator+(int x)
{
	CDate c = *this;

	for (int i = 0; i < x; i++)
	{
		++c;
	}

	return c;
}

CDate CDate::operator-(int x)
{
	CDate c = *this;

	for (int i = 0; i < x; i++)
	{
		--c;
	}

	return c;
}

bool CDate::check()
{
	if (Year < 0 || Month <= 0 || Month>12 || Day <= 0)  return false;

	switch (Month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	{
		if (Day > 31) return false;
		break;
	}
	case 4: case 6: case 9: case 11:
	{
		if (Day > 30) return false;
		break;
	}
	case 2:
	{
		if (Year % 400 == 0 || Year % 4 == 0 && Year % 100 != 0)
		{
			if (Day > 29) return false;
		}

		else
			if (Day > 28)return false;
		break;
	}
	}
	return true;
}

int CDate::MaxDay(int M, int Y)
{
	if ((M == 1) || (M == 3) || (M == 5) || (M == 7) || (M == 8) || (M == 10) || (M == 12))
	{
		return 31;
	}

	if (M == 2)
	{
		if (Y % 400 == 0 || (Y % 4 == 0 && Y % 100 != 0))
		{
			return 29;
		}
		return 28;
	}
	return 30;
}

CDate::~CDate()
{
}

istream & operator >> (istream & is, CDate& CD)
{
	do
	{
		is >> CD.Day >> CD.Month >> CD.Year;

	} while (!CD.check());

	return is;
}

ostream & operator << (ostream & os, CDate CD)
{
	os << CD.Day <<"/" << CD.Month << "/" << CD.Year;
	 
	return os;
}
