#include <iostream>

void readArray( int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        std::cin>>arr[i];
    }
}
bool contains(const int a[], int n, const int b[], int m){
    if ( m > n || m <= 0 || n <= 0) {
        return false;
    }

    for (int i = 0; i <= n - m; i++) { //обхождаме масива а до позиция, до която все още има достатъчно елементи
        bool match = true;
        for (int j = 0; j < m; j++) {
            if ( a[i + j] != b[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return true; //намерено е съвпадение
        }
    }
    return false; // не е намерено съвпадение
}

int main() {
    const int MAX_N = 100;
    const int MAX_M = 100;
    int arr1[MAX_N];
    int arr2[MAX_M];
    int n, m;
    std::cin>> n;
    readArray(arr1, n);
    std::cin>> m;
    readArray(arr2, m);
     if (contains(arr1, n, arr2, m)) {
            std::cout << "true" << std::endl;
        }
        else {
            std::cout << "false" << std::endl;
        }
return 0;
}