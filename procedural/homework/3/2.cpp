#include <iostream>
#include <math.h>

double foo(double S, double m, double n) {
    double r;
    double x1 = S * r * pow(1 + r, n);
    double x2 = 12 * (pow(1 + r, n) - 1);
    
    if (x2 == 0) {
        return -1;
    } else {
        return x1 / x2;
    }
}

int main(int argc, const char** argv)
{
    float s, p, n;
    std::cin >> s >> p >> n;
    std::cout << foo(s, p, n);

    return 0;
}