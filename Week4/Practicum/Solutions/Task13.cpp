#include <iostream>
using namespace std;

int sortDigits(unsigned int number) 
{
    int result = 0;

    for (int digit = 0; digit < 10; digit++) 
    {
        int temp = number;

        while (temp > 0) 
        {
            if (temp % 10 == digit)
            {
                result = result * 10 + digit;
            }
            temp /= 10;
        }
    }
    return result;
}

int main()
{
    std::cout << "Hello World!\n";
}

