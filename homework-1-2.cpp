#include <iostream>
//using namespace std;
const int MAX_SIZE = 50;

void reverseRange(int a[], int l, int r) {
    while (l < r) {
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        l++;
        r--;
    }
}

int main() {
    int arr[MAX_SIZE];
    int n, l, r;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cin >> l >> r;
    reverseRange(arr, l, r);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] <<  " ";
    }
    std::cout << std::endl;

    return 0;
}
