#ifndef ADT_MOD_HPP
#define ADT_MOD_HPP
#include <iostream>
using namespace std;

#define MIN_ACC_NUMBER 10000

struct Account {
    int num;
    string name;
    string bday;
    string contactNum;
    double balance; // same as initial deposit (>= 5000)
    string pin;
};

struct Node {
    Account acc;
    Node* prev;
    Node* next;

    Node(Account a) : acc(a), prev(nullptr), next(nullptr) {}
};

class LinkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    LinkedList() {}
    ~LinkedList() {
        Node* p = head;
        while (head != nullptr) {
            p = head;
            head = head->next;
            delete p;
        }
    }

    Node* findNode(int accNum);
    void add(Account a);
    void display(int accNum);
    void update(int accNum, int changeMode, string newVal);
    void update(int accNum, int changeMode, double newVal);
    void del(int accNum);
    int nextAccNum();

    Node* gethead(); // getter for private member Node* head
};

#endif
