#include <iostream>
#include <vector>
#include <cstdlib>

typedef std::vector<std::vector<float>> matrix;

void printMatrix(matrix& matrix)
{
    for(size_t i = 0; i < matrix.size(); ++i)
    {
        for(size_t j = 0; j < matrix[0].size(); ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }   
}

void initE(matrix& matrix)
{
    for(size_t i = 0; i < matrix.size(); ++i)
        for(size_t j = 0; j < matrix[0].size(); ++j)
        {
            if (i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
}

void initC(matrix& matrix)
{
    for(size_t i = 0; i < matrix.size(); ++i)
        for(size_t j = 0; j < matrix[0].size(); ++j)
            matrix[i][j] = static_cast<float>(1) / (static_cast<float>(i) + static_cast<float>(j) + 2);
}

matrix subMatrix(matrix A, matrix B)
{
    if(!(A.size() == B.size() && A[0].size() == B[0].size()))
        throw std::length_error("Different sizes of matrixes\n");

    matrix C(A.size(), std::vector<float>(A[0].size()));
    for(size_t i = 0; i < A.size(); ++i)
        for(size_t j = 0; j < A[0].size(); ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

matrix sumMatrix(matrix A, matrix B)
{
    if(!(A.size() == B.size() && A[0].size() == B[0].size()))
        throw std::length_error("Different sizes of matrixes\n");

    matrix C(A.size(), std::vector<float>(A[0].size()));
    for(size_t i = 0; i < A.size(); ++i)
        for(size_t j = 0; j < A[0].size(); ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

void initAB(matrix& matrix)
{
    for(size_t i = 0; i < matrix.size(); ++i)
        for(size_t j = 0; j < matrix[0].size(); ++j)
            std::cin >> matrix[i][j];
}

matrix multMatrix(matrix A, matrix B)
{
    matrix C(A.size(), std::vector<float>(B[0].size()));

    for (size_t i = 0; i < A.size(); ++i)
        for (size_t j = 0; j < B[0].size(); ++j)
        {
            C[i][j] = 0;
            for (size_t k = 0; k < A[0].size(); ++k)
                C[i][j] += A[i][k] * B[k][j];
        }

    return C;
}

int main(int argc, const char** argv)
{
    u_int16_t n;
    std::cout << "Enter N value(size of matrix NxN): ";
    std::cin >> n;
    std::cout << std::endl;

    matrix A(n, std::vector<float>(n));
    matrix B(n, std::vector<float>(n));
    matrix E(n, std::vector<float>(n));
    matrix C(n, std::vector<float>(n));

    initE(E);
    initC(C);

    std::cout << "Enter the A matrix:\n";
    initAB(A);
    std::cout << "\nEnter the B matrix:\n";
    initAB(B);

    matrix BE = subMatrix(B, E);
    std::cout << "\nB - E matrix:\n";
    printMatrix(BE);
    matrix ABE = multMatrix(A, BE);
    std::cout << "\nA(B - E) matrix:\n";
    printMatrix(ABE);
    matrix ABEC = sumMatrix(ABE, C);
    std::cout << "\nA(B - E) + C matrix:\n";
    printMatrix(ABEC);

    return 0;
}