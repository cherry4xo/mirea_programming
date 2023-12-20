#include <iostream>
#include <vector>
#include <fstream>

int main(int argc, const char** argv)
{
    std::fstream file("3_21.txt", std::ios_base::in | std::ios_base::out);

    std::vector<std::pair<char, int>> arr;

    arr.push_back(std::make_pair<char, int>('a', 0));
    arr.push_back(std::make_pair<char, int>('u', 0));
    arr.push_back(std::make_pair<char, int>('o', 0));
    arr.push_back(std::make_pair<char, int>('e', 0));
    arr.push_back(std::make_pair<char, int>('i', 0));
    arr.push_back(std::make_pair<char, int>('y', 0));

    if (!file)
        std::cout << "Error file opening\n";
    else 
    {
        char c;
        while(file.get(c))
        {
            switch(c)
            {
                case 'a':
                    ++arr[0].second;
                    break;
                case 'u':
                    ++arr[1].second;
                    break;
                case 'o':
                    ++arr[2].second;
                    break;
                case 'e':
                    ++arr[3].second;
                    break;
                case 'i':
                    ++arr[4].second;
                    break;
                case 'y':
                    ++arr[5].second;
                    break;
                case 'A':
                    ++arr[0].second;
                    break;
                case 'U':
                    ++arr[1].second;
                    break;
                case 'O':
                    ++arr[2].second;
                    break;
                case 'E':
                    ++arr[3].second;
                    break;
                case 'I':
                    ++arr[4].second;
                    break;
                case 'Y':
                    ++arr[5].second;
                    break;
                default:
                    break;
            }
        }
    }

    std::pair<char, int> max_char{'a', -1};

    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (arr[i].second > max_char.second)
        {
            max_char.first = arr[i].first;
            max_char.second = arr[i].second;
        }
    }

    std::cout << max_char.first << ": " << max_char.second << std::endl;

    return 0;
}