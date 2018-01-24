#include "PhanSo.h"

int main()
{
	Phanso a(2, 3), b(3, 4);

	cout << (a + b) << endl;
	cout << (a - b) << endl;
	cout << (a*b) << endl;
	cout <<( a / b) << endl;

	if (a > b)
	{
		cout << a<<endl;//Khong lam thay doi gia tri phan so ban dau 
	}

	else
	{
		cout << b<<endl;
	}

	cout << a + 7;
	cout << a - 5;

	a += b;
	cout << a<<endl;
	a -= b;
	cout << a << endl;
	a *= b;
	cout << a<< endl;
	a /= b;
	cout << a<< endl;

	cout << ++a << endl;
	cout << a++ << endl;
	cout << a-- << endl;
	cout << --a << endl;

	system("pause");
	return 0;
}