#include <iostream>
using namespace std;

void readArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << arr[i];
    }
    cout << endl;
}

// pos е мястото, на което ще се запише следващият ненулев елемент
void moveZerosToEnd(int arr[], int n)
{
    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[pos] = arr[i];
            pos++;
        }
    }

    for (int i = pos; i < n; i++)
    {
        arr[i] = 0;
    }
}

int main()
{
    constexpr int MAX_N = 100;
    int n;
    cin >> n;

    int arr[MAX_N];
    readArray(arr, n);

    moveZerosToEnd(arr, n);
    printArray(arr, n);

    return 0;
}
