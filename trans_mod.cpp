#include "trans_mod.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void Transaction::balInq(LinkedList &list, int accNum) {
    Node* p = list.findNode(accNum);

    if (p == nullptr) {
        cout << "Account not found. " << endl;
        return;
    }

    cout << fixed << setprecision(2);
    cout << "Current Balance: ₱" << p -> acc.balance << endl;
}

bool Transaction::withdraw(LinkedList &list, int accNum, double amount) {
    Node* p = list.findNode(accNum);

    if (p == nullptr) {
        cout << "Account not found. " << endl;
        return;
    }

    if (amount <= 0) {
        cout << "Invalid withdrawal amount. " << endl;
        return false;
    }

    if (amount > p -> acc.balance) {
        cout << "Insufficient balance. " << endl;
        return false;
    }

    p -> acc.balance -= amount;

    FileUtils file;
    file.saveAccounts(list);

    cout << fixed << setprecision(2);
    cout << "Withdraw successful! " << endl;
    cout << "Withdrawn: ₱" << amount << endl;
    cout << "Remaining balance: ₱" << p -> acc.balance << endl;

    return true;
}

bool Transaction::depos(LinkedList &list, int accNum, double amount) {
    Node* p = list.findNode(accNum);

    if (p == nullptr) {
        cout << "Account not found. " << endl;
        return;
    }

    if (amount <= 0) {
        cout << "Invalid deposit amount. " << endl;
        return false;
    }

    p -> acc.balance += amount;

    FileUtils file;
    file.saveAccounts(list);

    cout << fixed << setprecision(2);
    cout << "Deposit successful! " << endl;
    cout << "Deposited: ₱" << amount << endl;
    cout << "Current balance: ₱" << p -> acc.balance << endl;

    return true;
}
