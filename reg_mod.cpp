#include "reg_mod.hpp"

Account Registration::newAccount(string name, string bday, string contact, double deposit, string pin, LinkedList& list) {
    Account newAcc;

    // Assemble the raw data
    newAcc.num = list.nextAccNum();
    newAcc.name = name;
    newAcc.bday = bday;
    newAcc.contactNum = contact;
    newAcc.balance = initDepositValidator(deposit);
    newAcc.pin = pin;

    return newAcc;
}

double Registration::initDepositValidator(double initDeposit) {
    return initDeposit >= 5000 ? initDeposit : -1;   // deposit failed when value results to negative one
}
