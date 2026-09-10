#ifndef FILE_MOD_HPP
#define FILE_MOD_HPP
#include "adt_mod.hpp"
#include "reg_mod.hpp"

class FileUtils {
private:
    //for PIN security
    string encryptPIN(string pin);
    string decryptPIN(string pin);

    friend Account Registration::accountInfo(Account a, FileUtils fs);

public:
    void saveAcc(Account a); //saves new account in "accounts.dat"
    void readAccs(LinkedList &list); //reads account data from a file and stores it in a linkedlist
    void saveAccounts(LinkedList &list); //rewrites the whole file using the latest data in linkedlist

    string getUSBRoot(); // access and check of USB root

    void saveCard(Account a, string cardPath); //saves encrypted pin
    bool cardIns(string cardPath); //check if card is inserted
    bool readCard(string cardPath, int &accNum, string &pin); //reads card info upon insertion

    bool veriPIN(LinkedList &list, int accNum, string pin); //verifying pin
};

#endif
