#include "Matrix.h"
#include <iostream>

int main() {
    std::vector<std::vector<int>> A_vals = {
        {6, 4},
        {8, 3}
    };

    std::vector<std::vector<int>> B_vals = {
        {1, 2, 3},
        {4, 5, 6}
    };

    std::vector<std::vector<int>> C_vals = {
        {2, 4, 6},
        {1, 3, 5}
    };

    Matrix A(A_vals);
    Matrix B(B_vals);
    Matrix C(C_vals);

    Matrix CT = C.transpose();
    Matrix result = A + (B * 3) * CT;

    std::cout << "Result D = A + (3 * B) * Cᵀ:\n";
    result.print();

    return 0;
}
