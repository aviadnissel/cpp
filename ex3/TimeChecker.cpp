#include <iostream>
#include <chrono>
#include <ctime>
#include <eigen3/Eigen/Core>
#include "Matrix.hpp"

using std::cout;
using std::cerr;
using std::endl;
using Eigen::MatrixXd;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cerr << "Usage: " << argv[0] << " <size>" << endl;
		return 1;
	}
	int size = atoi(argv[1]); // TODO ?
	if (size < 1 || size > 500) // TODO consts
	{
		cerr << "Size must be between 1 and 500" << endl;
		return 2;
	}
	MatrixXd eigenMatrix = MatrixXd::Random(size, size);
	Matrix<double> myMatrix(size, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			myMatrix(i, j) = eigenMatrix(i, j);
		}
	}

	cout << "size " << size << endl;

	std::chrono::time_point<std::chrono::system_clock> start_time;
	
	start_time = std::chrono::system_clock::now();
	eigenMatrix * eigenMatrix;
	cout << "eigen mult " << (std::chrono::system_clock::now() - start_time).count() << endl;

	start_time = std::chrono::system_clock::now();
	eigenMatrix + eigenMatrix;
	cout << "eigen add " << (std::chrono::system_clock::now() - start_time).count() << endl;

	start_time = std::chrono::system_clock::now();
	myMatrix * myMatrix;
	cout << "matlib mult " << (std::chrono::system_clock::now() - start_time).count() << endl;

	start_time = std::chrono::system_clock::now();
	myMatrix + myMatrix;
	cout << "matlib add " << (std::chrono::system_clock::now() - start_time).count() << endl;

	return 0;
}
