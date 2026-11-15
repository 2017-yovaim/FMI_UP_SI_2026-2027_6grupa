#include <iostream>

//Създайте програма за управление на склад и ценообразуване за малък магазин, която включва две ключови функции.
//
//Първата функция е :
//
//bool processTransaction(int& stockQuantity, int quantityChange, bool isSale);
//Тя приема текущата наличност по референция, промяната на количеството и флаг дали е продажба или зареждане.Връща false при опит за продажба на повече стока от наличната, а в противен случай актуализира количеството и връща true при успех.
//
//Втората функция е :
//
//double calculatePrice(int quantity, double unitPrice, bool isVIP);
//Тя приема параметрите по стойност и изчислява крайната сума, като прилага 15 % отстъпка за VIP клиенти и допълнителни 5 % отстъпка, ако закупеното количество е над 10 броя.
//
//В главната функция main се симулират операции с начална наличност 20 броя, последвани от :
//
//зареждане на 15 броя;
//продажба на 25 броя за обикновен клиент;
//продажба на 5 броя за VIP клиент.
//Вход:
//
//20
//10.50
//1
//15
//1
//25
//0
//3
//5
//1
//Изход:
//
//20
//10.50
//15
//35
//25
//10
//262.50
//5
//5
//44.63
//5

double readValidUnitPrice(const char* prompt) {
    double price;

    while (true) {
        std::cout << prompt;
        std::cin >> price;

        if (std::cin.fail()) {
            std::cout << "Error: Invalid input! Please enter a valid number.\n";
            std::cin.clear();
            while (std::cin.get() != '\n' && !std::cin.eof());
            continue;
        }

        while (std::cin.peek() == ' ' || std::cin.peek() == '\t') {
            std::cin.get();
        }

        int nextChar = std::cin.peek();
        if (nextChar != '\n' && nextChar != std::char_traits<char>::eof()) {
            std::cout << "Error: Invalid characters after the number! Try again.\n";
            while (std::cin.get() != '\n' && !std::cin.eof());
            continue;
        }

        std::cin.get();

        if (price < 0.0) {
            std::cout << "Error: the price is a negative number! Try again.\n";
            continue;
        }

        return price;
    }
}

bool processTransaction(int& stockQuantity, int quantityChange, bool isSale) {
    if (isSale == true)
    {
        if (quantityChange > stockQuantity)
        {
            return false;
        }

        stockQuantity -= quantityChange;
    }
    else
    {
        stockQuantity += quantityChange;
    }

    return true;
}

double calculatePrice(int quantity, double unitPrice, bool isVIP) {
    double vipPrice = unitPrice * 0.85;
    double moreThan10Price = unitPrice * 0.95;
    double bothSalesPrice = unitPrice * 0.80;

    if (isVIP == true && quantity < 10)
    {
        return quantity * vipPrice;
    }
    else if (isVIP == true && quantity >= 10)
    {
        return quantity * bothSalesPrice;
    }
    else if (quantity >= 10)
    {
        return quantity * moreThan10Price;
    }
    else
    {
        return quantity * unitPrice;
    }
}

int main() {
    int stockQuantity = 20;

    double unitPrice = readValidUnitPrice("Enter the price of the product: ");

    //Не разбрах какви трябва да бъдат входните данни, затова
    //ще използвам зададените в условието

    std::cout << processTransaction(stockQuantity, 15, false) << std::endl;

    std::cout << calculatePrice(25, unitPrice, false) << std::endl;
    std::cout << processTransaction(stockQuantity, 25, true) << std::endl;

    std::cout << calculatePrice(5, unitPrice, true) << std::endl;
    std::cout << processTransaction(stockQuantity, 5, true) << std::endl;

    return 0;
}