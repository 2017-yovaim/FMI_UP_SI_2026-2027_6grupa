#include <iostream>
using namespace std;

unsigned int concat(unsigned int first, unsigned int second) 
{
    unsigned int multiplier = 1;
    unsigned int temp = second;

    do 
    {
        multiplier *= 10;
        temp /= 10;
    } while (temp != 0);

    return first * multiplier + second;
}

int main()
{
    std::cout << "Hello World!\n";
}

