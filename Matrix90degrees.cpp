#include <iostream>
using namespace std;

const size_t MAX_COLS = 3;

void printMatrix(int matrix[][MAX_COLS], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void mySwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void transposeSquareMatrix(int matrix[][MAX_COLS], size_t rows, size_t cols) {
	if (rows != cols) { //not a square matrix
		return;
	}

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = i + 1; j < cols; j++) {
			mySwap(matrix[i][j], matrix[j][i]);
		}
	}
}

void swapMatrixColumns(int matrix[][MAX_COLS], size_t rows, size_t cols) {
	int leftColIndex = 0, rightColIndex = cols - 1;
		while (leftColIndex <= rightColIndex) {
			for (int i = 0; i < rows; i++) {
				mySwap(matrix[i][leftColIndex], matrix[i][rightColIndex]);
			}
			leftColIndex++;
			rightColIndex--;
		}
	
}

void rotateMatrix90Degrees(int matrix[][MAX_COLS], size_t rows, 
	size_t cols) {
	transposeSquareMatrix(matrix, MAX_COLS, MAX_COLS);
	swapMatrixColumns(matrix, MAX_COLS, MAX_COLS);
}

void rotateMultipleTimes(int matrix[][MAX_COLS], size_t rows,
	size_t cols, unsigned int N) {
	for (int i = 0; i < N; i++) {
		rotateMatrix90Degrees(matrix, rows, cols);
	}
}

int main() {
	int matrix[MAX_COLS][MAX_COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	rotateMatrix90Degrees(matrix, MAX_COLS, MAX_COLS);
	printMatrix(matrix, MAX_COLS, MAX_COLS);
	return 0;
}