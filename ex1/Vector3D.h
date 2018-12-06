#ifndef CPP_VECTOR3D_H
#define CPP_VECTOR3D_H

#define X 0
#define Y 1
#define Z 2

#define DEFAULT_VALUE 0

class Vector3D
{
public:
    Vector3D();
    Vector3D(double x, double y, double z);
    Vector3D(const double coordinates[3]);
    Vector3D(const Vector3D &other);

private:
    double coordinates[3];
};

#endif
