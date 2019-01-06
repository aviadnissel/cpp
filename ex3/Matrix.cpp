#include "Matrix.hpp"

template <class T>
Matrix<T>::Matrix()
{
    vector<T> row;
    row.push_back(T(0));
    rows.push_back(row);
}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols)
{
    for(int i = 0; i < rows; i++)
    {
        vector<T> row;
        for(int j = 0; j < cols; j++)
        {
            row.push_back(T(0));
        }
        this->rows.push_back(row);
    }
}

template <class T>
Matrix<T>::Matrix(Matrix &other)
{
    // TODO implement
}