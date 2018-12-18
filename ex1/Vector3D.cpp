#include "Vector3D.h"

/**
 * See header.
 */
Vector3D::Vector3D()
{
	coordinates[X] = DEFAULT_VALUE;
	coordinates[Y] = DEFAULT_VALUE;
	coordinates[Z] = DEFAULT_VALUE;
}

/**
 * See header.
 */
Vector3D::Vector3D(const double coordinates[3])
{
	for (int i = 0; i < 3; i++)
	{
		this->coordinates[i] = coordinates[i];
	}
}

/**
 * See header.
 */
Vector3D::Vector3D(double x, double y, double z)
{
	coordinates[X] = x;
	coordinates[Y] = y;
	coordinates[Z] = z;
}

/**
 * See header.
 */
Vector3D::Vector3D(const Vector3D &other)
{
	for(int i = 0; i < 3; i++)
	{
		coordinates[i] = other[i];
	}
}

/**
 * See header.
 */
Vector3D Vector3D::operator+(const Vector3D &other) const
{
	Vector3D newVector(this->coordinates);
	for (int i = 0; i < 3; i++)
	{
		newVector[i] += other[i];
	}
	return newVector;
}

/**
 * See header.
 */
Vector3D Vector3D::operator-(const Vector3D &other) const
{
	return this->operator+(-other);
}

/**
 * See header.
 */
Vector3D& Vector3D::operator+=(const Vector3D &other)
{
	for(int i = 0; i < 3; i++)
	{
		coordinates[i] += other[i];
	}
	return *this;
}

/**
 * See header.
 */
Vector3D& Vector3D::operator-=(const Vector3D &other)
{
	return this->operator+=(-other);
}

/**
 * See header.
 */
Vector3D& Vector3D::operator+=(double num)
{
	for(int i = 0; i < 3; i++)
	{
		coordinates[i] += num;
	}
	return *this;
}

/**
 * See header.
 */
Vector3D& Vector3D::operator-=(double num)
{
	// TODO strandatize
	return this->operator+=(-num);
}

/**
 * See header.
 */
Vector3D Vector3D::operator-() const
{
	double x = -coordinates[X];
	double y = -coordinates[Y];
	double z = -coordinates[Z];
	return Vector3D(x, y, z);
}

/**
 * See header.
 */
Vector3D& Vector3D::operator*=(double num)
{
	for(int i = 0; i < 3; i++)
	{
		(*this)[i] *= num;
	}
	return *this;
}

/**
 * See header.
 */
Vector3D& Vector3D::operator/=(double num)
{
	if (num == 0)
	{
		return *this; // TODO ??
	}
	return *this *= (1 / num);
}

/**
 * See header.
 */
Vector3D Vector3D::operator*(double num) const
{
	Vector3D newVector(*this);
	for(int i = 0; i < 3; i++)
	{
		newVector[i] *= num;
	}
	return newVector;
}

/**
 * See header.
 */
Vector3D Vector3D::operator/(double num) const
{
	if (num == 0)
	{
		return *this;
	}
	return *this * (1 / num);
}

/**
 * See header.
 */
double Vector3D::operator|(const Vector3D &other) const
{
	double sum = 0;
	for(int i = 0; i < 3; i++)
	{
		sum += pow((coordinates[i] - other[i]), 2);
	}
	return sqrt(sum);

}

/**
 * See header.
 */
double Vector3D::operator*(const Vector3D &other) const
{
	double sum = 0;
	for(int i = 0; i < 3; i++)
	{
		sum += coordinates[i] * other[i];
	}
	return sum;
}

/**
 * See header.
 */
double Vector3D::operator^(const Vector3D &other) const
{
	double cosDeg;
	double deg;

	cosDeg = *this * other;
	cosDeg /= (this->norm() * other.norm());
	deg = acos(cosDeg);
	return deg;
}

/**
 * See header.
 */
Vector3D& Vector3D::operator=(const Vector3D &other)
{
	if (this == &other)
	{
		return *this;
	}
	for(int i = 0; i < 3; i++)
	{
		coordinates[i] = other[i];
	}
	return *this;
}

/**
 * See header.
 */
double Vector3D::operator[](int i) const
{
	return coordinates[i];
}

/**
 * See header.
 */
double& Vector3D::operator[](int i)
{
	return coordinates[i];
}

/**
 * See header.
 */
double Vector3D::norm() const
{
	return *this | Vector3D(0, 0, 0);
}

/**
 * See header.
 */
double Vector3D::dist(const Vector3D& other) const
{
	return *this | other;
}

/**
 * See header.
 */
Vector3D operator*(double num, const Vector3D &origin)
{
	return origin * num;
}

/**
 * See header.
 */
std::istream& operator>>(std::istream &is, Vector3D& vec)
{
	for(int i = 0; i < 3; i++)
	{
		is >> vec[i];
	}
	return is;
}

/**
 * See header.
 */
std::ostream& operator<<(std::ostream &os, const Vector3D &vec)
{
	bool firstRun = true;
	for(int i = 0; i < 3; i++)
	{
		if(!firstRun)
		{
			os << " ";
		}
		firstRun = false;
		os << vec[i];
	}
	return os;
}
