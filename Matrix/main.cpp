#include "Matrix.h"


int main()
{

	CMatrix A, B;
	cin>>A;
	cin>>B;
	cout << "Matrix Ma: ";
	cout<<A;
	cout << "Matrix Mb: ";
	cout<<B;

	
	cout << A + B << endl;

	cout << A - B << endl;
	 
	cout << A * 3 << endl;

	cout << A*B << endl;

	system("pause");
	return 0;
}