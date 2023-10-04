#include <iostream>

int main(int argc, const char** argv)
{
    for(size_t i = 0; i < 13; ++i)
    {
        for(size_t j = 0; j < 30; ++j)
        {
            if (i < 6 && j < 8)
                std::cout << "* ";
            else if (j < 8)
                std::cout << "__";
            else
                std::cout << "_";
        }
        std::cout << std::endl;
    }

    return 0;
}