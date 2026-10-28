#include <iostream>
using namespace std;

void readArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

// Монотонно намаляваща: a[0] >= a[1] >= ... >= a[n-1].
// За строго намаляваща редица => arr[i] <= arr[i + 1].
bool isMonotonicallyDecreasing(const int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
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

    int arr[MAX_N];
    readArray(arr, n);

    if (isMonotonicallyDecreasing(arr, n))
    {
        cout << "The series is monotonically decreasing." << endl;
    }
    else
    {
        cout << "The series is not monotonically decreasing." << endl;
    }

    return 0;
}
