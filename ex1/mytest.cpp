#include "Matrix3D.h"
#include "Vector3D.h"
#include <sstream>
#include <iostream>

int main()
{
	Vector3D f;
        std::streambuf* orig = std::cin.rdbuf();
        std::istringstream input("5 4 3");
        std::cin.rdbuf(input.rdbuf());
        std::cin >> f;
        std::cin.rdbuf(orig);
	std::cout << f[0] << std::endl;
        std::cout << f << std::endl;
	return 0;
}
