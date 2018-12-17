//
// Created by odedw on 12/9/2018.
//

#include "Vector3D.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>

void constructorsTest(int &tests);

void readFromStreamTest(int &tests);

void outputToStreamTest(int &tests);

void additionTest(int &tests);

void subtractionTest(int &tests);

void currentAddTest(int &tests);

void currentSubtractTest(int &tests);

void negateTest(int &tests);

void scalarMulVecTest(int &tests);

void vecMulScalarTest(int &tests);

void vecDivScalarTest(int &tests);

void currentMulScalarTest(int &tests);

void currentDivScalarTest(int &tests);

void distanceOperatorTest(int &tests);

void radianAngleTest(int &tests);

void assignmentTest(int &tests);

void scalarMulTest(int &tests);

void accessTest(int &tests);

void normTest(int &tests);

void distanceMethodTest(int &tests);

/**
 * A few tests for the Vector3D class. if the printing to cout does not work well - all tests will fail.
 * @return 0
 */
int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int overallTests = 20;
    int successfulTests = 0;
    readFromStreamTest(successfulTests);
    outputToStreamTest(successfulTests);
    constructorsTest(successfulTests);
    additionTest(successfulTests);
    subtractionTest(successfulTests);
    currentAddTest(successfulTests);
    currentSubtractTest(successfulTests);
    negateTest(successfulTests);
    scalarMulVecTest(successfulTests);
    vecMulScalarTest(successfulTests);
    vecDivScalarTest(successfulTests);
    currentMulScalarTest(successfulTests);
    currentDivScalarTest(successfulTests);
    distanceOperatorTest(successfulTests);
    scalarMulTest(successfulTests);
    radianAngleTest(successfulTests);
    assignmentTest(successfulTests);
    accessTest(successfulTests);
    normTest(successfulTests);
    distanceMethodTest(successfulTests);
    std::cout << std::endl << "----------------------------------------" << std::endl;
    std::cout << successfulTests << " out of " << overallTests << " test passed." << std::endl;
    return 0;

}

void distanceMethodTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x1, y1, z1, x2, y2, z2;
        x1 = std::rand();
        y1 = std::rand();
        z1 = std::rand();
        x2 = std::rand();
        y2 = std::rand();
        z2 = std::rand();
        if (x1 % 2 == 0) {
            x1 = -x1;
        }
        if (y1 % 2 == 0) {
            y1 = -y1;
        }
        if (z1 % 2 == 0) {
            z1 = -z1;
        }
        if (x2 % 2 == 0) {
            x2 = -x2;
        }
        if (y2 % 2 == 0) {
            y2 = -y2;
        }
        if (z2 % 2 == 0) {
            z2 = -z2;
        }
        Vector3D a(x1, y1, z1);
        Vector3D b(x2, y2, z2);
        double dx1 = x1, dy1 = y1, dz1 = z1, dx2 = x2, dy2 = y2, dz2 = z2;
        double res = a.dist(b);
        double correct = std::sqrt(
                std::pow((dx1 - dx2), 2) + std::pow((dy1 - dy2), 2) + std::pow((dz1 - dz2), 2));
        if (res != correct) {
            std::cerr << "dist method test failed. Should be " << correct << " yet received " << res << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
        std::cout<<"Vector.dist(Vector) tests passed"<<std::endl;
    }
}

void normTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x, y, z;
        x = std::rand();
        y = std::rand();
        z = std::rand();
        if (x % 2 == 0) {
            x = -x;
        }
        if (y % 2 == 0) {
            y = -y;
        }
        if (z % 2 == 0) {
            z = -z;
        }
        Vector3D a(x, y, z);
        double dx = x, dy = y, dz = z;
        double res = a.norm();
        double correct = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2) + std::pow(dz, 2));
        if (res != correct) {
            std::cerr << "norm test failed. Should be " << correct << " yet received " << res << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
        std::cout<<"Vector.norm() tests passed"<<std::endl;
    }
}

void accessTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x, y, z;
        x = std::rand();
        y = std::rand();
        z = std::rand();
        if (x % 2 == 0) {
            x = -x;
        }
        if (y % 2 == 0) {
            y = -y;
        }
        if (z % 2 == 0) {
            z = -z;
        }
        Vector3D a(x, y, z);
        if (a[0] != x || a[1] != y || a[2] != z) {
            std::cerr << "[] operator test failed. Should be "
                      << x << " " << y << " " << z << " yet received " << a[0] << a[1] << a[2] << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
        std::cout<<"Vector[i] tests passed"<<std::endl;
    }
}

void scalarMulTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x1, y1, z1, x2, y2, z2;
        x1 = std::rand();
        y1 = std::rand();
        z1 = std::rand();
        x2 = std::rand();
        y2 = std::rand();
        z2 = std::rand();
        if (x1 % 2 == 0) {
            x1 = -x1;
        }
        if (y1 % 2 == 0) {
            y1 = -y1;
        }
        if (z1 % 2 == 0) {
            z1 = -z1;
        }
        if (x2 % 2 == 0) {
            x2 = -x2;
        }
        if (y2 % 2 == 0) {
            y2 = -y2;
        }
        if (z2 % 2 == 0) {
            z2 = -z2;
        }
        Vector3D a(x1, y1, z1);
        Vector3D b(x2, y2, z2);
        double dx1 = x1, dy1 = y1, dz1 = z1, dx2 = x2, dy2 = y2, dz2 = z2;
        double res = a * b;
        double correct = (dx1 * dx2) + (dy1 * dy2) + (dz1 * dz2);
        if (res != correct) {
            std::cerr << "Scalar multiplicity (vec*vec) test failed. Should be " << correct << " yet received " << res
                      << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
    }
}

void assignmentTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x1, y1, z1, x2, y2, z2;
        x1 = std::rand();
        y1 = std::rand();
        z1 = std::rand();
        x2 = std::rand();
        y2 = std::rand();
        z2 = std::rand();
        if (x1 % 2 == 0) {
            x1 = -x1;
        }
        if (y1 % 2 == 0) {
            y1 = -y1;
        }
        if (z1 % 2 == 0) {
            z1 = -z1;
        }
        if (x2 % 2 == 0) {
            x2 = -x2;
        }
        if (y2 % 2 == 0) {
            y2 = -y2;
        }
        if (z2 % 2 == 0) {
            z2 = -z2;
        }
        Vector3D a(x1, y1, z1);
        a[0] = x2;
        a[1] = y2;
        a[2] = z2;
        double dx2 = x2, dy2 = y2, dz2 = z2;

        if ((a[0] != dx2) || (a[1] != dy2) || (a[2] != dz2)) {
            std::cerr << "[] assignment test failed. Should be " << dx2 << " " << dy2 << " " << dz2 << " yet received "
                      << a << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
        std::cout<<"Vector[i]=Scalar tests passed"<<std::endl;
    }
}

void radianAngleTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x1, y1, z1, x2, y2, z2;
        x1 = std::rand();
        y1 = std::rand();
        z1 = std::rand();
        x2 = std::rand();
        y2 = std::rand();
        z2 = std::rand();
        if (x1 % 2 == 0) {
            x1 = -x1;
        }
        if (y1 % 2 == 0) {
            y1 = -y1;
        }
        if (z1 % 2 == 0) {
            z1 = -z1;
        }
        if (x2 % 2 == 0) {
            x2 = -x2;
        }
        if (y2 % 2 == 0) {
            y2 = -y2;
        }
        if (z2 % 2 == 0) {
            z2 = -z2;
        }
        Vector3D a(x1, y1, z1);
        Vector3D b(x2, y2, z2);
        double dx1 = x1, dy1 = y1, dz1 = z1, dx2 = x2, dy2 = y2, dz2 = z2;
        double res = a ^b;
        double correct = std::acos(((dx1 * dx2) + (dy1 * dy2) + (dz1 * dz2)) /
                                   (std::sqrt((dx1 * dx1) + (dy1 * dy1) + (dz1 * dz1)) *
                                    std::sqrt((dx2 * dx2) + (dy2 * dy2) + (dz2 * dz2))));
        if (res != correct) {
            std::cerr << "^ operator test failed. Should be " << correct << " yet received " << res << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
        std::cout << "Vector^Vector tests passed" << std::endl;
    }
}

void distanceOperatorTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x1, y1, z1, x2, y2, z2;
        x1 = std::rand();
        y1 = std::rand();
        z1 = std::rand();
        x2 = std::rand();
        y2 = std::rand();
        z2 = std::rand();
        if (x1 % 2 == 0) {
            x1 = -x1;
        }
        if (y1 % 2 == 0) {
            y1 = -y1;
        }
        if (z1 % 2 == 0) {
            z1 = -z1;
        }
        if (x2 % 2 == 0) {
            x2 = -x2;
        }
        if (y2 % 2 == 0) {
            y2 = -y2;
        }
        if (z2 % 2 == 0) {
            z2 = -z2;
        }
        Vector3D a(x1, y1, z1);
        Vector3D b(x2, y2, z2);
        double dx1 = x1, dy1 = y1, dz1 = z1, dx2 = x2, dy2 = y2, dz2 = z2;
        double res = a | b;
        double correct = std::sqrt(
                std::pow((dx1 - dx2), 2) + std::pow((dy1 - dy2), 2) + std::pow((dz1 - dz2), 2));
        if (res != correct) {
            std::cerr << "| operator test failed. Should be " << correct << " yet received " << res << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
        std::cout << "Vector|Vector tests passed" << std::endl;
    }
}

void currentDivScalarTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x, y, z, scalar;
        x = std::rand();
        y = std::rand();
        z = std::rand();
        scalar = std::rand();
        if (x % 2 == 0) {
            x = -x;
        }
        if (y % 2 == 0) {
            y = -y;
        }
        if (z % 2 == 0) {
            z = -z;
        }
        Vector3D a(x, y, z);
        a /= scalar;
        os << a;
        if (!os.str().compare(
                std::to_string(x / scalar) + " " + std::to_string(y / scalar) + " " + std::to_string(z / scalar))) {
            std::cerr << "Vector/=Scalar test failed. Should be "
                      << std::to_string(x / scalar) + " " + std::to_string(y / scalar) + " " +
                         std::to_string(z / scalar) << " yet received " << a << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
        std::cout << "Vector/=Scalar tests passed" << std::endl;
    }
}

void currentMulScalarTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x, y, z, scalar;
        x = std::rand();
        y = std::rand();
        z = std::rand();
        scalar = std::rand();
        if (x % 2 == 0) {
            x = -x;
        }
        if (y % 2 == 0) {
            y = -y;
        }
        if (z % 2 == 0) {
            z = -z;
        }
        Vector3D a(x, y, z);
        a *= scalar;
        os << a;
        if (!os.str().compare(
                std::to_string(x * scalar) + " " + std::to_string(y * scalar) + " " + std::to_string(z * scalar))) {
            std::cerr << "Vector*=Scalar test failed. Should be "
                      << std::to_string(x * scalar) + " " + std::to_string(y * scalar) + " " +
                         std::to_string(z * scalar) << " yet received " << a << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
        std::cout << "Vector*=Scalar tests passed" << std::endl;
    }
}

void vecDivScalarTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x, y, z, scalar;
        x = std::rand();
        y = std::rand();
        z = std::rand();
        scalar = std::rand();
        if (x % 2 == 0) {
            x = -x;
        }
        if (y % 2 == 0) {
            y = -y;
        }
        if (z % 2 == 0) {
            z = -z;
        }
        Vector3D a(x, y, z);
        os << (a / scalar);
        if (!os.str().compare(
                std::to_string(x / scalar) + " " + std::to_string(y / scalar) + " " + std::to_string(z / scalar))) {
            std::cerr << "Vector/Scalar test failed. Should be "
                      << std::to_string(x / scalar) + " " + std::to_string(y / scalar) + " " +
                         std::to_string(z / scalar) << " yet received " << (a / scalar) << std::endl;
            fail = true;
        }
        os.str(std::string());

        os << a;
        if (!os.str().compare(std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z))) {
            std::cerr << "Vector/Scalar test failed - changed the divided vector. Should be " + std::to_string(x) +
                         " " + std::to_string(y) + " " + std::to_string(z) + " yet received " << a << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
        std::cout << "Vector/Scalar tests passed" << std::endl;
    }
}

void vecMulScalarTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x, y, z, scalar;
        x = std::rand();
        y = std::rand();
        z = std::rand();
        scalar = std::rand();
        if (x % 2 == 0) {
            x = -x;
        }
        if (y % 2 == 0) {
            y = -y;
        }
        if (z % 2 == 0) {
            z = -z;
        }
        Vector3D a(x, y, z);
        os << (a * scalar);
        if (!os.str().compare(
                std::to_string(x * scalar) + " " + std::to_string(y * scalar) + " " + std::to_string(z * scalar))) {
            std::cerr << "Vector*Scalar test failed. Should be "
                      << std::to_string(x * scalar) + " " + std::to_string(y * scalar) + " " +
                         std::to_string(z * scalar) << " yet received " << (a * scalar) << std::endl;
            fail = true;
        }
        os.str(std::string());

        os << a;
        if (!os.str().compare(std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z))) {
            std::cerr << "Vector*Scalar test failed - changed the multiplied vector. Should be " + std::to_string(x) +
                         " " + std::to_string(y) + " " + std::to_string(z) + " yet received " << a << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
        std::cout << "Vector*Scalar tests passed" << std::endl;
    }
}

void scalarMulVecTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x, y, z, scalar;
        x = std::rand();
        y = std::rand();
        z = std::rand();
        scalar = std::rand();
        if (x % 2 == 0) {
            x = -x;
        }
        if (y % 2 == 0) {
            y = -y;
        }
        if (z % 2 == 0) {
            z = -z;
        }
        Vector3D a(x, y, z);
        os << (scalar * a);
        if (!os.str().compare(
                std::to_string(x * scalar) + " " + std::to_string(y * scalar) + " " + std::to_string(z * scalar))) {
            std::cerr << "Scalar*Vector test failed. Should be "
                      << std::to_string(x * scalar) + " " + std::to_string(y * scalar) + " " +
                         std::to_string(z * scalar) << " yet received " << (scalar * a) << std::endl;
            fail = true;
        }
        os.str(std::string());

        os << a;
        if (!os.str().compare(std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z))) {
            std::cerr << "Scalar*Vector test failed - changed the multiplied vector. Should be " + std::to_string(x) +
                         " " + std::to_string(y) + " " + std::to_string(z) + " yet received " << a << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
        std::cout << "Scalar*Vector tests passed" << std::endl;
    }
}

void negateTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x, y, z;
        x = std::rand();
        y = std::rand();
        z = std::rand();
        if (x % 2 == 0) {
            x = -x;
        }
        if (y % 2 == 0) {
            y = -y;
        }
        if (z % 2 == 0) {
            z = -z;
        }
        Vector3D a(x, y, z);
        os << (-a);
        if (!os.str().compare(
                std::to_string(-x) + " " + std::to_string(-y) + " " + std::to_string(-z))) {
            std::cerr << "Negation test failed. Should be "
                      << std::to_string(-x) + " " + std::to_string(-y) + " " +
                         std::to_string(-z) << " yet received " << (-a) << std::endl;
            fail = true;
        }
        os.str(std::string());

        os << a;
        if (!os.str().compare(std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z))) {
            std::cerr << "Negation test failed - changed the negated vector. Should be " + std::to_string(x) +
                         " " + std::to_string(y) + " " + std::to_string(z) + " yet received " << a << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
        std::cout << "-Vector tests passed" << std::endl;
    }
}

void currentSubtractTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x1, y1, z1, x2, y2, z2;
        x1 = std::rand();
        y1 = std::rand();
        z1 = std::rand();
        x2 = std::rand();
        y2 = std::rand();
        z2 = std::rand();
        if (x1 % 2 == 0) {
            x1 = -x1;
        }
        if (y1 % 2 == 0) {
            y1 = -y1;
        }
        if (z1 % 2 == 0) {
            z1 = -z1;
        }
        if (x2 % 2 == 0) {
            x2 = -x2;
        }
        if (y2 % 2 == 0) {
            y2 = -y2;
        }
        if (z2 % 2 == 0) {
            z2 = -z2;
        }
        Vector3D a(x1, y1, z1);
        Vector3D b(x2, y2, z2);
        a -= b;
        os << a;
        if (!os.str().compare(
                std::to_string(x1 - x2) + " " + std::to_string(y1 - y2) + " " + std::to_string(z1 - z2))) {
            std::cerr << "-= test failed. Should be "
                      << std::to_string(x1 - x2) + " " + std::to_string(y1 - y2) + " " + std::to_string(z1 - z2)
                      << " yet received " << a << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
        std::cout << "Vector-=vector tests passed" << std::endl;
    }
}

void currentAddTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x1, y1, z1, x2, y2, z2;
        x1 = std::rand();
        y1 = std::rand();
        z1 = std::rand();
        x2 = std::rand();
        y2 = std::rand();
        z2 = std::rand();
        if (x1 % 2 == 0) {
            x1 = -x1;
        }
        if (y1 % 2 == 0) {
            y1 = -y1;
        }
        if (z1 % 2 == 0) {
            z1 = -z1;
        }
        if (x2 % 2 == 0) {
            x2 = -x2;
        }
        if (y2 % 2 == 0) {
            y2 = -y2;
        }
        if (z2 % 2 == 0) {
            z2 = -z2;
        }
        Vector3D a(x1, y1, z1);
        Vector3D b(x2, y2, z2);
        a += b;
        os << a;
        if (!os.str().compare(
                std::to_string(x1 + x2) + " " + std::to_string(y1 + y2) + " " + std::to_string(z1 + z2))) {
            std::cerr << "+= test failed. Should be "
                      << std::to_string(x1 + x2) + " " + std::to_string(y1 + y2) + " " + std::to_string(z1 + z2)
                      << " yet received " << a << std::endl;
            fail = true;
        }
        os.str(std::string());
    }

    if (!fail) {
        ++tests;
        std::cout << "Vector+=Vector tests passed" << std::endl;
    }
}

void subtractionTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x1, y1, z1, x2, y2, z2;
        x1 = std::rand();
        y1 = std::rand();
        z1 = std::rand();
        x2 = std::rand();
        y2 = std::rand();
        z2 = std::rand();
        if (x1 % 2 == 0) {
            x1 = -x1;
        }
        if (y1 % 2 == 0) {
            y1 = -y1;
        }
        if (z1 % 2 == 0) {
            z1 = -z1;
        }
        if (x2 % 2 == 0) {
            x2 = -x2;
        }
        if (y2 % 2 == 0) {
            y2 = -y2;
        }
        if (z2 % 2 == 0) {
            z2 = -z2;
        }
        Vector3D a(x1, y1, z1);
        Vector3D b(x2, y2, z2);
        os << (a - b);
        if (!os.str().compare(
                std::to_string(x1 - x2) + " " + std::to_string(y1 - y2) + " " + std::to_string(z1 - z2))) {
            std::cerr << "- test failed. Should be "
                      << std::to_string(x1 - x2) + " " + std::to_string(y1 - y2) + " " + std::to_string(z1 - z2)
                      << " yet received " << (a - b) << std::endl;
            fail = true;
        }
        os.str(std::string());

        os << a;
        if (!os.str().compare(
                std::to_string(x1) + " " + std::to_string(y1) + " " + std::to_string(z1))) {
            std::cerr << "- test failed. Should be "
                      << std::to_string(x1) + " " + std::to_string(y1) + " " + std::to_string(z1)
                      << " yet received " << a << std::endl;
            fail = true;
        }
    }

    if (!fail) {
        ++tests;
        std::cout << "Vector-Vector tests passed" << std::endl;
    }
}

void additionTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    int i;
    for (i = 0; i < 100; i++) {
        int x1, y1, z1, x2, y2, z2;
        x1 = std::rand();
        y1 = std::rand();
        z1 = std::rand();
        x2 = std::rand();
        y2 = std::rand();
        z2 = std::rand();
        if (x1 % 2 == 0) {
            x1 = -x1;
        }
        if (y1 % 2 == 0) {
            y1 = -y1;
        }
        if (z1 % 2 == 0) {
            z1 = -z1;
        }
        if (x2 % 2 == 0) {
            x2 = -x2;
        }
        if (y2 % 2 == 0) {
            y2 = -y2;
        }
        if (z2 % 2 == 0) {
            z2 = -z2;
        }
        Vector3D a(x1, y1, z1);
        Vector3D b(x2, y2, z2);
        os << (a + b);
        if (!os.str().compare(
                std::to_string(x1 + x2) + " " + std::to_string(y1 + y2) + " " + std::to_string(z1 + z2))) {
            std::cerr << "+ test failed. Should be "
                      << std::to_string(x1 + x2) + " " + std::to_string(y1 + y2) + " " + std::to_string(z1 + z2)
                      << " yet received " << (a + b) << std::endl;
            fail = true;
        }
        os.str(std::string());

        os << a;
        if (!os.str().compare(
                std::to_string(x1) + " " + std::to_string(y1) + " " + std::to_string(z1))) {
            std::cerr << "+ test failed. Should be "
                      << std::to_string(x1) + " " + std::to_string(y1) + " " + std::to_string(z1)
                      << " yet received " << a << std::endl;
            fail = true;
        }
    }

    if (!fail) {
        ++tests;
        std::cout << "Vector+Vector tests passed" << std::endl;
    }
}

void outputToStreamTest(int &tests) {
    bool fail = false;
    std::stringstream os;

    Vector3D a(1, 2, 3);
    os << a;
    if (!os.str().compare("1 2 3")) {
        std::cerr << "output to stream test failed. should be 1 2 3 yet was " << a << std::endl;
        fail = true;
    }

    if (!fail) {
        ++tests;
        std::cout << "Printing vector to stream tests passed" << std::endl;
    }
}

void readFromStreamTest(int &tests) {
    bool fail = false;
    std::stringstream os;
    os << 2.0 << " " << 3.0 << " " << 4.0;
    Vector3D a;
    os >> a;
    os.str(std::string());
    os << a;
    if (!os.str().compare("2 3 4")) {
        std::cerr << "reading doubles from stream failed. should be 2 3 4 but was " << a << std::endl;
        fail = true;
    }
    os.str(std::string());
    os << 2.1 << " " << 3.1 << " " << 4.1;
    os >> a;
    os.str(std::string());
    os << a;
    if (!os.str().compare("2.1 3.1 4.1")) {
        std::cerr << "reading doubles from stream failed. should be 2.1 3.1 4.1 but was " << a << std::endl;
        fail = true;
    }

    if (!fail) {
        ++tests;
        std::cout << "Reading vector from stream tests passed" << std::endl;
    }

}

void constructorsTest(int &tests) {
    bool fail = false;
    std::stringstream os;

    Vector3D a;
    os << a;
    if (!os.str().compare("0 0 0")) {
        std::cerr << "default constructor failed." << std::endl;
        fail = true;
    }
    os.str(std::string());
    a = Vector3D(1, 1, 1);
    os << a;
    if (!os.str().compare("1 1 1")) {
        std::cerr << "constructor from 3 integers failed." << std::endl;
        fail = true;
    }
    os.str(std::string());

    a = Vector3D(1.0, 1.5, 1.7);
    os << a;
    if (!os.str().compare("1 1.5 1.7")) {
        std::cerr << "constructor from 3 doubles failed." << std::endl;
        fail = true;
    }
    os.str(std::string());

    double arr[3] = {3.5, 2.3, 7.9};
    a = Vector3D(arr);
    os << a;
    if (!os.str().compare("3.5 2.3 7.9")) {
        std::cerr << "constructor from array failed." << std::endl;
        fail = true;
    }
    os.str(std::string());

    Vector3D b(a);
    os << b;
    if (!os.str().compare("3.5 2.3 7.9")) {
        std::cerr << "copy constructor failed." << std::endl;
        fail = true;
    }
    os.str(std::string());

    if (!fail) {
        ++tests;
        std::cout << "Constructor tests passed" << std::endl;
    }
}