#include <iostream>
#include <math.h>

float foo(float x)
{
    if (x == 1)
        return std::nan("1");
    return (x * x - 2 * x + 2) / (x - 1);
}

int main(int argc, const char** argv)
{
    for(float i = -4; i <= 4; i += 0.5)
        std::cout << i << "\t" << foo(i) << std::endl; 

    return 0;
}