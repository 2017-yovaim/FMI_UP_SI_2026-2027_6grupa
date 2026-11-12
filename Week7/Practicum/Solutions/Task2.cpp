#include <iostream>
using namespace std;

constexpr int N = 4;

void readMatrix(matrix[][N])
{
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void printMatrixInOrder(matrix[][N])
{ 
    // ред 0 отляво надясно
    for (int j = 0; j < N; j++)
    {
        cout << m[0][j] << " ";
    }

    // ред 3 отдясно наляво
    for (int j = N - 1; j >= 0; j--)
    {
        cout << m[3][j] << " ";
    }

    // ред 1 отдясно наляво
    for (int j = N - 1; j >= 0; j--)
    {
        cout << m[1][j] << " ";
    }

    // ред 2 отляво надясно
    for (int j = 0; j < N; j++)
    {
        cout << m[2][j] << " ";
    }
    cout << endl;
}

int main() {
    int m[N][N];

    readMatrix(matrix);
    printMatrixInOrder(matrix);

    return 0;
}
