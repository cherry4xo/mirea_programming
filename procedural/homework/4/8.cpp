#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

std::vector<std::vector<float>> mult(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B)
{
    std::vector<std::vector<float>> C(A.size(), std::vector<float>(B[0].size()));

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
    int n;
    std::cout << "Count of sellers: ";
    std::cin >> n;
    std::vector<std::vector<float>> A(n, std::vector<float>(4));
    std::vector<std::vector<float>> B(4, std::vector<float>(2));

    std::cout << "First matrix:\n";
    for (size_t i = 0; i < A.size(); ++i)
        for (size_t j = 0; j < A[0].size(); ++j)
            std::cin >> A[i][j];
    std::cout << "Second matrix:\n";
    for (size_t i = 0; i < B.size(); ++i)
        for (size_t j = 0; j < B[0].size(); ++j)
            std::cin >> B[i][j];

    std::vector<std::vector<float>> C = mult(A, B);
    std::cout << "Multiple of matrixes:\n";
    for (size_t i = 0; i < C.size(); ++i)
    {
        for (size_t j = 0; j < C[0].size(); ++j)
            std::cout << C[i][j] << " ";
        std::cout << std::endl;
    }

    float maxSalary = std::numeric_limits<float>::min();
    int maxSalaryIndex = C.size() - 1;
    float minSalary = std::numeric_limits<float>::max();
    int minSalaryIndex = C.size() - 1;
    float maxComs = std::numeric_limits<float>::min();
    int maxComsIndex = C.size() - 1;
    float minComs = std::numeric_limits<float>::max();
    int minComsIndex = C.size() - 1;
    float summSalary = 0, summComs = 0;

    for (size_t i = 0; i < C.size(); ++i)
    {
        if (C[i][0] > maxSalary)
        {
            maxSalary = C[i][0];
            maxSalaryIndex = i;
        }
        if (C[i][0] < minSalary)
        {
            minSalary = C[i][0];
            minSalaryIndex = i;
        }

        if (C[i][1] > maxComs)
        {
            maxComs = C[i][1];
            maxComsIndex = i;
        }
        if (C[i][1] < minComs)
        {
            minComs = C[i][1];
            minComsIndex = i;
        }

        summSalary += C[i][0];
        summComs += C[i][1];
    }

    std::cout << "Max salary: " << maxSalaryIndex + 1 << std::endl
              << "Min salary: " << minSalaryIndex + 1 << std::endl
              << "Max commission: " << maxComsIndex + 1 << std::endl
              << "Min commission: " << minComsIndex + 1 << std::endl
              << "Summ of salary: " << summSalary << std::endl
              << "Summ of commission: " << summComs << std::endl
              << "Total summ: " << summSalary + summComs << std::endl; 

    return 0;
}