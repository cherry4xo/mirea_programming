#include <iostream>
#include <math.h>
#include <string.h>

long long int convertToDec(char n1[], int b1){

    int j = strlen(n1) - 1, k = 0;

    long long int n = 0;

    while(j >= 0){
        int i = (int) n1[j--];
        if(i >= 48 && i <= 57)
            i -= 48;
        else if(i >= 65 && i <= 90)
            i -= 55;
        else if(i >= 97 && i <= 122)
            i -= 61;
        else if(i == 43 || i == 44)
            i += 19;       
        n = n + (i * pow(b1, k++));
    }
    return n;
}

void func(long long int n2, int b2){
    if(n2 > 0){
        func(n2 / b2, b2);
        int i = n2 % b2;
        if(i >= 0 && i <= 9)
            i += 48;
        else if(i >= 10 && i <= 35)
            i += 55;
        else if(i >= 36 && i <= 61)
            i+=61;      
        else if(i == '+' || i == '/')
            i-=19;
        std::cout << (char)i;
    }
}
void convertToBase(char n1[], int b1, int b2){

    long long int n2 = convertToDec(n1, b1);

    if(n2 == 0)
        std::cout << 0;

    func(n2, b2);
}

int main(int i = 1){

    if(!i)
        return 0;

    char n1[100];
    int b1, b2;

    std::cout << "Input string: ";
    std::cin >> n1;
    std::cout << "Base: ";
    std::cin >> b1;
    std::cout << "Desired base: ";
    std::cin >> b2;

    std::cout << "Output: ";
    convertToBase(n1,b1,b2);

    std::cout << "\n\nEnter 0 to exit, 1 to continue ";
    std::cin >> i;
    std::cout << std::endl;

    main(i);
}