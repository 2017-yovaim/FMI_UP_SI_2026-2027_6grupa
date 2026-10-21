#include <iostream>
using namespace std;

bool isDivisableByValue(int number, int divisor) 
{
    if (divisor == 0)
    {
        return false;
    }

    int quotient = number / divisor;
    return quotient * divisor == number;
}

int main()
{
    std::cout << "Hello World!\n";
}

