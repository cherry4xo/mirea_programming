#include <iostream>
#include <math.h>

int main(int argc, const char** argv)
{
    long double ans = 0;
    long double sin_sum = 0;
    int n;
    std::cin >> n;

    for(size_t i = 1; i < n + 1; ++i)
    {
        sin_sum += std::sin(i);
        ans += i / (sin_sum);
    }

    std::cout << ans << std::endl;

    return 0;
}