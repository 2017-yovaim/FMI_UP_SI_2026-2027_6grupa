#include <iostream>

bool processTransaction(int &stockQuantity, int quantityChange, bool isSale) {
    if (isSale) { // ако е продажба, проверявам дали има достатъчна стока
        if (quantityChange > stockQuantity) {
            return false;
        }
        stockQuantity -= quantityChange;
    } 
    else { //зареждане
        stockQuantity += quantityChange;
    }
    true;
}

double calculatePrice(int quantity, double unitPrice, bool isVIP){
    double total = quantity * unitPrice;

    if (isVIP) {
        total *= 0.85;
    }

    if (quantity > 10) {
        total *= 0.95;
    }

    return total;
}

int main() {
    int stockQuantity;
    double unitPrice;

    std::cin >> stockQuantity >> unitPrice;

    int operation1Type, operation1Quantity;
    std::cin >> operation1Type >> operation1Quantity;
    processTransaction(stockQuantity, operation1Quantity, (operation1Type != 0));
    std::cout << stockQuantity << "\n";

    int op2Type, op2Quantity;
    std::cin >> op2Type >>op2Quantity;
    if (processTransaction(stockQuantity, op2Quantity, (op2Type != 0))){
        double price = calculatePrice(op2Quantity, unitPrice, false);
        std::cout << stockQuantity << "\n";
        std::cout << price << "\n";
    }

    int isVipInput, op3Quantity;
    std::cin >> isVipInput >> op3Quantity;

    if (processTransaction(stockQuantity, op3Quantity, true)){
        double price = calculatePrice(op3Quantity, unitPrice, (isVipInput !=0));
        std::cout << stockQuantity << "\n";
        std::cout << price << "\n";
    }

    return 0;
}