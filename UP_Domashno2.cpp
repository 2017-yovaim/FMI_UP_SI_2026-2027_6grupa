#include <iostream>
#include <limits>

const int MAX_SIZE = 50;

int validSize(int minVal, int maxVal)
{
    int size = 0;

    do {
        std::cin >> size;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            size = 0;
            continue;
        }

    } while (size < minVal || size > maxVal);
    return size;
}

void validArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        while (true) {
            std::cin >> arr[i];
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
    }
}

void reverseRange(int a[], int l, int r) 
{
    int temp;

    while (l < r)
    {
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        l++;
        r--;
    }

}

int main()
{
    int arr[MAX_SIZE];

    int n = validSize(1, MAX_SIZE);
    validArray(arr, n);

    int l = validSize(0, MAX_SIZE - 1);

    int r = validSize(l, MAX_SIZE - 1);

    reverseRange(arr, l, r);

    for (int i = 0; i <= n-1 ; i++) {

        std::cout << arr[i] << " ";
    }


}