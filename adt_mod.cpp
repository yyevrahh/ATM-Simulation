#include "adt_mod.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Node* LinkedList::findNode(int accNum) {
    Node* p = head;
    while (p != nullptr) {
        if (p->acc.num == accNum) return p;
        p = p->next;
    }

    return nullptr;
}

void LinkedList::add(Account a) {
    Node* newNode = new Node(a);

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}


/*
*   Displays account info from an account number
*/
void LinkedList::display(int accNum) {
    Node* p = findNode(accNum);

    if (p == nullptr) return;
    else cout << fixed << setprecision(2) << right << setw(20) << "Account Number: " << setw(20) << p->acc.num << endl <<
        setw(20) << "Name: " << setw(50) << p->acc.name << endl <<
        setw(20) << "Birthday: " << setw(20) << p->acc.bday << endl <<
        setw(20) << "Contact Number: " << setw(40) << p->acc.contactNum << endl << endl <<
        setw(20) << "Balance: " << setw(5) << "₱" << setw(15) << p->acc.balance << endl;

    return;
}

void LinkedList::update(int accNum, int changeMode, string newVal) {
    Node* p = findNode(accNum);

    if (p == nullptr) return;
    if (changeMode == 1) p->acc.name = newVal;
    else if (changeMode == 2) p->acc.bday = newVal;
    else if (changeMode == 3) p->acc.contactNum = newVal;
    else if (changeMode == 5) p->acc.pin = newVal;
}

// override
void LinkedList::update(int accNum, int changeMode, double newVal) {
    Node* p = findNode(accNum);

    if (p == nullptr) return;
    if (changeMode == 4) p->acc.balance = newVal;
}

void LinkedList::del(int accNum) {
    Node* p = findNode(accNum);
    if (p == nullptr) return;

    if (p == head && p == tail) head = tail = nullptr;
    else if (p == head) {
        head = head->next;
        head->prev = nullptr;
    } else if (p != head && p != tail) {
        p->next->prev = p->prev;
        p->prev->next = p->next;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete p;
    return;
}

/*
*   Gives the next account number based on tail's last
*/
int LinkedList::nextAccNum() {
    if (tail == nullptr) return MIN_ACC_NUMBER;
    return tail->acc.num + 1;
}
