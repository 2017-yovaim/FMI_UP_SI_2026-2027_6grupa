#include <iostream>

void successful(int& operationCount)
{
	operationCount++;
	
}
int calculations(int numberOfaction, double num1, double num2)
{
	int power = 0;
	switch (numberOfaction)
	{
	case 1:
		std::cout << "Result: "<<num1<<"+"<<num2 << " = "<<"\n";
		return num1 + num2;
		break;
		;
	case 2:
		std::cout << "Result: "<<num1<<"-"<<num2 << " = " << "\n";
		return num1 - num2;
		break;
	case 3:
		std::cout << "Result: " << num1 << "*" << num2 << " = " << "\n";
		return num1 * num2;
		break;
	case 4:
	{
		if (num2 == 0)
		{
			std::cout << "Error! You can not devide with 0!";
		}
		else
		{
			std::cout << "Result: " << num1 << "/" << num2 << " = " << "\n";
			return num1 / num2;
		}
	}
		break;
	case 5:
		while (power<=num2)
		{
			num1 *= num1;
			power++;
		}
		std::cout << "Result: " << num1 << "^" << num2 << " = " << "\n";
		return num1;
		break;
	default: break;
	}
}

int main()
{
	std::cout << "1.Sum" << std::endl;
	std::cout << "2.Substract" << std::endl;
	std::cout << "3.Multiplicate" << std::endl;
	std::cout << "4.Divide" << std::endl;
	std::cout << "5.Pow" << std::endl;
	std::cout << "Exit" << std::endl;
	
	int operationCount=0;
	int numOfaction;
	double number1, number2;
	while (true)
	{
		std::cout << " " << std::endl;
		std::cout << "Choose an option (1-5): ";
		std::cin >> numOfaction;
		if (numOfaction < 1 || numOfaction>5)
		{
			std::cout << "Number of successful actions: "<<operationCount;
			break;
		}
		std::cout << "Enter your first number: ";
		std::cin >> number1;
		std::cout << "Enter your second number: ";
		std::cin >> number2;
		if (number2 != 0)
		{
			successful(operationCount);
		}
		std::cout<<calculations(numOfaction, number1, number2);
	}
	
}