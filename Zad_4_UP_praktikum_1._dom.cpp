#include <iostream>

//Напишете програма на C++, която симулира стандартен настолен калкулатор, работещ в безкраен цикъл до избор на опция за изход от потребителя, като менюто се управлява чрез switch оператор и включва основни аритметични операции като събиране, изваждане, умножение и деление, степенуване, квадратен корен и изход.
//
//Програмата трябва да съдържа поне две функции :
//
//една за извършване на изчисленията;
//втора функция, приемаща параметър по референция(int& operationCount), която следи и брои колко успешни математически операции са били извършени.
//Задължително е да се реализира валидация на входните данни.
//
//Пример:
//
//1. Събиране
//2. Изваждане
//3. Умножение
//4. Деление
//5. Степенуване
//6. Всяко друго число изкарва статистика и приключва програмата
//
//Изберете операция(1 - 4) : 1
//Въведете първото число : 12.5
//Въведете второто число : 7.5
//Резултат : 12.5 + 7.5 = 20.00
//
//Изберете операция(1 - 4) : 1
//Въведете първото число : 100
//Въведете второто число : 0
//ГРЕШКА : Деление на нула не е позволено!
//
//Изберете операция(1 - 4) : 1
//Въведете първото число : 100
//Въведете второто число : 4
//Резултат : 100 / 4 = 25.00
//
//Изберете операция(1 - 4) : 5
//Въведете основата : 2
//Въведете степента : 3
//Резултат : 2 на степен 3 = 8.00
//
//Изберете операция(1 - 4) : 6
//Общ брой успешни изчисления : 3


bool readInt(int& number) {
    std::cin >> number;

    if (std::cin.fail()) {
        std::cin.clear();
        while (std::cin.get() != '\n' && !std::cin.eof());
        return false;
    }

    while (std::cin.peek() == ' ' || std::cin.peek() == '\t') {
        std::cin.get();
    }

    int nextChar = std::cin.peek();
    if (nextChar != '\n' && nextChar != std::char_traits<char>::eof()) {
        while (std::cin.get() != '\n' && !std::cin.eof());
        return false;
    }

    std::cin.get();
    return true;
}

bool readDouble(double& number) {
    std::cin >> number;

    if (std::cin.fail()) {
        std::cin.clear();
        while (std::cin.get() != '\n' && !std::cin.eof());
        return false;
    }

    while (std::cin.peek() == ' ' || std::cin.peek() == '\t') {
        std::cin.get();
    }

    int nextChar = std::cin.peek();
    if (nextChar != '\n' && nextChar != std::char_traits<char>::eof()) {
        while (std::cin.get() != '\n' && !std::cin.eof());
        return false;
    }

    std::cin.get();
    return true;
}

void addition(double num1, double num2) {
    std::cout << num1 << " + " << num2 << " = " << (num1 + num2) << std::endl;
}

void subtraction(double num1, double num2) {
    std::cout << num1 << " - " << num2 << " = " << (num1 - num2) << std::endl;
}

void multiplication(double num1, double num2) {
    std::cout << num1 << " * " << num2 << " = " << (num1 * num2) << std::endl;
}

void division(double num1, double num2) {
    std::cout << num1 << " / " << num2 << " = " << (num1 / num2) << std::endl;
}

void toThePower(double num1, int num2) {
    double result = 1;

    if (num2 > 0)
    {
        for (int i = 0; i < num2; i++)
        {
            result *= num1;
        }
        std::cout << num1 << " ^ " << num2 << " = " << result << std::endl;
    }
    else if (num2 < 0)
    {
        for (int i = 0; i < -num2; i++)
        {
            result *= 1 / num1;
        }
        std::cout << num1 << " ^ " << num2 << " = " << result << std::endl;
    }
    else
    {
        std::cout << num1 << " ^ " << num2 << " = " << result << std::endl;
    }
}

void countIncrease(int& count) {
    count++;
}

int main() {
    std::cout << "1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \n5. Exponentiation \n6. Any other number displays statistics and exits the program\n" << std::endl;
    int operationCount = 0;

    while (true) {
        int operationIndex = 0;
        double num1 = 0.0, num2 = 0.0;
        int exponent = 0;

        std::cout << "Choose an operation (1-5): ";
        while (!readInt(operationIndex)) {
            std::cout << "Invalid input! Please enter a valid integer: ";
        }

        if (operationIndex >= 1 && operationIndex <= 5)
        {
            std::cout << "Enter the first number: ";
            while (!readDouble(num1)) 
            {
                std::cout << "Invalid number! Enter the first number again: ";
            }

            if (operationIndex == 5) 
            {
                std::cout << "Enter the exponent (whole number): ";
                while (!readInt(exponent)) 
                {
                    std::cout << "Invalid input! Enter a whole number for the exponent: ";
                }
            }
            else 
            {
                std::cout << "Enter the second number: ";
                while (!readDouble(num2)) 
                {
                    std::cout << "Invalid number! Enter the second number again: ";
                }
            }
        }
        else
        {
            std::cout << "Total number of successful calculations: " << operationCount << std::endl;
            return 0;
        }

        switch (operationIndex)
        {
        case 1:
            std::cout << "Result: ";
            addition(num1, num2);
            countIncrease(operationCount);
            break;

        case 2:
            std::cout << "Result: ";
            subtraction(num1, num2);
            countIncrease(operationCount);
            break;

        case 3:
            std::cout << "Result: ";
            multiplication(num1, num2);
            countIncrease(operationCount);
            break;

        case 4:
            if (num2 == 0)
            {
                std::cout << "ERROR: Division by zero is not allowed!" << std::endl << std::endl;
                continue;
            }
            std::cout << "Result: ";
            division(num1, num2);
            countIncrease(operationCount);
            break;

        case 5:
            if (num1 == 0 && exponent < 0)
            {
                std::cout << "ERROR: Zero cannot be raised to a negative power!" << std::endl << std::endl;
                continue;
            }
            std::cout << "Result: ";
            toThePower(num1, exponent);
            countIncrease(operationCount);
            break;

        default:
            return 0;
        }

        std::cout << std::endl;
    }

    return 0;
}