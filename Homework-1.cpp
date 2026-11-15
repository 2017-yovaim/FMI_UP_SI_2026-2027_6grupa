#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

bool contains(const int a[], int n, const int b[], int m) {
    if (m <= 0 || n <= 0 || m > n) {
        return false;
    }
    for (int i = 0; i <= n - m; ++i) {
        bool ifMatch = true;
        for (int j = 0; j < m; ++j) {
            if (a[i + j] != b[j]) {
                ifMatch = false;
                break; 
            }
        }
        if (ifMatch) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE];
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    bool result = contains(arr1, n, arr2, m);
    if (result) {
        cout << "1 (true)" << endl;
    }
    else {
        cout << "0 (false)" << endl;
    }

    return 0;
}
