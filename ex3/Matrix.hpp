#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <exception>
// TODO use cols()
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
	bool operator==(const Matrix<T> &other) const;
	bool operator!=(const Matrix<T> &other) const;

	Matrix<T> trans() const;
	bool isSquareMatrix() const;

	T operator()(unsigned int row, unsigned int col) const;
	T& operator()(unsigned int row, unsigned int col);

	typename std::vector<T>::const_iterator begin() const;
	typename std::vector<T>::const_iterator end() const;

	int rows() const;
	int cols() const;

	template <class S>
	friend std::ostream& operator<<(std::ostream &os, const Matrix<S> &mat);


private:
	vector<T> getRow(int row) const;
	vector<T> getCol(int col) const;
	vector<T> values;
	int _cols;

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
		values.push_back(T(0));
	}
	this->_cols = cols;
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> &other)
{
	_cols = other._cols;
	values = other.values;
}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols, const vector<T>& cells) : Matrix(rows, cols)
{
	int row;
	int col;
	// TODO is this the best way?
	for (int i = 0; i < cells.size(); i++)
	{
		values.push_back(cells.at(i));
	}
	this->_cols = cols;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &other)
{
	_cols = other._cols;
	values = other.values;
	return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) const
{
        // TODO check for size 0?
        if(other.values.size() != values.size())
        {
                throw std::invalid_argument("Matrices sizes don't match");
        }
        int cols = other._cols;
        int rows = other.values.size() / cols;
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
	// TODO merge with operator+
        if(other.values.size() != values.size())
        {
                throw std::invalid_argument("Matrices sizes don't match");
        }
        int cols = other._cols;
        int rows = other.values.size() / cols;
        vector<T> newValues = values;
        for(int i = 0; i < values.size(); i++)
        {
                values.at(i) -= other.values.at(i);
        }
        Matrix<T> newMatrix(rows, cols, newValues);
        return newMatrix;

}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const
{
	// TODO check sizes
	int rowsNum = rows();
	Matrix<T> result(rowsNum, other._cols);
	for(int i = 0; i < rowsNum; i++)
	{
		for(int j = 0; j < other._cols; j++)
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
Matrix<T> Matrix<T>::trans() const
{
	if (!isSquareMatrix())
	{
		throw std::invalid_argument("Matrix must be square");
	}
	Matrix<T> resultMatrix;
	return resultMatrix;
	// TODO implement
}

template <class T>
bool Matrix<T>::isSquareMatrix() const
{
	return _cols == rows();
}

template <class T>
T Matrix<T>::operator()(unsigned int row, unsigned int col) const
{
	return values.at(row * _cols + col);
}


template <class T>
T& Matrix<T>::operator()(unsigned int row, unsigned int col)
{
	return values.at(row * _cols + col);
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
	auto start = values.begin() + row * _cols;
	auto end = values.begin + (row + 1) * _cols;
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
int Matrix<T>::rows() const
{
	return values.size() / _cols;
}

template <class T>
int Matrix<T>::cols() const
{
	return _cols;
}

template <class T>
std::ostream& operator<<(std::ostream &os, const Matrix<T> &mat)
{
	for(unsigned long int i = 0; i < mat.values.size(); i++)
	{
		std::cout << mat.values.at(i) << "\t";
		if((i + 1) % mat._cols == 0)
		{
			std::cout << std::endl;
		}
	}
	return os;
}

#endif //MATRIX_HPP
