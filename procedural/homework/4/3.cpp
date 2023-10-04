#include <iostream>
#include <math.h>

float AreaTriangle(float a, float h)
{
    return 0.5 * a * h;
}

float AreaRectangle(float a, float b)
{
    return a * b;
}

float AreaCircle(float r)
{
    return M_PI * r * r;
}

int main(int argc, const char** argv)
{
    int choice;
    std::cout << "Choose one of the figures\n1.Triangle\n2.Rectangle\n3.Circle\n--> ";
    std::cin >> choice;

    switch (choice)
    {
    float a, h, b, r;
    case 1:
        std::cout << "Side--> ";
        std::cin >> a;
        if(a <= 0){
            std::cout << "Incorrect value\n";
            break;
        }
        std::cout << "High--> ";
        std::cin >> h;
        if(h <= 0){
            std::cout << "Incorrect value\n";
            break;
        }
        std::cout << "Area = " << AreaTriangle(a, h) << std::endl;
        break;
    case 2:
        std::cout << "First side--> ";
        std::cin >> a;
        if(a <= 0){
            std::cout << "Incorrect value\n";
            break;
        }
        std::cout << "Second side--> ";
        std::cin >> b;
        if(b <= 0){
            std::cout << "Incorrect value\n";
            break;
        }
        std::cout << "Area = " << AreaRectangle(a, b) << std::endl;
        break;
    case 3:
        std::cout << "Radius--> ";
        std::cin >> r;
        if(r <= 0){
            std::cout << "Incorrect value\n";
            break;
        }
        std::cout << "Area = " << AreaCircle(r) << std::endl;
        break;
    default:
        std::cout << "Incorrect number\n";
        break;
    }
    return 0;
}