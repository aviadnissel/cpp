#include "Matrix3D.h"
#include "Vector3D.h"
#include <iostream>

int main()
{
	Vector3D v1(0, 1, 0);
	Vector3D v2(1, 0, 0);
	std::cout << (v1 ^ v2) << std::endl;
	return 0;
}
