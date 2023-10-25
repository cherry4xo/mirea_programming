#include <iostream>
#include <cmath>
#include <string>

bool is_int(std::string n)
{
    for (size_t i = 0; i < n.length(); ++i)
    {
        if (!isdigit(n[i]))
            return 0;
    }
    return 1;
}

int main(int argc, const char** argv)
{
    std::string n;
    std::cin >> n;

    if (!is_int(n))
    {
        std::cout << "Incorrect number\n";
        return 1;
    }

    for (size_t i = std::stoi(n); i < std::stoi(n) + 10; ++i)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}