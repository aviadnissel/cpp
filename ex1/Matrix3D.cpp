#include "Matrix3D.h"

/**
 * See header.
 */
Matrix3D::Matrix3D()
{
	// Nothing to do, since vector3d is initialized with default value.
}

/**
 * See header.
 */
Matrix3D::Matrix3D(double num)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			vectors[i][j] = i == j ? num : 0;
		}
	}
}

/**
 * See header.
 */
Matrix3D::Matrix3D(double num1, double num2, double num3,
				   double num4, double num5, double num6,
				   double num7, double num8, double num9)
{
	vectors[0][0] = num1;
	vectors[0][1] = num2;
	vectors[0][2] = num3;

	vectors[1][0] = num4;
	vectors[1][1] = num5;
	vectors[1][2] = num6;

	vectors[2][0] = num7;
	vectors[2][1] = num8;
	vectors[2][2] = num9;
}

/**
 * See header.
 */
Matrix3D::Matrix3D(const double numbers[9])
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			vectors[i][j] = numbers[i * 3 + j];
		}
	}
}

/**
 * See header.
 */
Matrix3D::Matrix3D(const double numbers[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			vectors[i][j] = numbers[i][j];
		}
	}
}

/**
 * See header.
 */
Matrix3D::Matrix3D(const Vector3D& vectorOne, const Vector3D& vectorTwo, const Vector3D& vectorThree)
{
	vectors[0] = vectorOne;
	vectors[1] = vectorTwo;
	vectors[2] = vectorThree;
}

/**
 * See header.
 */
Matrix3D::Matrix3D(const Matrix3D &other) : Matrix3D(other.vectors[0], other.vectors[1], other.vectors[2])
{
}

/**
 * See header.
 */
Matrix3D& Matrix3D::operator+=(const Matrix3D &other)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			vectors[i][j] += other[i][j];
		}
	}
	return *this;
}

/**
 * See header.
 */
Matrix3D& Matrix3D::operator-=(const Matrix3D &other)
{
	return *this += -other;
}

/**
 * See header.
 */
Matrix3D Matrix3D::operator-() const
{
	Matrix3D newMatrix;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			newMatrix[i][j] = -vectors[i][j];
		}
	}
	return newMatrix;
}

/**
 * See header.
 */
Matrix3D& Matrix3D::operator*=(const Matrix3D &other)
{
	*this = *this * other;
	return *this;
}

/**
 * See header.
 */
Matrix3D Matrix3D::operator+(const Matrix3D &other) const
{
	Matrix3D newMatrix(*this);
	for(int i = 0; i < 3; i++)
	{
		newMatrix[i] += other[i];
	}
	return newMatrix;
}

/**
 * See header.
 */
Matrix3D Matrix3D::operator-(const Matrix3D &other) const
{
	return *this + (-other);
}

/**
 * See header.
 */
Matrix3D Matrix3D::operator*(const Matrix3D &other) const
{
	// TODO use * Vector3D
	Matrix3D newMatrix;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			newMatrix[i][j] = row(i) * other.column(j);
		}
	}
	return newMatrix;
}

/**
 * See header.
 */
Matrix3D& Matrix3D::operator*=(double num)
{
	for(int i = 0; i < 3; i++)
	{
		vectors[i] *= num;
	}
	return *this;
}

/**
 * See header.
 */
Matrix3D& Matrix3D::operator/=(double num)
{
	if(num == 0)
	{
		return *this;
	}
	return *this *= (1 / num);
}

/**
 * See header.
 */
Vector3D Matrix3D::operator*(const Vector3D &other) const
{
	Vector3D newVector;
	for(int i = 0; i < 3; i++)
	{
		newVector[i] = vectors[i] * other;
	}
	return newVector;
}

/**
 * See header.
 */
Matrix3D& Matrix3D::operator=(const Matrix3D &other)
{
	for(int i = 0; i < 3; i++)
	{
		vectors[i] = other.vectors[i];
	}
	return *this;
}

/**
 * See header.
 */
Vector3D Matrix3D::operator[](int i) const
{
	return vectors[i];
}

/**
 * See header.
 */
Vector3D& Matrix3D::operator[](int i)
{
	return vectors[i];
}

/**
 * See header.
 */
Vector3D Matrix3D::row(short row) const
{
	return vectors[row];
}

/**
 * See header.
 */
Vector3D Matrix3D::column(short column) const
{
	Vector3D newVector;
	for(int i = 0; i < 3; i++)
	{
		newVector[i] = vectors[i][column];
	}
	return newVector;
}

/**
 * See header.
 */
double Matrix3D::trace() const
{
	double trace = 0;
	for(int i = 0; i < 3; i++)
	{
		trace += vectors[i][i];
	}
	return trace;
}

/**
 * See header.
 */
double Matrix3D::determinant() const
{
	double determinant = 0;
	double sign;
	double curValue;
	double smallDeterminant;
	int nextCell;
	int doubleNextCell;
	Vector3D firstRow = row(0);
	Vector3D secondRow = row(1);
	Vector3D thirdRow = row(2);

	for(int i = 0; i < 3; i++)
	{
		sign = pow(-1, i);
		curValue = firstRow[i];
		nextCell = std::min((i + 1) % 3, (i + 2) % 3);
		doubleNextCell = std::max((i + 1) % 3, (i + 2) % 3);
		smallDeterminant = secondRow[nextCell] * thirdRow[doubleNextCell];
		smallDeterminant -= secondRow[doubleNextCell] * thirdRow[nextCell];
		determinant += sign * curValue * smallDeterminant;
	}
	return determinant;
}

/**
 * See header.
 */
std::istream& operator>>(std::istream &is, Matrix3D &mat)
{
	for(int i = 0; i < 3; i++)
	{
		is >> mat[i];
	}
	return is;
}

/**
 * See header.
 */
std::ostream& operator<<(std::ostream &os, const Matrix3D &mat)
{
	bool firstRun = true;
	for(int i = 0; i < 3; i++)
	{
		if(!firstRun)
		{
			os << std::endl;
		}
		firstRun = false;
		os << mat[i];
	}
	return os;
}
