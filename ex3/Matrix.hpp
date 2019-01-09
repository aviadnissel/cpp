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
	vector<T> values;
	int cols;

};

template <class T>
Matrix<T>::Matrix()
{
	values.push_back(T(0));
	cols = 1;
}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols)
{
	for(unsigned int i = 0; i < rows * cols; i++)
	{
		values.push_back(T(0));
	}
	this->cols = cols;
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> &other)
{
	cols = other.cols;
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
	this->cols = cols;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &other)
{
	cols = other.cols;
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
        int cols = other.cols;
        int rows = other.values.size() / cols;
	vector<T> newValues = values;
	for(int i = 0; i < values.size(); i++)
	{
		values.at(i) += other.values.at(i);
	}
	Matrix<T> newMatrix(rows, cols, newValues);
	return newMatrix;
}

template <class T>
std::ostream& operator<<(std::ostream &os, const Matrix<T> &mat)
{
	for(unsigned long int i = 0; i < mat.values.size(); i++)
	{
		std::cout << mat.values.at(i) << "\t";
		if((i + 1) % mat.cols == 0)
		{
			std::cout << std::endl;
		}
	}
	return os;
}

#endif //MATRIX_HPP
