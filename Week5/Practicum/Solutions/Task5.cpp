#include <iostream>
using namespace std;

// cin >> ch прескача интервалите, затова работи и за "abcba", и за "a b c b a"
void readArray(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

bool isSymmetric(const char arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    constexpr int MAX_N = 50;
    int n;
    cin >> n;

    char arr[MAX_N];
    readArray(arr, n);

    if (isSymmetric(arr, n))
    {
        cout << "Yes, the array is symmetric." << endl;
    }
    else
    {
        cout << "No, the array is not symmetric." << endl;
    }

    return 0;
}
