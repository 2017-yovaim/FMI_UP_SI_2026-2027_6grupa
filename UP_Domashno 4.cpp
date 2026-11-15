#include <iostream>
#include <limits>

int validOperation()
{
    int input = 0;
    while (true)
    {
        std::cout << "Изберете операция (1-5): ";
        std::cin >> input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return input;
    }
}

double validDouble(double& a)
{
    while (true)
    {
        std::cin >> a;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }
    return a;
}

void increment(int& count)
{
    count++;
}

double power(double a, double b) 
{

    double result = 1.0;

    for (int i = 0; i <= b; i++) 
    {

        result *= a;

    }
    return result;

}

void calculator(int function, double num1, double num2, int& count)
{
    switch (function)
    {
    case 1:
        std::cout << "Резултат: " << num1 << " + " << num2 << " = " << num1 + num2 << "\n\n";
        increment(count);
        break;
    case 2:
        std::cout << "Резултат: " << num1 << " - " << num2 << " = " << num1 - num2 << "\n\n";
        increment(count);
        break;
    case 3:
        std::cout << "Резултат: " << num1 << " * " << num2 << " = " << num1 * num2 << "\n\n";
        increment(count);
        break;
    case 4:
        if (num2 == 0)
        {
            std::cout << "ГРЕШКА: Деление на нула не е позволено!\n\n";
        }
        else
        {
            std::cout << "Резултат: " << num1 << " / " << num2 << " = " << num1 / num2 << "\n\n";
            increment(count);
        }
        break;
    case 5:
        std::cout << "Резултат: " << num1 << " на степен " << num2 << " = " << power(num1, (int)num2) << "\n\n";
        increment(count);
        break;
    }
}

int main() 
{

    std::cout << "1. Събиране\n";
    std::cout << "2. Изваждане\n";
    std::cout << "3. Умножение\n";
    std::cout << "4. Деление\n";
    std::cout << "5. Степенуване\n";
    std::cout << "6. Всяко друго число изкарва статистика и приключва програмата\n\n";

    int count = 0;

    while (true)
    {

        int function = validOperation();

        if (function < 1 || function > 5) 
        {

            std::cout << "Общ брой успешни изчисления: " << count;
            break;

        }

        double num1;
        double num2;

        if (function != 5) 
        {

            std::cout << "Въведете първото число: \n";
            validDouble(num1);

            std::cout << "Въведете второто число: \n";
            validDouble(num2);

        }

        else 
        {

            std::cout << "Въведете основата: \n";
            validDouble(num1);

            std::cout << "Въведете степента: \n";
            validDouble(num2);

        }

        calculator(function, num1, num2, count);

    }

    return 0;
}