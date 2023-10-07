#include <cstddef>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
 
static const char *k_base_symbols = "0123456789ABCDEFGHIJKLMNOPQRASUVWXYZ";
 
bool IsLegalNumber(const char *string, size_t base, const char *base_symbols) 
{
    const char *symbol = string;
    while (*symbol != '\0') 
    {
        const char *position = strchr(base_symbols, *symbol);
        if (position == NULL || position - base_symbols + 1 > base)
            return false;
        ++symbol;
    }
    return true;
}
 
size_t FromBase(const char *string, size_t base, const char *base_symbols = k_base_symbols) 
{
    size_t result = 0;
    size_t string_length = strlen(string);
    assert(base <= strlen(base_symbols));
    assert(IsLegalNumber(string, base, base_symbols));
    for (int i = string_length - 1, counter = 0; i >= 0; --i, ++counter) 
    {
        size_t digit = strchr(base_symbols, string[i]) - base_symbols;
        result += digit * pow(base, counter);
    }
    return result;
}
 
char *ToBase(char *buffer, size_t number, size_t base, const char *base_symbols = k_base_symbols) 
{
    size_t a_number = number;
    char *symbol = buffer;
    int string_size = 0;
    do
    {
        *symbol = base_symbols[a_number % base];
        a_number /= base;
        ++symbol;
        ++string_size;
    } while (a_number !=0);
    *symbol = '\0';
    
    for (int i = 0; i < string_size / 2; ++i) 
    {
        char temporary = buffer[i];
        buffer[i] = buffer[string_size - i - 1];
        buffer[string_size - i - 1] = temporary;
    }
 
    return buffer;
}

char* AnyToAny(char* buffer, size_t number, size_t base_from, size_t base_to, const char* base_symbols = k_base_symbols)
{
    if (IsLegalNumber())
}
 
int main(int argc, char **argv) {
  size_t k_buffer_size = 2048;
  char buffer[k_buffer_size];
 
 
  printf("Hexademical FFFF in dec is %d\n", FromBase("FFFF", 16));
  printf("8 in base 4 = %s\n", ToBase(buffer, 8, 4));
  return 0;
}