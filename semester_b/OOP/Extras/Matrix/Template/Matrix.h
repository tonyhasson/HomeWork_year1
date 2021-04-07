#pragma once
#include <iostream>
#include <cmath>


using namespace std;

template<typename T> class Matrix;  // pre-declare the template class itself
template<typename T>  ostream& operator<<(ostream&, const Matrix<T>&);
template<typename T> istream& operator>>(istream&, Matrix<T>&);
template<typename T> Matrix<T> operator*(const double&, const Matrix<T>&);
template<typename T> void fill_mat(Matrix<T>& m);
template<typename T> void Print_mat(Matrix<T>& m);


template<typename T>
class Matrix
{
	friend ostream& operator<<<>(ostream&, const Matrix<T>&);
	friend istream& operator>><>(istream&, Matrix<T>&);
	friend Matrix<T> operator*<>(const double&, const Matrix<T>&);
	friend void fill_mat<>(Matrix<T>& m);
    friend void Print_mat<>(Matrix<T>& m);
	
public:
	Matrix(int x=0,int y=0);
	Matrix(const Matrix<T>&);
	~Matrix();
	int get_row();
	int get_col();
	T** get_mat();
	void set_row(int r);
	void set_col(int c);
	void Create_mat();
	//overloading operators with matrices
	Matrix<T>& operator=(const Matrix<T>&);
	Matrix<T>& operator=(const T);
	T* operator[](const int&)const;
	Matrix<T>& operator+=(const Matrix<T>&);
	Matrix<T> operator+(const Matrix<T>&)const;
	Matrix<T>& operator*=(const Matrix<T>&);
	Matrix<T> operator*(const Matrix<T>&)const;
	Matrix<T>& operator-=(const Matrix<T>&);
	Matrix<T> operator-(const Matrix<T>&)const;
	Matrix<T> operator-()const;//change to negetive
	Matrix<T> operator^(const int&)const;

	//overloading matrices with double
	Matrix<T>& operator*=(double);
	Matrix<T> operator*(double)const;
	

	
	

private:
	int row, col;
	T** mat;
};

