#include <iostream>

int main()
{
    int number;
    std::cin >> number;

    int digit1 = number % 10;
    int digit2 = number / 10 % 10;
    int digit3 = number / 100;
    int sum = digit1 + digit2 + digit3;

    std::cout << sum << std::endl;
    return 0;
}
