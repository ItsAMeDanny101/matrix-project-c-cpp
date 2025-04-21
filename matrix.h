#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

// Creation
Matrix createMatrix(int rows, int cols);
Matrix createFromArray(int rows, int cols, int values[rows][cols]);

// Operations
Matrix transpose(Matrix m);
Matrix scalarMultiply(Matrix m, int scalar);
Matrix multiply(Matrix a, Matrix b);
Matrix add(Matrix a, Matrix b);

// Display
void printMatrix(Matrix m);

// Cleanup
void freeMatrix(Matrix m);

#endif
