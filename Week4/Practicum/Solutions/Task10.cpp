#include <iostream>
using namespace std;

int absoluteValue(int num)
{
    return (num < 0) ? -num : num;
}

int getLength(int number) 
{
    number = absoluteValue(number);
    int length = 1;

    while (number >= 10) 
    {
        number /= 10;
        length++;
    }

    return length;
}

int main()
{
    std::cout << "Hello World!\n";
}

