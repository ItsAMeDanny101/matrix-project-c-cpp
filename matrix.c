#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// creates an empty matrix with all zeros
Matrix createMatrix(int rows, int cols) {
    Matrix newMatrix;
    newMatrix.rows = rows;
    newMatrix.cols = cols;
    newMatrix.data = (int**)malloc(rows * sizeof(int*));
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        newMatrix.data[rowIndex] = (int*)malloc(cols * sizeof(int));
    }
    return newMatrix;
}

// creates a matrix from a 2d array
Matrix createFromArray(int rows, int cols, int values[rows][cols]) {
    Matrix newMatrix = createMatrix(rows, cols);
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int colIndex = 0; colIndex < cols; colIndex++) {
            newMatrix.data[rowIndex][colIndex] = values[rowIndex][colIndex];
        }
    }
    return newMatrix;
}

// returns the transpose of a matrix
Matrix transpose(Matrix inputMatrix) {
    Matrix transposedMatrix = createMatrix(inputMatrix.cols, inputMatrix.rows);
    for (int rowIndex = 0; rowIndex < inputMatrix.rows; rowIndex++) {
        for (int colIndex = 0; colIndex < inputMatrix.cols; colIndex++) {
            transposedMatrix.data[colIndex][rowIndex] = inputMatrix.data[rowIndex][colIndex];
        }
    }
    return transposedMatrix;
}

// multiplies every element in a matrix by a number
Matrix scalarMultiply(Matrix inputMatrix, int scalar) {
    Matrix scaledMatrix = createMatrix(inputMatrix.rows, inputMatrix.cols);
    for (int rowIndex = 0; rowIndex < inputMatrix.rows; rowIndex++) {
        for (int colIndex = 0; colIndex < inputMatrix.cols; colIndex++) {
            scaledMatrix.data[rowIndex][colIndex] = inputMatrix.data[rowIndex][colIndex] * scalar;
        }
    }
    return scaledMatrix;
}

// multiplies two matrices together
Matrix multiply(Matrix matrixA, Matrix matrixB) {
    Matrix resultMatrix = createMatrix(matrixA.rows, matrixB.cols);
    for (int rowIndex = 0; rowIndex < matrixA.rows; rowIndex++) {
        for (int colIndex = 0; colIndex < matrixB.cols; colIndex++) {
            resultMatrix.data[rowIndex][colIndex] = 0;
            for (int k = 0; k < matrixA.cols; k++) {
                resultMatrix.data[rowIndex][colIndex] += matrixA.data[rowIndex][k] * matrixB.data[k][colIndex];
            }
        }
    }
    return resultMatrix;
}

// adds two matrices together
Matrix add(Matrix matrixA, Matrix matrixB) {
    Matrix sumMatrix = createMatrix(matrixA.rows, matrixA.cols);
    for (int rowIndex = 0; rowIndex < matrixA.rows; rowIndex++) {
        for (int colIndex = 0; colIndex < matrixA.cols; colIndex++) {
            sumMatrix.data[rowIndex][colIndex] = matrixA.data[rowIndex][colIndex] + matrixB.data[rowIndex][colIndex];
        }
    }
    return sumMatrix;
}

// prints the matrix to the screen
void printMatrix(Matrix matrixToPrint) {
    for (int rowIndex = 0; rowIndex < matrixToPrint.rows; rowIndex++) {
        for (int colIndex = 0; colIndex < matrixToPrint.cols; colIndex++) {
            printf("%d ", matrixToPrint.data[rowIndex][colIndex]);
        }
        printf("\n");
    }
}

// frees the memory used by a matrix
void freeMatrix(Matrix matrixToFree) {
    for (int rowIndex = 0; rowIndex < matrixToFree.rows; rowIndex++) {
        free(matrixToFree.data[rowIndex]);
    }
    free(matrixToFree.data);
}
