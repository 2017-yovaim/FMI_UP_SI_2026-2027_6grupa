#include <iostream>

//Дадени са масив от цели числа arr с дължина n(1 ≤ n ≤ 50) и две цели числа l и r(0 ≤ l ≤ r < n).
//
//    Напишете функция, която обръща реда на елементите в arr в интервала от позиция l до позиция r включително(останалите елементи остават на местата си) и извежда получения масив.
//
//    Функцията да бъде със следната сигнатура :
//
//void reverseRange(int a[], int l, int r);
//(към задачата да бъде приложена и main() функция)
//
//Задължително е да се реализира валидация на входните данни.
//
//Пример 1
//
//Вход:
//
//6
//1 2 3 4 5 6
//1 4
//Изход :
//
//    1 5 4 3 2 6
//    Пример 2
//
//    Вход :
//
//    5
//    10 20 30 40 50
//    0 4
//    Изход :
//
//    50 40 30 20 10
//    Пример 3
//
//    Вход :
//
//    4
//    7 8 9 1
//    2 2
//    Изход :
//
//    7 8 9 1

const int ARRSIZE = 50;

void reverseRange(int a[], int l, int r) 
{
    int tempL = l, tempR = r;

    for (tempL; tempL < tempR; tempL++) {
        int temp = a[tempL];
        a[tempL] = a[tempR];
        a[tempR] = temp;
        tempR--;
    }

    for (int i = l; i <= r; i++) {
        std::cout << a[i] << ' ';
    }
}

int main()
{
    int arr[ARRSIZE];
    int n, l, r = 0;
    std::cout << "Enter the lenght of the array (smaller than 50):" << std::endl;
    std::cin >> n;

    if (n < 1 || n > 50) {
        std::cout << "Error: n is not a valid number" << std::endl;
        return 0;
    }

    std::cout << "Enter the values of your array" << std::endl;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Enter the indexes of the two positions, between which you would like to put the values in reverse:" << std::endl;
    std::cin >> l >> r;

    if (l < 0 || r < 0 || l > (n - 1) || r > (n - 1)) {
        std::cout << "Error: the indexes are invalid numbers" << std::endl;
        return 0;
    }

    if (l > r) {
        std::cout << "Error: the first index has to be smaller than the second" << std::endl;
        return 0;
    }

    for (int i = 0; i < l; i++) {
        std::cout << arr[i] << ' ';
    }

    reverseRange(arr, l, r);

    for (int j = (r + 1); j < n; j++) {
        std::cout << arr[j] << ' ';
    }

    std::cout << std::endl;

    return 0;
}