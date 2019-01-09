#include "Matrix.hpp"
#include <iostream>

int main()
{
	Matrix<int> m(3, 4);
	std::cout << m;
	Matrix<int> n;
	std::cout << std::endl;
	n = m;
	std::cout << n;
	return 0;
}
