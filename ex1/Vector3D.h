#ifndef CPP_VECTOR3D_H
#define CPP_VECTOR3D_H

#include <iostream>
#include <cmath>

#define X 0
#define Y 1
#define Z 2

#define DEFAULT_VALUE 0

// TODO Where should the & go

class Vector3D
{

private:
	double coordinates[3];
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	Vector3D(const double coordinates[3]);
	Vector3D(const Vector3D &other);

	Vector3D operator+(const Vector3D &other) const;
	Vector3D operator-(const Vector3D &other) const;
	Vector3D& operator+=(const Vector3D &other);
	Vector3D& operator-=(const Vector3D &other);

	Vector3D& operator+=(double num);
	Vector3D& operator-=(double num);

	Vector3D operator*(double num) const;
	Vector3D operator/(double num) const;


	Vector3D operator-() const;

	Vector3D& operator*=(double num);
	Vector3D& operator/=(double num);

	double operator|(const Vector3D &other) const;
	double operator*(const Vector3D &other) const;
	double operator^(const Vector3D &other) const;

	Vector3D& operator=(const Vector3D &other);

	double operator[](int i) const;
	double& operator[](int i);

	double norm() const;
	double dist(const Vector3D& other) const;

	friend std::istream& operator>>(std::istream &is, Vector3D &vec);
	friend std::ostream& operator<<(std::ostream &os, const Vector3D &vec);

	friend Vector3D operator*(double num, const Vector3D &origin);

};



#endif
