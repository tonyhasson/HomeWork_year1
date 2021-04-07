#include "Complex.h"

//constructors and destructor

Complex::Complex(double x, double y) :a(x), b(y)
{
	if (abs(y) < 0.00000001)
	{
		b = 0;
	}
	if (abs(x) < 0.00000001)
	{
		a = 0;
	}
}

Complex::Complex(const Complex& c)
{
	a = c.a;
	b = c.b;
}

Complex::~Complex()
{
}


//getters and setters

double Complex::get_a()
{
	return(a);
}
double Complex::get_b()
{
	return(b);
}
void Complex::set_a(double x)
{
	a = x;
}
void Complex::set_b(double y)
{
	b = y;
}


//other functions

Complex Complex::get_conjugate()
{
	Complex ret;
	ret.a = this->a;
	ret.b = this->b * -1;
	return(ret);
}

Complex Complex::get_inverse()
{
	return(*this ^ -1);
}

double Complex::get_len()
{
	return(sqrt((this->a) * (this->a) + (this->b) * (this->b)));
}

//overloading operators

ostream& operator<<(ostream& cout, const Complex& c)
{
	if (c.b > 0)
	{
		cout << c.a << "+" << c.b << "*i" << endl;
	}
	else if (c.b < 0)
	{
		cout << c.a << c.b << "*i" << endl;
	}
	else
	{
		cout << c.a << endl;
	}
	return(cout);
}

istream& operator>>(istream& cin, Complex& c)
{
	cout << "enter real number and imaginary number:" << endl;
	cin >> c.a >> c.b;
	return(cin);
}

Complex& Complex::operator=(const Complex& c)
{
	a = c.a;
	b = c.b;
	return(*this);
}

Complex& Complex::operator+=(const Complex& c)
{
	Complex copy(*this);
	copy.a += c.a;
	copy.b += c.b;
	*this = copy;
	return(*this);
}

Complex Complex::operator+(const Complex& c)const
{
	double x, y;
	x = a + c.a;
	y = b + c.b;
	Complex ret(x, y);
	return(ret);


}

Complex& Complex::operator-=(const Complex& c)
{
	Complex copy(*this);
	copy.a += c.a;
	copy.b += c.b;
	*this = copy;
	return(*this);
}

Complex Complex::operator-(const Complex& c)const
{
	double x, y;
	x = a - c.a;
	y = b - c.b;
	Complex ret(x, y);
	return(ret);


}

Complex& Complex::operator*=(const Complex& c)
{
	
	Complex copy(*this);
	copy.a = this->a * c.a - this->b * c.b;
	copy.b = this->b * c.a + this->a * c.b;
	*this = copy;
	return(*this);

}

Complex Complex::operator*(const Complex& c)const
{
	double x = a, y = b,new_x,new_y;
	new_x = x * c.a - y * c.b;
	new_y = y * c.a + x * c.b;
	Complex ret(new_x, new_y);
	return(ret);

}

Complex& Complex::operator/=(Complex& c)
{
	Complex ret;
	double temp;
	temp = pow(c.get_len(), 2);
	ret = (*this * c.get_conjugate()) / (temp);
	*this = ret;
	return(*this);
}

Complex Complex::operator/(Complex& c)const
{
	Complex ret;
	double temp;
	temp = (c.a) * (c.a) + (c.b) * (c.b);
	ret = (*this * c.get_conjugate()) / (temp);
	return(ret);
}

Complex Complex::operator/(const double& d)const
{
	Complex ret;
	ret.a = this->a / d;
	ret.b = this->b / d;
	return(ret);
}

Complex Complex::operator^(const int& num)const
{
	Complex ret(*this);
	if (num == -1)
	{
		ret = ret.get_conjugate() / pow(ret.get_len(), 2);
	}
	else
	{
		
		int i = 1;
		while (i < num)
		{
			ret = ret * *this;
			i++;
		}
	}
	return(ret);
}
Complex Complex::operator*(const double& d)const//made for matrix complex
{
	Complex temp(d);
	return(*this * temp);
}

Complex operator*(const double& d, const Complex& m)//made for matrix complex
{
	Complex temp = m * d;
	return temp;
}
