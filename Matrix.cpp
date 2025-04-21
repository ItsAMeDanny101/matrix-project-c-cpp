#include "Matrix.h"
#include <iostream>
using namespace std;

// makes a matrix filled with zeros
Matrix::Matrix(int inputRows, int inputCols) : rows(inputRows), cols(inputCols) {
    data.resize(rows, vector<int>(cols, 0));
}

// makes a matrix from given values
Matrix::Matrix(vector<vector<int>> values) {
    data = values;
    rows = data.size();
    cols = data[0].size();
}

// returns the transpose of the matrix
Matrix Matrix::transpose() const {
    Matrix transposedMatrix(cols, rows);
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int colIndex = 0; colIndex < cols; colIndex++) {
            transposedMatrix.data[colIndex][rowIndex] = data[rowIndex][colIndex];
        }
    }
    return transposedMatrix;
}

// multiplies this matrix by another matrix
Matrix Matrix::operator*(const Matrix& otherMatrix) const {
    Matrix multipliedMatrix(rows, otherMatrix.cols);
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int colIndex = 0; colIndex < otherMatrix.cols; colIndex++) {
            for (int innerIndex = 0; innerIndex < cols; innerIndex++) {
                multipliedMatrix.data[rowIndex][colIndex] += data[rowIndex][innerIndex] * otherMatrix.data[innerIndex][colIndex];
            }
        }
    }
    return multipliedMatrix;
}

// adds this matrix with another matrix
Matrix Matrix::operator+(const Matrix& otherMatrix) const {
    Matrix sumMatrix(rows, cols);
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int colIndex = 0; colIndex < cols; colIndex++) {
            sumMatrix.data[rowIndex][colIndex] = data[rowIndex][colIndex] + otherMatrix.data[rowIndex][colIndex];
        }
    }
    return sumMatrix;
}

// multiplies this matrix by a number
Matrix Matrix::operator*(int scalar) const {
    Matrix scaledMatrix(rows, cols);
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int colIndex = 0; colIndex < cols; colIndex++) {
            scaledMatrix.data[rowIndex][colIndex] = data[rowIndex][colIndex] * scalar;
        }
    }
    return scaledMatrix;
}

// prints the matrix to the console
void Matrix::print() const {
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int colIndex = 0; colIndex < cols; colIndex++) {
            cout << data[rowIndex][colIndex] << " ";
        }
        cout << endl;
    }
}
