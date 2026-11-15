#include<iostream>
using namespace std;

void addition(int n1, int n2, int& operationsCount)
{
	cout << "Result: " << n1 + n2;
	operationsCount++;
}

void subtraction(int n1, int n2, int& operationsCount)
{
	cout << "Result: " << n1 - n2;
	operationsCount++;
}

void multiplication(int n1, int n2, int& operationsCount)
{
	cout << "Result: " << n1 * n2;
	operationsCount++;
}

void devision(int n1, int n2, int& operationsCount)
{
	if (n2!=0)
	{
		cout << "Result: " << n1 / n2;
		operationsCount++;
	}
	else
	{
		cout << "ERROR: Division by zero is not allowed!";
	}
}

void exponentiation(int num1, int num2, int operationsCount)
{
	int exp = 1;
	for (int i = 0; i < num2; i++) {
		exp = exp * num1;
	}
	cout << "Result: " << exp;
	operationsCount++;
}

int main()
{
	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Multiplication" << endl;
	cout << "4. Division" << endl;
	cout << "5. Exponentiation" << endl;
	cout << "6. Any other number outputs statistics and terminates the program" << endl;

	int a;

	int operationsCount=0;
	bool isTrue = 1;

	cout << endl;

	while (isTrue)
	{
		cout << "Select an operation (1-5):";
		cin >> a;
		if (a > 5 || a < 1)
		{
			break;
		}
		cout << "Enter the first number:";
		int num1;
		cin >> num1;
		cout << "Enter the second number:";
		int num2;
		cin >> num2;

		switch (a)
		{
		case 1: addition(num1, num2, operationsCount);break;
		case 2: subtraction(num1, num2, operationsCount); break;
		case 3: multiplication(num1, num2, operationsCount);break;
		case 4: devision(num1, num2, operationsCount); break;
		case 5: exponentiation(num1, num2, operationsCount); break;
		default: isTrue = 0;break;
		}
		cout << endl;
		cout << endl;
	}
	cout<< operationsCount;
}