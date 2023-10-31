#include <iostream>
#include <algorithm>

bool perestanovka(int* urna, int n) 
{
    for (int i = 0; i < n; ++i)
    {
        if (urna[i] == i)
        {
            return true;
        }
    }
    return false;
}

int main() 
{
    int ans = 0, n = 10, fac = 3628800;
    int urna[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < fac; ++i) 
    {
        std::next_permutation(urna, urna + n);
        if (perestanovka(urna,n))
            ans++;
    }
    std::cout << ans << std::endl;

    return 0;
}