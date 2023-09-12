#include <iostream>
#include <cmath>

std::pair<float, float> getCalc(float h, float r, float R, float l)
{
    return std::make_pair<float, float>(((M_PI * h * (R * R + R * r + r * r)) / 3), (M_PI * (R * R + (R + r) * l + r * r)));
}

int main(int argc, char** argv)
{
    float h, r, R, l;
    std::cin >> h >> r >> R >> l;

    std::pair<float, float> ans = getCalc(h, r, R, l);

    std::cout << ans.first << " " << ans.second << std::endl;

    return 0;
}