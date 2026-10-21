#include<iostream>
using namespace std;

bool isSquareRoot(int number) 
{
    if (number < 0) return false;

    for (int i = 0; i * i <= number; i++) 
    {
        if (i * i == number)
        {
            return true;
        }
    }
    return false;
}

int main()
{

}