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
        coordinates[i] = other.coordinates[i];
    }
}