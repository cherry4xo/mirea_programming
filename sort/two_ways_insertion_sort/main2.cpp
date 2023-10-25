#include <iostream>
#include <sys/types.h>
#include <random>

void setArr(int arr[], int n)
{
    // заполнение массива
    for (size_t i = 0; i < n; ++i)
        arr[i] = rand() % n + 1;
}

void getArr(int arr[], int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        std::cout << "[" << i << "]: " << arr[i] << std::endl;
    }
}

#define n 10

int main(int argc, const char** argv)
{
    int arr[n];
    setArr(arr, n);
    getArr(arr, n);

    int right, left, m;
    int mid = n / 2;
    int *tmpArr = new int[n];

    tmpArr[mid] = arr[0];
    left = mid;
    right = mid;
    m = mid;

    for(size_t i = 1; i < n; ++i)
    {
        if(arr[i] > tmpArr[m])
        {
            m = (left + right + 1) / 2;
            if (right == n - 1)
            {
                left = left - (m - mid);
                right = right - (m - mid);
                m = mid;
            }
            right = right + 1;
            tmpArr[right] = arr[i];
        }
        else
        {
            m = (right + left - 1) / 2;
            if (left == 0) 
            {
                left = left + (mid - m);
                right = right + (mid - m);
                m = mid;
            }
            left = left - 1;
            tmpArr[left] = arr[i];
        }
    }

    std::cout << "\n\n";

    for (size_t i = 0; i < n; ++i)
    {
        std::cout << "[" << i << "]: " << tmpArr[i] << std::endl;
    }

    // getArr(arr, n);

    return 0;
}