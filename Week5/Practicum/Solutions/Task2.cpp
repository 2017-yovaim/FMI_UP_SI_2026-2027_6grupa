#include <iostream>
using namespace std;

void readArray(double arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

double sum(const double arr[], int n)
{
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        result += arr[i];
    }
    return result;
}

double average(const double arr[], int n)
{
    return sum(arr, n) / n;
}

int main()
{
    constexpr int MAX_N = 50;
    int n;
    cin >> n;

    double arr[MAX_N];
    readArray(arr, n);

    cout << "Average: " << average(arr, n) << endl;

    return 0;
}
