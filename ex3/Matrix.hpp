/**
 * @file Matrix.hpp
 * @author Aviad Nissel <aviad.nissel@mail.huji.ac.il>
 *
 * A generic matrix class.
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP


/* --- Includes --- */

#include <vector>
#include <iostream>
#include <exception>
#include "Complex.h"

using std::vector;


/* --- Class --- */

/**
 * A generic matrix.
 *
 * @tparam T The type of the cells in the matrix.
 */
template <class T>
class Matrix
{
public:
	typedef typename std::vector<T>::const_iterator const_iterator;

	/**
	 * Default constructor. Constructs a 1x1 matrix with value 0.
	 */	
	Matrix();

	/**
	 * Constructs a new matrix with the given size. All values are 0.
	 *
	 * @param rows The number of rows.
	 * @param cols The number of columns.
	 */
	Matrix(unsigned int rows, unsigned int cols);

	/**
	 * Copy constructor.
	 *
	 * @param other The other matrix.
	 */
	Matrix(const Matrix<T>& other);

	/**
	 * Constructs a matrix with the given size, and given values.
	 * (Values order is (0,1) (0,2) ... (1,0) (1,1) ...
	 *
	 * @param rows The number of rows
	 * @param cols The number of columns.
	 * @param cells A vector of values, in the order above.
	 */
	Matrix(unsigned int rows, unsigned int cols, const vector<T>& cells);

	/**
	 * Assignment operator.
	 *
	 * @param other The other matrix.
	 * @return A reference to the current (changed) matrix.
	 */
	Matrix& operator=(const Matrix<T> &other);

	/**
	 * Plus operator.
	 *
	 * @param other The other matrix.
	 * @return The result matrix.
	 */
	Matrix operator+(const Matrix<T> &other) const;

    /**
     * Minus operator.
     *
     * @param other The other matrix.
     * @return The result matrix.
     */
	Matrix operator-(const Matrix<T> &other) const;

    /**
     * Multiply operator.
     *
     * @param other The other matrix.
     * @return The result matrix.
     */
	Matrix operator*(const Matrix<T> &other) const;

	/**
	 * Equal operator.
	 *
	 * @param other The other matrix.
	 * @return True if matrices are equal, false otherwise.
	 */
	bool operator==(const Matrix<T> &other) const;

    /**
     * Unequal operator.
     *
     * @param other The other matrix.
     * @return True if matrices are unequal, false otherwise.
     */
	bool operator!=(const Matrix<T> &other) const;

	/**
	 * Minus operator.
	 *
	 * @return This matrix, with a minus sign.
	 */
	Matrix operator-() const;

	/**
	 * Transposes the matrix.
	 *
	 * @return The new transposed matrix.
	 */
	Matrix trans() const;

	/**
	 * Checks if the matrix is a square matrix.
	 *
	 * @return True if the matrix is square, false othewise.
	 */
	bool isSquareMatrix() const;

	/**
	 * Access operator.
	 *
	 * @param row The row to access.
	 * @param col The column to access.
	 * @return The value in given cell.
	 */
	T operator()(unsigned int row, unsigned int col) const;

	/**
	 * Access operator.
	 *
	 * @param row The row to access.
	 * @param col The column to access.
	 * @return A reference to the given cell.
	 */
	T& operator()(unsigned int row, unsigned int col);

	/**
	 * Begin iterator.
	 *
	 * @return A const_iterator to the beginning of the matrix.
	 */
	const_iterator begin() const;

    /**
     * End iterator.
     *
     * @return A const_iterator to the end of the matrix.
     */
	const_iterator end() const;

	/**
	 * Getter for the number of rows in the matrix.
	 *
	 * @return The number of rows in the matrix.
	 */
	unsigned int rows() const;

    /**
     * Getter for the number of columns in the matrix.
     *
     * @return The number of columns in the matrix.
     */
	unsigned int cols() const;

    /**
     * << operator.
     *
     * @tparam S the type of the matrix.
     * @param is The output stream.
     * @param mat The matrix.
     * @return Reference to the original output stream.
     */
	template <class S>
	friend std::ostream& operator<<(std::ostream &os, const Matrix<S> &mat);


private:
    /**
     * Getter for the specific row.
     *
     * @param row The row to get.
     * @return A vector representing the row.
     */
	vector<T> _getRow(unsigned int row) const;

    /**
     * Getter for the specific column.
     *
     * @param row The column to get.
     * @return A vector representing the column.
     */
	vector<T> _getCol(unsigned int col) const;

	/** The values of the matrix. */
	vector<T> values;

	/** the number of columns the matrix have. */
	unsigned int _cols;

};


/* --- Method Impl. --- */

/**
 * See class definition.
 */
template <class T>
Matrix<T>::Matrix()
{
	values.push_back(T(0));
	_cols = 1;
}

/**
 * See class definition.
 */
template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols)
{
	for(unsigned int i = 0; i < rows * cols; i++)
	{
		values.push_back(T(0));
	}
	this->_cols = cols;
}

/**
 * See class definition.
 */
template <class T>
Matrix<T>::Matrix(const Matrix<T> &other)
{
	_cols = other.cols();
	values = other.values;
}

/**
 * See class definition.
 */
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

/**
 * See class definition.
 */
template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &other)
{
	_cols = other.cols();
	values = other.values;
	return *this;
}

/**
 * See class definition.
 */
template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) const
{
	if(other.values.size() != values.size())
	{
		throw std::invalid_argument("Matrices not the same size +");
	}
	unsigned int cols = other.cols();
	unsigned int rows = other.rows();
	vector<T> newValues = values;
	for(unsigned int i = 0; i < values.size(); i++)
	{
		newValues.at(i) += other.values.at(i);
	}
	Matrix<T> newMatrix(rows, cols, newValues);
	return newMatrix;
}

/**
 * See class definition.
 */
template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &other) const
{
	if(other.values.size() != values.size())
	{
		throw std::invalid_argument("Matrices not the same size -");
	}

	return (*this) + (-other);
}

/**
 * See class definition.
 */
template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const
{
	if(cols() != other.rows())
	{
		throw std::invalid_argument("Matrices not fitting size *");
	}
	Matrix<T> result(rows(), other.cols());
	for(unsigned int i = 0; i < rows(); i++)
	{
		for(unsigned int j = 0; j < other.cols(); j++)
		{
			T sum(0);
			for(unsigned int k = 0; k < cols(); k++)
			{
				sum += (*this)(i, k) * other(k, j);
			}
			result(i, j) = sum;
		}
	}
	return result;
}

/**
 * See class definition.
 */
template <class T>
bool Matrix<T>::operator==(const Matrix<T> &other) const
{
	return values == other.values;
}

/**
 * See class definition.
 */
template <class T>
bool Matrix<T>::operator!=(const Matrix<T> &other) const
{
	return !((*this) == other);
}

/**
 * See class definition.
 */
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

/**
 * See class definition.
 */
template <class T>
Matrix<T> Matrix<T>::trans() const
{
	if (!isSquareMatrix())
	{
		throw std::invalid_argument("matrix is not squared");
	}
	Matrix<T> resultMatrix;
	for(unsigned int i = 0; i < rows(); i++)
	{
		for(unsigned int j = 0; j < cols(); j++)
		{
			resultMatrix(i, j) = (*this)(j, i);
		}
	}
	return resultMatrix;
}

/**
 * See class definition.
 */
template <class T>
bool Matrix<T>::isSquareMatrix() const
{
	return _cols == rows();
}

/**
 * See class definition.
 */
template <class T>
T Matrix<T>::operator()(unsigned int row, unsigned int col) const
{
	if (row >= rows() || col >= cols())
	{
		throw std::out_of_range("array index out of bounds");
	}
	return values.at(row * cols() + col);
}

/**
 * See class definition.
 */
template <class T>
T& Matrix<T>::operator()(unsigned int row, unsigned int col)
{
	if (row >= rows() || col >= cols())
	{
		throw std::out_of_range("array index out of bounds");
	}
	return values.at(row * cols() + col);
}

/**
 * See class definition.
 */
template <class T>
typename Matrix<T>::const_iterator Matrix<T>::begin() const
{
	return values.cbegin();
}

/**
 * See class definition.
 */
template <class T>
typename Matrix<T>::const_iterator Matrix<T>::end() const
{
	return values.cend();
}

/**
 * See class definition.
 */
template <class T>
vector<T> Matrix<T>::_getRow(unsigned int row) const
{
	auto start = values.begin() + row * cols();
	auto end = values.begin + (row + 1) * cols();
	vector<T> result(start, end);
	return result;
}

/**
 * See class definition.
 */
template <class T>
vector<T> Matrix<T>::_getCol(unsigned int col) const
{
	vector<T> result;
	for(unsigned int i = 0; i < rows; i++)
	{
		result.push_back((*this)(i, col));
	}
	return result;
}

/**
 * See class definition.
 */
template <class T>
unsigned int Matrix<T>::rows() const
{
	return values.size() / cols();
}

/**
 * See class definition.
 */
template <class T>
unsigned int Matrix<T>::cols() const
{
	return _cols;
}

/**
 * See class definition.
 */
template <class T>
std::ostream& operator<<(std::ostream &os, const Matrix<T> &mat)
{
	for(unsigned int i = 0; i < mat.values.size(); i++)
	{
		std::cout << mat.values.at(i) << "\t";
		if((i + 1) % mat.cols() == 0)
		{
			std::cout << std::endl;
		}
	}
	return os;
}

/**
 * See class definition.
 */
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
