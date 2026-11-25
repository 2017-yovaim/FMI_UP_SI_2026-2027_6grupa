#include <iostream>

const int SIZE = 100;

void rareElements(int matrix[][SIZE], int rows, int cols);

int main()
{
	int matrix[SIZE][SIZE] = {};
	int n, m;
	std::cin >> n >> m;
	if (n < 1 || n > 64 || m < 1 || m > 64)
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

	rareElements(matrix, n, m);
}

void rareElements(int matrix[][SIZE], int rows, int cols)
{
	double averageSum = 0;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			averageSum += matrix[row][col];
		}
	}
	averageSum /= (double)(rows * cols);

	int colSteps[] = { -1, 1, 0, 0 };
	int rowSteps[] = { 0, 0, -1, 1 };
	const int steps = 4;
	int rowPosition = 0;
	int colPosition = 0;
	bool isRare = false;

	for (int row = 0; row < rows; row++)
	{
		rowPosition = row;
		for (int col = 0; col < cols; col++)
		{
			colPosition = col;
			if (matrix[row][col] > averageSum)
			{
				for (int step = 0; step < steps; step++)
				{
					if (matrix[row][col] < matrix[row + rowSteps[step]][col + colSteps[step]])
					{
						isRare = true;
						break;
					}
				}

				if (isRare)
				{
					for (int row = 0; row < rows; row++)
					{
						for (int col = 0; col < cols; col++)
						{
							if (row != rowPosition && col != colPosition && matrix[row][col] == matrix[rowPosition][colPosition])
							{
								isRare = false;
								break;
							}
						}
					}
				}
			}

			if (isRare)
			{
				std::cout << matrix[rowPosition][colPosition] << ' ';
			}
			isRare = false;
		}
	}
}
