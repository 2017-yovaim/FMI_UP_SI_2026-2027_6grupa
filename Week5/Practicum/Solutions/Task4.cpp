#include <iostream>
using namespace std;

void readArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

bool areAllDistinct(const int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    constexpr int MAX_N = 50;
    int n;
    cin >> n;

    int arr[MAX_N];
    readArray(arr, n);

    if (areAllDistinct(arr, n))
    {
        cout << "Yes, the sequence consists of distinct elements." << endl;
    }
    else
    {
        cout << "No, the sequence does not consist of distinct elements." << endl;
    }

    return 0;
}
