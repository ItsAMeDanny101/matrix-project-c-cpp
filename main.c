#include <stdio.h>
#include "matrix.h"

int main() {
    // values for matrix A (2x2)
    int matrixAValues[2][2] = {
        {6, 4},
        {8, 3}
    };

    // values for matrix B (2x3)
    int matrixBValues[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // values for matrix C (2x3)
    int matrixCValues[2][3] = {
        {2, 4, 6},
        {1, 3, 5}
    };

    Matrix matrixA = createFromArray(2, 2, matrixAValues);
    Matrix matrixB = createFromArray(2, 3, matrixBValues);
    Matrix matrixC = createFromArray(2, 3, matrixCValues);

    Matrix matrixCTranspose = transpose(matrixC);
    Matrix matrixBScaled = scalarMultiply(matrixB, 3);
    Matrix matrixProduct = multiply(matrixBScaled, matrixCTranspose);
    Matrix matrixD = add(matrixA, matrixProduct);

    printf("Result D = A + (3 * B) * Cᵀ:\n");
    printMatrix(matrixD);

    // free all matrix memory
    freeMatrix(matrixA);
    freeMatrix(matrixB);
    freeMatrix(matrixC);
    freeMatrix(matrixCTranspose);
    freeMatrix(matrixBScaled);
    freeMatrix(matrixProduct);
    freeMatrix(matrixD);

    return 0;
}
