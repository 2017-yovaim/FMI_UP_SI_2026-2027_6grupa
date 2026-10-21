#include <iostream>
using namespace std;

bool isDigit(char symbol) 
{
    return symbol >= '0' && symbol <= '9';
}


int main()
{
    cout << isDigit('5') << endl;
    return 0;
}
