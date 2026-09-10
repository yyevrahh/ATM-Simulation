#ifndef REG_MOD_HPP
#define REG_MOD_HPP
#include "adt_mod.hpp"
#include "file_mod.hpp"

using namespace std;


class Registration {
public:
    Account newAccount(Account a, FileUtils fs); // main will handle info input for this func
    double initDepositValidator(double initDeposit);
};

#endif
