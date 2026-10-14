#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long a = 0; // fib(1)
    long long b = 1; // fib(2)

    if (n == 1)
    {
        cout << a << endl;
    }

    int i = 2;
    while (i < n)
    {
        long long next = a + b;
        a = b;
        b = next;
        i++;
    }

    cout << b << endl;
    return 0;
}