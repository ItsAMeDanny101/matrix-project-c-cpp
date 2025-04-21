# Matrix Project – C & C++

## AUTHORING
- Daniel Jalali, UMBC/CMSC313, 04/19 to 20/2025

## PURPOSE OF SOFTWARE
This project implements a basic matrix library in both C and C++.
It demonstrates scalar multiplication, addition, matrix multiplication, and transposition.
The main test case computes the following expression from the hoemwork we had being: 
D = A + (3 * B) × Cᵀ

## FILES

# C Implementation 
- `c/matrix.h` – the header file for C matrix functions
- `c/matrix.c` – Implementation of C matrix functions
- `c/main.c` – this tests the driver for C version

# C++ Implementation
- `cpp/Matrix.h` – the matric header class definition C++
- `cpp/Matrix.cpp` – Implementation of Matrix class methods
- `cpp/main.cpp` – this tests the driver for C++ version

## BUILD INSTRUCTIONS

Compile C++ version:
g++ -o matrix_cpp cpp/Matrix.cpp cpp/main.cpp

but in VSCode i used Run Matrix C++ Executable

Compile C version:
gcc -o matrix_c c/matrix.c c/main.c

but in vs code i did Run Matrix C Executable

## TESTING METHODOLOGY
Tested using provided matrices:

A = [6 4] [8 3]

B = [1 2 3] [4 5 6]

C = [2 4 6] [1 3 5]

the expression that was evaluated was `D = A + (3 * B) × C`
and it would print in the program: 90  70
                                   200 150



## ADDITIONAL INFORMATION
This was submitted 24 hours late with the professor being notified because of illness 


