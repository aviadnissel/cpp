#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <exception>

using std::vector;

template <class T>
class Matrix {
public:
	Matrix<T>();
	Matrix<T>(unsigned int rows, unsigned int cols);
	Matrix<T>(const Matrix<T>& other);
	Matrix(unsigned int rows, unsigned int cols, const vector<T>& cells);

	Matrix<T>& operator=(const Matrix<T> &other);
	Matrix<T> operator+(const Matrix<T> &other) const;
	Matrix<T> operator-(const Matrix<T> &other) const;
	Matrix<T> operator*(const Matrix<T> &other) const;

	template <class S>
	friend std::ostream& operator<<(std::ostream &os, const Matrix<S> &mat);


private:
	vector<vector<T>> rows;

};

template <class T>
Matrix<T>::Matrix()
{
	vector<T> row;
	row.push_back(T(0));
	rows.push_back(row);
}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols)
{
	for(unsigned int i = 0; i < rows; i++)
	{
		vector<T> row;
		for(unsigned int j = 0; j < cols; j++)
		{
			row.push_back(T(0));
		}
		this->rows.push_back(row);
	}
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> &other)
{
	rows = other.rows;
}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols, const vector<T>& cells) : Matrix(rows, cols)
{
	int row;
	int col;
	// TODO is this the best way?
	for (int i = 0; i < cells.size(); i++)
	{
		row = i % rows;
		col = i - row;
		this->rows[row][col] = cells[i];
	}
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &other)
{
	rows = other.rows;
	return *this;
}

template <class T>
Matrix<T> operator+(const Matrix<T> &other) const
{
	int rowsSize = rows.size;
	int colsSize = rows[0].size;
	// TODO check for size 0?
	if(other.rows.size != rowsSize || other.rows[0].size != colsSize)
	{
		throw std::invalid_argument("Matrices sizes don't match");
	}
	Matrix<T> newMatrix(rowsSize, colsSize);
	for(int i = 0; i < rowsSize; i++)
	{
		for(int j = 0; j < colsSize; j++)
		{
			newMatrix(i, j) = (*this)(i, j) + other(i, j);
		}
	}
	return newMatrix;
}
Matrix<T> operator+(const Matrix<T> &other) const
{

}
Matrix<T> operator+(const Matrix<T> &other) const;
template <class T>
std::ostream& operator<<(std::ostream &os, const Matrix<T> &mat)
{
	for(vector<T> row: mat.rows)
	{
		for(T cell: row)
		{
			std::cout << cell << "\t";
		}
		std::cout << std::endl;
	}
	return os;
}

#endif //MATRIX_HPP
