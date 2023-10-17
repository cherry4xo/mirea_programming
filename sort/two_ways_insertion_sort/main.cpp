#include <iostream>
#include <string.h>

void Tinsert(int* a, int n)
{
    int* x, i, j, left = n - 1, right = n - 1, t;
    x = (int*) malloc((2 * n - 1) * sizeof(int));
    x[n - 1] = a[0];
    for(i = 1; i < n; ++i)
    {
        t = a[i];
        if(t >= a[0])
        {
            for(j = right; j >= 0 && t < x[j]; --j)
                x[j + 1] = x[j];
            x[j + 1] = t;
            ++right;
        }
        else
        {
            for(j = left; j <= 2 * n - 1 && t > x[j]; ++j)
                x[j - 1] = x[j];
            x[j - 1] = t;
            --left;
        }
    }
    for(j = left; j < left + n; ++j)
        a[j - left] = x[j];
    free(x);
}

int main(int argc, const char** argv)
{
    int a[10] = {321, -421, 54, -12, 0, -5, 320, -32, 10, 1};
    Tinsert(a, 10);

    for(size_t i = 0; i < 10; ++i)
        std::cout << *(a + i) << " ";
    std::cout << std::endl;

    return 0;
}