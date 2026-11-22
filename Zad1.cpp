#include <iostream>

const int MAX_LENGTH = 64;

double average(int matrix[][MAX_LENGTH], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return (double)sum / (rows * cols);
}

bool isUnique(int matrix[][MAX_LENGTH], int rows, int cols, int element) {
	int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (element == matrix[i][j]) {
                count++;
            }
        }
    }
	if (count == 1) {
		return true;
	}
    return false;
}

bool isNotLocalMax(int matrix[][MAX_LENGTH], int rows, int cols, int element, int ii, int jj) {
    if ((ii + 1 < rows && element < matrix[ii + 1][jj])
        || (ii - 1 >= 0 && element < matrix[ii - 1][jj])
        || (jj + 1 < cols && element < matrix[ii][jj + 1])
        || (jj - 1 >= 0 && element < matrix[ii][jj - 1])) {
        return true;
    }
    return false;
}

void rareElements(int matrix[][MAX_LENGTH], int rows, int cols) {
    bool found = false;
	double avg = average(matrix, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool isRare1 = false;
            bool isRare2 = false;
            bool isRare3 = false;
            if (matrix[i][j] > avg) {
                isRare1 = true;
            }
            if (isUnique(matrix, rows, cols, matrix[i][j])) {
                isRare2 = true;
            }
            if (isNotLocalMax(matrix, rows, cols, matrix[i][j], i, j)) {
                isRare3 = true;
            }
            if (isRare1 && isRare2 && isRare3) {
                std::cout << matrix[i][j] << " ";
                found = true;
            }
        }
    }
    if (!found) {
        std::cout << "No rare elements found";
    }
}

bool readMatrix(int matrix[][MAX_LENGTH], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(std::cin >> matrix[i][j])) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n; int m;
    if (!(std::cin >> n >> m) ||
        n < 1 || n > MAX_LENGTH ||
        m < 1 || m > MAX_LENGTH) {
        std::cout << "Invalid input";
        return 0;
    }
    int matrix[MAX_LENGTH][MAX_LENGTH];
    if (!readMatrix(matrix, n, m)) {
        std::cout << "Invalid input";
        return 0;
    }
    rareElements(matrix, n, m);
}