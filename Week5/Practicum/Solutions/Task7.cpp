#include <iostream>
using namespace std;

void readArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

bool isPalindrome(const int arr[], int n)
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
    constexpr int MAX_N = 100;
    int n;
    cin >> n;

    int arr[MAX_N];
    readArray(arr, n);

    if (isPalindrome(arr, n))
    {
        cout << "Yes, the array is a palindrome." << endl;
    }
    else
    {
        cout << "No, the array is not a palindrome." << endl;
    }

    return 0;
}
