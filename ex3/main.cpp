#include "Matrix.hpp"
#include <iostream>

int main()
{
	Matrix<int> m(3, 4);
	std::cout << m;
	Matrix<int> n;
	n = m;
	std::cout << n;
	return 0;
}
