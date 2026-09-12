#include "trans_mod.hpp"
#include "file_mod.hpp"
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
    cout << "Current Balance: ₱" << p->acc.balance << endl;
}

bool Transaction::withdraw(LinkedList &list, int accNum, double amount) {
    Node* p = list.findNode(accNum);

    if (p == nullptr) {
        cout << "Account not found. " << endl;
        return false;
    }

    if (amount <= 0) {
        cout << "Invalid withdrawal amount. " << endl;
        return false;
    }

    if (amount > p->acc.balance) {
        cout << "Insufficient balance. " << endl;
        return false;
    }

    p->acc.balance -= amount;

    FileUtils file;
    file.saveAccounts(list);

    cout << fixed << setprecision(2);
    cout << "Withdraw successful! " << endl;
    cout << "Withdrawn: ₱" << amount << endl;
    cout << "Remaining balance: ₱" << p->acc.balance << endl;

    return true;
}

bool Transaction::depos(LinkedList &list, int accNum, double amount) {
    Node* p = list.findNode(accNum);

    if (p == nullptr) {
        cout << "Account not found. " << endl;
        return false;
    }

    if (amount <= 0) {
        cout << "Invalid deposit amount. " << endl;
        return false;
    }

    p->acc.balance += amount;

    FileUtils file;
    file.saveAccounts(list);

    cout << fixed << setprecision(2);
    cout << "Deposit successful! " << endl;
    cout << "Deposited: ₱" << amount << endl;
    cout << "Current balance: ₱" << p->acc.balance << endl;

    return true;
}

bool Transaction::fundTrans(LinkedList &list, int fromAccNum, int toAccNum, double amount) {
    Node* fromAcc = list.findNode(fromAccNum);
    Node* toAcc = list.findNode(toAccNum);

    if (fromAcc == nullptr) {
        cout << "Sending account not found." << endl;
        return false;
    } else if (toAcc == nullptr) {
        cout << "Receiving account not found." << endl;
        return false;
    }

    if (amount <= 0) {
        cout << "Invalid transfer amount. " << endl;
        return false;
    } else if (amount > fromAcc->acc.balance) {
        cout << fromAcc->acc.num <<" has insufficient balance." << endl;
        return false;
    }

    fromAcc->acc.balance -= amount;
    toAcc->acc.balance += amount;

    cout << fixed << setprecision(2);
    cout << "Transfer successful! " << endl;
    cout << "Transferred amount: ₱" << amount << endl;
    cout << "[" << fromAcc->acc.num << "] balance: ₱" << fromAcc->acc.balance << endl;
    cout << "[" << toAcc->acc.num << "] balance: ₱" << toAcc->acc.balance << endl;
    return true;
}

bool Transaction::changePIN(LinkedList &list, int accNum, string newPin) {
    Node* p = list.findNode(accNum);

    if (p == nullptr) {
        cout << "Account not found.\n";
        return false;
    }

    string oldPin = p->acc.pin;

    p->acc.pin = newPin;

    cout << "Pin change successful! " << endl;
    cout << "Old PIN: " << oldPin << endl;
    cout << "New PIN: " << newPin << endl;
    return true;
}
