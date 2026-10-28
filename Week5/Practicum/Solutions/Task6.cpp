#include <iostream>
using namespace std;

void readArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

// Два масива (вектора) са линейно зависими, ако единият се получава от
// другия чрез умножение с число, т.е. ако за всеки два индекса i и j е
// изпълнено a[i] * b[j] == a[j] * b[i] (без деление, за да няма проблем с 0).
// Ако единият масив е нулев, масивите също се считат за линейно зависими.
bool areLinearlyDependent(const int a[], const int b[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            long long left = (long long)a[i] * b[j];
            long long right = (long long)a[j] * b[i];
            if (left != right)
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

    int a[MAX_N];
    int b[MAX_N];
    readArray(a, n);
    readArray(b, n);

    if (areLinearlyDependent(a, b, n))
    {
        cout << "Yes, the arrays are linearly dependent." << endl;
    }
    else
    {
        cout << "No, the arrays are not linearly dependent." << endl;
    }

    return 0;
}
