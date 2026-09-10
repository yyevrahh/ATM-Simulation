#include "file_mod.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>

using namespace std;

string FileUtils::encryptPIN(string pin) {
    string encrypted = "";

    //each character is shifted by 3
    for (char digit :  pin) {
        encrypted += char (digit + 3);
    }

    return encrypted;
}

string FileUtils::decryptPIN(string pin) {
    string decrypted = "";

    //converts pin back to its original value
    for (char digit :  pin) {
        decrypted += char (digit - 3);
    }

    return decrypted;
}


void FileUtils::saveAcc(Account a) {
    ofstream file ("accounts.dat", ios::app); //adds new data to the file without overwriting existing data

    file << a.num << endl;
    file << a.name << endl;
    file << a.bday << endl;
    file << a.contactNum << endl;
    file << a.balance << endl;
    file << encryptPIN(a.pin) << endl;

    file.close();
}

void FileUtils::readAccs(LinkedList &list) {
    ifstream file("accounts.dat");

    Account a;

    while (file >> a.num) {
        file.ignore();

        getline(file, a.name);
        getline(file, a.bday);
        getline(file, a.contactNum);

        file >> a.balance;

        string encryptedPIN;
        file >> encryptedPIN;
        a.pin = decryptPIN(encryptedPIN);

        list.add(a);
    }

    file.close();
}

namespace fs = filesystem;

string FileUtils::getUSBRoot() {
    string target = "pin.code";

#ifdef _WIN32
    for (char drive = 'D'; drive <= 'Z'; ++drive) {
        string root = string(1, drive) + ":\\";
        if (fs::exists(root + target)) return root;
    }
#elif __linux__
    string mediaPath = "/run/media/yyevrahh/";  // I am using my own file root name here change it if you'll use it
    if (fs::exists(mediaPath)) {
        for (const auto& entry : fs::directory_iterator(mediaPath)) {
            if (entry.is_directory() && fs::exists(entry.path() / target)) {
                return entry.path().string() + "/";
            }
        }
    }
#endif
    return ""; // USB not found
}

//saves encrypted pin in the flash drive
void FileUtils::saveCard(Account a, string cardPath) {
    ofstream file(cardPath + "/pin.code");

    file << a.num << endl;
    file << encryptPIN(a.pin) << endl;

    file.close();
}

//checks if card is inserted
bool FileUtils::cardIns(string cardPath) {
    ifstream file(cardPath + "/pin.code");

    if (!file) return false;

    file.close();
    return true;
}

bool FileUtils::readCard(string cardPath, int &accNum, string &pin) {
    ifstream file(cardPath + "/pin.code");

    if (!file) return false;

    string encryptedPIN;

    file >> accNum;
    file >> encryptedPIN;

    pin = decryptPIN(encryptedPIN); //pin holds the decrypted value of the encrypted PIN

    file.close();

    return true;
}

bool FileUtils::veriPIN(LinkedList &list, int accNum, string pin) {
    Node* p = list.findNode(accNum);

    if (p == nullptr) return false;

    return p -> acc.pin == pin;
}

void FileUtils::saveAccounts(LinkedList &list) {
    ofstream file("accounts.dat"); //intentionally rewrite the file from scratch using the current list

    Node* p = list.gethead();

    while (p != nullptr) {
        file << p -> acc.num << endl;
        file << p -> acc.name << endl;
        file << p -> acc.bday << endl;
        file << p -> acc.contactNum << endl;
        file << p -> acc.balance << endl;
        file << encryptPIN(p -> acc.pin) << endl;

        p = p -> next;
    }

    file.close();
}
