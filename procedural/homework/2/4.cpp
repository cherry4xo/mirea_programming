#include <iostream>

int main(int argc, const char** argv)
{
    int n;
    std::cin >> n;

    for (size_t i = n; i < n + 10; ++i)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}