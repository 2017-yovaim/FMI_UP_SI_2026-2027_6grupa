#include <iostream>
using namespace std;

int main() {

	char lowerCase = '\0';
	cout << "Please enter a lowercase letter - I will turn it into an uppercase letter!" << endl;
	cin >> lowerCase;

	int difference = 'a' - 'A';

	char upperCase = lowerCase - difference;
	cout << upperCase << endl;


	return 0;
}