#include <iostream>
#include "file_mod.hpp"

using namespace std;

template <typename T>
void getVal(T& var, const string& prompt);

int main()
{

    cout << "Hello world!" << endl;
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
