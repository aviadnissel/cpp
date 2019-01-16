#include "Matrix.hpp"
#include <iostream>
using namespace std;

int main()
{
	Matrix<int> m(3, 4);
	m(1, 1) = 2;
	cout << m(1,1) << endl;
	for (auto i: m)
	{
		cout << i << endl;
	}
	return 0;
}
