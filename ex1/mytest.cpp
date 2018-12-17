#include "Matrix3D.h"
#include "Vector3D.h"
#include <sstream>
#include <iostream>

int main()
{
	Matrix3D m(6, 1, 1, 4, -2, 5, 2, 8, 7);
        std::cout << m.determinant() << std::endl;
	return 0;
}
