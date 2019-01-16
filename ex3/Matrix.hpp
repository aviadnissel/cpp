#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <exception>

#include "Complex.h"

// TODO use cols()
using std::vector;

template <class T>
class Matrix
{
public:
	
	Matrix<T>();
	Matrix<T>(unsigned int rows, unsigned int cols);
	Matrix<T>(const Matrix<T>& other);
	Matrix(unsigned int rows, unsigned int cols, const vector<T>& cells);

	Matrix<T>& operator=(const Matrix<T> &other);
	Matrix<T> operator+(const Matrix<T> &other) const;
	Matrix<T> operator-(const Matrix<T> &other) const;
	Matrix<T> operator*(const Matrix<T> &other) const;
	bool operator==(const Matrix<T> &other) const;
	bool operator!=(const Matrix<T> &other) const;
	Matrix<T> operator-() const;

	Matrix<T> trans() const;
	bool isSquareMatrix() const;

	T operator()(unsigned int row, unsigned int col) const;
	T& operator()(unsigned int row, unsigned int col);

	typename std::vector<T>::const_iterator begin() const;
	typename std::vector<T>::const_iterator end() const;

	unsigned int rows() const;
	unsigned int cols() const;

	template <class S>
	friend std::ostream& operator<<(std::ostream &os, const Matrix<S> &mat);


private:
	vector<T> getRow(int row) const;
	vector<T> getCol(int col) const;
	vector<T> values;
	unsigned int _cols;

};

template <class T>
Matrix<T>::Matrix()
{
	values.push_back(T(0));
	_cols = 1;
}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols)
{
	for(unsigned int i = 0; i < rows * cols; i++)
	{
		std::cout << i << std::endl;
		values.push_back(T(0));
	}
	this->_cols = cols;
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> &other)
{
	_cols = other.cols();
	values = other.values;
}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols, const vector<T>& cells) : Matrix(rows, cols)
{
	if (cells.size() != rows * cols)
	{
		throw std::invalid_argument("allocation problem");
	}
	values = cells;
	this->_cols = cols;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &other)
{
	_cols = other.cols();
	values = other.values;
	return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) const
{
	if(other.values.size() != values.size())
	{
		throw std::invalid_argument("Matrices not the same size +");
	}
	int cols = other.cols();
	int rows = other.rows();
	vector<T> newValues = values;
	for(int i = 0; i < values.size(); i++)
	{
		newValues[i] += other.values.at(i);;
	}
	Matrix<T> newMatrix(rows, cols, newValues);
	return newMatrix;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &other) const
{
	if(other.values.size() != values.size())
	{
		throw std::invalid_argument("Matrices not the same size -");
	}

	return (*this) + (-other);
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const
{
	if(cols() != other.rows())
	{
		throw std::invalid_argument("Matrices not fitting size *");
	}
	Matrix<T> result(rows(), other.cols());
	for(int i = 0; i < rows(); i++)
	{
		for(int j = 0; j < other.cols(); j++)
		{
			T sum;
			for(int k = 0; k < cols(); k++)
			{
				sum += (*this)(i, k) * other(k, j);
			}
			result(i, j) = sum;
		}
	}
	return result;
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T> &other) const
{
	return values == other.values;
}

template <class T>
bool Matrix<T>::operator!=(const Matrix<T> &other) const
{
	return !((*this) == other);
}

template <class T>
Matrix<T> Matrix<T>::operator-() const
{
	vector<T> newValues;
	for(T value: values)
	{
		newValues.push_back(-value);
	}
	Matrix<T> newMatrix(rows(), cols(), newValues);
	return newMatrix;
}
template <class T>
Matrix<T> Matrix<T>::trans() const
{
	if (!isSquareMatrix())
	{
		throw std::invalid_argument("matrix is not squared");
	}
	Matrix<T> resultMatrix;
	for(int i = 0; i < rows(); i++)
	{
		for(int j = 0; j < cols(); j++)
		{
			resultMatrix(i, j) = (*this)(j, i);
		}
	}
	return resultMatrix;
}

template <class T>
bool Matrix<T>::isSquareMatrix() const
{
	return _cols == rows();
}

template <class T>
T Matrix<T>::operator()(unsigned int row, unsigned int col) const
{
	if (row >= rows() || col >= cols())
	{
		throw std::out_of_range("array index out of bounds");
	}
	return values.at(row * cols() + col);
}


template <class T>
T& Matrix<T>::operator()(unsigned int row, unsigned int col)
{
	if (row >= rows() || col >= cols())
	{
		throw std::out_of_range("array index out of bounds");
	}
	return values.at(row * cols() + col);
}

template <class T>
typename std::vector<T>::const_iterator Matrix<T>::begin() const
{
	return values.cbegin();
}

template <class T>
typename std::vector<T>::const_iterator Matrix<T>::end() const
{
	return values.cend();
}

template <class T>
vector<T> Matrix<T>::getRow(int row) const
{
	auto start = values.begin() + row * cols();
	auto end = values.begin + (row + 1) * cols();
	vector<T> result(start, end);
	return result;
}

template <class T>
vector<T> Matrix<T>::getCol(int col) const
{
	vector<T> result;
	for(int i = 0; i < rows; i++)
	{
		result.push_back((*this)(i, col));
	}
	return result;
}

template <class T>
unsigned int Matrix<T>::rows() const
{
	return values.size() / cols();
}

template <class T>
unsigned int Matrix<T>::cols() const
{
	return _cols;
}

template <class T>
std::ostream& operator<<(std::ostream &os, const Matrix<T> &mat)
{
	for(unsigned long int i = 0; i < mat.values.size(); i++)
	{
		std::cout << mat.values.at(i) << "\t";
		if((i + 1) % mat.cols() == 0)
		{
			std::cout << std::endl;
		}
	}
	return os;
}


template<>
Matrix<Complex> Matrix<Complex>::trans() const
{
	if (!isSquareMatrix())
	{
			throw std::invalid_argument("matrix is not squared (Complex)");
	}
	Matrix<Complex> resultMatrix;
	for(unsigned int i = 0; i < rows(); i++)
	{
			for(unsigned int j = 0; j < cols(); j++)
			{
					resultMatrix(i, j) = (*this)(j, i).conj();
			}
	}
	return resultMatrix;

}

#endif //MATRIX_HPP
