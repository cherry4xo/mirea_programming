#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct toy
{
    std::string title;
    int price;
    int age_from;
    int age_to;
};

std::vector<std::string> split(const std::string& str, const std::string& delim)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

int main(int argc, const char** argv)
{
    std::vector<toy> toys;

    std::fstream file("5_1.txt", std::ios_base::in | std::ios_base::out);

    if(!file)
        std::cout << "Error file opening\n";
    else
    {
        while(!file.eof())
        {
            std::string tmp;
            std::getline(file, tmp);

            std::vector<std::string> toy_data = split(tmp, " ");

            toy new_toy {toy_data[0], std::stoi(toy_data[1]), std::stoi(toy_data[2]), std::stoi(toy_data[3])};

            toys.push_back(new_toy);
        }
    }


    std::cout << "price <400 rub:\n";
    for(size_t i = 0; i < toys.size(); ++i)
    {
        if (toys[i].price < 400)
            std::cout << " - " << toys[i].title << std::endl;
    }

    int price_max = -1;
    for(size_t i = 0; i < toys.size(); ++i)
    {
        if (toys[i].price > price_max)
            price_max = toys[i].price;
    }
    std::cout << "max price: " << price_max << std::endl;

    std::cout << "fit to 4 y.o. and 10 y.o.:\n";
    for(size_t i = 0; i < toys.size(); ++i)
    {
        if (toys[i].age_from <= 4 && toys[i].age_to >= 10)
            std::cout << " - " << toys[i].title << std::endl;
    }
    

    return 0;
}