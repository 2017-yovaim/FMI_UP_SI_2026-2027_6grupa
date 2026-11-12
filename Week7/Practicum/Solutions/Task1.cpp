#include <iostream>
using namespace std;

constexpr int N = 6;

/*
За всеки ред намира индекса на най-големия елемент и проверява дали той е най-малък в колоната си. 
При първо съвпадение печата координатите, а ако няма такова, печата съобщението.
*/

void printSaddlePoint(int m[][N], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        // най-големият елемент в реда
        int maxCol = 0;
        for (int j = 1; j < cols; j++)
        {
            if (m[i][j] > m[i][maxCol])
            {
                maxCol = j;
            }
        }

        // проверка дали е минимален в колоната си
        bool isMin = true;
        for (int k = 0; k < rows; k++)
            if (m[k][maxCol] < m[i][maxCol]) 
            { 
                isMin = false;
                break; 
            }

        if (isMin) 
        {
            cout << i << " " << maxCol << endl;
            return;
        }
    }
    cout << "The matrix does not have saddle point." << endl;
}

void readMatrix(matrix[][N], int rows, int cols)
{
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            cin >> matrix[i][j];
        }
    }
}

int main() 
{
    int matrix[N][N];
    int rows, cols;
    cin >> rows >> cols;

    readMatrix(matrix, rows, cols);
    printSaddlePoint(matrix,rows,cols);
    return 0;
}
