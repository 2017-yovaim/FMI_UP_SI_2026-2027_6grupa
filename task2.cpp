#include <iostream>
using namespace std;
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
	int arr[50];
	int n;
	int l;
	int r;
	cout << "Enter the number n: ";
	cin >> n;
	if (n < 1 || n>50) {
		cout << "N must be greater than 1 and less than 50!";
	}
	else {
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		cout << "Enter number l and r: " ;
		cin >> l>>r;
		if (l < 0 || r < l || r > n) {
			cout << "Inavlids range in the array!";
		}
		reverseRange(arr, l, r);
		for (int i = 0; i < n; ++i) {
			cout << arr[i] << " ";
		}
	}

}