#include <iostream>
using namespace std;

int absoluteValue(int num)
{
    return (num < 0) ? -num : num;
}

int gcd(int first, int second) 
{
    first = absoluteValue(first);
    second = absoluteValue(second);

    while (second != 0) 
    {
        int remainder = first % second;
        first = second;
        second = remainder;
    }
    return first;
}

int main()
{
    std::cout << "Hello World!\n";
}

