#include "Matrix.h"
#include <iostream>


//constructor and destructor


Matrix::Matrix(int x, int y):row(x),col(y)
{	
	int i, j;
	if (row != 0 && col != 0)
	{
		mat = new double* [row];
		for (i = 0; i < row; i++)
		{
			mat[i] = new double[col];
			for (j = 0; j < col; j++)
				mat[i][j] = 0;
		}
	}
}


Matrix::Matrix(const Matrix& m):row(m.row),col(m.col)
{
	int i, j;
	mat = new double* [row];
	for (i = 0; i < row; i++)
	{
		mat[i] = new double[col];
		for (j = 0; j < col; j++)
			mat[i][j] = m.mat[i][j];
	}
}

Matrix::~Matrix()
{   
	
	for (int i = 0; i <this->row; i++) {
		delete[]this->mat[i];
	}
	delete[]this->mat;
	
}


//getters and setters

double** Matrix::get_mat()
{
	return(mat);
}

int Matrix::get_row()
{
	return(row);
}

int Matrix::get_col()
{
	return(col);
}

void Matrix::set_row(int r)
{
	row = r;
}

void Matrix::set_col(int c)
{
	col = c;
}



//other member functions


void Matrix::Create_mat()
{
	int i, j;
	mat = new double* [row];
	for (i = 0; i < row; i++)
	{
		mat[i] = new double[col];
		for (j = 0; j < col; j++)
			mat[i][j] = 0;
	}
}








//friend functions

void fill_mat(Matrix &m)
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
	double num;
	double** arr=m.get_mat();
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

//void Print_mat(Matrix &m)
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


ostream& operator<<(ostream& cout, const Matrix& m)
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

istream& operator>>(istream& cin, Matrix& m)
{
	fill_mat(m);
	return(cin);
}




Matrix& Matrix::operator=(const Matrix& m1)
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

Matrix& Matrix::operator=(const double d)
{

	
	int i, j;
	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < this->col; j++)
		{
			mat[i][j] = mat[i][j];
		}
	}
	return(*this);

}

double* Matrix::operator[](const int& i)const
{
	return(mat[i]);
}


Matrix& Matrix::operator+=(const Matrix& m1)
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

Matrix Matrix::operator+(const Matrix& m1)const//destructor deletes ret before returning it.
{
	
	if (this->row != m1.row || this->col != m1.col) {
		cout << "rows and coloumns of matrices do not match for this operation" << endl;
		Matrix ret;
		return ret;
	}
	else
	{
		Matrix ret(this->row, this->col);
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->col; j++) {
				ret.mat[i][j] = this->mat[i][j] + m1.mat[i][j];
			}
		}
		return ret;
	}
	
}

Matrix& Matrix::operator*=(const Matrix& m1)
{
	if (this->col!= m1.row)
	{
		cout << "rows and coloumns of matrices do not match for this operation" << endl;
		return(*this);
	}
	else
	{
		int i, j,t;
		double temp;
		Matrix copy = *this;
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

Matrix Matrix::operator*(const Matrix& m1)const
{

	if (this->row != m1.row || this->col != m1.col) {
		cout << "rows and coloumns of matrices do not match for this operation" << endl;
		Matrix ret;
		return ret;
	}
	else
	{
		int i, j, t;
		double temp;
		Matrix ret(this->row, m1.col);
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

Matrix& Matrix::operator-=(const Matrix& m1)
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

Matrix Matrix::operator-(const Matrix& m1)const
{

	if (this->row != m1.row || this->col != m1.col) {
		cout << "rows and coloumns of matrices do not match for this operation" << endl;
		Matrix ret;
		return ret;
	}
	else
	{
		Matrix ret(this->row, this->col);
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->col; j++) {
				ret.mat[i][j] = this->mat[i][j] - m1.mat[i][j];
			}
		}
		return ret;
	}

}

Matrix& Matrix::operator*=(double d)
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

Matrix Matrix::operator*(double d)const
{
	Matrix ret(this->row, this->col);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			ret.mat[i][j] = this->mat[i][j] * d;
		}
	}
	return ret;
}

Matrix operator*(const double& d,const Matrix& m)
{
	Matrix ret(m.row, m.col);
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.col; j++) {
			ret.mat[i][j] = d * m.mat[i][j];
		}
	}
	return ret;
}

Matrix Matrix::operator-()const
{
	Matrix m(*this);
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

Matrix Matrix::operator^(const int& num)const//added for fun
{
	if (this->row != this->col)
	{
		cout << "rows and coloumns of matrices do not match for this operation" << endl;
		Matrix ret;
		return ret;
	}
	else
	{
		int i = 1;
		Matrix ret(*this);
		while (i < num)
		{
			ret *= *this;
			i++;
		}
		return(ret);
	}
}

