#include <iostream>

const double PI = 3.14;//константа

int main()
{
    double diameter;
    std::cin >> diameter;
    double radius = diameter / 2;

    double area = PI * radius * radius;
    double perimeter = 2 * PI * radius;

    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;
    return 0;
}
