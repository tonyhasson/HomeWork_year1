#include "Matrix.h"
#include <iostream>




//constructor and destructor

template<typename T>
Matrix<T>::Matrix(int x, int y):row(x),col(y)
{	
	int i, j;
	if (row != 0 && col != 0)
	{
		mat = new T* [row];
		for (i = 0; i < row; i++)
		{
			mat[i] = new T[col];
			for (j = 0; j < col; j++)
				mat[i][j] = 0;
		}
	}
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& m):row(m.row),col(m.col)
{
	int i, j;
	mat = new T* [row];
	for (i = 0; i < row; i++)
	{
		mat[i] = new T[col];
		for (j = 0; j < col; j++)
			mat[i][j] = m.mat[i][j];
	}
}

template<typename T>
Matrix<T>::~Matrix()
{   
	
	for (int i = 0; i <this->row; i++) {
		delete[]this->mat[i];
	}
	delete[]this->mat;
	
}


//getters and setters

template<typename T>
T** Matrix<T>::get_mat()
{
	return(mat);
}
template<typename T>
int Matrix<T>::get_row()
{
	return(row);
}
template<typename T>
int Matrix<T>::get_col()
{
	return(col);
}
template<typename T>
void Matrix<T>::set_row(int r)
{
	row = r;
}
template<typename T>
void Matrix<T>::set_col(int c)
{
	col = c;
}



//other member functions

template<typename T>
void Matrix<T>::Create_mat()
{
	int i, j;
	mat = new T* [row];
	for (i = 0; i < row; i++)
	{
		mat[i] = new T[col];
		for (j = 0; j < col; j++)
			mat[i][j] = 0;
	}
}








//friend functions
template<typename T>
void fill_mat(Matrix<T> &m)
{
	if (m.get_col() == 0 || m.get_row() == 0)
	{
		int r, c;
		cout << "enter row and coloumn:" << endl;
		cin >> r >> c;
		m.set_row(r);
		m.set_col(c);
		m.Create_mat();
	}
	int i, j;
	T num;
	T** arr=m.get_mat();
	for (i = 0; i < m.get_row(); i++)
	{
		for (j = 0; j < m.get_col(); j++)
		{
			cout << "enter value to position [" << i << "][" << j << "]" << endl;
			cin >> num;
			arr[i][j] = num;
		}
	}
}

//void Print_mat(Matrix<T> &m)
//{
//	int i, j;
//	cout << "matrix is of dimentions [" << m.get_row() << "][" << m.get_col() << "]" << endl;
//	double** arr = m.get_mat();
//	for (i = 0; i < m.get_row(); i++)
//	{
//		for (j = 0; j < m.get_col(); j++)
//		{
//			cout << "matrix in position [" << i << "][" << j << "]" <<"is: "<<arr[i][j]<< endl;
//		}
//	}
//}



//operator overloading

template<typename T>
ostream& operator<<(ostream& cout, const Matrix<T>& m)
{
	if (m.row == 0 || m.col == 0)
	{
		cout << "matrix is undefined" << endl;
	}
	else
	{
		cout << "matrix is of dimentions [" << m.row << "][" << m.col << "]" << endl;
		for (int i = 0; i < m.row; i++) {
			for (int j = 0; j < m.col; j++)
			{
				cout << "[" << m.mat[i][j] << "]";
			}
			cout << std::endl;
		}
	}
	return cout;
}
template<typename T>
istream& operator>>(istream& cin, Matrix<T>& m)
{
	fill_mat(m);
	return(cin);
}



template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m1)
{
	
	if (row != m1.row || col != m1.col)
	{
		this->~Matrix();
		row=(m1.row);
		col=(m1.col);
		this->Create_mat();
		
	}
	int i, j;
	for (i = 0; i < m1.row; i++)
	{
		for (j = 0; j < m1.col; j++)
		{
			mat[i][j] = m1.mat[i][j];
		}
	}
	return(*this); 
	
}

//Matrix& Matrix::operator=(const double d)//not sure what i did here
//{
//
//	int i, j;
//	for (i = 0; i < this->row; i++)
//	{
//		for (j = 0; j < this->col; j++)
//		{
//			mat[i][j] = mat[i][j];
//		}
//	}
//	return(*this);
//
//}
template<typename T>
T* Matrix<T>::operator[](const int& i)const
{
	return(mat[i]);
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& m1)
{
	if (this->row != m1.row || this->col != m1.col)
	{
		cout << "rows and coloumns of matrices do not match for this operation" << endl;
		return(*this);
	}
	else
	{
		int i, j;
		for (i = 0; i < m1.row; i++)
		{
			for (j = 0; j < m1.col; j++)
			{
				this->mat[i][j] += m1.mat[i][j];
				
			}
		}
		
		return(*this);
	}
}
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m1)const
{
	
	if (this->row != m1.row || this->col != m1.col) {
		cout << "rows and coloumns of matrices do not match for this operation" << endl;
		Matrix<T> ret;
		return ret;
	}
	else
	{
		Matrix<T> ret(this->row, this->col);
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->col; j++) {
				ret.mat[i][j] = this->mat[i][j] + m1.mat[i][j];
			}
		}
		return ret;
	}
	
}
template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& m1)
{
	if (this->col!= m1.row)
	{
		cout << "rows and coloumns of matrices do not match for this operation" << endl;
		return(*this);
	}
	else
	{
		int i, j,t;
		T temp;
		Matrix<T> copy = *this;
		this->set_col(m1.col);
		this->set_row(copy.row);
		this->Create_mat();
		for (i = 0; i < this->row; i++)
		{
			for (j = 0; j < m1.col; j++)
			{
				temp = 0;
				for (t = 0; t < m1.row; t++)
				{
					temp += copy.mat[i][t] * m1.mat[t][j];
				}
				this->mat[i][j] = temp;
			}
		}

		return(*this);
	}
}
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& m1)const
{

	if (this->row != m1.row || this->col != m1.col) {
		cout << "rows and coloumns of matrices do not match for this operation" << endl;
		Matrix<T> ret;
		return ret;
	}
	else
	{
		int i, j, t;
		T temp;
		Matrix<T> ret(this->row, m1.col);
		for (i = 0; i < this->row; i++)
		{
			for (j = 0; j < m1.col; j++)
			{
				temp = 0;
				for (t = 0; t < m1.row; t++)
				{
					temp += this->mat[i][t] * m1.mat[t][j];
				}
				ret.mat[i][j] = temp;
			}
		}

		return(ret);
	}

}
template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& m1)
{
	if (this->row != m1.row || this->col != m1.col)
	{
		cout << "rows and coloumns of matrices do not match for this operation" << endl;
		return(*this);
	}
	else
	{
		int i, j;
		for (i = 0; i < m1.row; i++)
		{
			for (j = 0; j < m1.col; j++)
			{
				this->mat[i][j] -= m1.mat[i][j];

			}
		}

		return(*this);
	}
}
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& m1)const
{

	if (this->row != m1.row || this->col != m1.col) {
		cout << "rows and coloumns of matrices do not match for this operation" << endl;
		Matrix<T> ret;
		return ret;
	}
	else
	{
		Matrix<T> ret(this->row, this->col);
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->col; j++) {
				ret.mat[i][j] = this->mat[i][j] - m1.mat[i][j];
			}
		}
		return ret;
	}

}
template<typename T>
Matrix<T>& Matrix<T>::operator*=(double d)
{
	int i, j;
	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < this->col; j++)
		{
			this->mat[i][j] *=d;

		}
	}

	return(*this);
}
template<typename T>
Matrix<T> Matrix<T>::operator*(double d)const
{
	Matrix<T> ret(this->row, this->col);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			ret.mat[i][j] = this->mat[i][j] * d;
		}
	}
	return ret;
}
template<typename T>
Matrix<T> operator*(const double& d,const Matrix<T>& m)
{
	Matrix<T> ret(m.row, m.col);
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.col; j++) {
			ret.mat[i][j] = d * m.mat[i][j];
		}
	}
	return ret;
}
template<typename T>
Matrix<T> Matrix<T>::operator-()const
{
	Matrix<T> m(*this);
	int i, j;
	for (i = 0; i < m.row; i++)
	{
		for (j = 0; j < m.col; j++)
		{
			if (this->mat[i][j] != 0)//so it won't write -0
			{
				m.mat[i][j] = this->mat[i][j] * -1;
			}
		}
	}
	return(m);
	
}
template<typename T>
Matrix<T> Matrix<T>::operator^(const int& num)const//added for fun
{
	if (this->row != this->col)
	{
		cout << "rows and coloumns of matrices do not match for this operation" << endl;
		Matrix<T> ret;
		return ret;
	}
	else
	{
		int i = 1;
		Matrix<T> ret(*this);
		while (i < num)
		{
			ret *= *this;
			i++;
		}
		return(ret);
	}
}

