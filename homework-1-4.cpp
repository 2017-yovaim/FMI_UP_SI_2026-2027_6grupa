#include <iostream>

using namespace std;

double power(double base, int exp) {
    if (exp == 0) return 1.0;

    double result = 1.0;
    int absExp = (exp < 0) ? -exp : exp;

    for (int i = 0; i < absExp; ++i) {
        result *= base;
    }

    return (exp < 0) ? (1.0 / result) : result;
}
double customSqrt(double x) {
    if (x == 0.0) return 0.0;

    double guess = x;
    double epsilon = 0.0000001;

    while (true) {
        double nextGuess = 0.5 * (guess + x / guess);
        double diff = (guess > nextGuess) ? (guess - nextGuess) : (nextGuess - guess);
        if (diff < epsilon) {
            break;
        }
        guess = nextGuess;
    }

    return guess;
}

bool calculate(int choice, double a, double b, double& result) {
    switch (choice) {
    case 1: 
        result = a + b;
        return true;
    case 2: 
        result = a - b;
        return true;
    case 3: 
        result = a * b;
        return true;
    case 4: 
        if (b == 0) {
            cout << "Error: Division by zero is not allowed!" << endl;
            return false;
        }
        result = a / b;
        return true;
    case 5: 
        if (b != (int)b && b != 0.5) {
            cout << "Error: Enter an integer exponent (or 0.5 for square root)!" << endl;
            return false;
        }
        if (b == 0.5 && a < 0) {
            cout << "Error:: Square root of a negative number is not real!" << endl;
            return false;
        }
        if (a == 0 && b < 0) {
            cout << "Error:: Zero cannot be raised to a negative power!" << endl;
            return false;
        }
        result = power(a, b);
        return true;
    default:
        return false;
    }
}

void registerSuccess(int& operationCount) {
    operationCount++;
}
void clearInputStream() {
    cin.clear();
    while (cin.get() != '\n') {
    }
}

int main() {
    int operationCount = 0;
    int choice;

    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Power" << endl;
    cout << "6. Any other number displays statistics and exits the program" << endl;

    while (true) {
        cout << "\nChoose an operation (1-5): ";
        if (!(cin >> choice)) {
            cout << "ERROR: Invalid input! Please enter a number." << endl;
            clearInputStream();
            continue;
        }

        if (choice < 1 || choice > 5) {
            cout << "Total successful calculations: " << operationCount << endl;
            break;
        }

        double num1 = 0, num2 = 0, result = 0;

        if (choice == 5) {
            cout << "Enter the base: ";
            if (!(cin >> num1)) {
                cout << "Error:: Invalid base!" << endl;
                clearInputStream();
                continue;
            }
            cout << "Enter the exponent: ";
            if (!(cin >> num2)) {
                cout << "Error:: Invalid exponent!" << endl;
                clearInputStream();
                continue;
            }
        }
        else {
            cout << "Enter the first number: ";
            if (!(cin >> num1)) {
                cout << "ERROR: Invalid number!" << endl;
                clearInputStream();
                continue;
            }
            cout << "Enter the second number: ";
            if (!(cin >> num2)) {
                cout << "ERROR: Invalid number!" << endl;
                clearInputStream();
                continue;
            }
        }

        if (calculate(choice, num1, num2, result)) {
            registerSuccess(operationCount);

            cout.setf(ios::fixed);
            cout.precision(2);

            switch (choice) {
            case 1:
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case 2:
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case 3:
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case 4:
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                break;
            case 5:
                cout << "Result: " << num1 << " to the power of " << num2 << " = " << result << endl;
                break;
            }

            cout.unsetf(ios::fixed);
            cout.precision(6);
        }
    }

    return 0;
}
