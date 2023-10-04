#include <iostream>

int foo(float a)
{
    if(a > 0)
        return 1;
    if (a < 0)
        return -1;
    return 0; 
}

int main(int argc, const char** argv)
{
    int a;
    std::cin >> a;
    std::cout << foo(a) << std::endl;

    return 0;
}