#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

// this class represents a 2d matrix
class Matrix {
private:
    vector<vector<int>> data;
    int rows, cols;

public:
    // creates a matrix with zero values
    Matrix(int inputRows, int inputCols);

    // creates a matrix from given values
    Matrix(vector<vector<int>> values);

    // returns the transpose of the matrix
    Matrix transpose() const;

    // multiplies this matrix with another matrix
    Matrix operator*(const Matrix& otherMatrix) const;

    // adds this matrix to another matrix
    Matrix operator+(const Matrix& otherMatrix) const;

    // multiplies this matrix with a number
    Matrix operator*(int scalar) const;

    // prints the matrix to the screen
    void print() const;
};

#endif
