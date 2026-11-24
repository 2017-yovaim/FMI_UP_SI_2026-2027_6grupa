#include <iostream>

const size_t MAX_SIZE = 64;

bool checkSizeValue(int rows, int cols)
{
    if (rows < 1 || rows > 64)
    {
        std::cout << "Error: rows is not a valid number" << std::endl;
        return false;
    }

    if (cols < 1 || cols > 64)
    {
        std::cout << "Error: cols is not a valid number" << std::endl;
        return false;
    }

    return true;
}

void enterMatrix(int matrix[][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];

            if (std::cin.fail()) 
            {
                std::cout << "Error: not a valid number" << std::endl;
                exit(1);
            }
        }
    }
}

double averageValueOfMatrix(int matrix[][MAX_SIZE], int rows, int cols)
{
    double sumOfAllElements = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sumOfAllElements += matrix[i][j];
        }
    }

    return sumOfAllElements / (rows * cols);
}

bool checkIfIsInMatrixOnce(int matrix[][MAX_SIZE], int rows, int cols, int val)
{
    int counter = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == val)
            {
                counter++;
            }
        }
    }

    if (counter == 1)
    {
        return true;
    }

    return false;
}

bool checkIfNotLocalMax(int matrix[][MAX_SIZE], int row, int col, int rows, int cols, int currentVal)
{
    if ((row > 0) && (currentVal < matrix[row - 1][col]))
    {
        return true;
    }
    if ((row < rows - 1) && (currentVal < matrix[row + 1][col]))
    {
        return true;
    }
    if ((col > 0) && (currentVal < matrix[row][col - 1]))
    {
        return true;
    }
    if ((col < cols - 1) && (currentVal < matrix[row][col + 2]))
    {
        return true;
    }

    return false;
}

void rareElements(int matrix[][MAX_SIZE], int rows, int cols)
{
    double averageVal = averageValueOfMatrix(matrix, rows, cols);
    bool rareElementExists = false;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int currentMatrixVal = matrix[i][j];

            if (checkIfIsInMatrixOnce(matrix, rows, cols, currentMatrixVal) == true)
            {
                if (currentMatrixVal > averageVal) 
                {
                    if (checkIfNotLocalMax(matrix, i, j, rows, cols, currentMatrixVal) == true)
                    {
                        std::cout << currentMatrixVal << ' ';
                        rareElementExists = true;
                    }
                }
            }
        }
    }

    if (rareElementExists == false)
    {
        std::cout << "There are no rare elements";
    }

    std::cout << std::endl;
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];

    int rows = 0, cols = 0;

    std::cin >> rows >> cols;

    if (checkSizeValue(rows, cols) == false)
    {
        return 0;
    }

    enterMatrix(matrix, rows, cols);

    rareElements(matrix, rows, cols);

    return 0;
}