#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1;i <= n;i++)
    {
        int digit = i % 10;
        if (digit == 6 || digit == 8)
        {
            sum += i;
        }
    }

    cout << "Sum: " << sum << endl;
    return 0;
}

