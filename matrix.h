#ifndef MATRIX_H
#define MATRIX_H

// this struct represents a 2d matrix with rows, cols, and data
typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

// creates an empty matrix with all zeros
Matrix createMatrix(int rows, int cols);

// creates a matrix from a 2d array
Matrix createFromArray(int rows, int cols, int values[rows][cols]);

// returns the transpose of a matrix
Matrix transpose(Matrix inputMatrix);

// multiplies every element in a matrix by a number
Matrix scalarMultiply(Matrix inputMatrix, int scalar);

// multiplies two matrices together
Matrix multiply(Matrix matrixA, Matrix matrixB);

// adds two matrices together
Matrix add(Matrix matrixA, Matrix matrixB);

// prints the matrix to the screen
void printMatrix(Matrix matrixToPrint);

// frees the memory used by a matrix
void freeMatrix(Matrix matrixToFree);

#endif
