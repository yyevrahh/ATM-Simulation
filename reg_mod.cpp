#include "reg_mod.hpp"

Account Registration::newAccount(Account a, FileUtils fs) {
    Account newAcc = a;
    newAcc.pin = fs.encryptPIN(a.pin);  // just to encrypt pin before it is added to linked list via a friend connection

    return newAcc;
}

double Registration::initDepositValidator(double initDeposit) {
    return double >= 5000 ? initDeposit : -1;   // deposit failed when value results to negative one
}
