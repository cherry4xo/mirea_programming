#include <iostream>
#include <math.h>

void foo(float x, float y, float b)
{
    if (b - y > 0 && b - x >= 0)
        std::cout << log(b - y) * sqrt(b - x) << std::endl;
    else
        std::cout << "Incorrect parameters\n";   
}

int main(int argc, const char** argv)
{
    float x, y, b;
    std::cin >> x >> y >> b;

    foo(x, y, b);

    return 0;
}