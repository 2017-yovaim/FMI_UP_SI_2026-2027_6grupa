#include <iostream>
using namespace std;

bool isUpper(char s) 
{
    return s >= 'A' && s <= 'Z';
}

bool isLower(char s) 
{
    return s >= 'a' && s <= 'z';
}

char toUpper(char symbol) 
{
    if (isLower(symbol)) return symbol - ('a' - 'A');
    return symbol;
}

char toLower(char symbol) 
{
    if (isUpper(symbol)) return symbol + ('a' - 'A');
    return symbol;
}

int main()
{
   
}

