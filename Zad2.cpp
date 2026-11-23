#include <iostream>

const int MAX_SIZE = 10;
const int MIN_SIZE = 5;
const int SQUARE_SIZE = 3;

void readMatrix(int matrix[][MAX_SIZE], int N, int M){
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> matrix[i][j];
		}
	}
}

int calculateSum(int matrix[][MAX_SIZE], int startN, int startM) {
	int sum = 0;
	for (int i = startN; i < startN + SQUARE_SIZE; i++) {
		for (int j = startM; j < startM + SQUARE_SIZE; j++) {
			sum += matrix[i][j];
		}
	}
	return sum;
}

int findMaxSum(int matrix[][MAX_SIZE], int N, int M, int& maxSumN, int& maxSumM) {
	maxSumN = 0;
	maxSumM = 0;
	int sum = calculateSum(matrix, 0, 0);
	for (int i = 0; i <= N - SQUARE_SIZE; i++) {
		for (int j = 0; j <= M - SQUARE_SIZE; j++) {
			if (calculateSum(matrix, i, j) > sum) {
				sum = calculateSum(matrix, i, j);
				maxSumN = i;
				maxSumM = j;
			}
		}
	}
	return sum;
}

int main()
{
    int N, M;
	std::cin >> N >> M;
	if (N < MIN_SIZE || N > MAX_SIZE || M < MIN_SIZE || M > MAX_SIZE) {
		std::cout << "Invalid input!" << std::endl;
		return 0;
	}

	int matrix[MAX_SIZE][MAX_SIZE];
	readMatrix(matrix, N, M);

	int maxSumN = 0, maxSumM = 0;
	int maxSum = findMaxSum(matrix, N, M, maxSumN, maxSumM);
	std::cout << maxSum << std::endl;
	std::cout << maxSumN << " " << maxSumM << std::endl;
}