#include <iostream>
#include <vector>

int main(int argc, const char** argv)
{
    setlocale(LC_ALL, "");

    std::vector<std::vector<float>> det(2, std::vector<float>(2));

    std::cout << "Enter the second order matrix:\n";
    for(size_t i = 0; i < det.size(); ++i)
        for(size_t j = 0; j < det[0].size(); ++j)
            std::cin >> det[i][j];

    std::cout << "Determinant of matrix equals: " << det[0][0] * det[1][1] - det[0][1] * det[1][0] << std::endl;

    return 0;
}