#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Matrix
{
	friend ostream& operator<<(ostream&, const Matrix&);
	friend istream& operator>>(istream&, Matrix&);
	friend Matrix operator*(const double&, const Matrix&);
	friend void fill_mat(Matrix& m);
    friend void Print_mat(Matrix& m);
	
public:
	Matrix(int x=0,int y=0);
	Matrix(const Matrix&);
	~Matrix();
	int get_row();
	int get_col();
	double** get_mat();
	void set_row(int r);
	void set_col(int c);
	void Create_mat();
	//overloading operators with matrices
	Matrix& operator=(const Matrix&);
	Matrix& operator=(const double);
	double* operator[](const int&)const;
	Matrix& operator+=(const Matrix&);
	Matrix operator+(const Matrix&)const;
	Matrix& operator*=(const Matrix&);
	Matrix operator*(const Matrix&)const;
	Matrix& operator-=(const Matrix&);
	Matrix operator-(const Matrix&)const;
	Matrix operator-()const;
	Matrix operator^(const int&)const;

	//overloading matrices with double
	Matrix& operator*=(double);
	Matrix operator*(double)const;
	

	
	

private:
	int row, col;
	double** mat;
};

