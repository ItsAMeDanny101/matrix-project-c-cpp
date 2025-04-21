#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    // define matrix A (2x2)
    vector<vector<int>> matrixAValues = {
        {6, 4},
        {8, 3}
    };

    // define matrix B (2x3)
    vector<vector<int>> matrixBValues = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // define matrix C (2x3)
    vector<vector<int>> matrixCValues = {
        {2, 4, 6},
        {1, 3, 5}
    };

    Matrix matrixA(matrixAValues);
    Matrix matrixB(matrixBValues);
    Matrix matrixC(matrixCValues);

    Matrix matrixCTranspose = matrixC.transpose();
    Matrix matrixBScaled = matrixB * 3;
    Matrix matrixProduct = matrixBScaled * matrixCTranspose;
    Matrix matrixD = matrixA + matrixProduct;

    cout << "Result D = A + (3 * B) * Cᵀ:" << endl;
    matrixD.print();

    return 0;
}
