#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 1;
    while (i <= n)
    {
        int temp = i;
        int sum = 0;

        while (temp > 0)
        {
            sum += temp % 10; 
            temp /= 10;       
        }

        if (sum % 2 == 0)
        {
            cout << i << " ";
        }

        i++;
    }

    cout << endl;
    return 0;
}