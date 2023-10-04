#include <iostream>

void bubbleSort(char arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main(int argc, const char** argv)
{
    char str[31] = "whfdslsubotaorulbywgzpduqibnmf";
    bubbleSort(str, 30);
    for(size_t i = 0; i < 31; ++i)
        std::cout << str[i] << " ";
    std::cout << std::endl;

    return 0;
}