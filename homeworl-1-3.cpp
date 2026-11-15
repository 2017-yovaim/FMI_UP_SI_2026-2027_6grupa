#include <iostream>
using namespace std;

bool processTransaction(int& stockQuantity, int quantityChange, bool isSale) {
    if (quantityChange < 0) {
        return false;
    }

    if (isSale) {
        if (quantityChange > stockQuantity) {
            return false;
        }
        stockQuantity -= quantityChange;
    }
    else {
        stockQuantity += quantityChange;
    }

    return true;
}

double calculatePrice(int quantity, double unitPrice, bool isVIP) {
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

    int command1, loadQty;
    int command2, sale1Qty, isVip1;
    int command3, sale2Qty, isVip2;

    // 1. Четем ЦЕЛИЯ вход наведнъж (без да извеждаме нищо по време на въвеждането)
    cin >> stockQuantity >> unitPrice;
    cin >> command1 >> loadQty;
    cin >> command2 >> sale1Qty >> isVip1;
    cin >> command3 >> sale2Qty >> isVip2;

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << stockQuantity << endl;
    cout << unitPrice << endl;

    if (processTransaction(stockQuantity, loadQty, false)) {
        cout << loadQty << endl;
        cout << stockQuantity << endl;
    }

    if (processTransaction(stockQuantity, sale1Qty, true)) {
        cout << sale1Qty << endl;
        cout << stockQuantity << endl;
        cout << calculatePrice(sale1Qty, unitPrice, isVip1 == 1) << endl;
    }

    if (processTransaction(stockQuantity, sale2Qty, true)) {
        cout << sale2Qty << endl;
        cout << stockQuantity << endl;
        cout << calculatePrice(sale2Qty, unitPrice, isVip2 == 1) << endl;
    }

    cout << stockQuantity << endl;

    return 0;
}