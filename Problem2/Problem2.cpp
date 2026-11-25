#include <iostream>

int main()
{
	const int SIZE = 10;
	int matrix[SIZE][SIZE] = {};
	int n, m;
	std::cin >> n >> m;
	if (n < 5 || n > SIZE || m < 5 || m > SIZE)
	{
		std::cout << "Invalid input";
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	const int MATRIX_SIZE = 3;
	int maxSum = 0;
	int sum = 0;
	int rowPosition = 0;
	int colPosition = 0;
	bool isFirst = true;

	for (int row = 0; row <= n - MATRIX_SIZE; row++)
	{
		for (int col = 0; col <= m - MATRIX_SIZE; col++)
		{
			for (int i = 0; i < MATRIX_SIZE; i++)
			{
				for (int j = 0; j < MATRIX_SIZE; j++)
				{
					sum += matrix[row + i][col + j];
				}
			}

			if (isFirst || sum > maxSum)
			{
				maxSum = sum;
				rowPosition = row;
				colPosition = col;
				isFirst = false;
			}
			sum = 0;
		}
	}

	std::cout << maxSum << std::endl;
	std::cout << rowPosition << ' ' << colPosition << std::endl;
}