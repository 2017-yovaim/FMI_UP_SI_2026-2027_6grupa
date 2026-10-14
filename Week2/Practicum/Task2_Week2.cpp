#include <iostream>

int main()
{
    int number1;
    int number2;
    std::cin >> number1 >> number2;

    int digitsFirst = number1 % 100;
    int digitsSecond = number2 % 100;

    std::cout << digitsFirst << digitsSecond << std::endl;
    return 0;
}

