#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;//матрица n*n

    int i = 0;//rows
    while (i < n)
    {
        int j = 0;//cols
        while (j < n)
        {
            if (j <= i)//под главния диагонал
            {
                cout << 1 << " ";
            }
            else//над главния диагонал
            {
                cout << 0 << " ";
            }
            j++;
        }

        cout << endl;
        i++;
    }

    return 0;
}