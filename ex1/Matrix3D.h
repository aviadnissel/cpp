//
// Created by Avian on 14/12/2018.
//

#ifndef CPP_MATRIX3D_H
#define CPP_MATRIX3D_H

#include "Vector3D.h"

class Matrix3D {
private:
	Vector3D vectors[3];

public:
	Matrix3D();
	Matrix3D(double num);
	Matrix3D(double num1, double num2, double num3,
			 double num4, double num5, double num6,
			 double num7, double num8, double num9);
	Matrix3D(const double numbers[9]);
	Matrix3D(const double numbers[3][3]);
	Matrix3D(const Vector3D& vectorOne, const Vector3D& vectorTwo, const Vector3D& vectorThree);
	Matrix3D(const Matrix3D &other);

	Matrix3D& operator+=(const Matrix3D &other);
	Matrix3D& operator-=(const Matrix3D &other);

	Matrix3D operator-() const;

	Matrix3D& operator*=(const Matrix3D &other);

	Matrix3D operator+(const Matrix3D &other) const;
	Matrix3D operator-(const Matrix3D &other) const;
	Matrix3D operator*(const Matrix3D &other) const;

	Matrix3D& operator*=(double num);
	Matrix3D& operator/=(double num);

	Vector3D operator*(const Vector3D &other) const;

	Matrix3D& operator=(const Matrix3D &other);


	Vector3D operator[](int i) const;
	Vector3D& operator[](int i);

	Vector3D row(short row) const;
	Vector3D column(short column) const;
	double trace() const;
	double determinant() const;

	friend std::istream& operator>>(std::istream &is, Matrix3D &mat);
	friend std::ostream& operator<<(std::ostream &os, const Matrix3D &mat);

};



#endif
