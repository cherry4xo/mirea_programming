#include <iostream>
#include <fstream>

int main(int argc, const char** argv)
{
    std::fstream file;
    file.open("1.txt");
    for(size_t i = 0; i < 10; ++i)
    {
        float num;
        std::cin >> num;
        file << num << std::endl;
    }
    file.close();
    std::cout << std::endl;
    file.open("1.txt");
    while(!file.eof())
    {
        std::string s;
        std::getline(file, s);
        std::cout << s << std::endl;
    }
    file.close();

    return 0;
}