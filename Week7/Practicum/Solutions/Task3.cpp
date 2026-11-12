#include <iostream>
using namespace std;

const int N = 9;

/*Взема сумата на първия ред като еталон. 
После проверява дали всеки ред, всяка колона и 
всяка от деветте 3x3 подматрици имат същата сума,и печата 1 или 0.
*/

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

bool isEqualsSums(matrix[][N])
{
    // еталонна сума - първия ред
    int target = 0;
    for (int j = 0; j < N; j++)
    {
        target += m[0][j];
    }

    bool isEquals = true;

    // редове и колони
    for (int i = 0; i < N && ok; i++)
    {
        int row = 0, col = 0;

        for (int j = 0; j < N; j++)
        {
            row += m[i][j];
            col += m[j][i];
        }

        if (row != target || col != target)
        {
            isEquals = false;
        }
    }

    // 3x3 подматрици
    for (int bi = 0; bi < N && ok; bi += 3)
    {
        for (int bj = 0; bj < N && ok; bj += 3)
        {
            int sum = 0;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    sum += m[bi + i][bj + j];
                }

                if (sum != target)
                {
                    isEquals = false;
                }
            }
        }
    }

    return isEquals;
}

int main() {
    int m[N][N];
    readMatrix(matrix);
    cout << isEqualsSums(matrix);
    
    return 0;
}
