#include <iostream>

int main(int argc, const char** argv)
{   
    freopen("3.txt", "r", stdin);
    
    std::string x;
    while(!feof(stdin)){
        std::getline(std::cin, x);
        std::cout << x << std::endl;
    }

    return 0;
}