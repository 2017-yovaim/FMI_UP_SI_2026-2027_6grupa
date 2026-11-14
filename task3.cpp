#include <iostream>
using namespace std;

bool processTransaction(int& stockQuantity, int quantityChange, bool isSale) {
    if (isSale) {
        if (quantityChange > stockQuantity) {
            return false;
        }
        stockQuantity -= quantityChange;
    }else {
        stockQuantity += quantityChange;
    }
    return true;
}
double calculatePrice(int quantity, double unitPrice, bool isVIP) {
    double totalPrice = quantity * unitPrice;
    if (isVIP) {
        totalPrice *= 0.85;
    }
    if (quantity > 10) {
        totalPrice *= 0.95;
    }
    return totalPrice;
}

int main() {
    int stockQuantity;
    double unitPrice;
    cin >> stockQuantity >> unitPrice;
    cout << stockQuantity << endl;
    cout << unitPrice << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        int changeQty;
        cin >> changeQty;
        processTransaction(stockQuantity, changeQty, false);
        cout << changeQty << endl;
        cout << stockQuantity << endl;
    }
    cin >> choice;
    int sellQty;
    cin >> sellQty;
    int vipInput;
    cin >> vipInput;
    bool vip = (vipInput == 1);
    cout << sellQty << endl;
    if (processTransaction(stockQuantity, sellQty, true)) {
        double finalSum = calculatePrice(sellQty, unitPrice, vip);
        cout << stockQuantity << endl;
        cout << finalSum << endl;
    }

    cin >> choice;
    cin >> sellQty;
    cin >> vipInput;
    vip = (vipInput == 1);
    cout << sellQty << endl;
    if (processTransaction(stockQuantity, sellQty, true)) {
        double finalSum = calculatePrice(sellQty, unitPrice, vip);
        cout << stockQuantity << endl;
        cout << finalSum << endl;
    }
    return 0;
}