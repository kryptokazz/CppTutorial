#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    void setBalance(double b) {
        if (b >= 0)
            balance = b;
        else
            cout << "Invalid balance!" << endl;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc;
    acc.setBalance(1000);
    cout << "Current balance: $" << acc.getBalance() << endl;

    return 0;
}

