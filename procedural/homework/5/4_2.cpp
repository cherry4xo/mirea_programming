#include <iostream>
#include <vector>

int main(int argc, const char** argv)
{  
    u_int64_t n;
    double a;

    std::cin >> n >> a;

    std::vector<double> mult(n + 1);
    std::vector<double> ans(n + 1);

    mult[0] = a;
    ans[0] = 1 / a;

    for(size_t i = 1; i < n; ++i)
    {
        mult[i] = mult[i - 1] * (a + i);
        ans[i] = ans[i - 1] + (i + 1) / mult[i];
    }

    std::cout << ans[n - 1] << std::endl;

    return 0;
}