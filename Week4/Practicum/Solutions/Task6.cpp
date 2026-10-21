#include <iostream>
using namespace std;

long long power(int base, unsigned int exponent) 
{
    long long result = 1;
    for (unsigned int i = 0; i < exponent; i++)
    {
        result *= base;
    }

    return result;
}

int main()
{
    std::cout << "Hello World!\n";
}

