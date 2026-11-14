#include <iostream>
using namespace std;
void countOperations(int &operationCount) {
	operationCount++;
}
double pow(double number1, double number2) {
	double power=1;
	if (number2 == 0) {
			return 1;
		}else {
	for (int i = 0; i < number2; ++i) {
		 power *= number1;
		}
	return power;
	}
}
double calculator(int choice, int &operationCount) {
	double number1;
	double number2;
		switch (choice) {
		case 1:
			cout << "Enter the first number: ";
			cin >> number1;
			cout << "Enter the second number: ";
			cin >> number2;
			countOperations(operationCount);
			return number1 + number2;

			break;
		case 2: 
			cout << "Enter the first number: ";
			cin >> number1;
			cout << "Enter the second number: ";
			cin >> number2;
			countOperations(operationCount);
			return number1 - number2;
			break;
		case 3:
			cout << "Enter the first number: ";
			cin >> number1;
			cout << "Enter the second number: ";
			cin >> number2;
			countOperations(operationCount);
			return number1 * number2;
			break;
		case 4:
			cout << "Enter the first number: ";
			cin >> number1;
			cout << "Enter the second number: ";
			cin >> number2;
			if (number2 == 0) {
				cout << "Division by 0 is not allowed!";
				break;
			}else{
			countOperations(operationCount);
			return number1 / number2;}
			break;
		case 5:
			cout << "Enter the first number: ";
			cin >> number1;
			cout << "Enter the second number: ";
			cin >> number2;
			countOperations(operationCount);
			return pow(number1, number2);
			break;
		case 6:
			cout << "Total of operations:" << operationCount;
			break;
}
}
int main() {
	int n;
	double number1;
	double number2;
	int operationCount=0;
	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Multiplication" << endl;
	cout << "4. Division" << endl;
	cout << "5. Exponentiation" << endl;
	cout << "6. Exit and show statistic" << endl;

	while (true) {
		cout << "Choose an opreation: " ;
		cin >> n;
		if (n == 6 || n < 1 || n > 5) {
			cout << "Total successful calculations: " << operationCount;
			break;
		}
		double result = calculator(n, operationCount);
		cout << "Result: " << result << endl;
	}

}