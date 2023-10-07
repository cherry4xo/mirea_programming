#include <iostream>
#include <string>

std::string getAsciiByChar(char c)
{
    return std::to_string(static_cast<u_int32_t>(c));
}

std::string getAsciiLine(std::string s)
{
    std::string ans = "";
    for (auto i : s)
        ans += getAsciiByChar(i) + " ";
    return ans;
}

int main(int argc, const char** argv)
{
    freopen("3.txt", "r", stdin);
    freopen("3out.txt", "w", stdout);

    std::string ans = "";
    while(!feof(stdin))
    {
        std::string tmp;
        std::getline(std::cin, tmp);
        ans = ans + getAsciiLine(tmp);
    }

    std::cout << ans << std::endl;

    return 0;
}