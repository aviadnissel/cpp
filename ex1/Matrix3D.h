//
// Created by Avian on 14/12/2018.
//

#ifndef CPP_MATRIX3D_H
#define CPP_MATRIX3D_H

#include "Vector3D.h"
#include <algorithm>

/**
 * A 3x3 matrix.
 */
class Matrix3D {
private:
    /** The matrix's vectors. */
	Vector3D vectors[3];

public:
    /**
     * Default constructor. Constructs with zeroes.
     */
	Matrix3D();

	/**
	 * Constructs a matrix with num on the diagonal.
	 *
	 * @param num The number to use.
	 */
	Matrix3D(double num);

	/**
	 * Constructs a matrix with the given values.
	 *
	 * @param num1 0, 0
	 * @param num2 0, 1
	 * @param num3 0, 2
	 * @param num4 1, 0
	 * @param num5 1, 1
	 * @param num6 1, 2
	 * @param num7 2, 0
	 * @param num8 2, 1
	 * @param num9 2, 2
	 */
	Matrix3D(double num1, double num2, double num3,
			 double num4, double num5, double num6,
			 double num7, double num8, double num9);

	/**
	 * Constructs a matrix with the given values.
	 *
	 * @param numbers The numbers, left-to-right top-to-bottom.
	 */
	Matrix3D(const double numbers[9]);

	/**
	 * Constructs a matrix with the given matrix.
	 *
	 * @param numbers The matrix of numbers.
	 */
	Matrix3D(const double numbers[3][3]);

	/**
	 * Construct a matrix with given vectors.
	 *
	 * @param vectorOne First row.
	 * @param vectorTwo Second row.
	 * @param vectorThree Third row.
	 */
	Matrix3D(const Vector3D& vectorOne, const Vector3D& vectorTwo, const Vector3D& vectorThree);

	/**
	 * Copy constructor.
	 *
	 * @param other The matrix to copy.
	 */
	Matrix3D(const Matrix3D &other);

	/**
	 * Adds other matrix to this matrix, cell by cell.
     * Saves the result to this matrix.
	 *
	 * @param other The matrix to add.
	 * @return A reference to this matrix after change.
	 */
	Matrix3D& operator+=(const Matrix3D &other);

    /**
     * Subtracts other matrix from this matrix, cell by cell.
     * Saves the result to this matrix.
     *
     * @param other The matrix to subtract.
     * @return A reference to this matrix after change.
     */
	Matrix3D& operator-=(const Matrix3D &other);

	/**
	 * Minus operator.
	 *
	 * @return A copy of this matrix with inverse sign for each cell.
	 */
	Matrix3D operator-() const;

	/**
     * Multiplies other matrix by this matrix, cell by cell.
     * Saves the result to this matrix.
     *
     * @param other The matrix to multiply.
     * @return A reference to this matrix after change.
	 */
	Matrix3D& operator*=(const Matrix3D &other);

    /**
     * Adds this matrix to the other matrix
     *
     * @param other The matrix to add.
     * @return A new, result matrix.
     */
	Matrix3D operator+(const Matrix3D &other) const;

    /**
     * Subtracts this matrix from the other matrix
     *
     * @param other The matrix to subtract.
     * @return A new, result matrix.
     */
	Matrix3D operator-(const Matrix3D &other) const;

    /**
     * Multiplies this matrix with the other matrix
     *
     * @param other The matrix to multiply.
     * @return A new, result matrix.
     */
	Matrix3D operator*(const Matrix3D &other) const;

	/**
	 * Multiplies each cell of this matrix with given number.
     * Saves the result to this matrix.
     *
	 * @param num The number to multiply.
	 * @return A reference to this matrix after change.
	 */
	Matrix3D& operator*=(double num);

    /**
     * Divides each cell of this matrix with given number.
     * Saves the result to this matrix.
     *
     * @param num The number to multiply.
     * @return A reference to this matrix after change. No changes are made if num is zero.
     */
	Matrix3D& operator/=(double num);

	/**
	 * Multiplies the matrix by given vector.
	 *
	 * @param other The vector to multiply by.
	 * @return A new, result vector.
	 */
	Vector3D operator*(const Vector3D &other) const;

	/**
	 * Assignment operator. Changes this matrix.
	 *
	 * @param other The matrix to assign to this one.
	 * @return A reference to this matrix after change.
	 */
	Matrix3D& operator=(const Matrix3D &other);

    /**
     * Const access operator.
     *
     * @param i The row to return.
     * @return A copy of the ith row.
     */
	Vector3D operator[](int i) const;

	/**
	 * Access operator.
	 *
	 * @param i The row to return.
	 * @return A reference to the ith row.
	 */
	Vector3D& operator[](int i);

	/**
	 * Getter for a row.
	 *
	 * @param row The row to get.
	 * @return A copy of the row.
	 */
	Vector3D row(short row) const;

	/**
	 * Getter for a column.
	 * @param column The column to get.
	 * @return A copy fo the column.
	 */
	Vector3D column(short column) const;

	/**
	 * Calculates the trace of the matrix.
	 *
	 * @return The trace.
	 */
	double trace() const;

	/**
	 * Calculates the determinant of the matrix.
	 *
	 * @return The determinant.
	 */
	double determinant() const;

	/**
	 * >> operator.
	 *
	 * @param is The input stream.
	 * @param mat The matrix.
	 * @return Reference to the original input stream.
	 */
	friend std::istream& operator>>(std::istream &is, Matrix3D &mat);

    /**
     * << operator.
     *
     * @param is The output stream.
     * @param mat The matrix.
     * @return Reference to the original output stream.
     */
	friend std::ostream& operator<<(std::ostream &os, const Matrix3D &mat);

};

#endif
