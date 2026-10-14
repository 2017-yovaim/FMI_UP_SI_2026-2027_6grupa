#include <iostream>
using namespace std;

int main() {
	int number = 0;
	int factorial = 1;

	cout << "Please enter the number to count a factorial: ";
	cin >> number;
	for (int i = 1; i <= number; i++) 
	{
		factorial *= i;
	}

	cout << "Result: " << factorial;

	return 0;
}