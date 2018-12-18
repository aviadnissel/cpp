#ifndef CPP_VECTOR3D_H
#define CPP_VECTOR3D_H

#include <iostream>
#include <cmath>

/** x coordinate. */
#define X 0

/** y coordinate. */
#define Y 1

/** z coordinate. */
#define Z 2

/** Default value for the vector cells. */
#define DEFAULT_VALUE 0

// TODO Where should the & go

/**
 * A vector with 3 cells.
 */
class Vector3D
{

private:
	/** The vector's coordinates. */
	double coordinates[3];

public:
	/**
	 * Default constractor.
	 */
	Vector3D();

	/**
	 * Constructs a new vector with given values.
	 *
	 * @param x x value.
	 * @param y y value.
	 * @param z z value.
	 */
	Vector3D(double x, double y, double z);

	/**
	 * Constructs a new vector with given coordinates.
	 *
	 * @param coordinates The coordinates.
	 */
	Vector3D(const double coordinates[3]);

	/**
	 * Copy constructor.
	 *
	 * @param other The vector to copy from.
	 */
	Vector3D(const Vector3D &other);

	/**
	 * Adds this vector to the other vector.
	 *
	 * @param other The vector to add.
	 * @return A new, result matrix.
	 */
	Vector3D operator+(const Vector3D &other) const;

	/**
	 * Subtracts this vector from the other vector.
	 *
	 * @return A new, result vector.
	 */
	Vector3D operator-(const Vector3D &other) const;

	/**
	 * Adds other vector to this vector, cell by cell.
	 * Saves the result to this vector.
	 *
	 * @param other The vector to add.
	 * @return A reference to this vector after change.
	 */
	Vector3D& operator+=(const Vector3D &other);

	/**
	 * Subtracts other vector from this vector, cell by cell.
	 * Saves the result to this vector.
	 *
	 * @param other The vector to subtract.
	 * @return A reference to this vector after change.
	 */
	Vector3D& operator-=(const Vector3D &other);

	/**
	 * Adds the given number to each cell of the vector.
	 * Saves the result to this vector.
	 *
	 * @param other The number to add.
	 * @return A reference to this vector after change.
	 */
	Vector3D& operator+=(double num);

	/**
	 * Subtracts the given number from each cell of the vector.
	 * Saves the result to this vector.
	 *
	 * @param other The number to subtract.
	 * @return A reference to this vector after change.
	 */
	Vector3D& operator-=(double num);

	/**
	 * Multiplies this vector with the given number, cell by cell
	 *
	 * @param num The number to multiply.
	 * @return A new, result vector.
	 */
	Vector3D operator*(double num) const;

	/**
	 * Divides this vector from the other vector.
	 *
	 * @param The number to divide.
	 * @return A new, result vector. If num is zero, returns vector without change.
	 */
	Vector3D operator/(double num) const;

	/**
	 * Minus operator.
	 *
	 * @return A copy of this vector with inverse sign for each cell.
	 */
	Vector3D operator-() const;

	/**
	 * Multiplies each cell of this vector with given number.
	 * Saves the result to this vector.
	 *
	 * @param num The number to multiply.
	 * @return A reference to this vector after change.
	 */
	Vector3D& operator*=(double num);

	/**
	 * Divides each cell of this vector by given number.
	 * Saves the result to this vector.
	 *
	 * @param num The number to divide.
	 * @return A reference to this vector after change. If num is zero, returns vector without change.
	 */
	Vector3D& operator/=(double num);

	/**
	 * Calculates the distance between this vector and other.
	 *
	 * @param other The other vector.
	 * @return The distance.
	 */
	double operator|(const Vector3D &other) const;

	/**
	 * Multiplies the vector by the other vector.
	 *
	 * @param other The vector to multiply with.
	 * @return The result (a number).
	 */
	double operator*(const Vector3D &other) const;

	/**
	 * Calculates the angle between this vector and other.
	 *
	 * @param other The other vector.
	 * @return The angle.
	 */
	double operator^(const Vector3D &other) const;

	/**
	 * Assignment operator. Changes this vector.
	 *
	 * @param other The vector to assign to this one.
	 * @return A reference to this vector after change.
	 */
	Vector3D& operator=(const Vector3D &other);

	/**
	 * Const access operator.
	 *
	 * @param i The cell to return.
	 * @return The value of the cell.
	 */
	double operator[](int i) const;

	/**
	 * Access operator.
	 *
	 * @param i The cell to return.
	 * @return A reference to the value of the cell.
	 */
	double& operator[](int i);

	/**
	 * Calculates the norm of the vector.
	 *
	 * @return The norm.
	 */
	double norm() const;

	/**
	 * Calculates the distance between this vector and other.
	 *
	 * @param other The other vector.
	 * @return The distance.
	 */
	double dist(const Vector3D& other) const;

	/**
	 * >> operator.
	 *
	 * @param is The input stream.
	 * @param mat The vector.
	 * @return Reference to the original input stream.
	 */
	friend std::istream& operator>>(std::istream &is, Vector3D &vec);

	/**
	 * << operator.
	 *
	 * @param is The output stream.
	 * @param mat The matrix.
	 * @return Reference to the original output stream.
	 */
	friend std::ostream& operator<<(std::ostream &os, const Vector3D &vec);

	/**
	 * Multiplies the given number and vector, cell by cell.
	 *
	 * @param num The number.
	 * @param origin The vector.
	 * @return A copy of the result vector.
	 */
	friend Vector3D operator*(double num, const Vector3D &origin);

};



#endif
