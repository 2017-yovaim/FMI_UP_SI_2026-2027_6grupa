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

int main()
{
    cout << isUpper('B') << endl;
    cout << isLower('f') << endl;
    return 0;
}

