#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
	friend Complex operator*(const double& d, const Complex& m);//made for matrix complex

public:
	Complex(double x=0,double y=0);
	Complex(const Complex&);
	~Complex();
	double get_a();
	double get_b();
    void set_a(double x);
	void set_b(double y);
	Complex get_conjugate();
	Complex get_inverse();
	double get_len();
	Complex& operator=(const Complex&);
	Complex& operator+=(const Complex&);
	Complex operator+(const Complex&)const;
	Complex& operator*=(const Complex&);
	Complex operator*(const Complex&)const;
	Complex& operator-=(const Complex&);
	Complex operator-(const Complex&)const;
	Complex& operator/=(Complex&);
	Complex operator/(Complex&)const;
	Complex operator/(const double&)const;
	Complex operator^(const int&)const;
	//operator overload with double
	Complex operator*(const double&)const;//made for matrix complex



private:
	double a;
	double b;
};
