#include <iostream>
int const MAX_ROWS_SIZE = 5;
int const MAX_COLS_SIZE = 10;

bool validInput(int& n, int& m) {
    if (!(std::cin >> n) || n > MAX_ROWS_SIZE) {
        std::cout << "Invalid input." << std::endl;
        return 0;
    }
    if (!(std::cin >> m) || m > MAX_COLS_SIZE) {
        std::cout << "Invalid input." << std::endl;
        return 0;
    }
    return 1;
}

void inputArray(int matrix[MAX_ROWS_SIZE][MAX_COLS_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }
}
int sumarizeThree(int matrix[][MAX_COLS_SIZE], int rows, int cols) {
    int sum = 0;
    for (int i = rows; i < (rows + 3); i++) {
        for (int j = cols; j < (cols + 3); j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

void findMaxSquare(int matrix[][MAX_COLS_SIZE], int n, int m) {
    int maxSum = sumarizeThree(matrix, 0, 0);
    int leftRow = 0;
    int leftCol = 0;

    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            int currentSum = sumarizeThree(matrix, i, j);
            if (currentSum > maxSum) {
                maxSum = currentSum;
                leftRow = i;
                leftCol = j;
            }
        }
    }

    std::cout << maxSum << std::endl;
    std::cout << leftRow << " " << leftCol << std::endl;
}

int main() {
    int n, m;
    int matrix[MAX_ROWS_SIZE][MAX_COLS_SIZE];
    validInput(n, m);
    inputArray(matrix, n, m);
    findMaxSquare(matrix, n, m);
    return 0;
}