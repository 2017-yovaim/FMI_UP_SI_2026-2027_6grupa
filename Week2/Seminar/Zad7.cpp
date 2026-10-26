#include <iostream>
using namespace std;

int main() {
	unsigned n = 1;
	cout << "Please enter a number n - I will tell you the nth number of the Fibonacci sequence!" << endl;
	cin >> n;

	if (n <= 0) {
		cout << "Sorry, I need a positive integer!" << endl;
		return -1;
	}

	int fib1 = 1, fib2 = 1;

	if (n == 1 || n == 2) {
		cout << fib1 << endl;
		return 0;
	}

	for (int i = 3; i <= n; i++) { //the Fibonacci step
		int temp = fib2;
		fib2 += fib1;
		fib1 = temp;
	}

	cout << fib2 << endl;




	return 0;
}