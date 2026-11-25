#include <iostream>
using namespace std;

const size_t MAX_ROWS = 4;
const size_t MAX_COLS = 4;

//auxiliary function - print a matrix
void printMatrix(int matrix[][MAX_COLS], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


//Zad1 - magic square
bool isMagicSquare(int matrix[][MAX_COLS], size_t rows, size_t cols) {
	//if rows != cols - not a square matrix, automatically not a magic square
	if (rows != cols) {
		return false;
	}

	//get our magic sum by summing the elements of the first row
	int magicSum = 0;
	for (size_t i = 0; i < cols; i++) {
		magicSum += matrix[0][i];
	}

	//check all the remaining rows - if the sum of the elements of each rows is different that the magic sum, it's not a magic square
	//starting from the second row since we already have the sum of the first - it is our magic sum
	for (size_t i = 1; i < rows; i++) {
		int rowSum = 0;
		for (size_t j = 0; j < cols; j++) {
			rowSum += matrix[i][j];
		}
		if (rowSum != magicSum) {
			return false;
		}
	}

	//check all the columns
	for (size_t i = 0; i < cols; i++) {
		int colSum = 0;
		for (size_t j = 0; j < rows; j++) {
			colSum += matrix[j][i];
		}
		if (colSum != magicSum) {
			return false;
		}
	}

	//check the primary diagonal
	int diagSum = 0;
	for (size_t i = 0; i < rows; i++) {
		diagSum += matrix[i][i];
	}
	if (diagSum != magicSum) {
		return false;
	}

	//check the secondary diagonal
	diagSum = 0;
	for (size_t i = 0; i < rows; i++) {
		diagSum += matrix[i][rows - i - 1];
	}
	if (diagSum != magicSum) {
		return false;
	}

	//if we haven't returned by this point, then all the magic sum equations are true and therefore the matrix is a magic square
	return true;
}

//Zad2 - spiral traversal: clockwise, starting from [0, 0]
void spiralTraversal(int matrix[][MAX_COLS], size_t rows, size_t cols) {
	//define the boundaries
	int left = 0, right = cols - 1, up = 0, down = rows - 1;

	while (left <= right && up <= down) {
		//traverse top row from left to right according to the boundaries
		for (int i = left; i <= right; i++) {
			cout << matrix[up][i] << " ";
		}
		//now the upper boundary changes - we've already traversed the top row
		up++;

		//traverse the rightmost column from top to bottom according to the boundaries
		for (int i = up; i <= down; i++) {
			cout << matrix[i][right] << " ";
		}
		//now the right boundary changes - we've already traversed the rightmost column
		right--;

		if (up <= down) {
			//traverse the bottom row from right to left according to the boundaries
			for (int i = right; i >= left; i--) {
				cout << matrix[down][i] << " ";
			}
			//now the lower boundary changes - we've already traversed the bottom row
			down--;
		}

		if (left <= right) {
			//traverse the leftmost column from bottom to top according to the boundaries
			for (int i = down; i >= up; i--) {
				cout << matrix[i][left] << " ";
			}
			//now the left boundary changes - we've already traverse the leftmost column
			left++;
		}
	}

	//print a new line so it looks good
	cout << endl;
}

//Zad3 - multiply matrices
void multiplyMatrices(int matrix1[][MAX_COLS], size_t rows1, size_t cols1,
	int matrix2[][MAX_COLS], size_t rows2, size_t cols2,
	int resultMatrix[][MAX_COLS], size_t& resultRows, size_t& resultCols) {
	if (cols1 != rows2) { //impossible to multiply
		return;
	}

	//record the sizes of the result matrix
	resultRows = rows1;
	resultCols = cols2;
	
	//calculate the values of the result matrix
	for (size_t i = 0; i < rows1; i++) {
		for (size_t j = 0; j < cols2; j++) {
			for (size_t k = 0; k < cols1; k++) {
				resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
}

//Zad4 - transpose a random matrix into a result matrix, which we assume has enough space
void transposeMatrix(int sourceMatrix[][MAX_COLS], size_t rows, size_t cols, int destMatrix[][MAX_COLS]) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			destMatrix[j][i] = sourceMatrix[i][j];
		}
	}
}

//Zad5 - transpose a square matrix in-place
void transposeSquareMatrix(int matrix[][MAX_COLS], size_t rows, size_t cols) {
	if (rows != cols) { //not a square matrix
		return;
	}

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = i + 1; j < cols; j++) {
			//swap matrix[i][j] and matrix[j][i]
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}



//for testing
int main() {

	int magicSquare[MAX_ROWS][MAX_COLS] = { {7, 12, 1, 14}, {2, 13, 8, 11}, {16, 3, 10, 5}, {9, 6, 15, 4} };
	int notMagicSquare[MAX_ROWS][MAX_COLS] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
	cout << isMagicSquare(magicSquare, MAX_ROWS, MAX_COLS) << " " << isMagicSquare(notMagicSquare, MAX_ROWS, MAX_COLS) << endl;
	spiralTraversal(magicSquare, MAX_ROWS, MAX_COLS);
	int sourceMatrix[3][MAX_COLS] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	int destMatrix[MAX_ROWS][MAX_COLS]{ 0 };
	transposeMatrix(sourceMatrix, 3, MAX_COLS, destMatrix);
	printMatrix(destMatrix, MAX_COLS, 3);
	transposeSquareMatrix(notMagicSquare, MAX_ROWS, MAX_COLS);
	printMatrix(notMagicSquare, MAX_ROWS, MAX_COLS);

	int matrix1[3][MAX_COLS] = { {1, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 0, 1} };
	int matrix2[MAX_COLS][MAX_COLS] = { {0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 0, 1}, {0, 0, 0, 1} };
	int resultMatrix[3][MAX_COLS] = { 0 };
	size_t resultRows = 0, resultCols = 0;
	multiplyMatrices(matrix1, 3, MAX_COLS, matrix2, MAX_COLS, MAX_COLS, resultMatrix, resultRows, resultCols);
	printMatrix(resultMatrix, resultRows, resultCols);




	return 0;
}