#include <iostream>
#include <limits>

const int MAX_SIZE = 100;

int validSize(int minVal, int maxVal)
{
    int size = 0;

    do{
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

bool contains(const int a[], int n, const int b[], int m) {
    if (n < m) {
        return false;
    }

    for (int i = 0; i <= n - m; i++) {

        bool match = true;

        for (int j = 0; j < m; j++) {
            if (a[i + j] != b[j]) {
                match = false;
                break;
            }

        }
        if (match) {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr1 [MAX_SIZE];
    int arr2 [MAX_SIZE];

    int n = validSize(1, MAX_SIZE);
    validArray(arr1, n);

    int m = validSize(1, MAX_SIZE);
    validArray(arr2, m);

    bool result = contains(arr1, n, arr2, m);

    std::string answer = ( result ? "true" : "false");

    std::cout << answer;

    return 0;
}
