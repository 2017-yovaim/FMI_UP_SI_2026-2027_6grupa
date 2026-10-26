#include <iostream>
using namespace std;


int main() {
	int n = 0, m = 0, k = 0;
	cout << "Please enter 3 numbers: ";
	cin >> n >> m >> k;

	if (n > m) {
		int temp = n;
		n = m;
		m = temp;
	}

	if (k > m) {
		cout << "No numbers in the range [" << n << ", " << m << "] are divisble by " << k << endl;
		return -1;
	}

	for (int i = n; i <= m; i++) {
		if (i % k == 0) {
			cout << i << " ";
		}
	}
	cout << endl;





	return 0;
}