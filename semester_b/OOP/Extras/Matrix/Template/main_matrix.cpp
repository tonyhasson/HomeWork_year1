#include "Matrix.cpp"
#include "Complex.h"

void main()
{
	Matrix<Complex> m1,m2,m3,m4;
	cin >> m1;
	cin >> m2;
	cout <<m1<<m2;
	m1 += m2;
	cout << m1;
	m3 = m1 + m2;
	cout << m3;
	m3 = 5 * m2;
	cout << m3;
	m3[1][1]=2;
	cout << m3;
	m4 = m3 ^ 4;
	cout << m4;
	/*Matrix<double> m(2, 2);
	m[0][0] = 2;
	m[1][1] = 2;
	cout << m << endl;
	m = m;
	const Matrix<double> s = -m;
	cout << m << endl << s << endl;
	m = s + 2 * -m * m * 2 - s;
	cout << m << endl << s << endl;
	cout << s[1][1] << endl;*/
	
	
}
