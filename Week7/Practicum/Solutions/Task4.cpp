#include <iostream>
using namespace std;

const int MAXN = 10;

/*
Една функция завърта матрицата на 90° надясно, като елементът m[i][j] отива в m[j][n-1-i].
Основната функция я вика M % 4 пъти, защото 4 завъртания връщат матрицата в начално положение.
*/

void rotateOnce(int m[][MAXN], int n) 
{
    int tmp[MAXN][MAXN];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[j][n - 1 - i] = m[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m[i][j] = tmp[i][j];
        }
    }
}

void rotate(int m[][MAXN], int n, int M) 
{
    M %= 4; // 4 завъртания връщат матрицата в началното ѝ положение

    for (int k = 0; k < M; k++)
    {
        rotateOnce(m, n);
    }
}

void print(int m[][MAXN], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int a[MAXN][MAXN];
    int c = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = c++;
        }
    }

    cout << "3x3, M = 1:" << endl;
    rotate(a, 3, 1);
    print(a, 3);

    int b[MAXN][MAXN];
    c = 1;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            b[i][j] = c++;
        }
    }

    cout << "6x6, M = 2:" << endl;
    rotate(b, 6, 2);
    print(b, 6);

    return 0;
}
