#include <iostream>
#include <string>
#include <fstream>

const char replace_char = '_';

int main(int argc, const char** argv)
{
    std::fstream file("3_1.txt", std::ios_base::in | std::ios_base::out);

    if(!file)
        std::cout << "Error file opening\n";
    else
    {
        char c;
        std::streampos pos = file.tellg();
        while(file.get(c))
        {
            file.seekp(pos);
            if (c == ' ')
                c = replace_char;

            file << c;
            pos = file.tellg();
        }
    }

    return 0;
}