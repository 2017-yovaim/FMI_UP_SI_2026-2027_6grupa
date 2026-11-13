#include <iostream>

void readArray ( int arr[], int n) {
 for ( int i = 0; i < n; i++) {
    std::cin>>arr[i];
 }
}

void reverseRange (int a[], int l, int r) {
    while ( l < r) { // докато левият индекс е преди десния, разменям елементите им
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;

        l++; //левият индекс се премества надясно
        r--; //десният индекс се премества налява
    }
}

int main() {
  const int MAX_N = 50;
  int arr[MAX_N];
  int n, l , r;
  if (!(std::cin >> n) || n < 1 || n > MAX_N) {
        return 1;
  }
  readArray(arr, n);

if (!(std::cin >> l >> r) || l < 0 || r >= n || l > r) {
        return 1;
    }

    reverseRange(arr , l , r);
     for (int i = 0; i < n; i++) {
        std::cout << arr[i] << (i== n -1 ? "" : " "); //извежда елементите като проверява да не би i да е последният (с индекс n-1)
     }
     std::cout << std::endl;


    return 0;
}