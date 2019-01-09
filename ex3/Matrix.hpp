#ifndef CPP_MATRIX_H
#define CPP_MATRIX_H

#include <vector>
#include <iostream>

using std::vector;

template <class T>
class Matrix {
public:
	Matrix<T>();
	Matrix<T>(unsigned int rows, unsigned int cols);
	Matrix<T>(Matrix<T>& other);

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

#endif //CPP_MATRIX_H
