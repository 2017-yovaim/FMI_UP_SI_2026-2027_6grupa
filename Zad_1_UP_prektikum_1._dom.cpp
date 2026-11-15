#include <iostream>

//Дадени са два масива от цели числа : arr1 с дължина n и arr2 с дължина m(1 ≤ n, m ≤ 100).
//
//Масивът arr2 се съдържа в масива arr1, ако в arr1 съществуват m последователни елемента, които съвпадат по стойност и по ред с елементите на arr2.
//
//Напишете функция с дадената сигнатура по - долу, която проверява дали arr2 се съдържа в arr1 и връща като резултат съответно 1 (true), ако условието е изпълнено, и 0 (false) – в противен случай.
//
//(към задачата да бъде приложена и main() функция).Задължително е да се реализира валидация на входните данни.
//
//bool contains(const int a[], int n, const int b[], int m);
//Пример 1:
//
//Вход:
//
//8
//3 1 4 1 5 9 2 6
//3
//1 5 9
//Изход :
//
//    1 (true)
//    Пример 2 :
//
//    Вход :
//
//    8
//    3 1 4 1 5 9 2 6
//    3
//    1 4 5
//    Изход :
//
//    0 (false)

const int ARRSIZE = 100;

bool contains(const int a[], int n, const int b[], int m) {

    bool contains = false;

    for (int i = 0; i < n; i++) {

        if (a[i] == b[0]) {

            contains = true;

            for (int j = 0; j < m; j++) {

                if (i + j > n - 1 || b[j] != a[i + j]) {
                    contains =  false;
                }

            }

            if (contains == true) {
                return true;
            }

        }

    }

    return false;

}

bool checkIfLenghtIsValid(int lenght) 
{
    if (lenght < 1 || lenght > 100) 
    {
        return false;
    }
    return true;
}

int main()
{
    int n = 0, m = 0;
    int arr1[ARRSIZE];
    int arr2[ARRSIZE];

    std::cout << "Enter the lenght of the first arr (between 1 and 100):"<<std::endl;
    std::cin >> n;

    if (checkIfLenghtIsValid(n) == false) 
    {
        std::cout << "Not a valid lenght" << std::endl;
        return 0;
    }

    std::cout << "Enter the values of the first arr:" << std::endl;

    for (int i = 0; i < n; i++) 
    {
        std::cin >> arr1[i];
        
    }

    std::cout << "Enter the lenght of the second arr:" << std::endl;
    std::cin >> m;

    if (checkIfLenghtIsValid(m) == false) 
    {
        std::cout << "Not a valid number";
        return 0;
    }

    if (m > n) 
    {
        std::cout << "n has to be larger than m in order for this program to run" << std::endl;
        return 0;
    }

    std::cout << "Enter the values of the second arr:" << std::endl;

    for (int i = 0; i < m; i++) 
    {
        std::cin >> arr2[i];
    }

    std::cout << "\n" << contains(arr1, n, arr2, m) << std::endl;

    return 0;
}