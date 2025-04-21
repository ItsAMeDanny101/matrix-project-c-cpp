#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows, cols;

public:
    Matrix(int rows, int cols);
    Matrix(std::vector<std::vector<int>> values);

    Matrix transpose() const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(int scalar) const;

    void print() const;
};

#endif
