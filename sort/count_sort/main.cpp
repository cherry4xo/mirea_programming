#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
void countSort(vector<char> &input)
{
    // создаем пустую карту для хранения частот элементов массива
    map<int, char> freq;
 
    // сохраняем различные значения во входном массиве как ключ и
    // их соответствующие счетчики как значения
    for (int x: input) {
        freq[x]++;
    }
 
    // обход карты и перезапись входного массива отсортированными элементами
    // (карта будет повторяться на основе отсортированного порядка ключей)
    int i = 0;
    for (auto &p: freq)
    {
        while (p.second--) {
            input[i++] = p.first;
        }
    }
}
 
int main()
{
    vector<char> input = { 'a', 't', '2', 'c', 'o', 'r', 'e', '8', '3', 'b' };
 
    countSort(input);
 
    for (char i: input) {
        cout << i;
    }
    cout << endl;
 
    return 0;
}