#include <iostream>

const size_t MAX_ROWS = 5;
const size_t MAX_COLS = 10;

int sumOfSquare(int matrix[][MAX_COLS], int i, int j)
{
    int sum = 0;

    for (int i1 = i; i1 < i+3; i1++)
    {
        for (int j1 = j; j1 < j+3; j1++)
        {
            sum += matrix[i1][j1];
        }
    }

    return sum;
}

void largestSquareInMatrix(int matrix[][MAX_COLS], int rows, int cols)
{
    bool isLargetsSquare = false;
    int sumOfLargestsquare = 0;
    int rowIndexOfLargestSquare = 0;
    int colIndexOfLargestSquare = 0;

    for (int i = 0; i < rows - 2; i++)
    {
        for (int j = 0; j < cols - 2; j++)
        {
            int sumOfCurrentSquare = sumOfSquare(matrix, i, j);

            if (sumOfCurrentSquare > sumOfLargestsquare)
            {
                sumOfLargestsquare = sumOfCurrentSquare;
                rowIndexOfLargestSquare = i;
                colIndexOfLargestSquare = j;
            }
        }
    }

    std::cout << "Sum of largest values in one square: " << sumOfLargestsquare<<std::endl;
    std::cout << "Indexes of largest square: " << rowIndexOfLargestSquare << ' ' << colIndexOfLargestSquare << std::endl;
}

void enterMatrix(int matrix[][MAX_COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

int main()
{
    int matrix[MAX_ROWS][MAX_COLS];

    std::cout<<"Enter the number of you rows and columns:"<<std::endl;
    int rows = 0;
    std::cin >> rows;

    if (rows > MAX_ROWS || rows < 3)
    {
        std::cout << "Error: number of rows is not valid" << std::endl;
        return 0;
    }

    int cols = 0;
    std::cin >> cols;

    if (cols > MAX_COLS || cols < 3)
    {
        std::cout << "Error: number of columns is not valid" << std::endl;
        return 0;
    }

    enterMatrix(matrix, rows, cols);

    largestSquareInMatrix(matrix, rows, cols);
}