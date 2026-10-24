#include <iostream>
using namespace std;

int main() {
	char upperCase = '\0';
	cout << "Please enter an uppercase letter - I will turn it into lowercase!" << endl;
	cin >> upperCase;

	int difference = 'a' - 'A';

	char lowerCase = upperCase + difference;
	cout << lowerCase << endl;




	return 0;
}