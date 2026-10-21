#include <iostream>
using namespace std;

int absoluteValue(int number) 
{
    return number < 0 ? -number : number;
}


int main()
{
    cout << absoluteValue(-4) << endl;
    return 0;
}
