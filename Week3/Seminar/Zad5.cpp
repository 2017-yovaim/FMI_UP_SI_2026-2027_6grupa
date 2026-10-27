#include <iostream>
using namespace std;

int main() {
	unsigned grade = 0;
	cout << "Please enter a number - I will tell you the grade it corresponds to!" << endl;
	cin >> grade;

	switch (grade) {
	case 6: 
		cout << "Excellent!" << endl;
		break;
	case 5:
		cout << "Very good!" << endl;
		break;
	case 4:
		cout << "Good!" << endl;
		break;
	case 3:
		cout << "Average" << endl;
		break;
	case 2:
		cout << "Poor" << endl;
		break;
	default:
		cout << "Not a grade!" << endl;
		break;
	}




	return 0;
}