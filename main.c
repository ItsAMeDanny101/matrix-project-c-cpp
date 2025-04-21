#include <stdio.h>
#include "matrix.h"

int main() {
    int A_vals[2][2] = {
        {6, 4},
        {8, 3}
    };

    int B_vals[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int C_vals[2][3] = {
        {2, 4, 6},
        {1, 3, 5}
    };

    Matrix A = createFromArray(2, 2, A_vals);
    Matrix B = createFromArray(2, 3, B_vals);
    Matrix C = createFromArray(2, 3, C_vals);

    Matrix CT = transpose(C);
    Matrix B3 = scalarMultiply(B, 3);
    Matrix prod = multiply(B3, CT);
    Matrix D = add(A, prod);

    printf("Result D = A + (3 * B) * Cᵀ:\n");
    printMatrix(D);

    // Clean up memory
    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);
    freeMatrix(CT);
    freeMatrix(B3);
    freeMatrix(prod);
    freeMatrix(D);

    return 0;
}
