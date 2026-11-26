#include <iostream>
int const MAX_ROWS_SIZE = 64;
int const MAX_COLS_SIZE = 64;

bool validInput(int&n, int&m) {
    if (!(std::cin >> n) || n < 1 || n > MAX_ROWS_SIZE) {
        std::cout << "Invalid input." << std::endl;
        return 0;
    }
    if (!(std::cin >> m) || m < 1 || m > MAX_COLS_SIZE) {
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
double arithmeticMean(int matrix[][MAX_COLS_SIZE], int rows, int cols) {
    double arithmeticMean = 0, sum=0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    arithmeticMean = sum / (rows * cols);
    return arithmeticMean;
}
bool ifOnce(int matrix[][MAX_COLS_SIZE], int rows, int cols, int i, int j) {
     int count = 0;
     for (int p = 0; p < rows; p++) {
         for (int q = 0; q < cols; q++) {
            if (matrix[p][q] == matrix[i][j]) {
                count++;
            }
         }
     }
     if (count == 1) {
         return 1;
     }
     else {
         return 0;
     }
    
}
bool localMax(int matrix[][MAX_COLS_SIZE], int rows, int cols, int i, int j) {
            int fix = matrix[i][j];
            if (i > 0 && matrix[i - 1][j] > fix) { 
                return 0; 
            }
            if (i < (rows-1) && matrix[i +1][j] > fix) {
                return 0; 
            }
            if (j > 0 && matrix[i][j-1] > fix) {
                return 0; 
            }
            if (j < (cols-1) && matrix[i][j+1] > fix) {
                return 0; 
            }
        
    return 1;
}
void rareElements(int matrix[][MAX_COLS_SIZE], int rows, int cols) {
    bool found = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > arithmeticMean(matrix, rows, cols) && ifOnce(matrix, rows, cols, i, j) && !localMax(matrix, rows, cols, i, j)) {
                std::cout << matrix[i][j] << " ";
                found = true;
            }
        }
    }
    if (!found) {
        std::cout << "No rare elements found.";
    }
    std::cout << std::endl;
}

int main()
{
    int n, m;
    int matrix[MAX_ROWS_SIZE][MAX_COLS_SIZE];
    validInput(n, m);
    inputArray(matrix, n, m);
    rareElements(matrix, n, m);
    return 0;
}

