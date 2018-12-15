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
         double num7, double num8, double num9) : Matrix3D({num1, num2, num3,
                                                            num4, num5, num6,
                                                            num7, num8, num9})
{}

Matrix3D::Matrix3D(double numbers[9])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            vectors[i][j] = numbers[i * 3 + j];
        }
    }
}

Matrix3D::Matrix3D(double numbers[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            vectors[i][j] = numbers[i][j];
        }
    }
}

Matrix3D::Matrix3D(Vector3D vectors[3])
{
    for(int i = 0; i < 3; i++)
    {
        this->vectors[i] = vectors[i];
    }
}

Matrix3D::Matrix3D(const Matrix3D &other)
{
    for(int i = 0; i < 3; i++)
    {
        vectors[i] = other.vectors[i];
    }
}

