#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int max = INT_MIN;//int max=0;

    for (int i = 0;i < n;i++)
    {
        int num;
        cin >> num;
        if (num > max)
        {
            max = num;
        }
    }

    cout << "Max: " << max;
    return 0;
}

