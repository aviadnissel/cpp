#include "Matrix.hpp"
#include <iostream>
using namespace std;

int main()
{
	Matrix<int> m(3, 4);
	m(1, 1) = 2;
	cout << m(1,1) << endl;
	return 0;
}
