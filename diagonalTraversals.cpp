#include <iostream>
using namespace std;
const size_t MAX_ROWS = 4;
const size_t MAX_COLS = 4;

void positiveDiagonalTraversal(int matrix[][MAX_COLS], size_t rows, size_t cols) {
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        int i = rowIndex, j = 0;
        while (i >= 0 && j < cols) {
            cout << matrix[i][j] << " ";
            i--;
            j++;
        }
        cout << endl;
    }

    for (int colIndex = 1; colIndex < cols; colIndex++) {
        int i = rows - 1, j = colIndex;    
        while (i >= 0 && j < cols) {
            cout << matrix[i][j] << " ";
            i--;
            j++;
        }
        cout << endl;
    }
}

void negativeDiagonalTraversal(int matrix[][MAX_COLS], size_t rows, size_t cols) {
    for (int colIndex = 0; colIndex < cols; colIndex++) {
        int i = rows - 1, j = colIndex;

        while (i >= 0 && j >= 0) {
            cout << matrix[i][j] << " ";
            i--;
            j--;
        }
        cout << endl;
    }

    for (int rowIndex = rows - 2; rowIndex >= 0; rowIndex--) {
        int i = rowIndex, j = cols - 1;

        while (i >= 0 && j >= 0) {
            cout << matrix[i][j] << " ";
            i--;
            j--;
        }
        cout << endl;
    }
}

int main()
{
    int matrix[3][MAX_COLS] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    positiveDiagonalTraversal(matrix, 3, 4);
    negativeDiagonalTraversal(matrix, 3, 4);

    return 0;
}