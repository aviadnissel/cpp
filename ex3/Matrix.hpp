#ifndef CPP_MATRIX_H
#define CPP_MATRIX_H

#include <vector>

using std::vector;

template <class T>
class Matrix {
public:
    Matrix();
    Matrix(unsigned int rows, unsigned int cols);
    Matrix(Matrix& other);
private:
    vector<vector<T>> rows;

};


#endif //CPP_MATRIX_H
