#include <iostream>

#define m1 37
#define i1 3
#define c1 64
#define m2 25173
#define i2 13849
#define c2 65537

int getNextFirst(int num)
{
    return (m1 * num + i1) % c1;
}

void randomFirst(int num)
{
    num = getNextFirst(num);
    for(size_t i = 0; i < 9; ++i)
    {
        std::cout << num << " ";
        num = getNextFirst(num);
    }
    std::cout << std::endl;
}

int getNextSecond(int num)
{
    return (m2 * num + i2) % c2;
}

void randomSecond(int num)
{
    num = getNextSecond(num);
    for(size_t i = 0; i < 9; ++i)
    {
        std::cout << num << " ";
        num = getNextSecond(num);
    }
    std::cout << std::endl;
}

int main(int argc, const char** argv)
{
    randomFirst((unsigned)time(NULL));
    randomSecond((unsigned)time(NULL));

    return 0;
}