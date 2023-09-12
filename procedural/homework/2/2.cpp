#include <iostream>
#include <cmath>

float getAns(float a, float x)
{
    float ans = NULL;

    if (std::abs(x) < 1)
    {
        if (x == 0) return ans;
        return a * std::log(std::abs(x));
    }
    else
    {
        if (a - x * x < 0) return ans;
        return sqrt(a - x * x);
    }
}

int main(int argc, char** argv)
{
    float a, x;

    std::cin >> a >> x;

    std::cout << getAns(a, x) << std::endl;

    return 0;
}