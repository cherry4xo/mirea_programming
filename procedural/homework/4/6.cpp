#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <numeric>

void romanToIntFirst(std::string roman)
{
    std::string buff = "";
    for (auto i : roman)
        buff = buff + char(std::toupper(i));
    std::map<char, int> nums{{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};

    std::vector<int> values;

    for (auto i : roman)
    {
        if (nums.find(i) == nums.end())
            std::cout << "Invalid symbol <" << i << ">\n"; 
    }

    for (size_t i = 0; i < roman.length(); ++i)
    {
        int value = nums[roman[i]];
        try
        {
            int nextValue = nums[roman[i + 1]];
            if (nextValue > value)
                value *= -1;
        }
        catch (std::out_of_range) {}

        values.push_back(value); 
    }

    int sum = 0;
    sum = std::accumulate(values.begin(), values.end(), 0);

    std::cout << sum << std::endl;
}

void romanToIntSecond(std::string roman)
{
    std::string buff = "";
    for (auto i : roman)
        buff = buff + char(std::toupper(i));

    std::vector<std::pair<std::string, std::pair<int, int>>> nums{{"M", std::make_pair<int, int>(1000, 3)}, {"CM", std::make_pair<int, int>(900, 1)},
                                                                  {"D", std::make_pair<int, int>(500, 1)}, {"CD", std::make_pair<int, int>(400, 1)},
                                                                  {"C", std::make_pair<int, int>(100, 3)}, {"XC", std::make_pair<int, int>(90, 1)},
                                                                  {"L", std::make_pair<int, int>(50, 1)}, {"XL", std::make_pair<int, int>(40, 1)},
                                                                  {"X", std::make_pair<int, int>(10, 3)}, {"IX", std::make_pair<int, int>(9, 1)},
                                                                  {"V", std::make_pair<int, int>(5, 1)}, {"IV", std::make_pair<int, int>(4, 1)}, 
                                                                  {"I", std::make_pair<int, int>(1, 3)}};
    int result = 0, index = 0;
    for (auto i : nums)
    {
        int count = 0;
        while(roman.substr(index, i.first.length()) == i.first)
        {
            ++count;
            if (count > i.second.second)
                throw std::invalid_argument("Invalid symbol found of count\n");
            result += i.second.first;
            index += i.first.length();
        }
    }
    if (index < roman.size())
        throw std::invalid_argument("Invalid symbol found of length\n");
    else
        std::cout << result << std::endl;
}

int main(int argc, const char** argv)
{
    std::string roman;
    std::cin >> roman;

    // romanToIntFirst(roman);
    romanToIntSecond(roman);

    return 0;
}