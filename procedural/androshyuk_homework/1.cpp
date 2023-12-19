#include <iostream>

int gcd(u_int16_t a, u_int16_t b)
{
    if (a == 0 || b == 0)
        return a + b;
    if (a > b)
        return gcd (a % b, b);
    return gcd(a, b % a);
}

int main(int argc, const char** agrv)
{
    std::cout << gcd(27, 43) << std::endl;

    return 0;
}