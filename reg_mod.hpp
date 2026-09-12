#ifndef REG_MOD_HPP
#define REG_MOD_HPP
#include "adt_mod.hpp"

using namespace std;

class Registration {
public:
    Account newAccount(string name, string bday, string contact, double deposit, string pin, LinkedList& list); // main will handle info input for this func
    double initDepositValidator(double initDeposit);
};

#endif
