#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix createMatrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        m.data[i] = (int*)malloc(cols * sizeof(int));
    }
    return m;
}

Matrix createFromArray(int rows, int cols, int values[rows][cols]) {
    Matrix m = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            m.data[i][j] = values[i][j];
    return m;
}

Matrix transpose(Matrix m) {
    Matrix t = createMatrix(m.cols, m.rows);
    for (int i = 0; i < m.rows; i++)
        for (int j = 0; j < m.cols; j++)
            t.data[j][i] = m.data[i][j];
    return t;
}

Matrix scalarMultiply(Matrix m, int scalar) {
    Matrix result = createMatrix(m.rows, m.cols);
    for (int i = 0; i < m.rows; i++)
        for (int j = 0; j < m.cols; j++)
            result.data[i][j] = m.data[i][j] * scalar;
    return result;
}

Matrix multiply(Matrix a, Matrix b) {
    Matrix result = createMatrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

Matrix add(Matrix a, Matrix b) {
    Matrix result = createMatrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < a.cols; j++)
            result.data[i][j] = a.data[i][j] + b.data[i][j];
    return result;
}

void printMatrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++)
            printf("%d ", m.data[i][j]);
        printf("\n");
    }
}

void freeMatrix(Matrix m) {
    for (int i = 0; i < m.rows; i++)
        free(m.data[i]);
    free(m.data);
}
