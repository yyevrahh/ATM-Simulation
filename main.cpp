#include "file_mod.hpp"
#include "reg_mod.hpp"
#include "trans_mod.hpp"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template <typename T>
void getVal(T& var, const string& prompt);
void showMenu();
void balanceInquiry(Transaction &trans, LinkedList &list);
void withdraw(Transaction &trans, LinkedList &list);
void deposit(Transaction &trans, LinkedList &list);

int main()
{
    LinkedList list;

    FileUtils file;
    Registration reg;
    Transaction trans;

    file.readAccs(list); //load saved accounts from accounts.dat

    int choice;

    do {
        showMenu();

        getVal(choice, " Enter choice: ");

        switch (choice) {
            case 1: balanceInquiry(trans, list); break;
            case 2: withdraw(trans, list); break;
            case 3: deposit(trans, list); break;
            //case 4: fundTransfer
            //case 5: changePIN
            default:
                cout << "Invalid Input. Please try again.\n" << endl;
        }

    } while (choice != 4);

    return 0;
}

template <typename T>
T getVal(T& var, const string& prompt) {
    cout << prompt;
    while (!(cin >> var)) {
        cout << "\tTry again." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << prompt;
    }
}

void showMenu() {
    cout << "\n==============================\n" << endl;
    cout << "           ATM Simulation          " << endl;
    cout << "\n==============================\n" << endl;
    cout << "   [1] Balance Inquiry " << endl;
    cout << "   [2] Withdraw " << endl;
    cout << "   [3] Deposit " << endl;
    cout << "   [4] Exit " << endl;
    cout << "==============================" << endl;
}

void balanceInquiry(Transaction &trans, LinkedList &list) {
    int accNum;

    cout << "\n********** BALANCE INQUIRY **********" << endl;

    getVal(accNum, "Account number: ");

    trans.balInq(list, accNum);
}

void withdraw(Transaction &trans, LinkedList &list) {
    int accNum;
    double amount;

    cout << "\n************* WITHDRAW *************" << endl;

    getVal(accNum, "Account number: ");
    getVal(amount, "Amount to withdraw: ");

    trans.withdraw(list, accNum, amount);
}

void deposit(Transaction &trans, LinkedList &list) {
    int accNum;
    double amount;

    cout << "\n************* DEPOSIT *************" << endl;

    getVal(accNum, "Account number: ");
    getVal(amount, "Amount to deposit: ");

    trans.depos(list, accNum, amount);
}
