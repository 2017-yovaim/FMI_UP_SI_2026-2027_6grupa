#include <iostream>

int main()
{
	int number1;
	int number2;
	std::cin >> number1 >> number2;

	std::cout << "Sum: " << number1 + number2 << std::endl;
	std::cout << "Difference: " << number1 - number2 << std::endl;
	std::cout << "Multiplication: " << number1 * number2 << std::endl;

	if (number2 == 0)
	{
		std::cout << "Division impossible!" << std::endl;
	}
	else
	{
		std::cout << "Division: " << number1 / number2 << std::endl;
	}

	return 0;
}

