#include <iostream>

double power ( double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

void calculate(int choice, int &operationCount, double a, double b) {
    switch (choice) {
        case 1 : 
        std::cout << "Result: " << a << " + " << b << " = " << (a + b) << std::endl;
        operationCount++;
        break;

        case 2 :
         std::cout << "Result: " << a << " - " << b << " = " << (a - b) << std::endl;
        operationCount++;
        break;
        
        case 3 :
        std::cout << "Result: " << a << " * " << b << " = " << (a * b) << std::endl;
        operationCount++;
        break;

        case 4 :
        if (b == 0) {
            std::cout << "Invalid input! Division by 0 is not allowed. " << std::endl;
        }
        else {
        std::cout << "Result: " << a << " / " << b << " = " << (a / b) << std::endl;
        operationCount++; 
        }
        break;

        case 5:
        {int exp = b;
        double result = power(a, exp);
        std::cout << "Result: " << a << " powered up by " << exp << " = " << result << std::endl;
        operationCount++;}
        break;

        default:
        std::cout << "Invalid operation\n";
        break;
    }
}

int main() {
    int operationCount = 0;
    int choice;
    
    while (true) {
        std::cout << "\n1. Addition\n";
        std::cout << "2. Subtraction\n";
        std::cout << "3. Multiplication\n";
        std::cout << "4. Division\n";
        std::cout << "5. Exponentiation\n";
        std::cout << "6. Any other number shows statistics and exits the program.\n" << std::endl;

        std::cout << "Choose an operation (1-5): ";
        if(!(std::cin >> choice)) {
            break;
        }

        if (choice < 1 || choice > 5) { //ако е извън 1-5, излизаме от цикъла
            break;
        }

        double a, b;
        std::cout << "Enter the first number: ";
        std::cin >> a;
        std::cout << "Enter the second number (or exponent): ";
        std::cin >> b;

        calculate(choice, operationCount, a ,b);
    }
        std::cout <<"Total successful calculations: " << operationCount << std::endl;

        return 0;
    }
