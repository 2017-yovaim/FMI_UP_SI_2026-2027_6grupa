#include <iostream>

const int MIN_N = 5;
const int MAX_N = 10;
const int MIN_M = 5;
const int MAX_M = 10;

void readMatrix(int matrix[][MAX_M], int n, int m) 
{
    if (n < 5 || n > 10 || m < 5 || m > 10) //валидация за n и m
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

void findLargestSum (int matrix[][MAX_M], int n, int m) 
{
    if (n < 5 || n > 10 || m < 5 || m > 10) //валидация за n и m
    {
        return;
    }
    int maxSum =INT_MIN;

    int index1 =0;
    int index2=0;

    for (int bi = 0; bi < n - 2; bi++) //bi е ограничен до n - 2, защото при вземане на 3 реда заедно всички възможности на избор са точно n-2 до последния ред 
    {
        for (int bj = 0; bj < n - 2; bj++) //същото важи и за колоните
        {
            
            int currentSum = 0;
            for (int i = 0; i < 3; i++) //i е ограничен до 3 защото взимаме всички 3x3 матрици
            {
                for (int j = 0; j < 3; j++) // j по същия начин както i
                {
                    currentSum +=matrix[bi +i][bj + j];
                }
            }

            if (currentSum > maxSum) 
            {
                maxSum = currentSum;
                 index1 = bi;
                 index2 = bj;
            }
        }
    }
    std::cout << maxSum << std::endl;
    std::cout << "Index: " << index1 << " " << index2 << std::endl;
}


int main() 
{
    int matrix[MAX_N][MAX_M];
  int N;
  int M;
  std::cin >> N >> M;
  readMatrix(matrix, N, M);
  findLargestSum(matrix, N, M);


  return 0;
}