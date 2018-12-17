#include "Vector3D.h"

Vector3D::Vector3D()
{
	coordinates[X] = DEFAULT_VALUE;
	coordinates[Y] = DEFAULT_VALUE;
	coordinates[Z] = DEFAULT_VALUE;
}

Vector3D::Vector3D(const double coordinates[3]) {
	for (int i = 0; i < 3; i++)
	{
		this->coordinates[i] = coordinates[i];
	}
}

Vector3D::Vector3D(double x, double y, double z)
{
	coordinates[X] = x;
	coordinates[Y] = y;
	coordinates[Z] = z;
}

Vector3D::Vector3D(const Vector3D &other)
{
	for(int i = 0; i < 3; i++)
	{
		coordinates[i] = other[i];
	}
}

Vector3D Vector3D::operator+(const Vector3D &other) const
{
	Vector3D newVector(this->coordinates);
	for (int i = 0; i < 3; i++)
	{
		newVector[i] += other[i];
	}
	return newVector;
}
Vector3D Vector3D::operator-(const Vector3D &other) const
{
	return this->operator+(-other);
}

Vector3D& Vector3D::operator+=(const Vector3D &other)
{
	for(int i = 0; i < 3; i++)
	{
		coordinates[i] += other[i];
	}
	return *this;
}
Vector3D& Vector3D::operator-=(const Vector3D &other)
{
	return this->operator+=(-other);
}

Vector3D& Vector3D::operator+=(double num)
{
	for(int i = 0; i < 3; i++)
	{
		coordinates[i] += num;
	}
	return *this;
}

Vector3D& Vector3D::operator-=(double num)
{
	// TODO strandatize
	return this->operator+=(-num);
}


Vector3D Vector3D::operator-() const
{
	double x = -coordinates[X];
	double y = -coordinates[Y];
	double z = -coordinates[Z];
	return Vector3D(x, y, z);
}

Vector3D& Vector3D::operator*=(double num)
{
	for(int i = 0; i < 3; i++)
	{
		(*this)[i] *= num;
	}
	return *this;
}

Vector3D& Vector3D::operator/=(double num)
{
	if (num == 0)
	{
		return *this; // TODO ??
	}
	return *this *= (1/num);
}


Vector3D Vector3D::operator*(double num) const
{
	Vector3D newVector(*this);
	for(int i = 0; i < 3; i++)
	{
		newVector[i] *= num;
	}
	return newVector;
}

Vector3D Vector3D::operator/(double num) const
{
	if (num == 0)
	{
		return *this;
	}
	return *this * (1/num);
}

double Vector3D::operator|(const Vector3D &other) const
{
	double sum = 0;
	for(int i = 0; i < 3; i++) {
		sum += pow((coordinates[i] - other[i]), 2);
	}
	return sqrt(sum);

}
double Vector3D::operator*(const Vector3D &other) const
{
	double sum = 0;
	for(int i = 0; i < 3; i++)
	{
		sum += coordinates[i] * other[i];
	}
	return sum;
}

double Vector3D::operator^(const Vector3D &other) const
{
	double cosDeg;
	double deg;

	cosDeg = *this * other;
	cosDeg /= (this->norm() * other.norm());
	deg = acos(cosDeg);
	return deg;
}

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


double Vector3D::operator[](int i) const
{
	return coordinates[i];
}

double& Vector3D::operator[](int i)
{
	// TODO Does this work?
	return coordinates[i];
}

double Vector3D::norm() const
{
	return *this | Vector3D(0, 0, 0);
}

double Vector3D::dist(const Vector3D& other) const
{
	return *this | other;
}

Vector3D operator*(double num, const Vector3D &origin)
{
	return origin * num;
}

std::istream& operator>>(std::istream &is, Vector3D& vec)
{
	for(int i = 0; i < 3; i++)
	{
		is >> vec[i];
	}
	return is;
}


std::ostream& operator<<(std::ostream &os, const Vector3D &vec)
{
	for(int i = 0; i < 3; i++)
	{
		os << vec[i];
		if ( i < 2)
		{
			os << " ";
		}
	}
	// TODO Check format
	return os;
}
