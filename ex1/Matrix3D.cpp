#include "Matrix3D.h"

Matrix3D::Matrix3D()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            vectors[i][j] = 0;
        }
    }
}

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
Matrix3D::Matrix3D(double num1, double num2, double num3,
         double num4, double num5, double num6,
         double num7, double num8, double num9)
{
    // TODO Make it better
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

Matrix3D::Matrix3D(const Vector3D vectors[3])
{
    // TODO can that be merged with [3][3]?
    for(int i = 0; i < 3; i++)
    {
        this->vectors[i] = vectors[i];
    }
}

Matrix3D::Matrix3D(const Matrix3D &other) : Matrix3D(other.vectors)
{
}

Matrix3D& Matrix3D::operator+=(const Matrix3D &other)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            vectors[i][j] += other[i][j];
        }
    }
}
Matrix3D& Matrix3D::operator-=(const Matrix3D &other)
{
    return *this += -other;
}

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

Matrix3D& Matrix3D::operator*=(const Matrix3D &other)
{
    *this = *this * other;
    return *this;
}

Matrix3D Matrix3D::operator+(const Matrix3D &other) const
{
    Matrix3D newMatrix(*this);
    for(int i = 0; i < 3; i++)
    {
        newMatrix[i] += other[i];
    }
    return newMatrix;
}
Matrix3D Matrix3D::operator-(const Matrix3D &other) const
{
    return *this + (-other);
}
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

Matrix3D& Matrix3D::operator*=(double num)
{
    for(int i = 0; i < 3; i++)
    {
        vectors[i] *= num;
    }
    return *this;
}

Matrix3D& Matrix3D::operator/=(double num)
{
    if(num == 0)
    {
        return *this;
    }
    return *this *= (1/num);
}

Vector3D Matrix3D::operator*(const Vector3D &other) const
{
    Vector3D newVector;
    for(int i = 0; i < 3; i++)
    {
        newVector[i] = vectors[i] * other;
    }
    return newVector;
}