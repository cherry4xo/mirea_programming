#include <iostream>
#include <cmath>

std::pair<float, float> getCalc(float h, float r, float R)
{
    return std::make_pair<float, float>(((M_PI * h * (R * R + R * r + r * r)) / 3), 
                                         (M_PI * (R * R + (R + r) * (sqrt((R - r) * (R - r) + h * h)) + r * r)));
}

int main(int argc, char** argv)
{
    float h, r, R;
    std::cin >> h >> r >> R;

    if(R < 0 || h < 0 || r < 0)
    {
        std::cout << "Incorrect parameters\n";
        return 1;
    }

    if(R == r) 
    {
        std::cout << "Cylinder\n";
        return 1;
    }

    std::pair<float, float> ans = getCalc(h, r, R);

    std::cout << ans.first << " " << ans.second << std::endl;

    return 0;
}