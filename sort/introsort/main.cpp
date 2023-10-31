#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
 
// Функция для выполнения сортировки вставками в подмассиве `a[low…high]`
void insertionsort(char a[], int low, int high)
{
    // начинаем со второго элемента подмассива
    // (элемент с индексом `low` уже отсортирован)
    for (int i = low + 1; i <= high; i++)
    {
        int value = a[i];
        int j = i;
 
        // найти индекс `j` в отсортированном подмножестве a[0…i-1]
        // где находится элемент a[i]
        while (j > low && a[j - 1] > value)
        {
            a[j] = a[j - 1];
            j--;
        }
 
        // Обратите внимание, что подмассив `a[j…i-1]` сдвинут на
        // вправо на одну позицию, т.е. `a[j+1…i]`
 
        a[j] = value;
    }
}
 
// Функция для разбиения массива по схеме разбиения Lomuto
int partition(char a[], int low, int high)
{
    // Выбираем крайний правый элемент в качестве опорного элемента массива
    int pivot = a[high];
 
    // элементы, меньшие точки поворота, будут перемещены влево от `pIndex`
    // элементы больше, чем точка поворота, будут сдвинуты вправо от `pIndex`
    // равные элементы могут идти в любом направлении
    int pIndex = low;
 
    // каждый раз, когда мы находим элемент, меньший или равный опорному, `pIndex`
    // увеличивается, и этот элемент будет помещен перед опорной точкой.
    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
 
    // поменять местами `pIndex` с пивотом
    swap (a[pIndex], a[high]);
 
    // вернуть `pIndex` (индекс опорного элемента)
    return pIndex;
}
 
// Быстрая сортировка рандомизированного раздела для перестановки элементов по оси
int randPartition(char a[], int low, int high)
{
    // выбираем случайный индекс между `[low, high]`
    int pivotIndex = rand() % (high - low + 1) + low;
 
    // поменять местами конечный элемент с элементом, имеющим случайный индекс
    swap(a[pivotIndex], a[high]);
 
    // вызов процедуры разделения
    return partition(a, low, high);
}
 
// Функция для выполнения пирамидальной сортировки заданного диапазона элементов
void heapsort(char *begin, char *end)
{
    make_heap(begin, end);
    sort_heap(begin, end);
}
 
// Функция для выполнения начальной сортировки заданного массива
void introsort(char a[], char *begin, char *end, int maxdepth)
{
    // выполняем сортировку вставками, если размер раздела 16 или меньше
    if ((end - begin) < 16) {
        insertionsort(a, begin - a, end - a);
    }
    // выполнить пирамидальную сортировку, если максимальная глубина равна 0
    else if (maxdepth == 0) {
        heapsort(begin, end + 1);
    }
    else {
        // иначе выполняем быструю сортировку
        int pivot = randPartition(a, begin - a, end - a);
        introsort(a, begin, a + pivot - 1, maxdepth - 1);
        introsort(a, a + pivot + 1, end, maxdepth - 1);
    }
}
 
int main()
{
    char a[] = { 'f', '1', 'o', 'a', 'w', 'b', 'd', 'q', '7', '3', 'n', 'm', 'z', 'x', 'c'};
    int n = sizeof(a) / sizeof(a[0]);
 
    // получаем максимальную глубину
    int maxdepth = log(n) * 2;
 
    // сортируем массив, используя алгоритм introsort
    introsort(a, a, a + n - 1, maxdepth);
 
    // печатаем отсортированный массив
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
 
    return 0;
}