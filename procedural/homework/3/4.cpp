#include <iostream>
#include <string>

std::string printNums(std::string s)
{
    std::string ans = "";
    for(size_t i = 0; i < s.size(); ++ i)
    {
        if (std::isdigit(s[i]) || (s[i] == '.' && std::isdigit(s[i - 1]) && std::isdigit(s[i + 1])))
            ans = ans + s[i];
        else if (!std::isdigit(s[i]) && ans[ans.length() - 1] != ' ')
            ans = ans + ' ';
    }
    return ans;
}

int main(int argc, const char** agrv)
{
    freopen("4.txt", "r", stdin);

    std::string x;
    while(!feof(stdin))
    {
        std::getline(std::cin, x);
        std::cout << printNums(x) << " ";
    }
    std::cout << std::endl;

    return 0;
}