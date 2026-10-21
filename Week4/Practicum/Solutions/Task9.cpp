#include <iostream>
using namespace std;

bool isPrime(unsigned int number) 
{
    if (number < 2) return false;
    for (int i = 2; i * i <= number; i++) 
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::cout << "Hello World!\n";
}

