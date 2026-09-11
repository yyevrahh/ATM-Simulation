#ifndef TRANS_MOD_HPP
#define TRANS_MOD_HPP
#include "adt_mod.hpp"
#include "file_mod.hpp"

class Transaction {
    public:
        void balInq(LinkedList &list, int accNum);
        bool withdraw(LinkedList &list, int accNum, double amount);
        bool depos(LinkedList &list, int accNum, double amount);
};

#endif
