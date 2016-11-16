#include "t_complex.h"
using namespace std;

int main(){
	complex<int> c1(3, 4), c2(4, 5);
	complex<float> c3(3.2, 4.5), c4(6.7, 1.2);
	complex <double> c5(5.67, 0.123), c6(7.43, 1.001);

	cout << "c1 =" << c1 << endl;
	cout << "c2 = " << c2 << endl;

	cout << "c1 + c2 = " << c1 + c2 << endl;
	cout << "c1 * c2 = " << c1 * c2 << endl;

	cout << c3 << " * " << c4 << " = " << c3*c4 << endl;
	c1 = c2; //testing the gets operator
	if (c1 == c2)
	{
		cout << "it's the same" << endl;
	}
	else
	{
		cout << "It's not the same" << endl;
	}

	system("pause");
}