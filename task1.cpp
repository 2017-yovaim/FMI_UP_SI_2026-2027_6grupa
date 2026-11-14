#include <iostream>
using namespace std;
bool contains(const int a[], int n, const int b[], int m) {
	for (int i = 0; i <= n-m; ++i) {
		int j = 0;
		while (j < m && a[i + j] == b[j]) {
			j++;
		}
		if (j == m) {
			return true;
		}
	}
	return false;
}

int main() {
	int arr1[100];
	int arr2[100];
	int n;
	int m;
	cout << "Enter the number n: ";
	cin >> n;
	if (n < 1 || n>100) {
		cout << "N must be greater than 1 and less than 100!"<<endl;
	}else{
	cout << "Enter n amount of numbers for arr1: ";
	for (int i = 0; i < n; ++i) {
		cin >> arr1[i];
	}
	}
	cout << "Enter the m number: ";
	cin >> m;
	if (m < 1 || m > 100) {
		cout << "M must be greater than 1 and less than 100!"<<endl;
	}
	else if (m > n) {
		cout << "M cannot be greater than N!";
	}else{
		
	cout << "Enter m amount of numbers for arr2: ";
	for (int i = 0; i < m; ++i) {
		cin >> arr2[i];
	}
	}
	cout << contains(arr1, n, arr2, m);

}
