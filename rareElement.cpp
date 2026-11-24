#include <iostream>

const int MAX_N = 64;
const int MAX_M = 64;

void readMatrix( int matrix[][MAX_M], int n, int m)
{
    if (n < 1 || n > 64 || m < 1 || m > 64 )
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }

    }
}

double calcAverage (int matrix[][MAX_M], int rows, int cols)
{
    // намиране на средна аритметична стойност на цялата матрица

    double sum =0;
    
    for (int i = 0; i < rows; i++)
    {
        for ( int j =0; j < cols; j++)
        {
            sum += matrix[i][j];
        }

    }
    return sum / (rows*cols);
}

bool hasDuplicate ( int matrix[][MAX_M], int rows, int cols, int r, int c)
{
    int target = matrix[r][c]; //съответният елемент, с който работим в момента
    
    for (int i = 0; i < rows; i++) //обхождаме матрицата и сравняваме всеки елемент с нашия избран target
    {
        for (int j = 0; j < cols; j++)
        {
            if( i == r && j == c) //ако индексите съвпадат, програмата продължава да търси още 
            {
                continue;
            }
            if (matrix[i][j] == target)
            {
                return true;
            }
    }
}
return false; // има само един единствен елемент, т.е няма дубликати
}

bool isNotLocalExtremum (int matrix[][MAX_M], int rows, int cols, int r, int c)
{
    const int dr[4] = { -1, 1, 0, 0}; // промяната в номера на реда: -1 нагоре, +1 надолу, 0 същия ред
    const int dc[4] = {0, 0, -1, 1}; // промяната в номера на колоната: -1 наляво, +1 надясно, 0 същата колона
    

    int current = matrix[r][c];

    for (int k =0; k < 4; k++)
    {
        int nr = r + dr[k]; //новият съседен ред
        int nc = c + dc[k]; //новата съседна колона

        if (nr >=0 && nr < rows && nc >=0 && nc < cols) //проверка дали да не сме излезли от границата на матрицата
        {
            if (matrix[nr][nc] > current)
            {
                return true; //нашият елемент не е лок. макс.
            }
        }
    }
    return false;
}
void rareElements(int matrix[][MAX_M], int rows, int cols)
{
    if ( rows <=0 || rows > MAX_N || cols <=0 || cols > MAX_M)
    {
        return ;
    }

    double averageSum = calcAverage(matrix, rows, cols);
    bool foundRareElements = false;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            bool aboveAverage = matrix[i][j] > averageSum;
            bool unique = !hasDuplicate(matrix, rows, cols, i, j);
            bool notLocalMax = isNotLocalExtremum(matrix, rows, cols, i, j);

            if (aboveAverage && unique && notLocalMax)
            {
                std::cout << matrix[i][j] << " ";
                foundRareElements = true;
            }
        }

    }

       if (!foundRareElements)
        {
            std::cout << "No rare elements." << std::endl;

        }

}

int main()
{
    int matrix[MAX_N][MAX_M];
    int n, m;
    std::cin >> n >> m;
    readMatrix(matrix,n, m);
    rareElements(matrix, n, m);

    return 0;
}