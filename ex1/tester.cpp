// ============================ Includes ============================

#include "Vector3D.h"
#include "Matrix3D.h"
#include <iostream>
#include <sstream>

// ================== Change ONLY these variables ==================

// "true" if you want to print errors only
// "false" if you want to print all tests
bool printErrorsOnly = true;

// "true" if you want to debug one error at a time
bool oneErrorAtATime = false;

// "true" if you want to test Vector3D class
bool testVectorClass = true;

// "true" if you want to test Matrix3D class
bool testMatrixClass = true;

// =================================================================

int numOfErrors = 0;

int check(std::stringstream& buffer, const std::string &answer, const std::string &tested)
{
	if(buffer.str() != answer)
	{
		numOfErrors++;
	}
	if(!printErrorsOnly || buffer.str() != answer)
	{
		std::cout << tested << std::endl;
		std::cout << "Your answer: " << std::endl << "\"" << buffer.str() << "\"" << std::endl;
		std::cout << "Right answer: " << std::endl << "\"" << answer << "\"" << std::endl << std::endl;
		std::cout.flush();
		if(buffer.str() != answer && oneErrorAtATime)
		{
			std::exit(1);
		}
	}
	buffer.str(std::string());
	buffer.clear();
}

std::string getString(Vector3D& vector)
{
	std::stringstream buffer;
	buffer << vector;
	return buffer.str();
}

std::string getString(Matrix3D& matrix)
{
	std::stringstream buffer;
	buffer << matrix;
	return buffer.str();
}

void testVector()
{
	std::stringstream buffer;
	Vector3D a(3.0, 2.0, 5.0);
	Vector3D b(7.0, 1.0, 0.0);
	double nums[3] = {5.0, 1.0, 4.0};
	Vector3D c(nums);
	Vector3D d(15.0, 5.0, 10.0);
	Vector3D t;

	// Test Constructors

	buffer << t;
	check(buffer, "0 0 0", "Construct a new vector with default constructor");

	buffer << a;
	check(buffer, "3 2 5", "Construct a new vector with 3 given doubles");

	buffer << c;
	check(buffer, "5 1 4", "Construct a new vector with array of 3 doubles");

	Vector3D r(c);
	buffer << r;
	check(buffer, "5 1 4", "Construct a new vector with copy constructor");

	// Test Operators

	Vector3D e = b + c;
	buffer << e;
	check(buffer, "12 2 4", "Test '+' operator. [" + getString(b) + "] + [" + getString(c) + "]");

	buffer << a - b;
	check(buffer, "-4 1 5", "Test '-' operator. [" + getString(a) + "] - [" + getString(b) + "]");

	std::string tempB = getString(b);
	std::string tempC = getString(c);
	b -= c;
	c += d;
	buffer << b;
	check(buffer, "2 0 -4", "Test '-=' operator. [" + tempB + "] -= [" + tempC + "]");
	buffer << c;
	check(buffer, "20 6 14", "Test '+=' operator. [" + tempC + "] += [" + getString(d) + "]");

	buffer << -d;
	check(buffer, "-15 -5 -10", "Test 'unary -' operator. -[" + getString(d) + "]");

	buffer << a[2];
	check(buffer, "5", "Test '[]' operator. [" + getString(a) + "][2]");

	tempB = getString(b);
	b[0] = 3.0;
	buffer << b;
	check(buffer, "3 0 -4", "Test '[]' operator. [" + tempB + "][0] = 3.0");

	std::string tempA = getString(a);
	tempB = getString(b);
	a -= 5;
	b += 3;
	buffer << a;
	check(buffer, "-2 -3 0", "Test '-=' operator. [" + tempA + "] -= 5");
	buffer << b;
	check(buffer, "6 3 -1", "Test '+=' operator. [" + tempB + "] += 3");

	Vector3D f = a * 5;
	Vector3D g = b / 2;
	buffer << f;
	check(buffer, "-10 -15 0", "Test '*' operator. [" + getString(a) + "] * 5");
	buffer << g;
	check(buffer, "3 1.5 -0.5", "Test '/' operator. [" + getString(a) + "] / 5");

	f = 2 * b;
	buffer << f;
	check(buffer, "12 6 -2", "Test '*' operator. 2 * [" + getString(b) + "]");

	std::string tempF = getString(f);
	std::string tempG = getString(g);
	f *= 5;
	g /= 0.5;
	buffer << f;
	check(buffer, "60 30 -10", "Test '*=' operator. [" + tempF + "] *= 5");
	buffer << g;
	check(buffer, "6 3 -1", "Test '/=' operator. [" + tempG + "] /= 0.5");

	buffer << (a|f);
	check(buffer, "70.9436", "Test '|' operator. ([" + getString(a) + "] | " + "[" + getString(f) + "])");

	buffer << (f*g);
	check(buffer, "460", "Test '*' operator. ([" + getString(f) + "] * " + "[" + getString(g) + "])");

	buffer << (a^b);
	check(buffer, "2.60363", "Test '^' operator. ([" + getString(a) + "] ^ " + "[" + getString(b) + "])");

	Vector3D m = d;
	buffer << m;
	check(buffer, "15 5 10", "Test '=' operator. m = [" + getString(d) + "]");

	std::streambuf* orig = std::cin.rdbuf();
	std::istringstream input("5 4 3");
	std::cin.rdbuf(input.rdbuf());
	std::cin >> f;
	std::cin.rdbuf(orig);
	buffer << f;
	check(buffer, "5 4 3", "Test '>>' operator. Read \"5 4 3\" from stdin into vector");

	// Test Functions

	buffer << a.norm();
	check(buffer, "3.60555", "Run \"norm()\" function. [" + getString(a) + "].norm()");

	buffer << a.dist(b);
	check(buffer, "10.0499", "Run \"dist\" function. [" + getString(a) + "].dist([" + getString(b) + "])");
}

void testMatrix()
{

	std::stringstream buffer;
	Matrix3D a;
	Matrix3D b(8);
	Matrix3D c(1, 2, 3, 4, 5, 6, 7, 8, 9);
	double nums[9] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
	Matrix3D d(nums);
	double nums2[3][3] = {3, 6, 9, 12, 15, 18, 21, 24, 27};
	Matrix3D e(nums2);
	Vector3D g(3.0, 2.0, 5.0);

	// Test Constructors

	buffer << a;
	check(buffer, "0 0 0\n0 0 0\n0 0 0", "Construct a new matrix with default constructor");

	buffer << b;
	check(buffer, "8 0 0\n0 8 0\n0 0 8", "Construct a new matrix with a given double (8) in diagonal");

	buffer << c;
	check(buffer, "1 2 3\n4 5 6\n7 8 9", "Construct a new matrix with 9 given doubles");

	buffer << d;
	check(buffer, "2 4 6\n8 10 12\n14 16 18", "Construct a new matrix with a given [9] array");

	buffer << e;
	check(buffer, "3 6 9\n12 15 18\n21 24 27", "Construct a new matrix with a given [3][3] array");

	Matrix3D r(c);
	buffer << r;
	check(buffer, "1 2 3\n4 5 6\n7 8 9", "Construct a new matrix with copy constructor");

	// Test Operators

	buffer << (b + c);
	check(buffer, "9 2 3\n4 13 6\n7 8 17", "Test '+' operator. \n" + getString(b) + "\n  + \n" + getString(c));

	buffer << (a - b);
	check(buffer, "-8 0 0\n0 -8 0\n0 0 -8", "Test '-' operator. \n" + getString(a) + "\n  - \n" + getString(b));

	buffer << (d * e);
	check(buffer, "180 216 252\n396 486 576\n612 756 900", "Test '*' operator. \n" + getString(d) + "\n  * \n" + getString(e));

	buffer << (d * g);
	check(buffer, "44 104 164", "Test '*' operator. \n" + getString(d) + "\n  * \n" + getString(g));

	std::string tempE = getString(e);
	e /= 3;
	buffer << e;
	check(buffer, "1 2 3\n4 5 6\n7 8 9", "Test '/=' operator. \n" + tempE + "\n  /= \n3");

	std::string tempC = getString(c);
	c *= 5;
	buffer << c;
	check(buffer, "5 10 15\n20 25 30\n35 40 45", "Test '*=' operator. \n" + tempC + "\n  *= \n 5");

	Matrix3D m = e;
	buffer << m;
	check(buffer, "1 2 3\n4 5 6\n7 8 9", "Test '=' operator.");

	std::streambuf* orig = std::cin.rdbuf();
	std::istringstream input("6 2 3 4 5 8 7 9 5");
	std::cin.rdbuf(input.rdbuf());
	std::cin >> m;
	std::cin.rdbuf(orig);
	buffer << m;
	check(buffer, "6 2 3\n4 5 8\n7 9 5", "Test '>>' operator. Read \"6 2 3 4 5 8 7 9 5\" from stdin into matrix");

	buffer << c[2];
	check(buffer, "35 40 45", "Test '[]' operator. Get [2] line of: \n" + getString(c));

	std::string tempB = getString(b);
	b[0] = {5, 6, 7};
	buffer << b;
	check(buffer, "5 6 7\n0 8 0\n0 0 8", "Test '[]' operator. Change [0] line of: \n" + tempB + "\nwith [5, 6, 7]");

	tempC = getString(c);
	c *= d;
	buffer << c;
	check(buffer, "300 360 420\n660 810 960\n1020 1260 1500", "Test '*=' operator. \n" + tempC + "\n  *= \n " + getString(d));

	tempB = getString(b);
	tempC = getString(c);
	b -= c;
	c += d;
	buffer << b;
	check(buffer, "-295 -354 -413\n-660 -802 -960\n-1020 -1260 -1492", "Test '-=' operator. \n" + tempB + "\n  -= \n" + tempC);
	buffer << c;
	check(buffer, "302 364 426\n668 820 972\n1034 1276 1518", "Test '+=' operator. \n" + tempC + "\n  += \n" + getString(d));

	// Test Functions

	buffer << b.row(2);
	check(buffer, "-1020 -1260 -1492", "Run \"row(2)\" function on: \n" + getString(b));

	buffer << c.column(1);
	check(buffer, "364 820 1276", "Run \"column(1)\" function on: \n" + getString(c));

	buffer << d.trace();
	check(buffer, "30", "Run \"trace()\" function on: \n" + getString(d));

	buffer << b.determinant();
	check(buffer, "193520", "Run \"determinant()\" function on: \n" + getString(b));
}

int main()
{
	int vectorErrors = 0;
	int matrixErrors = 0;
	if(testVectorClass)
	{
		testVector();
		vectorErrors = numOfErrors;
		numOfErrors = 0;
	}
	if(testMatrixClass)
	{
		testMatrix();
		matrixErrors = numOfErrors;
	}
	if(vectorErrors == 0 && matrixErrors == 0)
	{
		std::cout << "All tests passed";
	}
	else
	{
		std::cout << "Num of Vector3D errors: " << vectorErrors << std::endl;
		std::cout << "Num of Matrix3D errors: " << matrixErrors << std::endl;
	}
	return 0;
}